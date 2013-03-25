
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
	
	int tok = 0;

	if(argc < 2) {
		fprintf(stderr,"Error: No input file\n");
		exit(1);
	}	
	
	yyin=fopen(argv[1],"r"); //yyin: global var which stores the file pointer to the current input file of the lexycal analyzer
	

	if(yyin < 0) {
		fprintf(stderr,"Error opening the file\n");
		exit(1);
	}
        	
	while(!feof(yyin)){			
			
		tok = yylex();
		
		if(feof(yyin)) break;
		
		switch(tok){
			
			switch(tok){
			case 0: break; //\n			
			case KW_WORD : printf("KW_WORD at line: %d, and address: xxx\n",LineNumber);break;
			case KW_BOOL : printf("KW_BOOL at line: %d\n",LineNumber);break;
			case KW_BYTE : printf("KW_BYTE at line: %d\n",LineNumber);break;
			case KW_IF: printf("KW_IF at line: %d\n",LineNumber);break;
			case KW_THEN: printf("KW_THEN at line %d\n",LineNumber);break;
			case TK_IDENTIFIER: printf("TK_IDENTIFIER at line %d\n",LineNumber);break;
			case TOKEN_ERROR: printf("TOKEN_ERROR at line %d\n",LineNumber); break;
			case LIT_CHAR: printf("LIT_CHAR at line %d\n",LineNumber); break;	
			case LIT_STRING: printf("LIT_STRING at line %d\n",LineNumber); break;
			default: printf("Tok: %s at line %d\n", yytext,LineNumber);

		}
	}
	hashPrint();
	return 1;
}
