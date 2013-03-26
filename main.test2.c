
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
#include "tokens.h"

extern char * yytext;
extern FILE * yyin;
extern int LineNumber;
extern int running;




int main(int argc , char ** argv){
	
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
			case TK_IDENTIFIER: printf("TK_IDENTIFIER at line %d\n",LineNumber);break;
			case LIT_INTEGER: printf("LIT_INTEGER at line %d\n",LineNumber); break;
			case LIT_FALSE: printf("LIT_FALSE at line %d\n",LineNumber); break;
			case LIT_TRUE: printf("LIT_TRUE at line %d\n",LineNumber); break;
			case LIT_CHAR: printf("LIT_CHAR at line %d\n",LineNumber); break;	
			case LIT_STRING: printf("LIT_STRING at line %d\n",LineNumber); break;
			case TOKEN_ERROR: printf("TOKEN_ERROR at line %d\n",LineNumber); break;
			default: printf("Tok: %s at line %d\n", yytext,LineNumber);
		}
	}
	
	return 1;
}
