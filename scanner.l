%{

#include "hashtable.h"
#include "tokens.h"

int LineNumber = 1;
int running = 1;


%}

%x COMMENT

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

"<="	{ if(hashInsert(yytext,OPERATOR_LE) != (void*)0) return OPERATOR_LE;else return TOKEN_ERROR;}
">="	{ if(hashInsert(yytext,OPERATOR_GE) != (void*)0) return OPERATOR_GE;else return TOKEN_ERROR;}
"=="	{ hashInsert(yytext,OPERATOR_EQ);return OPERATOR_EQ;}
"!="	{ hashInsert(yytext,OPERATOR_NE); return OPERATOR_NE;}
"&&"	{ hashInsert(yytext,OPERATOR_AND);return OPERATOR_AND;}
"||"	{ hashInsert(yytext,OPERATOR_OR); return OPERATOR_OR;}
, | ; | : | ( | ) | [ | ] | { | } | + | - | * | / | < | > | = | ! | & | $ {hashInsert(yytext,yytext[0]); return yytext[0];} /* especiais */

false			{ hashInsert(yytext,LIT_FALSE); return LIT_FALSE;}
true			{ hashInsert(yytext,LIT_TRUE); return LIT_TRUE;}
[a-zA-Z_][a-zA-Z0-9_]*	{ hashInsert(yytext,TK_IDENTIFIER);return TK_IDENTIFIER;}
[0-9]+			{ hashInsert(yytext,LIT_INTEGER);return LIT_INTEGER;}
['].[']			{ hashInsert(yytext,LIT_CHAR); return LIT_CHAR;} /* ? */
["][^"\0]["]	{ hashInsert(yytext,LIT_STRING); return LIT_STRING;}     



"\n"			{ ++LineNumber; } 
"/*"	{ BEGIN(COMMENT);} //parses comments in a different lexycal analyzer
<COMMENT>"*/"	{ BEGIN(INITIAL);} //initial starts the main(initial) lexycal analyzer again 
<COMMENT>. 	{}
<COMMENT>"\n"	{++LineNumber;}

%%




yywrap(){
	return 1;
}
