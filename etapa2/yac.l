/**********************************************************************
 *Analisador Sintático  
 **********************************************************************
 * This represents the syntax analyzer.
 **********************************************************************
 * Authors:
 * Luiz Gustavo Frozi de Castro e Souza (fongoses@gmail.com)
 * Mario Cesar Gasparoni Junior (mariogasparoni@gmail.com)
 **********************************************************************/

/* Should we put the following code in  y.tab.h?*/

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

%token TK_IDENTIFIER  
%token LIT_INTEGER    
%token LIT_FALSE      
%token LIT_TRUE	     
%token LIT_CHAR       
%token LIT_STRING     

%token TOKEN_ERROR    




%token KW_WORD
%token KW_IF
%token KW_LOOP
%token KW_INT
%token IDENTIFIER
%token LIT_INTEGER

%%

program: dec program
	|
	;

dec: vardec
	;
 /* declaracao de variaveis*/
vardec : KW_INT IDENTIFIER '=' LIT_INTEGER { fprintf(stderr,""); };



//fundec : KW_INT IDENTIFIER '(' ')' '{' body '}' ; 

%%

#include <stdio.h>
#include <stdlib.h>

int yylval=0;

int yyerror(){
	fprintf(stderr, "Syntax Error\n");
	exit(1);
}
