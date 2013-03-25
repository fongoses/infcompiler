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
		switch(tok){
			case KW_IF: printf("KW_IF at line: %d\n",LineNumber);

			case KW_THEN: printf("KW_THEN at line %d\n",LineNumber);	

			case LIT_INTEGER: printf("LIT_INT at line %d\n",LineNumber);			

			default: printf("No match for this: %c at line %d\n", tok,LineNumber);
		}
	}
	return 1;
}
