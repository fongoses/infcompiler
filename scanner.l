%{

#include <stdio.h>
#include "hashtable.c"

#define KW_IF 256
#define KW_WHILE 257
#define INT 258


int LineNumber = 1;
int running = 1;


%}

%x COMMENT

%%

"/*"	{ BEGIN(COMMENT);} //parses comments in a different lexycal analyzer
if	{ return KW_IF;}
while	{ return KW_WHILE;}
[0-9]+	{ hashInsert(yytext,INT);return INT;}
"\n"	{ ++LineNumber; }
[-+,*]	{ return yytext[0];} 

<COMMENT>"*/"	{ BEGIN(INITIAL);} //initial starts the main(initial) lexycal analyzer again 
<COMMENT>. 	{}
<COMMENT>"\n"	{++LineNumber;}
%%


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

			case KW_WHILE: printf("KW_WHILE at line %d\n",LineNumber);	

			case INT: printf("INT at line %d\n",LineNumber);			

			default: printf("No match for this: %c at line %d\n", tok,LineNumber);
		}
	}
	return 1;
}

yywrap(){
	return 1;
}
