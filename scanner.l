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

"=="	{ hashInsert(yytext,OPERATOR_EQ);return OPERATOR_EQ;}
"!="	{ hashInsert(yytext,OPERATOR_NE);return OPERATOR_NE;}
"&&"	{ hashInsert(yytext,OPERATOR_AND);return OPERATOR_AND;}
"||"	{ hashInsert(yytext,OPERATOR_OR);return OPERATOR_OR;}

 /* especiais, incluindo alguns operadores */
[,;:()[\]{}\+\-*<>=!&$]+ { hashInsert(yytext,yytext[0]);return yytext[0];} 
"/"			{ hashInsert(yytext,yytext[0]);return yytext[0];}


 /* literais e restantes */

false			{ hashInsert(yytext,LIT_FALSE); return LIT_FALSE;}
true			{ hashInsert(yytext,LIT_TRUE);return LIT_TRUE;}
[a-zA-Z_][a-zA-Z0-9_]*	{ hashInsert(yytext,TK_IDENTIFIER);return TK_IDENTIFIER;}
[0-9][a-fA-F0-9]*	{ hashInsert(yytext,LIT_INTEGER);return LIT_INTEGER;}
\'.\'			{ hashInsert(yytext,LIT_CHAR);return LIT_CHAR;} /* ok */
\".+\"			{ hashInsert(yytext,LIT_STRING);return LIT_STRING;} /* ok */
"\n"			{ ++LineNumber;return 0;}

"//"			{ BEGIN(COMMENT_LINE);}
<COMMENT_LINE>. 	{}
<COMMENT_LINE>"\n"	{++LineNumber;BEGIN(INITIAL);}




"/*"	{ BEGIN(COMMENT_MULTIPLE_LINES);} //parses comments in a different lexycal analyzer
<COMMENT_MULTIPLE_LINES>"*/"	{ BEGIN(INITIAL);} //initial starts the main(initial) lexycal analyzer again 
<COMMENT_MULTIPLE_LINES>. 	{}
<COMMENT_MULTIPLE_LINES><<EOF>> {return TOKEN_ERROR;} //?
<COMMENT_MULTIPLE_LINES>"\n"	{++LineNumber;}
" "				{return 0;} //ignore whitespace?
"ç"				{return TOKEN_ERROR;}
.				{return TOKEN_ERROR;}//if the token doesnt match any other rule, it is invalid

<<EOF>>			{running=0; return running;}
%%

int getLineNumber(){
	return LineNumber;
}


yywrap(){
	return 1;
	}




