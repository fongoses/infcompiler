/**********************************************************************
 *Analisador Sintático  
 **********************************************************************
 * This represents the syntax analyzer.
 **********************************************************************
 * Authors:
 * Luiz Gustavo Frozi de Castro e Souza (fongoses@gmail.com)
 * Mario Cesar Gasparoni Junior (mariogasparoni@gmail.com)
 **********************************************************************/

%token KW_WORD  /* tipo 'int' */   
%token KW_BOOL /* tipo 'boolean' */
%token KW_BYTE /* tipo 'char' */
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
}
	

%%


program: dec program
	| /* empty program */
	;


dec: 	vardec
	| varassign
	| fundec
	;

literal : 
	 LIT_INTEGER
	| LIT_FALSE
	| LIT_TRUE
	| LIT_CHAR	
	| LIT_STRING
	;

tipos :  
	  KW_WORD
	| KW_BOOL
	| KW_BYTE
	;
 



/* var declaration*/
 // $2 corresponde a KW_WORD e %4 corresponde a LIT_INTEGER recebido em yyval pelo analisador lexico
 vardec:
	  tipos TK_IDENTIFIER ':' literal ';' { fprintf(stdout,"Var %s inicializada\n",(char*)$2); };
	

	/*
	 | KW_WORD TK_IDENTIFIER ':' LIT_INTEGER ';' { fprintf(stdout,"Var %s inicializada com %d\n",(char*)$2, $4); }
	 | KW_BOOL TK_IDENTIFIER ':' LIT_FALSE ';' { fprintf(stdout,"Var %s inicializada com %d\n",(char*)$2, $4); }
	 | KW_BOOL TK_IDENTIFIER ':' LIT_TRUE ';' { fprintf(stdout,"Var %s inicializada com %d\n",(char*)$2, $4); }
	 | KW_BYTE TK_IDENTIFIER ':' LIT_CHAR ';' { fprintf(stdout,"Var %s inicializada com um char\n",(char*)$2); }
	 | KW_BYTE '$' TK_IDENTIFIER ':' LIT_STRING ';' { fprintf(stdout,"Var %s inicializada com uma string\n",(char*)$3);}
	 | vetordec
         ;
	*/
	/* cifrao colado ? */

 /* inicializador de vetor */
  vetorini: literal
	| literal ',' vetorini
	;

 vetordec: 
	 tipo TK_IDENTIFIER '[' LIT_INTEGER ']' ':' vetorini ';' {fprintf(stdout,"Vetor %s inicializado corretamente\n",(char*)$2); }
	;

	/*
	 KW_WORD TK_IDENTIFIER '[' LIT_INTEGER ']' ':' LIT_INTEGER ';' {fprintf(stdout,"Vetor %s inicializado corretamente\n",(char*)$2); }
	|KW_BOOL TK_IDENTIFIER '[' LIT_INTEGER ']' ':' literal_bool ';' {fprintf(stdout,"Vetor %s inicializado corretamente com booleanos\n",(char*)$2); }
	|KW_BYTE TK_IDENTIFIER '[' LIT_INTEGER ']' ':' LIT_CHAR ';' {fprintf(stdout,"Vetor %s inicializado corretamente com char\n",(char*)$2); }
	|KW_BYTE '$' TK_IDENTIFIER '[' LIT_INTEGER ']' ':' LIT_STRING ';' {fprintf(stdout,"Vetor %s inicializado corretamente com string\n",(char*)$3);}
	;*/



 /* var assignment*/
 // $1 corresponde a KW_WORD e %3 corresponde a LIT_INTEGER recebido em yyval pelo analisador lexico
 varassign: TK_IDENTIFIER '=' LIT_INTEGER ';' { fprintf(stdout,"Var %s recebe %d\n",(char*)$1, $3); }
	 |  TK_IDENTIFIER '=' LIT_FALSE ';' { fprintf(stdout,"Var %s recebe %d\n",(char*)$1, $3); }
	 |  TK_IDENTIFIER '=' LIT_TRUE ';' { fprintf(stdout,"Var %s recebe %d\n",(char*)$1, $3); }
	 |  TK_IDENTIFIER '=' LIT_CHAR ';' { fprintf(stdout,"Var %s recebe um char",(char*)$1); }
	 |  '$' TK_IDENTIFIER '=' LIT_STRING ';' { fprintf(stdout,"Var %s recebe uma string\n",(char*)$2); };
		
	

 /* function declaration */
 fundec : KW_WORD TK_IDENTIFIER '(' funparam ')' '{' body '}'	{ fprintf(stdout,"funcao:\n > %s \n",(char*)$2); };

 funparam: 	/* empty params */
		| KW_WORD TK_IDENTIFIER 
		| KW_WORD TK_IDENTIFIER ',' funparam 
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

