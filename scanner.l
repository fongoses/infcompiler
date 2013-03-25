%{
/**********************************************************************
 *Scanner  
 **********************************************************************
 * This scanner represents the lexycal analyzer.
 **********************************************************************
 * Authors:
 * Luiz Gustavo Frozi de Castro e Souza (fongoses@gmail.com)
 * Mario Cesar Gasparoni Junior (mariogasparoni@gmail.com)
 **********************************************************************/



#include "hashtable.h"
#include "tokens.h"
int LineNumber = 1;
int running = 1;


%}
%x COMMENT_LINE

%x COMMENT_MULTIPLE_LINES

%%

word	{ return KW_WORD;}
bool	{ return KW_BOOL;}
byte	{ return KW_BYTE;}
if	{ return KW_IF;}
then	{ return KW_THEN;}
else	{ return KW_ELSE;}
loop	{ return KW_LOOP;}
input	{ return KW_INPUT;}
return	{ return KW_RETURN;}
output	{ return KW_OUTPUT;}

"=="	{ return OPERATOR_EQ;}
"!="	{ return OPERATOR_NE;}
"&&"	{ return OPERATOR_AND;}
"||"	{ return OPERATOR_OR;}

 /* especiais, incluindo alguns operadores */
[,;:()[\]{}\+\-*<>=!&$]+ { return yytext[0];} 
"/"			{ return yytext[0];}


 /* literais e restantes */

false			{ return LIT_FALSE;}
true			{ return LIT_TRUE;}
[a-zA-Z_][a-zA-Z0-9_]*	{ return TK_IDENTIFIER;}
[0-9]+			{ return LIT_INTEGER;}
\'.\'			{ return LIT_CHAR;} /* ok */
\".+\"			{ return LIT_STRING;} /* ok */
"\n"			{ ++LineNumber;return 0;} 

"//"			{ BEGIN(COMMENT_LINE);}
<COMMENT_LINE>. 	{}
<COMMENT_LINE>"\n"	{++LineNumber;BEGIN(INITIAL);}




"/*"	{ BEGIN(COMMENT_MULTIPLE_LINES);} //parses comments in a different lexycal analyzer
<COMMENT_MULTIPLE_LINES>"*/"	{ BEGIN(INITIAL);} //initial starts the main(initial) lexycal analyzer again 
<COMMENT_MULTIPLE_LINES>. 	{}
<COMMENT_MULTIPLE_LINES><<EOF>> {return TOKEN_ERROR;} //?
<COMMENT_MULTIPLE_LINES>"\n"	{++LineNumber;}

"ç"				{return TOKEN_ERROR;}
.				{return TOKEN_ERROR;}//if the token doesnt match any other rule, it is invalid

%%

int getLineNumber(){
	return LineNumber;
}


yywrap(){
	return 1;
	}




