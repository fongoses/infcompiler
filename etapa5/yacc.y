 /**********************************************************************
     *Analisador Sintático
 **********************************************************************
 * This represents the syntax analyzer.
 **********************************************************************
 * Authors:
 * Luiz Gustavo Frozi de Castro e Souza (fongoses@gmail.com)
 * Mario Cesar Gasparoni Junior (mariogasparoni@gmail.com)
 **********************************************************************/

%token <tipo> KW_WORD  /* tipo 'int' */
%token <tipo> KW_BOOL /* tipo 'boolean' */
%token <tipo> KW_BYTE /* tipo 'char' */
%token <exp> KW_IF
%token <exp> KW_THEN
%token <exp> KW_ELSE
%token <exp> KW_LOOP
%token <exp> KW_INPUT
%token <exp> KW_RETURN
%token <exp> KW_OUTPUT


%token <operator> OPERATOR_LE
%token <operator> OPERATOR_GE
%token <operator> OPERATOR_EQ
%token <operator> OPERATOR_NE
%token <operator> OPERATOR_AND
%token <operator> OPERATOR_OR


%token <node> LIT_INTEGER
%token <node> LIT_FALSE
%token <node> LIT_TRUE
%token <node> LIT_CHAR
%token <node> LIT_STRING
%token <node> TK_IDENTIFIER
%token TOKEN_ERROR


%token SYMBOL_LIT_UNDEFINED 0
%token SYMBOL_LIT_INTEGER 1
%token SYMBOL_LIT_FLOATING 2
%token SYMBOL_LIT_TRUE 3
%token SYMBOL_LIT_FALSE 4
%token SYMBOL_LIT_CHAR 5
%token SYMBOL_LIT_STRING 6
%token SYMBOL_IDENTIFIER 7

 //tipos dos valores a serem associados , pelo parser, a essas expressoes
%type <tree> literal  // 07/05 : identificador e number sao as mesmas coisas. Associados a eles temos o ponteiro para a tab de simbolos
%type <tree> expressao //07/05 : 'number' para 'tree'
%type <tree> comando
%type <tree> comandosseq //em cmdlist, estamos associando um ponteiro da arvore estatica ao valor padrao ($$) da expressa
%type <tree> blococomandos
%type <tree> litseq
%type <tree> varassign
%type <tree> vetorassign
%type <tree> argseq
%type <tree> vetordec
%type <tree> vardec
%type <tree> fundec
%type <tree> paramseq
%type <tree> localdecseq
%type <tree> tipos
%type <tree> program
%type <tree> dec
%type <tree> globalseq

%type <tree> controlefluxo
%type <tree> input
%type <tree> output
%type <tree> return
%type <tree> outputseq
%type <tree> condif
%type <tree> loop
%type <tree> param

%{

    #include "astree.h" //ja inclui hashtable.h
    #include "tac.h"
    #include <stdio.h>
    #include <stdlib.h>

    #define DEBUG 0
    extern char error;
    extern int yyin;
    extern FILE * outputFile;
    extern ASTREE * TREE ; //no com a lista de declaracoes globais
    extern TAC * mainTAC; //tac global
%}


%union {
    HASH_NODE * node;
    char * text;
    int boolean; /* we are associating our boolean type to C's int type. */
    int tipo;
    int exp;
    int operator;
    ASTREE * tree;
    HASH_NODE * symbol;
}

 //associatividade/prioridade de expressoes
 //prioridade >
%left OPERATOR_AND OPERATOR_OR
%nonassoc OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE '<' '>' '&' '|' '!' '\\'
%left '+' '-'
%left '*' '/'
%nonassoc IFX
%nonassoc KW_ELSE

%%


program: globalseq {
        $$ = astreeCreate(ASTREE_PROGRAM,$1,0,0,0,0);
        TREE = $$->son[0]; //armazena arvore em variavel global, ja que algumas declaracoes precisam ser recuperadas durante o percurso da arvore
        if(outputFile) astreeCreateCode($$,0);
        astreeCheckDeclarations($$);
        if (astreeCheckNature($$) == DATATYPE_INVALID) error = 1;
        mainTAC = generateCode($$);
        //print_tac(mainTAC);
        print_tac(tacReverse(mainTAC));
        //astreePrintTree($$,0);
    ;};


globalseq: /* empty program */
    { $$ = 0;}
    | globalseq dec {
        //antes de criar no com declaracao, verifica declaracao
        $$ = astreeCreate(ASTREE_GLOBALSEQ,$1,$2,0,0,0);
    //  astreeCheckDeclarations($2); em astreeCreate
         }
    ;

dec:    vardec { $$ = $1;}
    | vetordec { $$ = $1; } //declaracao de vetor
    | fundec { $$ = $1; }
    ;

localdecseq: //lista de declaracoes locais :declaracoes permitidas antes de um bloco (declaracao de vetor e funcao nao sao permitidas aqui
    { $$ = 0;}
    | localdecseq vardec { $$ = astreeCreate(ASTREE_LOCALDECSEQ,$1,$2,0,0,0);}
    ;

comando:
    varassign { $$ =  $1;}
    | vetorassign { $$ = $1;}
    | controlefluxo { $$ = $1;}
    | input { $$ = $1;}
    | output { $$ = $1;}
    | return { $$ = $1;}
    | blococomandos { $$ = $1;}
    ;


comandosseq: //rever: como serah reconstituida uma seq de ponto-e-virgula
    /* sequencia de comandos vazia : comando vazio*/
    {$$ = 0; }
    |';' { $$ = 0; } //seq vazia: valor associado eh zero.
    | comandosseq comando ';'  {
        $$ = astreeCreate(ASTREE_COMMANDSEQ,$1,$2,0,0,0);
    }
    ;

blococomandos:
    '{' comandosseq '}' { $$ = astreeCreate(ASTREE_BLOCK,$2,0,0,0,0); }
    ;

literal :
     LIT_INTEGER  {
            //printf(" Achei integer %d\n",$1);
            //$$ = $1; //valor associado ao literal inteiro lido eh o proprio valor do analisador lexico
            //obs: necessario declarar o type para essa associacao.

            //para gerar arvore:
            $$ = astreeCreate(ASTREE_LIT_INT,0,0,0,0,$1); //07/05: ptr da tabela de simbolos recebido pelo scanner

            }
    | LIT_FALSE { $$ = astreeCreate(ASTREE_LIT_FALSE,0,0,0,0,$1); }
    | LIT_TRUE   { $$ = astreeCreate(ASTREE_LIT_TRUE,0,0,0,0,$1); }
    | LIT_CHAR { $$ = astreeCreate(ASTREE_LIT_CHAR,0,0,0,0,$1); }
    | LIT_STRING {$$ = astreeCreate(ASTREE_LIT_STRING,0,0,0,0,$1);}
    ;

 litseq : //sequencia de literais
    { $$ = 0; }
    | litseq literal  {$$ = astreeCreate(ASTREE_LIT_SEQ,$1,$2,0,0,0);}//rever: recursao a esquerda aqui gera mais 9 red-red conflicts oO
    ;


tipos:  KW_WORD { $$ = astreeCreate(ASTREE_KWWORD,0,0,0,0,0); }
    | KW_BOOL{ $$ = astreeCreate(ASTREE_KWBOOL,0,0,0,0,0); }
    | KW_BYTE{ $$ = astreeCreate(ASTREE_KWBYTE,0,0,0,0,0); }
    ;

controlefluxo: condif { $$ = $1;}
    | loop {$$ = $1;}
    ;


/* var declaration*/
 // $2 corresponde a KW_WORD e %4 corresponde a LIT_INTEGER recebido em yyval pelo analisador lexico
 vardec:
     tipos TK_IDENTIFIER ':' literal ';' { if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)$2);
        $$ = astreeCreate(ASTREE_VARDEC,$1,$4,0,0,$2);

     }
     | tipos '$' TK_IDENTIFIER ':' literal ';'  { if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)$3);
        $$ = astreeCreate(ASTREE_PTRDEC,$1,$5,0,0,$3);
     }
     ;


 vetordec:
    tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ';' {if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)$2);

        $$ = astreeCreate(ASTREE_VETORDEC,$1,astreeCreate(ASTREE_LIT_INT,0,0,0,0,$4),0,0,$2); //gambiarra autorizada: nao pode ter literal, pois vetordec somente aceita inteiros como tamanho.
    }
    | tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ':' litseq ';' {if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)$2);
        $$ = astreeCreate(ASTREE_VETORDEC,$1,astreeCreate(ASTREE_LIT_INT,0,0,0,0,$4),$7,0,$2); //gambiarra autorizada.
     }
    ;



 /* var assignment*/
 //alteracao pelo professor (imprimir arvore na atribuicao)
 // $1 corresponde a KW_WORD e $3 corresponde a LIT_INTEGER recebido em yyval pelo analisador lexico
 varassign: TK_IDENTIFIER '=' expressao  {
            $$ = astreeCreate(ASTREE_SCALAR_ASS,$3,0,0,0,$1); //$1 eh o identificador (na realidade o seu ponteiro para tab de simbolos)

            if(DEBUG) fprintf(stdout,"Var %s recebe um valor\n",(char*)$1); //astreePrint()
    }
       | '&' TK_IDENTIFIER '=' expressao  { if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)$2);

        $$ = astreeCreate(ASTREE_PTR_ASS,$4,0,0,0,$2); //ajustar alterar, nao eh SCALAR_ASS
     }
       | '*' TK_IDENTIFIER '=' expressao  { if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)$2);
        $$ = astreeCreate(ASTREE_DEREF_ASS,$4,0,0,0,$2);
     }
    ;

 vetorassign:  TK_IDENTIFIER '[' expressao ']' '=' expressao  { if(DEBUG) fprintf(stdout,"Vetor %s recebe uma string\n",(char*)$1);
    $$ = astreeCreate(ASTREE_VET_ASS,$3,$6,0,0,$1);
     }
    ;


/* functions */
//inserir esse codigo na etapa2
 param: tipos TK_IDENTIFIER {$$ = astreeCreate(ASTREE_PARAM,$1,0,0,0,$2);}
    | tipos '$' TK_IDENTIFIER {$$= astreeCreate(ASTREE_PTRPARAM,$1,0,0,0,$3);}
    ;

 paramseq:
    /* empty params */
    { $$=0;}
    | param {$$ = $1;}
    | paramseq ',' param { $$ =  astreeCreate(ASTREE_PARAMSEQ,$1,$3,0,0,0); }
    ;

 fundec :  tipos TK_IDENTIFIER '(' paramseq ')'  localdecseq blococomandos {
    if(DEBUG) fprintf(stdout,"funcao %s:\n",(char*)$2);
        $$ = astreeCreate(ASTREE_FUNDEC,$1,$4,$6,$7,$2);
     }
    ;

  /* function's body declaration */

 input:
    KW_INPUT TK_IDENTIFIER  {
        if(DEBUG) fprintf(stdout,"Lido valor e armazenado em %s\n",(char*) $2);
        $$ = astreeCreate(ASTREE_INPUT,0,0,0,0,$2);
    }
    ;

 outputseq: /* expressao da clausula output, eh uma sequencia. */
    expressao { $$ = $1;}
    | outputseq ',' expressao {$$ = astreeCreate(ASTREE_OUTPUTSEQ,$1,$3,0,0,0);}
    ;

 output: KW_OUTPUT outputseq  {if(DEBUG) fprintf(stdout,"Valor escrito na saida padrao\n");
            $$=astreeCreate(ASTREE_OUTPUT,$2,0,0,0,0);
    }
    ;

 return: KW_RETURN expressao { $$ = astreeCreate(ASTREE_RETURN,$2,0,0,0,0); }
    ;


 argseq: //rever: argumentos de chamada de funcao eh uma lista de expressoes
    { $$ = 0;}
    | expressao     {$$ = $1;}
    | argseq ',' expressao  {$$ = astreeCreate(ASTREE_ARGSEQ,$1,$3,0,0,0); }
    ;

 //alteracoes feitas em aula, sugeridas pelo professor
 //basicamente, as alteracoes correspondem somente ao analisador sintatico reali
 //zar a avaliacao e o calculo de algumas operacoes. Isso corresponde a um inter
 //pretador, e nao a um compilador, de fato.
 //Serao feitas, ainda na aula de hoje (25/04/13) , mecanismos para geracao de
 //arvore sintatica (astree.h)
 expressao:
    literal { $$ = $1; } //ok, apenas associa o valor recebido a expressao. No caso, eh o ponteiro da tab de simb
    |  TK_IDENTIFIER { $$=astreeCreate(ASTREE_SYMBOL,0,0,0,0,$1); } //scanner necessita retornar ptr para tab de simbolos (ok)
    | TK_IDENTIFIER '[' expressao  ']' { $$ = astreeCreate(ASTREE_VETCALL,$3,0,0,0,$1); } //chamada de campo vetor
    | TK_IDENTIFIER '(' argseq ')'  { $$ = astreeCreate(ASTREE_FUNCALL,$3,0,0,0,$1); }// Chamada de funcao
    | '&' TK_IDENTIFIER { $$ = astreeCreate(ASTREE_PTRADDR,0,0,0,0,$2); }
    | '*' TK_IDENTIFIER { $$ = astreeCreate(ASTREE_PTRVALUE,0,0,0,0,$2); }
    | '(' expressao ')' { $$ = astreeCreate(ASTREE_EXPRESSION,$2,0,0,0,0); }
    | expressao '-' expressao { $$=astreeCreate(ASTREE_MIN,$1,$3,0,0,0); }
    | '-' expressao { $$=astreeCreate(ASTREE_UMIN,$2,0,0,0,0); } // Menos Unario
    | expressao '+' expressao { $$=astreeCreate(ASTREE_ADD,$1,$3,0,0,0); }
    | expressao '*' expressao {  $$=astreeCreate(ASTREE_MUL,$1,$3,0,0,0); }
    | expressao OPERATOR_LE expressao {  $$=astreeCreate(ASTREE_LE,$1,$3,0,0,0); }
    | expressao OPERATOR_GE  expressao {  $$=astreeCreate(ASTREE_GE,$1,$3,0,0,0); }
    | expressao OPERATOR_EQ expressao {  $$=astreeCreate(ASTREE_EQ,$1,$3,0,0,0); }
    | expressao OPERATOR_NE expressao{  $$=astreeCreate(ASTREE_NE,$1,$3,0,0,0); }
    | expressao OPERATOR_AND expressao {  $$=astreeCreate(ASTREE_AND,$1,$3,0,0,0); }
    | expressao OPERATOR_OR  expressao{  $$=astreeCreate(ASTREE_OR,$1,$3,0,0,0); }
    | expressao '/'  expressao{  $$=astreeCreate(ASTREE_DIV,$1,$3,0,0,0); }
    | expressao '<' expressao {  $$=astreeCreate(ASTREE_L,$1,$3,0,0,0); }
    | expressao '>'  expressao {  $$=astreeCreate(ASTREE_G,$1,$3,0,0,0); }
    // | '!' expressao {  $$=astreeCreate(ASTREE_NOT,$1,0,0,0,0); } //existe essa expressao ?
    ;

 /* FLUXO */
 //comando nao pode ter ';' por causa do if
 condif:
         KW_IF '(' expressao ')' KW_THEN comando %prec IFX {
        if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");
        $$=astreeCreate(ASTREE_IF,$3,$6,0,0,0);
    }
    |KW_IF '(' expressao ')' KW_THEN comando KW_ELSE comando {
        if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");
        $$=astreeCreate(ASTREE_IF_ELSE,$3,$6,$8,0,0);
    }
        ;

 loop : KW_LOOP '(' expressao ')' comando {
        if(DEBUG) fprintf(stdout,"Clausula loop avaliada\n");
        $$=astreeCreate(ASTREE_LOOP,$3,$5,0,0,0);
    }
    ; //obs: um bloco de comandos tb eh um comando

%%


int yyerror(char *s){
        fprintf(stderr, "Failed to compilate the code.\n");
    exit(3);

}


