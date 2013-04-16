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
#include "y.tab.h" //definicoes do analisador sintatico (nao utilizamos mais tokens.h)
int LineNumber = 1;
int running = 1;
//extern union yylval; //store the value of currnet token. this is used by the syntax analyzer //nao necessario: ja presente no y.tab.h gerado

%}
%x COMMENT_LINE

%x COMMENT_MULTIPLE_LINES

%%


word	{ yylval.tipo=KW_WORD; return KW_WORD;}
bool	{ yylval.tipo=KW_BOOL;return KW_BOOL;}
byte	{ yylval.tipo=KW_BYTE;return KW_BYTE;}
if	{ yylval.exp=KW_IF; return KW_IF;}
then	{ yylval.exp=KW_THEN;return KW_THEN;}
else	{ yylval.exp=KW_ELSE;return KW_ELSE;}
loop	{ yylval.exp=KW_LOOP;return KW_LOOP;}
input	{ yylval.exp=KW_INPUT;return KW_INPUT;}
return	{ yylval.exp=KW_RETURN;return KW_RETURN;}
output	{ yylval.exp=KW_OUTPUT;return KW_OUTPUT;}


"<="	{ yylval.number=OPERATOR_LE;return OPERATOR_LE;}
">="	{ yylval.number=OPERATOR_GE;return OPERATOR_GE;}
"=="	{ return OPERATOR_EQ;}
"!="	{ return OPERATOR_NE;}
"&&"	{ return OPERATOR_AND;}
"||"	{ return OPERATOR_OR;}

 /* especiais, incluindo alguns operadores */
[,;:()[\]{}\+\-*<>=!&$] { return yytext[0];} 
"/"			{ return yytext[0];}


 /* literais e restantes, sao inseridos na tab de simbolos */

FALSE			{ hashInsert(yytext,LIT_FALSE); return LIT_FALSE;}
TRUE			{ hashInsert(yytext,LIT_TRUE);return LIT_TRUE;}
[a-zA-Z_][a-zA-Z0-9_]*	{ hashInsert(yytext,TK_IDENTIFIER);yylval.text = yytext;return TK_IDENTIFIER;}
[0-9][a-fA-F0-9]*	{ hashInsert(yytext,LIT_INTEGER);yylval.number = atoi(yytext);return LIT_INTEGER;}
\'.\'			{ hashInsert(yytext,LIT_CHAR);return LIT_CHAR;} /* ok */
\".+\"			{ hashInsert(yytext,LIT_STRING);return LIT_STRING;} /* ok */
"\n"			{ ++LineNumber;} //corrigido 1

"//"			{ BEGIN(COMMENT_LINE);}
<COMMENT_LINE>. 	{}
<COMMENT_LINE>"\n"	{++LineNumber;BEGIN(INITIAL);}




"/*"	{ BEGIN(COMMENT_MULTIPLE_LINES);} //parses comments in a different lexycal analyzer
<COMMENT_MULTIPLE_LINES>"*/"	{ BEGIN(INITIAL);} //initial starts the main(initial) lexycal analyzer again 
<COMMENT_MULTIPLE_LINES>. 	{}
<COMMENT_MULTIPLE_LINES>"\n"	{++LineNumber;}
" "				{} //ignore whitespace? yes. Corrigido 2
"\t"				{}
.				{return TOKEN_ERROR;}//if the token doesnt match any other rule, it is invalid

%%

int getLineNumber(){
	return LineNumber;
}


int yywrap(){
	
	running=0;
	return 1;
}

void initMe(){
	hashInit();	
}


