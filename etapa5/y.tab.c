#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20120115

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 79 "yacc.y"

	#include "astree.h" /*ja inclui hashtable.h*/
	#include "tac.h"
	#include <stdio.h>
	#include <stdlib.h>
	
	#define DEBUG 0
	extern char error;
	extern int yyin;	
	extern FILE * outputFile;
	extern ASTREE * TREE ; /*no com a lista de declaracoes globais*/
	extern TAC * mainTAC; /*tac global*/
#line 94 "yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	HASH_NODE * node;
	char * text;
	int boolean; /* we are associating our boolean type to C's int type. */
	int tipo;
	int exp;
	int operator;
	ASTREE * tree;
	HASH_NODE * symbol;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 50 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define KW_WORD 257
#define KW_BOOL 258
#define KW_BYTE 259
#define KW_IF 260
#define KW_THEN 261
#define KW_ELSE 262
#define KW_LOOP 263
#define KW_INPUT 264
#define KW_RETURN 265
#define KW_OUTPUT 266
#define OPERATOR_LE 267
#define OPERATOR_GE 268
#define OPERATOR_EQ 269
#define OPERATOR_NE 270
#define OPERATOR_AND 271
#define OPERATOR_OR 272
#define LIT_INTEGER 273
#define LIT_FALSE 274
#define LIT_TRUE 275
#define LIT_CHAR 276
#define LIT_STRING 277
#define TK_IDENTIFIER 278
#define TOKEN_ERROR 279
#define SYMBOL_LIT_UNDEFINED 0
#define SYMBOL_LIT_INTEGER 1
#define SYMBOL_LIT_FLOATING 2
#define SYMBOL_LIT_TRUE 3
#define SYMBOL_LIT_FALSE 4
#define SYMBOL_LIT_CHAR 5
#define SYMBOL_LIT_STRING 6
#define SYMBOL_IDENTIFIER 7
#define IFX 280
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   17,   17,   16,   16,   16,   14,   14,    3,    3,
    3,    3,    3,    3,    3,    4,    4,    4,    5,    1,
    1,    1,    1,    1,    6,    6,   15,   15,   15,   18,
   18,   11,   11,   10,   10,    7,    7,    7,    8,   25,
   25,   13,   13,   13,   12,   19,   22,   22,   20,   21,
    9,    9,    9,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,   23,   23,   24,
};
static const short yylen[] = {                            2,
    1,    0,    2,    1,    1,    1,    0,    2,    1,    1,
    1,    1,    1,    1,    1,    0,    1,    3,    3,    1,
    1,    1,    1,    1,    0,    2,    1,    1,    1,    1,
    1,    5,    6,    6,    8,    3,    4,    4,    6,    2,
    3,    0,    1,    3,    7,    2,    1,    3,    2,    2,
    0,    1,    3,    1,    1,    4,    4,    2,    2,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    6,    8,    5,
};
static const short yydefred[] = {                         2,
    0,    0,   27,   28,   29,    5,    4,    6,    0,    3,
    0,    0,    0,    0,    0,    0,   20,   21,   22,   23,
   24,    0,    0,    0,    0,   43,    0,   32,    0,    0,
    7,   40,    0,    0,   34,   25,   44,    0,   41,   33,
    0,    0,   45,    8,    0,   35,   26,   17,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   19,    0,
   15,    9,   10,   11,   12,   13,   14,   30,   31,    0,
    0,   46,    0,    0,    0,    0,   54,    0,    0,    0,
    0,    0,    0,    0,   18,    0,    0,    0,    0,   58,
   59,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   60,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   63,   70,    0,    0,    0,
    0,    0,   75,   56,    0,   57,    0,    0,    0,    0,
    0,   74,
};
static const short yydgoto[] = {                          1,
   77,   78,   60,   49,   61,   41,   62,   63,  114,    6,
    7,    8,   24,   38,   25,   10,    2,   64,   65,   66,
   67,   80,   68,   69,   26,
};
static const short yysindex[] = {                         0,
    0, -117,    0,    0,    0,    0,    0,    0,  -36,    0,
  -14, -248, -189, -241, -117,  -24,    0,    0,    0,    0,
    0,   14,   -4,    8,  -35,    0, -189,    0,  -22, -117,
    0,    0, -177,   43,    0,    0,    0,  -60,    0,    0,
  -56,   48,    0,    0,  -34,    0,    0,    0,  -33,   59,
   71,   81, -152,  -27,  -27,  -43, -150, -148,    0,   86,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -27,
  -27,    0,  -23, -128, -120,  -27,    0,  147,  147,  116,
  -27,  -27,  105,  112,    0,   53,   63,  -27,  -27,    0,
    0,   77,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
  -27,  -27,  -27,  -27,  -27,  122,  147,  -27,  -27,  -99,
   -7,  133,  147,   15,    0,  -18,  -18,  -18,  -18,  101,
  101,  -18,  -18,  -19,  -19,    0,    0,  147,  118,  147,
  147,   -7,    0,    0,  -27,    0,  -27,  -85,  147,  147,
   -7,    0,
};
static const short yyrindex[] = {                         0,
    0,  186,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   30,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -26,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -2,    0,    0,    0,    0,  -52,  -40,  -51,
    0,    0,    0,    0,    0,    0,    0,    0,   38,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -49,    0,    0,    0,
    0,    0,   68,    0,    0,   34,   88,   90,   92,   94,
  111,  113,  115,   10,   21,    0,    0,  -38,    0,  -39,
  -37,    0,    0,    0,    0,    0,    0,  129,  127,  -21,
    0,    0,
};
static const short yygindex[] = {                         0,
   20,  351,  -65,    0,  153,    0,    0,    0,    0,    0,
  158,    0,    0,    0,   12,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  170,
};
#define YYTABLESIZE 488
static const short yytable[] = {                         12,
   33,   12,   46,   47,   57,   48,   50,   49,   58,   36,
   74,   16,   76,    9,   75,   16,   89,   82,   47,   37,
   48,   38,  103,  103,  101,   15,  102,  104,  104,   16,
   57,   23,   22,   27,   58,   36,   35,   39,   55,   55,
   55,   55,   55,   13,   55,  133,   34,   81,   31,   45,
   62,   30,   62,   62,   62,  136,   55,   55,  135,   55,
   47,   61,   42,   61,   61,   61,  138,   88,   62,   62,
   42,   62,   28,   42,   64,  142,   14,   64,   51,   61,
   61,   51,   61,   17,   18,   19,   20,   21,   29,   42,
   55,   59,   64,  110,  103,  101,   16,  102,   16,  104,
   39,   40,   62,  111,  103,  101,   48,  102,   52,  104,
   70,   52,   99,   61,  100,   42,   13,  115,  103,  101,
   71,  102,   99,  104,  100,   72,   64,   83,   65,   84,
   66,   65,   67,   66,   68,   67,   99,   68,  100,    3,
    4,    5,  103,  101,   85,  102,   65,  104,   66,   90,
   67,   69,   68,   71,   69,   72,   71,   91,   72,  105,
   99,  132,  100,  103,  101,  108,  102,   53,  104,   69,
   53,   71,  109,   72,  103,  101,  141,  102,  137,  104,
   65,   99,   66,  100,   67,    1,   68,   73,  103,  101,
   43,  102,   99,  104,  100,   44,    3,    4,    5,   37,
    0,    0,    0,   69,    0,   71,   99,   72,  100,   50,
   49,    0,   36,    0,  129,    0,   17,   18,   19,   20,
   21,   47,   37,   48,   38,  134,   51,    0,    0,   52,
   53,   54,   55,   16,    0,    0,   16,   16,   16,   16,
   39,   11,   32,   50,   56,   17,   18,   19,   20,   21,
   73,   16,   51,    0,    0,   52,   53,   54,   55,   55,
    0,    0,    0,    0,   55,   55,   55,   55,   55,   55,
   56,   62,    0,    0,    0,    0,   62,   62,   62,   62,
   62,   62,   61,    0,    0,    0,    0,   61,   61,   61,
   61,   61,   61,    0,    0,   64,    0,    0,    0,    0,
    0,    0,    0,    0,   64,   64,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   93,
   94,   95,   96,   97,   98,    0,    0,    0,    0,   93,
   94,   95,   96,   97,   98,    0,    0,    0,    0,    0,
    0,    0,    0,   93,   94,   95,   96,   97,   98,   65,
    0,   66,    0,   67,    0,   68,    0,    0,   65,   65,
   66,   66,   67,   67,   68,   68,    0,   93,   94,   95,
   96,    0,   69,    0,   71,    0,   72,    0,    0,    0,
    0,   69,   69,   71,   71,   72,   72,    0,   93,   94,
   95,   96,   97,   98,    0,    0,    0,    0,    0,   93,
   94,   95,   96,   97,   98,   79,    0,    0,    0,    0,
    0,    0,    0,   93,   94,   95,   96,   97,   98,    0,
   86,   87,    0,    0,    0,    0,   92,    0,    0,    0,
    0,  106,  107,    0,    0,    0,    0,    0,  112,  113,
    0,    0,    0,  116,  117,  118,  119,  120,  121,  122,
  123,  124,  125,  126,  127,  128,    0,    0,  130,  131,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  139,    0,  140,
};
static const short yycheck[] = {                         36,
   36,   36,   59,   44,   38,   44,   59,   59,   42,   59,
   38,   38,   40,    2,   42,   42,   40,   61,   59,   59,
   59,   59,   42,   42,   43,   40,   45,   47,   47,  278,
   38,  273,   13,   58,   42,   58,   59,   59,   41,   42,
   43,   44,   45,   58,   47,  111,   27,   91,   41,   38,
   41,   44,   43,   44,   45,   41,   59,   60,   44,   62,
   41,   41,  123,   43,   44,   45,  132,   91,   59,   60,
   41,   62,   59,   44,   41,  141,   91,   44,   41,   59,
   60,   44,   62,  273,  274,  275,  276,  277,   93,  123,
   93,  125,   59,   41,   42,   43,  123,   45,  125,   47,
  278,   59,   93,   41,   42,   43,   59,   45,   41,   47,
   40,   44,   60,   93,   62,  123,   58,   41,   42,   43,
   40,   45,   60,   47,   62,  278,   93,  278,   41,  278,
   41,   44,   41,   44,   41,   44,   60,   44,   62,  257,
  258,  259,   42,   43,   59,   45,   59,   47,   59,  278,
   59,   41,   59,   41,   44,   41,   44,  278,   44,   44,
   60,  261,   62,   42,   43,   61,   45,   41,   47,   59,
   44,   59,   61,   59,   42,   43,  262,   45,   61,   47,
   93,   60,   93,   62,   93,    0,   93,   59,   42,   43,
   38,   45,   60,   47,   62,   38,  257,  258,  259,   30,
   -1,   -1,   -1,   93,   -1,   93,   60,   93,   62,  262,
  262,   -1,  262,   -1,   93,   -1,  273,  274,  275,  276,
  277,  262,  262,  262,  262,   93,  260,   -1,   -1,  263,
  264,  265,  266,  260,   -1,   -1,  263,  264,  265,  266,
  262,  278,  278,  278,  278,  273,  274,  275,  276,  277,
  278,  278,  260,   -1,   -1,  263,  264,  265,  266,  262,
   -1,   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,
  278,  262,   -1,   -1,   -1,   -1,  267,  268,  269,  270,
  271,  272,  262,   -1,   -1,   -1,   -1,  267,  268,  269,
  270,  271,  272,   -1,   -1,  262,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  271,  272,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,
  268,  269,  270,  271,  272,   -1,   -1,   -1,   -1,  267,
  268,  269,  270,  271,  272,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,  262,
   -1,  262,   -1,  262,   -1,  262,   -1,   -1,  271,  272,
  271,  272,  271,  272,  271,  272,   -1,  267,  268,  269,
  270,   -1,  262,   -1,  262,   -1,  262,   -1,   -1,   -1,
   -1,  271,  272,  271,  272,  271,  272,   -1,  267,  268,
  269,  270,  271,  272,   -1,   -1,   -1,   -1,   -1,  267,
  268,  269,  270,  271,  272,   55,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,   -1,
   70,   71,   -1,   -1,   -1,   -1,   76,   -1,   -1,   -1,
   -1,   81,   82,   -1,   -1,   -1,   -1,   -1,   88,   89,
   -1,   -1,   -1,   93,   94,   95,   96,   97,   98,   99,
  100,  101,  102,  103,  104,  105,   -1,   -1,  108,  109,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  135,   -1,  137,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#if YYDEBUG
static const char *yyname[] = {

"end-of-file","SYMBOL_LIT_INTEGER","SYMBOL_LIT_FLOATING","SYMBOL_LIT_TRUE",
"SYMBOL_LIT_FALSE","SYMBOL_LIT_CHAR","SYMBOL_LIT_STRING","SYMBOL_IDENTIFIER",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'!'",0,0,"'$'",0,"'&'",0,"'('",
"')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,"':'","';'","'<'",
"'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",
"'\\\\'","']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",
"'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_WORD","KW_BOOL","KW_BYTE","KW_IF",
"KW_THEN","KW_ELSE","KW_LOOP","KW_INPUT","KW_RETURN","KW_OUTPUT","OPERATOR_LE",
"OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE","OPERATOR_AND","OPERATOR_OR",
"LIT_INTEGER","LIT_FALSE","LIT_TRUE","LIT_CHAR","LIT_STRING","TK_IDENTIFIER",
"TOKEN_ERROR","IFX",
};
static const char *yyrule[] = {
"$accept : program",
"program : globalseq",
"globalseq :",
"globalseq : globalseq dec",
"dec : vardec",
"dec : vetordec",
"dec : fundec",
"localdecseq :",
"localdecseq : localdecseq vardec",
"comando : varassign",
"comando : vetorassign",
"comando : controlefluxo",
"comando : input",
"comando : output",
"comando : return",
"comando : blococomandos",
"comandosseq :",
"comandosseq : ';'",
"comandosseq : comandosseq comando ';'",
"blococomandos : '{' comandosseq '}'",
"literal : LIT_INTEGER",
"literal : LIT_FALSE",
"literal : LIT_TRUE",
"literal : LIT_CHAR",
"literal : LIT_STRING",
"litseq :",
"litseq : litseq literal",
"tipos : KW_WORD",
"tipos : KW_BOOL",
"tipos : KW_BYTE",
"controlefluxo : condif",
"controlefluxo : loop",
"vardec : tipos TK_IDENTIFIER ':' literal ';'",
"vardec : tipos '$' TK_IDENTIFIER ':' literal ';'",
"vetordec : tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ';'",
"vetordec : tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ':' litseq ';'",
"varassign : TK_IDENTIFIER '=' expressao",
"varassign : '&' TK_IDENTIFIER '=' expressao",
"varassign : '*' TK_IDENTIFIER '=' expressao",
"vetorassign : TK_IDENTIFIER '[' expressao ']' '=' expressao",
"param : tipos TK_IDENTIFIER",
"param : tipos '$' TK_IDENTIFIER",
"paramseq :",
"paramseq : param",
"paramseq : paramseq ',' param",
"fundec : tipos TK_IDENTIFIER '(' paramseq ')' localdecseq blococomandos",
"input : KW_INPUT TK_IDENTIFIER",
"outputseq : expressao",
"outputseq : outputseq ',' expressao",
"output : KW_OUTPUT outputseq",
"return : KW_RETURN expressao",
"argseq :",
"argseq : expressao",
"argseq : argseq ',' expressao",
"expressao : literal",
"expressao : TK_IDENTIFIER",
"expressao : TK_IDENTIFIER '[' expressao ']'",
"expressao : TK_IDENTIFIER '(' argseq ')'",
"expressao : '&' TK_IDENTIFIER",
"expressao : '*' TK_IDENTIFIER",
"expressao : '(' expressao ')'",
"expressao : expressao '-' expressao",
"expressao : expressao '+' expressao",
"expressao : expressao '*' expressao",
"expressao : expressao OPERATOR_LE expressao",
"expressao : expressao OPERATOR_GE expressao",
"expressao : expressao OPERATOR_EQ expressao",
"expressao : expressao OPERATOR_NE expressao",
"expressao : expressao OPERATOR_AND expressao",
"expressao : expressao OPERATOR_OR expressao",
"expressao : expressao '/' expressao",
"expressao : expressao '<' expressao",
"expressao : expressao '>' expressao",
"condif : KW_IF '(' expressao ')' KW_THEN comando",
"condif : KW_IF '(' expressao ')' KW_THEN comando KW_ELSE comando",
"loop : KW_LOOP '(' expressao ')' comando",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 358 "yacc.y"


int yyerror(char *s){
        fprintf(stderr, "Failed to compilate the code.\n");
	exit(3); 
	
}


#line 447 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 117 "yacc.y"
	{ 
		yyval.tree = astreeCreate(ASTREE_PROGRAM,yystack.l_mark[0].tree,0,0,0,0);
		TREE = yyval.tree->son[0]; /*armazena arvore em variavel global, ja que algumas declaracoes precisam ser recuperadas durante o percurso da arvore		*/
		if(outputFile) astreeCreateCode(yyval.tree,0);
		astreeCheckDeclarations(yyval.tree);
		if (astreeCheckNature(yyval.tree) == DATATYPE_INVALID) error = 1;
		mainTAC = generateCode(yyval.tree);
		print_tac(mainTAC);
      		/*astreePrintTree($$,0);*/
	;}
break;
case 2:
#line 130 "yacc.y"
	{ yyval.tree = 0;}
break;
case 3:
#line 131 "yacc.y"
	{
		/*antes de criar no com declaracao, verifica declaracao*/
		yyval.tree = astreeCreate(ASTREE_GLOBALSEQ,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,0,0,0);		
	/*	astreeCheckDeclarations($2); em astreeCreate*/
		 }
break;
case 4:
#line 138 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 5:
#line 139 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree; }
break;
case 6:
#line 140 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree; }
break;
case 7:
#line 144 "yacc.y"
	{ yyval.tree = 0;}
break;
case 8:
#line 145 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_LOCALDECSEQ,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,0,0,0);}
break;
case 9:
#line 149 "yacc.y"
	{ yyval.tree =  yystack.l_mark[0].tree;}
break;
case 10:
#line 150 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 11:
#line 151 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 12:
#line 152 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 13:
#line 153 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 14:
#line 154 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 15:
#line 155 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 16:
#line 161 "yacc.y"
	{yyval.tree = 0; }
break;
case 17:
#line 162 "yacc.y"
	{ yyval.tree = 0; }
break;
case 18:
#line 163 "yacc.y"
	{
 		yyval.tree = astreeCreate(ASTREE_COMMANDSEQ,yystack.l_mark[-2].tree,yystack.l_mark[-1].tree,0,0,0);
	}
break;
case 19:
#line 169 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_BLOCK,yystack.l_mark[-1].tree,0,0,0,0); }
break;
case 20:
#line 173 "yacc.y"
	{
			/*printf(" Achei integer %d\n",$1);*/
			/*$$ = $1; //valor associado ao literal inteiro lido eh o proprio valor do analisador lexico */
			/*obs: necessario declarar o type para essa associacao.*/

			/*para gerar arvore:*/
			yyval.tree = astreeCreate(ASTREE_LIT_INT,0,0,0,0,yystack.l_mark[0].node); /*07/05: ptr da tabela de simbolos recebido pelo scanner*/
	
			}
break;
case 21:
#line 182 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_LIT_FALSE,0,0,0,0,yystack.l_mark[0].node); }
break;
case 22:
#line 183 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_LIT_TRUE,0,0,0,0,yystack.l_mark[0].node); }
break;
case 23:
#line 184 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_LIT_CHAR,0,0,0,0,yystack.l_mark[0].node); }
break;
case 24:
#line 185 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_LIT_STRING,0,0,0,0,yystack.l_mark[0].node);}
break;
case 25:
#line 189 "yacc.y"
	{ yyval.tree = 0; }
break;
case 26:
#line 190 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_LIT_SEQ,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,0,0,0);}
break;
case 27:
#line 194 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_KWWORD,0,0,0,0,0); }
break;
case 28:
#line 195 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_KWBOOL,0,0,0,0,0); }
break;
case 29:
#line 196 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_KWBYTE,0,0,0,0,0); }
break;
case 30:
#line 199 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 31:
#line 200 "yacc.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 32:
#line 207 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)yystack.l_mark[-3].node);
		yyval.tree = astreeCreate(ASTREE_VARDEC,yystack.l_mark[-4].tree,yystack.l_mark[-1].tree,0,0,yystack.l_mark[-3].node);
	
	 }
break;
case 33:
#line 211 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)yystack.l_mark[-3].node);
		yyval.tree = astreeCreate(ASTREE_PTRDEC,yystack.l_mark[-5].tree,yystack.l_mark[-1].tree,0,0,yystack.l_mark[-3].node);
	 }
break;
case 34:
#line 218 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)yystack.l_mark[-4].node); 
	
		yyval.tree = astreeCreate(ASTREE_VETORDEC,yystack.l_mark[-5].tree,astreeCreate(ASTREE_LIT_INT,0,0,0,0,yystack.l_mark[-2].node),0,0,yystack.l_mark[-4].node); /*gambiarra autorizada: nao pode ter literal, pois vetordec somente aceita inteiros como tamanho.*/
	}
break;
case 35:
#line 222 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)yystack.l_mark[-6].node);
		yyval.tree = astreeCreate(ASTREE_VETORDEC,yystack.l_mark[-7].tree,astreeCreate(ASTREE_LIT_INT,0,0,0,0,yystack.l_mark[-4].node),yystack.l_mark[-1].tree,0,yystack.l_mark[-6].node); /*gambiarra autorizada.*/
	 }
break;
case 36:
#line 232 "yacc.y"
	{ 
			yyval.tree = astreeCreate(ASTREE_SCALAR_ASS,yystack.l_mark[0].tree,0,0,0,yystack.l_mark[-2].node); /*$1 eh o identificador (na realidade o seu ponteiro para tab de simbolos)*/
			
			if(DEBUG) fprintf(stdout,"Var %s recebe um valor\n",(char*)yystack.l_mark[-2].node); /*astreePrint() */
	}
break;
case 37:
#line 237 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)yystack.l_mark[-2].node);
	
		yyval.tree = astreeCreate(ASTREE_PTR_ASS,yystack.l_mark[0].tree,0,0,0,yystack.l_mark[-2].node); /*ajustar alterar, nao eh SCALAR_ASS*/
	 }
break;
case 38:
#line 241 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)yystack.l_mark[-2].node);
		yyval.tree = astreeCreate(ASTREE_DEREF_ASS,yystack.l_mark[0].tree,0,0,0,yystack.l_mark[-2].node);
	 }
break;
case 39:
#line 246 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Vetor %s recebe uma string\n",(char*)yystack.l_mark[-5].node);
	yyval.tree = astreeCreate(ASTREE_VET_ASS,yystack.l_mark[-3].tree,yystack.l_mark[0].tree,0,0,yystack.l_mark[-5].node);		
	 }
break;
case 40:
#line 254 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_PARAM,yystack.l_mark[-1].tree,0,0,0,yystack.l_mark[0].node);}
break;
case 41:
#line 255 "yacc.y"
	{yyval.tree= astreeCreate(ASTREE_PTRPARAM,yystack.l_mark[-2].tree,0,0,0,yystack.l_mark[0].node);}
break;
case 42:
#line 260 "yacc.y"
	{ yyval.tree=0;}
break;
case 43:
#line 261 "yacc.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 44:
#line 262 "yacc.y"
	{ yyval.tree =  astreeCreate(ASTREE_PARAMSEQ,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 45:
#line 265 "yacc.y"
	{ 	
	if(DEBUG) fprintf(stdout,"funcao %s:\n",(char*)yystack.l_mark[-5].node);
		yyval.tree = astreeCreate(ASTREE_FUNDEC,yystack.l_mark[-6].tree,yystack.l_mark[-3].tree,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,yystack.l_mark[-5].node);
	 }
break;
case 46:
#line 274 "yacc.y"
	{
		if(DEBUG) fprintf(stdout,"Lido valor e armazenado em %s\n",(char*) yystack.l_mark[0].node);
		yyval.tree = astreeCreate(ASTREE_INPUT,0,0,0,0,yystack.l_mark[0].node);
	}
break;
case 47:
#line 281 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 48:
#line 282 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_OUTPUTSEQ,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);}
break;
case 49:
#line 285 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Valor escrito na saida padrao\n");
			yyval.tree=astreeCreate(ASTREE_OUTPUT,yystack.l_mark[0].tree,0,0,0,0);
	}
break;
case 50:
#line 290 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_RETURN,yystack.l_mark[0].tree,0,0,0,0); }
break;
case 51:
#line 295 "yacc.y"
	{ yyval.tree = 0;}
break;
case 52:
#line 296 "yacc.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 53:
#line 297 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_ARGSEQ,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 54:
#line 306 "yacc.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 55:
#line 307 "yacc.y"
	{ yyval.tree=astreeCreate(ASTREE_SYMBOL,0,0,0,0,yystack.l_mark[0].node);}
break;
case 56:
#line 308 "yacc.y"
	{
		yyval.tree = astreeCreate(ASTREE_VETCALL,yystack.l_mark[-1].tree,0,0,0,yystack.l_mark[-3].node);
	}
break;
case 57:
#line 311 "yacc.y"
	{
		yyval.tree = astreeCreate(ASTREE_FUNCALL,yystack.l_mark[-1].tree,0,0,0,yystack.l_mark[-3].node);
	}
break;
case 58:
#line 314 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_PTRADDR,0,0,0,0,yystack.l_mark[0].node);}
break;
case 59:
#line 315 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_PTRVALUE,0,0,0,0,yystack.l_mark[0].node);}
break;
case 60:
#line 316 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_EXPRESSION,yystack.l_mark[-1].tree,0,0,0,0);}
break;
case 61:
#line 317 "yacc.y"
	{ 
		yyval.tree=astreeCreate(ASTREE_MIN,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);
	}
break;
case 62:
#line 320 "yacc.y"
	{ 
		yyval.tree=astreeCreate(ASTREE_ADD,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);			
		/*print_tac(generateCode($$));*/
	}
break;
case 63:
#line 324 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_MUL,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 64:
#line 325 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_LE,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 65:
#line 326 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_GE,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 66:
#line 327 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_EQ,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 67:
#line 328 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_NE,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 68:
#line 329 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_AND,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 69:
#line 330 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_OR,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 70:
#line 331 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_DIV,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 71:
#line 332 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_L,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 72:
#line 333 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_G,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 73:
#line 341 "yacc.y"
	{ 
		if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");
		yyval.tree=astreeCreate(ASTREE_IF,yystack.l_mark[-3].tree,yystack.l_mark[0].tree,0,0,0);
	}
break;
case 74:
#line 345 "yacc.y"
	{
		if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");
		yyval.tree=astreeCreate(ASTREE_IF_ELSE,yystack.l_mark[-5].tree,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0);
	}
break;
case 75:
#line 351 "yacc.y"
	{
		if(DEBUG) fprintf(stdout,"Clausula loop avaliada\n");
		yyval.tree=astreeCreate(ASTREE_LOOP,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);
	}
break;
#line 1023 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
