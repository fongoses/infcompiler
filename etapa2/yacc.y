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
	#define DEBUG 1	
	#define TESTE_MANUAL 0
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


program: dec program
	| /* empty program */
	;

dec: blocodec
	| vetordec
	;

blocodec:
	 vardec
	| fundec
	| expressao ';'  { if(DEBUG) if(DEBUG) fprintf(stdout,"Expressao!\n");}
	| comando
	;

comando:
	 varassign
	| vetorassign
	| controlefluxo
	| input
	| output
	| return
	;

comandos:
	/* comando vazio*/
	| comando
	| comando comandos;

literal : 
	 LIT_INTEGER
	| LIT_FALSE
	| LIT_TRUE
	| LIT_CHAR	
	| LIT_STRING
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
	/*  ponteiro */

 /* inicializador de vetor */
  vetorini:// literal
	| literal vetorini //totest1
	;

 vetordec:
	 tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ';'  {if(DEBUG) fprintf(stdout,"Vetor %s declarado sem inicializacao\n",(char*)$2); }
	| tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ':' vetorini ';' {if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)$2); }
	; //totest2



 /* var assignment*/
 // $1 corresponde a KW_WORD e %3 corresponde a LIT_INTEGER recebido em yyval pelo analisador lexico
 varassign: TK_IDENTIFIER '=' literal ';' { if(DEBUG) fprintf(stdout,"Var %s recebe um valor\n",(char*)$1); }
	   | '$' TK_IDENTIFIER '=' literal ';' { if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)$2); }
	;

 vetorassign:  TK_IDENTIFIER '[' expressao ']' '=' literal ';' { if(DEBUG) fprintf(stdout,"Vetor %s recebe uma string\n",(char*)$1); }	
		;
	 
		//totest3
	

 /* function declaration */
 fundec : tipos TK_IDENTIFIER '(' funparam ')'  body	{ if(DEBUG) fprintf(stdout,"funcao:\n > %s \n",(char*)$2); };

 funparam: 	/* empty params */
		| tipos TK_IDENTIFIER
		| tipos '$' TK_IDENTIFIER //totest4			 
		| tipos TK_IDENTIFIER ',' funparam 
		| tipos '$' TK_IDENTIFIER ',' funparam
		; //vetor nao eh parametro

 /* function's body declaration */
 //function's body is basically a block.
 bloco:  /* empty body/block */ 
	| comandos
	;

 body: '{' bloco '}' ';'
	;
	
 input:
	KW_INPUT TK_IDENTIFIER ';' {if(DEBUG) fprintf(stdout,"Lido valor e armazenado em %s\n",(char*) $2);}
	;

 outputexp: /* expressao da clausula output */
	| expressao
	| expressao ',' outputexp
	; 

 output: KW_OUTPUT outputexp ';' {if(DEBUG) fprintf(stdout,"Valor escrito na saida padrao\n");}
	;

 return: KW_RETURN expressao ';'
	;

 operador: OPERATOR_LE
	| OPERATOR_GE
	| OPERATOR_EQ
	| OPERATOR_NE
	| OPERATOR_AND
	| OPERATOR_OR
	| '+' | '-' | '*' | '\\' | '<' | '>' | '!' | '&' | '/'
	;	
	
expressao:
	 literal
	| TK_IDENTIFIER
	| TK_IDENTIFIER '[' LIT_INTEGER ']' 
	| '&' TK_IDENTIFIER 
	| '*' TK_IDENTIFIER	
	| '(' expressao ')'
	| expressao operador expressao
	;

/* FLUXO */


condif: KW_IF '(' expressao ')' KW_THEN comando KW_ELSE comando {if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");}
       | KW_IF '(' expressao ')' KW_THEN body {if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");}
       | KW_IF '(' expressao ')' KW_THEN body KW_ELSE body {if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");}
       ;

loop : KW_LOOP '(' expressao ')' body {if(DEBUG) fprintf(stdout,"Clausula loop avaliada\n");}
   | KW_LOOP '(' expressao ')' comando {if(DEBUG) fprintf(stdout,"Clausula loop avaliada\n");}
   ;

%%


#include <stdio.h>
#include <stdlib.h>

extern int yyin;

int yyerror(char *s){
	fprintf(stderr, "Failed to compilate the code\n");
	exit(3); 
	
}


int main(int argc , char ** argv){


	if(TESTE_MANUAL){

		if(argc < 2) {
                	fprintf(stderr,"Error: No input file\n");
                	exit(1);
       	 	}

        	yyin=fopen(argv[1],"r"); //yyin: global var which stores the file pointer to the current input file of the lexycal analyzer

        	if(yyin <= 0) {
                	fprintf(stderr,"Error opening the file\n");
                	exit(1);
        	}
		initMe();
		yyparse();


	}else{

		initMe();	
		yyparse(); //if something goes wrong, then yyerror will be called and the program dies here.
		
		fprintf(stdout,"Compilation Successfull.\n");
		exit(0); //successfull compilation: exits with 0
	}	


}

