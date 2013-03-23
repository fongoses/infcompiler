%{

#include "hashtable.h"
#include "tokens.h"

int LineNumber = 1;
int running = 1;


%}

%x COMMENT

%%

"/*"	{ BEGIN(COMMENT);} //parses comments in a different lexycal analyzer
if	{ return KW_IF;}
then	{ return KW_THEN;}
[0-9]+	{ hashInsert(yytext,LIT_INTEGER);return LIT_INTEGER;}
"\n"	{ ++LineNumber; }
[-+,*]	{ return yytext[0];} 

<COMMENT>"*/"	{ BEGIN(INITIAL);} //initial starts the main(initial) lexycal analyzer again 
<COMMENT>. 	{}
<COMMENT>"\n"	{++LineNumber;}
%%




yywrap(){
	return 1;
}
