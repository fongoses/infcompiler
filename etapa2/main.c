
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
#include "hashtable.h" //incluimos aqui tb, pois o y.tab.h nao enxerga o hashtable.h
#include "y.tab.h"

extern FILE * yyin;
extern int LineNumber;
extern int running;
extern int yyparse(void);

#define TESTE_MANUAL 0
#define DEBUGGING 0


int main(int argc , char ** argv){


	if(!TESTE_MANUAL){

		if(argc < 2) {
                	if(DEBUGGING) fprintf(stderr,"Error: No input file\n");
                	exit(3);
       	 	}

        	yyin=fopen(argv[1],"r"); //yyin: global var which stores the file pointer to the current input file of the lexycal analyzer

        	if(yyin <= 0) {
                	if(DEBUGGING)fprintf(stderr,"Error opening the file\n");
                	exit(3);
        	}
		initMe();
		yyparse();
		//yyerror (in yacc.y) handles erros, exiting 3		
	 	if(DEBUGGING)fprintf(stdout,"Compilation Successfull.\n");
		exit(0);

	}else{

		initMe();	
		yyparse(); //if something goes wrong, then yyerror will be called and the program dies here.
		
		if(DEBUGGING)fprintf(stdout,"Compilation Successfull.\n");
		exit(0); //successfull compilation: exits with 0
	}	


}

