/**********************************************************************
 *Analisador Sintático  
 **********************************************************************
 * This represents the syntax analyzer.
 **********************************************************************
 * Authors:
 * Luiz Gustavo Frozi de Castro e Souza (fongoses@gmail.com)
 * Mario Cesar Gasparoni Junior (mariogasparoni@gmail.com)
 **********************************************************************/

%token KW_WORD     
%token KW_BOOL
%token KW_BYTE
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_LOOP
%token KW_INPUT        
%token KW_RETURN      
%token KW_OUTPUT      


%token OPERATOR_LE    
%token OPERATOR_GE    
%token OPERATOR_EQ    
%token OPERATOR_NE    
%token OPERATOR_AND   
%token OPERATOR_OR    

%token <number> SYMBOL_LIT_INTEGER /*todo1: floating too? */   
%token SYMBOL_LIT_FALSE      
%token SYMBOL_LIT_TRUE	     
%token SYMBOL_LIT_CHAR       
%token SYMBOL_LIT_STRING
%token <node> SYMBOL_IDENTIFIER  
%token TOKEN_ERROR    

%{

	#include "hashtable.h" //pega tipo 'node'

%}


%union {
	int number;
	HASH_NODE * node;
	char * text;
}
	

%%


program: dec program
	| /* empty program */
	;


dec: 	vardec
	| fundec
	;


intdec : SYMBOL_LIT_INTEGER { fprintf(stdout,"Inteiro!\n"); };
	
 /* var declaration*/
 // $2 corresponde a KW_WORD e %4 corresponde a SYMBOL_LIT_INTEGER recebido em yyval pelo analisador lexico
 vardec: KW_WORD SYMBOL_IDENTIFIER '=' SYMBOL_LIT_INTEGER ';' { fprintf(stdout,"Var %s recebe %d\n",(char*)$2, $4); };
 

 /* function declaration */
 fundec : KW_WORD SYMBOL_IDENTIFIER '(' funparam ')' '{' body '}'	{ fprintf(stdout,"funcao:\n > %s \n",(char*)$2); };

 funparam: 	/* empty params */
		| KW_WORD SYMBOL_IDENTIFIER 
		| KW_WORD SYMBOL_IDENTIFIER ',' funparam 
		;

 /* function's body declaration */
 //function's body is basically a block.
 body:  /* empty body/block */ 
	| dec; // or contains declarations. Todo: bodydec (body's declarations is not the same as the program declarations 
	

%%

#include <stdio.h>
#include <stdlib.h>



int yyerror(char *s){
	fprintf(stderr, "Failed to compilate the code\n");
	exit(1); //Todo: exit with value 1 on error ?
	
}


int main(){

	
	yyparse(); //if something goes wrong, then yyerror will be called and the program dies here.
		
	fprintf(stdout,"Compilation Successfull.\n");
	exit(0); //successfull compilation: exits with 0
	


}

