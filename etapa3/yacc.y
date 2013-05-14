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


%{

//	#include "hashtable.h" //pega tipo 'node'
	#include "astree.h" //ja inclui hashtable.h
	#include <stdio.h>
	#include <stdlib.h>

	extern int yyin;
	ASTREE * TREE;

	#define DEBUG 0	
%}


%union {
	int number; //obs do professor: em vez do numero, deve haver um ponteiro
				// para a tabela de simbolos
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


program: 
	/* empty program */
	{ $$ = 0; fprintf(stdout,"Program:\n");}
	| dec program { $$ = astreeCreate(ASTREE_PROGRAM,$1,$2,0,0,0);astreePrintTree($$); } // astreeCreate(ASTREE_PROGRAM,$1,$2,0,0,0);
	
	;

dec: 	vardec { $$ = astreeCreate(ASTREE_DEC,$1,0,0,0,0); fprintf(stdout,"Vardec\n"); }
	| vetordec { $$ = astreeCreate(ASTREE_DEC,$1,0,0,0,0); } //declaracao de vetor
	| fundec { $$ = astreeCreate(ASTREE_DEC,$1,0,0,0,0); }
	;

localdecseq: //lista de declaracoes locais :declaracoes permitidas antes de um bloco (declaracao de vetor e funcao nao sao permitidas aqui
	{ $$ = 0;}
	| vardec localdecseq { $$ = astreeCreate(ASTREE_LOCALDECSEQ,$1,$2,0,0,0);}
	;

comando:
	 varassign { $$ = 0;}
	| vetorassign { $$ = 0;} 
	| controlefluxo { $$ = 0;}
	| input{ $$ = 0;}
	| output{ $$ = 0;}
	| return{ $$ = 0;}
	| blococomandos{ $$ = 0;}
	;


comandosseq:
	/* sequencia de comandos vazia : comando vazio*/
	{ $$ = 0; } //seq vazia: valor associado eh zero. 
	| comando ';' comandosseq  {
		//07/05: ok, de acordo com o codigo do professor
		astreeCreate(ASTREE_CMDL,$1,$3,0,0,0);
		} //recursao a esquerda

blococomandos:
	'{' comandosseq '}' { $$ = $2; astreePrintTree($2); }
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
 //	| LIT_STRING //Professor recomenda string nao ser literal, por motivos a serem discutidos na etapa futura	
	;

 litseq : //sequencia de literais
	{ $$ = 0; }
	| literal litseq  {$$ = astreeCreate(ASTREE_LIT_SEQ,$1,$2,0,0,0);}//rever: recursao a esquerda aqui gera mais 9 red-red conflicts oO
	;
 

tipos:  KW_WORD { $$ = astreeCreate(ASTREE_KWWORD,0,0,0,0,0); }
	| KW_BOOL{ $$ = astreeCreate(ASTREE_KWBOOL,0,0,0,0,0); }
	| KW_BYTE{ $$ = astreeCreate(ASTREE_KWBYTE,0,0,0,0,0); }
	;
	
controlefluxo: condif
	| loop
	;


/* var declaration*/
 // $2 corresponde a KW_WORD e %4 corresponde a LIT_INTEGER recebido em yyval pelo analisador lexico
 vardec:
	 tipos TK_IDENTIFIER ':' literal ';' { if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)$2);
		$$ = astreeCreate(ASTREE_VARDEC,$1,$4,0,0,$2);
	
	 }
	 | tipos '$' TK_IDENTIFIER ':' literal ';'  { if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)$3);
		$$ = astreeCreate(ASTREE_VARDEC,$1,$5,0,0,$3);
	 }
	 ; //totest6 

 
 vetordec:
	tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ';' {if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)$2); 
	
		$$ = astreeCreate(ASTREE_VETORDEC,$1,astreeCreate(ASTREE_LIT_INT,0,0,0,0,$4),0,0,$2); //ajustar
	}
	| tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ':' litseq ';' {if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)$2);
		$$ = astreeCreate(ASTREE_VETORDEC,$1,astreeCreate(ASTREE_LIT_INT,0,0,0,0,$4),$7,0,$2); //ajustar
	 }
	; //totest2



 /* var assignment*/ 
 //alteracao pelo professor (imprimir arvore na atribuicao)
 // $1 corresponde a KW_WORD e %3 corresponde a LIT_INTEGER recebido em yyval pelo analisador lexico
 varassign: TK_IDENTIFIER '=' expressao  { 
			$$ = astreeCreate(ASTREE_SCALAR_ASS,0,0,0,0,$1); //$1 eh o identificador (na realidade o seu ponteiro para tab de simbolos)
			
			if(DEBUG) fprintf(stdout,"Var %s recebe um valor\n",(char*)$1); //astreePrint() 
	}
	   | '$' TK_IDENTIFIER '=' expressao  { if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)$2);
	
		$$ = astreeCreate(ASTREE_SCALAR_ASS,0,0,0,0,0); //ajustar alterar, nao eh SCALAR_ASS
	 }
	   | '*' TK_IDENTIFIER '=' expressao  { if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)$2);
		$$ = astreeCreate(ASTREE_SCALAR_ASS,0,0,0,0,0);
	 }
	;

 vetorassign:  TK_IDENTIFIER '[' expressao ']' '=' literal  { if(DEBUG) fprintf(stdout,"Vetor %s recebe uma string\n",(char*)$1);
			$$ = astreeCreate(ASTREE_SCALAR_ASS,0,0,0,0,0);
		
		 }	
		;
	 

/* functions */	
 paramseq: 	/* empty params */
		{ $$=0;}
		| tipos TK_IDENTIFIER {$$ = astreeCreate(ASTREE_PARAMSEQ,0,0,0,0,$2);}
		| tipos '$' TK_IDENTIFIER {$$= astreeCreate(ASTREE_PARAMSEQ,0,0,0,0,$3);}			 
		| tipos TK_IDENTIFIER ',' paramseq {$$ = astreeCreate(ASTREE_PARAMSEQ,$4,0,0,0,$2);}
		| tipos '$' TK_IDENTIFIER ',' paramseq { $$ = astreeCreate(ASTREE_PARAMSEQ,$5,0,0,0,$3);}
		; //vetor nao eh parametro, porem ponteiros sao


 fundec :  tipos TK_IDENTIFIER '(' paramseq ')'  localdecseq blococomandos { 
	
	if(DEBUG) fprintf(stdout,"funcao %s:\n",(char*)$2);
		$$ = astreeCreate(ASTREE_FUNDEC,$4,$6,$7,0,$2);
	 }
	;

  /* function's body declaration */
 //function's body is basically a block.

 input:
	KW_INPUT TK_IDENTIFIER  {if(DEBUG) fprintf(stdout,"Lido valor e armazenado em %s\n",(char*) $2);}
	;

 outputexp: /* expressao da clausula output */
	  expressao
	| LIT_STRING
	| expressao ',' outputexp
	| LIT_STRING ',' outputexp
	; 

 output: KW_OUTPUT outputexp  {if(DEBUG) fprintf(stdout,"Valor escrito na saida padrao\n");}
	;

 return: KW_RETURN expressao 
	;

 
 argseq: //rever: argumentos de chamada de funcao eh uma lista de expressoes
	{ $$ = 0;} 
	| expressao 	{$$ = astreeCreate(ASTREE_ARGSEQ,$1,0,0,0,0);}
	| argseq ',' expressao  {$$ = astreeCreate(ASTREE_ARGSEQ,$1,$3,0,0,0); }
	;

 //alteracoes feitas em aula, sugeridas pelo professor
 //basicamente, as alteracoes correspondem somente ao analisador sintatico reali
 //zar a avaliacao e o calculo de algumas operacoes. Isso corresponde a um inter
 //pretador, e nao a um compilador, de fato.
 //Serao feitas, ainda na aula de hoje (25/04/13) , mecanismos para geracao de	
 //arvore sintatica (astree.h) 
 expressao: literal {
			 
		//	$$ = $1; //acao default, nao necessaria 
			//para a associacao acima '$$', que corresponde a asso
			//ciacao de 'expressao' com literal, eh necessario
			//declarar o tipo 'type' de expressao, que nessa regra
			//eh um 'number'

			//dia 07/05: a insercao deve ocorrer aqui ou em literal ?Literal
			$$ = $1; //ok, apenas associa o valor recebido a expressao. No caso, eh o ponteiro da tab de simb	
			}
	|  TK_IDENTIFIER { 
				$$=astreeCreate(ASTREE_SYMBOL,0,0,0,0,$1); //scanner necessita retornar ptr para tab de simbolos (ok)
			 } 
	| TK_IDENTIFIER '[' expressao  ']' {$$ = astreeCreate(ASTREE_VETCALL,$3,0,0,0,$1);} //chamada de campo vetor
 	| TK_IDENTIFIER '(' argseq')'  {$$ = astreeCreate(ASTREE_FUNCALL,0,$3,0,0,$1);}// Chamada de funcao
	| '&' TK_IDENTIFIER { $$ = astreeCreate(ASTREE_PTRADDR,0,0,0,0,$2);} 
	| '*' TK_IDENTIFIER { $$ = astreeCreate(ASTREE_PTRVALUE,0,0,0,0,$2);} 
	| '(' expressao ')' { $$ = 0;} 
	| expressao '-'	expressao   //prof: expressoes agora sao separadas.
				{ 
					$$=astreeCreate(ASTREE_ADD,$1,$3,0,0,0);
				}
	| expressao '+' expressao { 
					 //adcionar if DEBUG aqui
					//$$ = $1 + $3; //associado o valor da ex-
					//pressao como o resultado da soma	
					//printf("Soma %d\n",$1+$3);

					//agora, gerando a arvore (anteriormente
					//apenas interpretavamos o codigo)
					$$=astreeCreate(ASTREE_ADD,$1,$3,0,0,0);
				
	
				 }
	| expressao '*' expressao {  $$=astreeCreate(ASTREE_MUL,$1,$3,0,0,0); }
	| expressao OPERATOR_LE expressao {  $$=astreeCreate(ASTREE_MUL,$1,$3,0,0,0); }
	| expressao OPERATOR_GE  expressao {  $$=astreeCreate(ASTREE_DIV,$1,$3,0,0,0); }
	| expressao OPERATOR_EQ expressao {  $$=astreeCreate(ASTREE_MUL,$1,$3,0,0,0); }
	| expressao OPERATOR_NE expressao{  $$=astreeCreate(ASTREE_DIV,$1,$3,0,0,0); }
	| expressao OPERATOR_AND expressao {  $$=astreeCreate(ASTREE_MUL,$1,$3,0,0,0); }
	| expressao OPERATOR_OR  expressao{  $$=astreeCreate(ASTREE_DIV,$1,$3,0,0,0); }
	| expressao '\\'  expressao{  $$=astreeCreate(ASTREE_DIV,$1,$3,0,0,0); }
	| expressao '<' expressao {  $$=astreeCreate(ASTREE_MUL,$1,$3,0,0,0); }
	| expressao '>'  expressao{  $$=astreeCreate(ASTREE_DIV,$1,$3,0,0,0); }
	| expressao '!' expressao {  $$=astreeCreate(ASTREE_MUL,$1,$3,0,0,0); }
	| expressao '&'  expressao{  $$=astreeCreate(ASTREE_DIV,$1,$3,0,0,0); }


	;

 /* FLUXO */
 //comando nao pode ter ';' por causa do if
 condif: 
        KW_IF '(' expressao ')' KW_THEN comando %prec IFX {if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");}
	|KW_IF '(' expressao ')' KW_THEN comando KW_ELSE comando {if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");}
       	;

 loop : KW_LOOP '(' expressao ')' comando {if(DEBUG) fprintf(stdout,"Clausula loop avaliada\n");}
   	; //obs: um bloco de comandos tb eh um comando

%%


int yyerror(char *s){
        fprintf(stderr, "Failed to compilate the code\n");
	exit(3); 
	
}


