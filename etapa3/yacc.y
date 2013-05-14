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


%token <number> LIT_INTEGER /*todo1: floating too? */   
%token <boolean> LIT_FALSE      
%token <boolean> LIT_TRUE	     
%token <text> LIT_CHAR       
%token <text> LIT_STRING
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

%{

//	#include "hashtable.h" //pega tipo 'node'
	#include "astree.h" //ja inclui hashtable.h
	#include <stdio.h>
	#include <stdlib.h>

	extern int yyin;


	#define DEBUG 0	
%}


%union {
	int number; //obs do professor: em vez do numero, deve haver um ponteiro
				// para a tabela de simbolos
	HASH_NODE * node;
	char * text;
	char boolean; /* we are associating our boolean type to C's char type. */
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
	| dec program
	;

dec: 	vardec 
	| vetordec //declaracao de vetor
	| fundec
	;

localdecseq: //lista de declaracoes locais :declaracoes permitidas antes de um bloco (declaracao de vetor e funcao nao sao permitidas aqui)
	| vardec localdecseq
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
			$$ = astreeCreate(ASTREE_LIT_INT,0,0,0,0,(HASH_NODE*)$1); //07/05: ptr da tabela de simbolos recebido pelo scanner
	
			}
	
	| LIT_FALSE { }
	| LIT_TRUE  { }
	| LIT_CHAR	
 //	| LIT_STRING //Professor recomenda string nao ser literal, por motivos a serem discutidos na etapa futura	
	;

 litseq : //sequencia de literais
	{ $$ = 0; }
	| literal litseq  {$$ = astreeCreate(ASTREE_LIT_SEQ,$1,$2,0,0,0);}//rever: recursao a esquerda aqui gera mais 9 red-red conflicts oO
	;
 

tipos:  KW_WORD 
	| KW_BOOL
	| KW_BYTE
	;
	
controlefluxo: condif
	| loop
	;


/* var declaration*/
 // $2 corresponde a KW_WORD e %4 corresponde a LIT_INTEGER recebido em yyval pelo analisador lexico
 vardec:
	 tipos TK_IDENTIFIER ':' literal ';' { if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)$2); }
	 | tipos '$' TK_IDENTIFIER ':' literal ';'  { if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)$3); }
	 ; //totest6 

 
 vetordec:
	tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ';' {if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)$2); }
	| tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ':' litseq ';' {if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)$2); }
	; //totest2



 /* var assignment*/ 
 //alteracao pelo professor (imprimir arvore na atribuicao)
 // $1 corresponde a KW_WORD e %3 corresponde a LIT_INTEGER recebido em yyval pelo analisador lexico
 varassign: TK_IDENTIFIER '=' expressao  { 
			$$ = astreeCreate(ASTREE_SCALAR_ASS,0,0,0,0,$1); //$1 eh o identificador (na realidade o seu ponteiro para tab de simbolos)
			
			if(DEBUG) fprintf(stdout,"Var %s recebe um valor\n",(char*)$1); //astreePrint() 
	}
	   | '$' TK_IDENTIFIER '=' expressao  { if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)$2); }
	   | '*' TK_IDENTIFIER '=' expressao  { if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)$2); } //rever: pode essa atribuicao?
	;

 vetorassign:  TK_IDENTIFIER '[' expressao ']' '=' literal  { if(DEBUG) fprintf(stdout,"Vetor %s recebe uma string\n",(char*)$1); }	
		;
	 

/* functions */	
 paramseq: 	/* empty params */
		| tipos TK_IDENTIFIER
		| tipos '$' TK_IDENTIFIER //totest4			 
		| tipos TK_IDENTIFIER ',' paramseq 
		| tipos '$' TK_IDENTIFIER ',' paramseq
		; //vetor nao eh parametro, porem ponteiros sao


 fundec :  tipos TK_IDENTIFIER '(' paramseq ')'  localdecseq blococomandos { if(DEBUG) fprintf(stdout,"funcao %s:\n",(char*)$2); };

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

 
//sequencia de argumentos para chamada de funcao: Rever: uma expressao pode ser expressa na chamada de funcao?
/* argseq:
	| literal
	| TK_IDENTIFIER
	| argseq ',' literal 	
	| argseq ',' TK_IDENTIFIER
	;
*/
 argseq: //rever: argumentos de chamada de funcao eh uma lista de expressoes 
	| expressao
	| argseq ',' expressao
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
	| TK_IDENTIFIER '[' expressao  ']' //chamada de campo vetor
 	| TK_IDENTIFIER '(' argseq')' // Chamada de funcao
	| '&' TK_IDENTIFIER 
	| '*' TK_IDENTIFIER	
	| '(' expressao ')'
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


