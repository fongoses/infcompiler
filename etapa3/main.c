
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
//#include "hashtable.h" //ja incluso no astree.h
#include "astree.h"
#include "y.tab.h"

extern FILE * yyin;
FILE * outputFile;
extern int LineNumber;
extern int running;
extern int yyparse(void);
#define TESTE_MANUAL 0



int main(int argc , char ** argv){



	if(argc < 2) {
		fprintf(stderr,"Error: No input file\n");
		exit(3);
	}

	yyin=fopen(argv[1],"r");
 
	if(yyin <= 0) {
		fprintf(stderr,"Error opening the file\n");
		exit(3);
	}
	
	if(argc==3) {
		outputFile = fopen(argv[2],"w+"); //global var
	}
	
	initMe();
	yyparse();
	//yyerror (in yacc.y) handles erros, exiting 3		
	exit(0);




}

