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

%token SYMBOL_LIT_INTEGER /*todo1: floating too? */   
%token SYMBOL_LIT_FALSE      
%token SYMBOL_LIT_TRUE	     
%token SYMBOL_LIT_CHAR       
%token SYMBOL_LIT_STRING
%token SYMBOL_IDENTIFIER  

%token TOKEN_ERROR    


%%

 /*
program:  empty program 
	| dec program
	;
*/

dec: vardec
	;
 /* declaracao de variaveis*/
vardec: SYMBOL_LIT_INTEGER SYMBOL_IDENTIFIER '=' SYMBOL_LIT_INTEGER { fprintf(stdout,"Declaracao de var\n"); };



 /* fundec : KW_INT IDENTIFIER '(' ')' '{' body '}' ; */

%%

#include <stdio.h>
#include <stdlib.h>



int yyerror(){
	//fprintf(stderr, "Syntax Error\n");
	//exit(1);	
	return -1;
	
}
