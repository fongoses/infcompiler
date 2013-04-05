
/*main.c  
 **********************************************************************
 * This code represents the main function, which calls/uses the scanner.
 **********************************************************************
 * Authors:
 * Luiz Gustavo Frozi de Castro e Souza (fongoses@gmail.com)
 * Mario Cesar Gasparoni Junior (mariogasparoni@gmail.com)
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

extern char * yytext;
extern FILE * yyin;
extern int LineNumber;
extern int running;


int lexycalAnalyzer(){
	/*
		This function reads the data coming from the stdin untill finds an EOF.
		The data is parsed and inserted into the Symbol Table (Hash Table).
	
	*/	


	int tok=0;
	while(tok != EOF){			
			
		tok = yylex();		
		
		switch(tok){
			case 0: break; //\n			
			case KW_WORD : printf("KW_WORD at line: %d, and address: xxx\n",LineNumber);break;
			case KW_BOOL : printf("KW_BOOL at line: %d\n",LineNumber);break;
			case KW_BYTE : printf("KW_BYTE at line: %d\n",LineNumber);break;
			case KW_IF: printf("KW_IF at line: %d\n",LineNumber);break;			
			case KW_THEN: printf("KW_THEN at line %d\n",LineNumber);break;
			case KW_ELSE: printf("KW_ELSE at line %d\n",LineNumber);break;
			case KW_LOOP: printf("KW_LOOP at line %d\n",LineNumber);break;
			case KW_INPUT: printf("KW_INPUT at line %d\n",LineNumber);break;
			case KW_RETURN: printf("KW_RETURN at line %d\n",LineNumber);break;
			case KW_OUTPUT: printf("KW_OUTPUT at line %d\n",LineNumber);break;
			case OPERATOR_LE: printf("OPERATOR_LE at line %d\n",LineNumber);break;
			case OPERATOR_GE: printf("OPERATOR_GE at line %d\n",LineNumber);break;
			case OPERATOR_EQ: printf("OPERATOR_EQ at line %d\n",LineNumber);break;
			case OPERATOR_NE: printf("OPERATOR_NE at line %d\n",LineNumber);break;
			case OPERATOR_AND: printf("OPERATOR_AND at line %d\n",LineNumber);break;
			case OPERATOR_OR: printf("OPERATOR_OR at line %d\n",LineNumber);break;
			case SYMBOL_IDENTIFIER: printf("SYMBOL_IDENTIFIER at line %d\n",LineNumber);break;
			case SYMBOL_LIT_INTEGER: printf("SYMBOL_LIT_INTEGER at line %d\n",LineNumber); break;
			case SYMBOL_LIT_FALSE: printf("SYMBOL_LIT_FALSE at line %d\n",LineNumber); break;
			case SYMBOL_LIT_TRUE: printf("SYMBOL_LIT_TRUE at line %d\n",LineNumber); break;
			case SYMBOL_LIT_CHAR: printf("SYMBOL_LIT_CHAR at line %d\n",LineNumber); break;	
			case SYMBOL_LIT_STRING: printf("SYMBOL_LIT_STRING at line %d\n",LineNumber); break;
			case TOKEN_ERROR: printf("TOKEN_ERROR at line %d\n",LineNumber); return -1; //Invalid symbol. Compilation error!
			default: printf("Tok: %s at line %d\n", yytext,LineNumber);
		}
	}

	return 1;


}

int syntaxAnalyzer(){
	/*
		This functions parses all the tokens given by the lexycal analyzer.	
	*/	
	
	yyparse();
	
	return 1;	



}



int main(int argc , char ** argv){
	
	//Lexycal Analyzer
	if(lexycalAnalyzer() <0) {
		fprintf(stderr,"Invalid symbol at line %d\n",LineNumber);
		exit(1);	
	}
	
	//Syntax Analyzer
	if(syntaxAnalyzer() < 0){
		
		fprintf(stderr,"Compilation Error\n");
		exit(1);	

	}
	
	return 1;
}
