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



%{

	#include "hashtable.h" //pega tipo 'node'
	#include <stdio.h>
	#include <stdlib.h>

extern int yyin;


	#define DEBUG 0	
%}


%union {
	int number;
	HASH_NODE * node;
	char * text;
	char boolean; /* we are associating our boolean type to C's char type. */
	int tipo;
	int exp;
	int operator;
}
	

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
	 varassign
	| vetorassign
	| controlefluxo
	| input
	| output
	| return
	| blococomandos
	;


comandosseq:
	/* sequencia de comandos vazia : comando vazio*/	
	| comando ';' comandosseq //recursao a esquerda

blococomandos:
	'{' comandosseq '}'
	;

literal : 
	 LIT_INTEGER { printf(" Achei integer %d\n",$1);}
	| LIT_FALSE
	| LIT_TRUE
	| LIT_CHAR	
 //	| LIT_STRING //Professor recomenda string nao ser literal, por motivos a serem discutidos na etapa futura	
	;

 litseq : //sequencia de literais
	literal //sequencia de literais nao pode ser vazia por causa da clausula vetordec  (que adiciona ':').
	| literal litseq //rever: recursao a esquerda aqui gera mais 9 red-red conflicts oO
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
 // $1 corresponde a KW_WORD e %3 corresponde a LIT_INTEGER recebido em yyval pelo analisador lexico
 varassign: TK_IDENTIFIER '=' expressao  { if(DEBUG) fprintf(stdout,"Var %s recebe um valor\n",(char*)$1); }
	   | '$' TK_IDENTIFIER '=' expressao  { if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)$2); }
	   | '*' TK_IDENTIFIER '=' expressao  { if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)$2); } //rever: pode essa atribuicao?
	;

 vetorassign:  TK_IDENTIFIER '[' expressao ']' '=' literal  { if(DEBUG) fprintf(stdout,"Vetor %s recebe uma string\n",(char*)$1); }	
		;
	 
		//totest //rever: no do professor , string nao eh literal3

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

 operador: OPERATOR_LE
	| OPERATOR_GE
	| OPERATOR_EQ
	| OPERATOR_NE
	| OPERATOR_AND
	| OPERATOR_OR
	| '+' | '-' | '*' | '\\' | '<' | '>' | '!' | '&' | '/'
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

 expressao: literal
	|  TK_IDENTIFIER
	| TK_IDENTIFIER '[' expressao  ']' //chamada de campo vetor
 	| TK_IDENTIFIER '(' argseq')' // Chamada de funcao
	| '&' TK_IDENTIFIER 
	| '*' TK_IDENTIFIER	
	| '(' expressao ')'
	| expressao operador expressao
	;

 /* FLUXO */
 //comando nao pode ter ';' por causa do if
 condif: KW_IF '(' expressao ')' KW_THEN comando KW_ELSE comando {if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");}
       | KW_IF '(' expressao ')' KW_THEN comando  {if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");}
       ;

 loop : KW_LOOP '(' expressao ')' comando {if(DEBUG) fprintf(stdout,"Clausula loop avaliada\n");}
   	; //obs: um bloco de comandos tb eh um comando

%%


int yyerror(char *s){
	fprintf(stderr, "Failed to compilate the code\n");
	exit(3); 
	
}


