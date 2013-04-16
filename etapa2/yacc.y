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


dec: 	vardec
	| vetordec
	| varassign
	| fundec
	| expressao ';'  {fprintf(stdout,"Expressao!\n");}
	| input
	| output
;

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
 
expressao:	 
	 literal operador expressao
 	| '(' expressao ')' operador '(' expressao ')'
	| '(' expressao ')'
	| LIT_INTEGER | LIT_FALSE | LIT_TRUE | LIT_CHAR | LIT_STRING  	 
	;	

operador: OPERATOR_LE
	| OPERATOR_GE
	| OPERATOR_EQ
	| OPERATOR_NE
	| OPERATOR_AND
	| OPERATOR_OR
	| '+' | '-' | '*' | '\\' | '<' | '>' | '!' | '&' | '/'
	;	
	
	


/* var declaration*/
 // $2 corresponde a KW_WORD e %4 corresponde a LIT_INTEGER recebido em yyval pelo analisador lexico
 vardec:
	 tipos TK_IDENTIFIER ':' literal ';' { fprintf(stdout,"Var %s inicializada\n",(char*)$2); }
	 | tipos '$' TK_IDENTIFIER ':' literal ';'  { fprintf(stdout,"Var %s inicializada\n",(char*)$3); }
	 ; //totest6 
	/*  ponteiro */

 /* inicializador de vetor */
  vetorini:// literal
	| literal vetorini //totest1
	;

 vetordec:
	 tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ';'  {fprintf(stdout,"Vetor %s declarado sem inicializacao\n",(char*)$2); }
	| tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ':' vetorini ';' {fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)$2); }
	; //totest2



 /* var assignment*/
 // $1 corresponde a KW_WORD e %3 corresponde a LIT_INTEGER recebido em yyval pelo analisador lexico
 varassign: TK_IDENTIFIER '=' literal ';' { fprintf(stdout,"Var %s recebe um valor\n",(char*)$1); }
	   | '$' TK_IDENTIFIER '=' literal ';' { fprintf(stdout,"Var %s recebe uma string\n",(char*)$2); }
		| TK_IDENTIFIER '['LIT_INTEGER ']' '=' literal ';' { fprintf(stdout,"Vetor %s recebe uma string\n",(char*)$1); }	
		;
	 
		//totest3
	

 /* function declaration */
 fundec : tipos TK_IDENTIFIER '(' funparam ')' '{' body '}'	{ fprintf(stdout,"funcao:\n > %s \n",(char*)$2); };

 funparam: 	/* empty params */
		| tipos TK_IDENTIFIER
		| tipos '$' TK_IDENTIFIER //totest4			 
		| tipos TK_IDENTIFIER ',' funparam 
		| tipos '$' TK_IDENTIFIER ',' funparam
		; //vetor nao eh parametro

 /* function's body declaration */
 //function's body is basically a block.
 body:  /* empty body/block */ 
	| dec; // or contains declarations. Todo: bodydec (body's declarations is not the same as the program declarations 

 input:
	KW_INPUT TK_IDENTIFIER ';' {fprintf(stdout,"Lido valor e armazenado em %s\n",(char*) $2);}
	;

 outputexp:
	| expressao
	| expressao ',' outputexp
	; 

 output: KW_OUTPUT outputexp ';' {fprintf(stdout,"Valor escrito na saida padrao\n");}
	; 
	

%%

#include <stdio.h>
#include <stdlib.h>



int yyerror(char *s){
	fprintf(stderr, "Failed to compilate the code\n");
	exit(1); //Todo: exit with value 1 on error ?
	
}


int main(){

	initMe();	
	yyparse(); //if something goes wrong, then yyerror will be called and the program dies here.
		
	fprintf(stdout,"Compilation Successfull.\n");
	exit(0); //successfull compilation: exits with 0
	


}

