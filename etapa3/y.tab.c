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

/*	#include "hashtable.h" //pega tipo 'node'*/
	#include "astree.h" /*ja inclui hashtable.h*/
	#include <stdio.h>
	#include <stdlib.h>
	
	#define DEBUG 0

	extern int yyin;	
	extern FILE * outputFile;
#line 92 "yacc.y"
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
#line 48 "y.tab.c"

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
    2,    2,    2,   23,   23,   24,
};
static const short yylen[] = {                            2,
    1,    0,    2,    1,    1,    1,    0,    2,    1,    1,
    1,    1,    1,    1,    1,    0,    1,    3,    3,    1,
    1,    1,    1,    1,    0,    2,    1,    1,    1,    1,
    1,    5,    6,    6,    8,    3,    4,    4,    6,    2,
    3,    0,    1,    3,    7,    2,    1,    3,    2,    2,
    0,    1,    3,    1,    1,    4,    4,    2,    2,    4,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    6,    8,    5,
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
    0,    0,    0,    0,    0,    0,   61,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   64,   71,    0,
    0,    0,    0,    0,   76,   56,    0,   57,   60,    0,
    0,    0,    0,    0,   75,
};
static const short yydgoto[] = {                          1,
   77,   78,   60,   49,   61,   41,   62,   63,  115,    6,
    7,    8,   24,   38,   25,   10,    2,   64,   65,   66,
   67,   80,   68,   69,   26,
};
static const short yysindex[] = {                         0,
    0, -221,    0,    0,    0,    0,    0,    0,  -36,    0,
  -32, -254,   64, -248, -221,  -14,    0,    0,    0,    0,
    0,    8,   14,   27,  -35,    0,   64,    0,   -9, -221,
    0,    0, -203,   42,    0,    0,    0,  -71,    0,    0,
   34,   52,    0,    0,  -34,    0,    0,    0,  -33,   59,
   81,   89, -147,  -27,  -27,  -43, -145, -144,    0,   76,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -27,
  -27,    0,  -18, -136,  -37,  -27,    0,  137,  137,  100,
  -27,  -27,   87,   91,    0,   53,   63,  -27,  -27,    0,
    0,  -27,   77,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
  -27,  -27,  -27,  -27,  -27,  -27,  129,  137,  -27,  -27,
 -111,   -7,  257,  137,   33,   85,    0,  -13,  -13,  -13,
  -13,  159,  159,  -13,  -13,  -19,  -19,    0,    0,  137,
   92,  137,  137,   -7,    0,    0,  -27,    0,    0,  -27,
 -107,  137,  137,   -7,    0,
};
static const short yyrindex[] = {                         0,
    0,  161,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   35,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -26,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -2,    0,    0,    0,    0,  -55,  -38,  -52,
    0,    0,    0,    0,    0,    0,    0,    0,   41,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -49,    0,    0,
    0,    0,    0,   45,    0,    0,    0,   43,   97,   99,
  105,  110,  116,  118,  122,   10,   21,    0,    0,    2,
    0,  -45,  -42,    0,    0,    0,    0,    0,    0,    0,
  106,   68,  -39,    0,    0,
};
static const short yygindex[] = {                         0,
    6,  360,  -56,    0,  130,    0,    0,    0,    0,    0,
  132,    0,    0,    0,   25,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  143,
};
#define YYTABLESIZE 529
static const short yytable[] = {                         12,
   33,   12,   92,   50,   57,   47,   49,   15,   58,   36,
   74,   16,   76,   37,   75,   16,   38,   82,   22,   39,
   47,   89,  104,   16,   23,   13,    9,  105,  104,  102,
   57,  103,   34,  105,   58,    3,    4,    5,   55,   55,
   55,   55,   55,   27,   55,   48,   47,   81,   36,   35,
   63,   42,   63,   63,   63,  135,   55,   55,   14,   55,
   48,   62,   45,   62,   62,   62,   28,   31,   63,   63,
   30,   63,   88,  138,   39,   42,  137,  141,   42,   62,
   62,   51,   62,   65,   51,   52,   65,  145,   52,   42,
   55,   59,   46,  111,  104,  102,   16,  103,   16,  105,
   40,   65,   63,  112,  104,  102,   29,  103,   53,  105,
   48,   53,  100,   62,  101,   42,   13,  117,  104,  102,
   70,  103,  100,  105,  101,  139,  104,  102,   71,  103,
   72,  105,   83,   84,   85,   65,  100,   66,  101,   67,
   66,   90,   67,  106,  100,   68,  101,  109,   68,  134,
   69,  110,  140,   69,  144,   66,   70,   67,   72,   70,
    1,   72,   73,   68,   74,   73,    0,   43,   69,   44,
  104,  102,   37,  103,   70,  105,   72,    0,  104,  102,
   73,  103,    0,  105,    0,    3,    4,    5,  100,   66,
  101,   67,    0,    0,    0,    0,  100,   68,  101,    0,
  104,  102,   69,  103,    0,  105,   50,    0,   70,   49,
   72,    0,   36,    0,   73,    0,   37,    0,  100,   38,
  101,  131,   39,   47,    0,    0,   51,    0,    0,   52,
   53,   54,   55,   16,    0,    0,   16,   16,   16,   16,
   91,   11,   32,   50,   56,   17,   18,   19,   20,   21,
   73,   16,   51,    0,    0,   52,   53,   54,   55,   55,
    0,    0,    0,   48,   55,   55,   55,   55,   55,   55,
   56,   63,    0,    0,    0,    0,   63,   63,   63,   63,
   63,   63,   62,    0,    0,    0,    0,   62,   62,   62,
   62,   62,   62,    0,    0,    0,    0,    0,  104,  102,
    0,  103,    0,  105,   65,    0,   17,   18,   19,   20,
   21,    0,    0,   65,   65,    0,  100,    0,  101,   94,
   95,   96,   97,   98,   99,    0,    0,    0,    0,   94,
   95,   96,   97,   98,   99,    0,   17,   18,   19,   20,
   21,    0,    0,   94,   95,   96,   97,   98,   99,  136,
    0,   94,   95,   96,   97,   98,   99,    0,   66,    0,
   67,    0,    0,    0,    0,    0,   68,   66,   66,   67,
   67,   69,    0,    0,    0,   68,   68,   70,    0,   72,
   69,   69,    0,   73,    0,    0,   70,   70,   72,   72,
    0,    0,   73,   73,    0,   94,   95,   96,   97,   98,
   99,    0,    0,   94,   95,   96,   97,   98,   99,    0,
    0,    0,    0,    0,   79,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   94,   95,   96,   97,   86,
   87,    0,    0,    0,    0,   93,    0,    0,    0,    0,
  107,  108,    0,    0,    0,    0,    0,  113,  114,    0,
    0,  116,    0,  118,  119,  120,  121,  122,  123,  124,
  125,  126,  127,  128,  129,  130,    0,    0,  132,  133,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  142,    0,    0,  143,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   94,   95,   96,   97,   98,   99,
};
static const short yycheck[] = {                         36,
   36,   36,   40,   59,   38,   44,   59,   40,   42,   59,
   38,   38,   40,   59,   42,   42,   59,   61,   13,   59,
   59,   40,   42,  278,  273,   58,    2,   47,   42,   43,
   38,   45,   27,   47,   42,  257,  258,  259,   41,   42,
   43,   44,   45,   58,   47,   44,   41,   91,   58,   59,
   41,  123,   43,   44,   45,  112,   59,   60,   91,   62,
   59,   41,   38,   43,   44,   45,   59,   41,   59,   60,
   44,   62,   91,   41,  278,   41,   44,  134,   44,   59,
   60,   41,   62,   41,   44,   41,   44,  144,   44,  123,
   93,  125,   59,   41,   42,   43,  123,   45,  125,   47,
   59,   59,   93,   41,   42,   43,   93,   45,   41,   47,
   59,   44,   60,   93,   62,  123,   58,   41,   42,   43,
   40,   45,   60,   47,   62,   41,   42,   43,   40,   45,
  278,   47,  278,  278,   59,   93,   60,   41,   62,   41,
   44,  278,   44,   44,   60,   41,   62,   61,   44,  261,
   41,   61,   61,   44,  262,   59,   41,   59,   41,   44,
    0,   44,   41,   59,   59,   44,   -1,   38,   59,   38,
   42,   43,   30,   45,   59,   47,   59,   -1,   42,   43,
   59,   45,   -1,   47,   -1,  257,  258,  259,   60,   93,
   62,   93,   -1,   -1,   -1,   -1,   60,   93,   62,   -1,
   42,   43,   93,   45,   -1,   47,  262,   -1,   93,  262,
   93,   -1,  262,   -1,   93,   -1,  262,   -1,   60,  262,
   62,   93,  262,  262,   -1,   -1,  260,   -1,   -1,  263,
  264,  265,  266,  260,   -1,   -1,  263,  264,  265,  266,
  278,  278,  278,  278,  278,  273,  274,  275,  276,  277,
  278,  278,  260,   -1,   -1,  263,  264,  265,  266,  262,
   -1,   -1,   -1,  262,  267,  268,  269,  270,  271,  272,
  278,  262,   -1,   -1,   -1,   -1,  267,  268,  269,  270,
  271,  272,  262,   -1,   -1,   -1,   -1,  267,  268,  269,
  270,  271,  272,   -1,   -1,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,  262,   -1,  273,  274,  275,  276,
  277,   -1,   -1,  271,  272,   -1,   60,   -1,   62,  267,
  268,  269,  270,  271,  272,   -1,   -1,   -1,   -1,  267,
  268,  269,  270,  271,  272,   -1,  273,  274,  275,  276,
  277,   -1,   -1,  267,  268,  269,  270,  271,  272,   93,
   -1,  267,  268,  269,  270,  271,  272,   -1,  262,   -1,
  262,   -1,   -1,   -1,   -1,   -1,  262,  271,  272,  271,
  272,  262,   -1,   -1,   -1,  271,  272,  262,   -1,  262,
  271,  272,   -1,  262,   -1,   -1,  271,  272,  271,  272,
   -1,   -1,  271,  272,   -1,  267,  268,  269,  270,  271,
  272,   -1,   -1,  267,  268,  269,  270,  271,  272,   -1,
   -1,   -1,   -1,   -1,   55,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  267,  268,  269,  270,   70,
   71,   -1,   -1,   -1,   -1,   76,   -1,   -1,   -1,   -1,
   81,   82,   -1,   -1,   -1,   -1,   -1,   88,   89,   -1,
   -1,   92,   -1,   94,   95,   96,   97,   98,   99,  100,
  101,  102,  103,  104,  105,  106,   -1,   -1,  109,  110,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  137,   -1,   -1,  140,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,
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
"expressao : '*' '(' expressao ')'",
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
#line 347 "yacc.y"


int yyerror(char *s){
        fprintf(stderr, "Failed to compilate the code\n");
	exit(3); 
	
}


#line 454 "y.tab.c"

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
#line 115 "yacc.y"
	{ 
		yyval.tree = astreeCreate(ASTREE_PROGRAM,yystack.l_mark[0].tree,0,0,0,0);		
		if(!outputFile) astreePrintTree(yyval.tree,0);
		else astreeCreateCode(yyval.tree,0);
	;}
break;
case 2:
#line 123 "yacc.y"
	{ yyval.tree = 0;}
break;
case 3:
#line 124 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_GLOBALSEQ,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 4:
#line 127 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 5:
#line 128 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree; }
break;
case 6:
#line 129 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree; }
break;
case 7:
#line 133 "yacc.y"
	{ yyval.tree = 0;}
break;
case 8:
#line 134 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_LOCALDECSEQ,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,0,0,0);}
break;
case 9:
#line 138 "yacc.y"
	{ yyval.tree =  yystack.l_mark[0].tree;}
break;
case 10:
#line 139 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 11:
#line 140 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 12:
#line 141 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 13:
#line 142 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 14:
#line 143 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 15:
#line 144 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 16:
#line 150 "yacc.y"
	{yyval.tree = 0; }
break;
case 17:
#line 151 "yacc.y"
	{ yyval.tree = 0; }
break;
case 18:
#line 152 "yacc.y"
	{
 		yyval.tree = astreeCreate(ASTREE_COMMANDSEQ,yystack.l_mark[-2].tree,yystack.l_mark[-1].tree,0,0,0);
	}
break;
case 19:
#line 158 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_BLOCK,yystack.l_mark[-1].tree,0,0,0,0); }
break;
case 20:
#line 162 "yacc.y"
	{
			/*printf(" Achei integer %d\n",$1);*/
			/*$$ = $1; //valor associado ao literal inteiro lido eh o proprio valor do analisador lexico */
			/*obs: necessario declarar o type para essa associacao.*/

			/*para gerar arvore:*/
			yyval.tree = astreeCreate(ASTREE_LIT_INT,0,0,0,0,yystack.l_mark[0].node); /*07/05: ptr da tabela de simbolos recebido pelo scanner*/
	
			}
break;
case 21:
#line 171 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_LIT_FALSE,0,0,0,0,yystack.l_mark[0].node); }
break;
case 22:
#line 172 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_LIT_TRUE,0,0,0,0,yystack.l_mark[0].node); }
break;
case 23:
#line 173 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_LIT_CHAR,0,0,0,0,yystack.l_mark[0].node); }
break;
case 24:
#line 174 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_LIT_STRING,0,0,0,0,yystack.l_mark[0].node);}
break;
case 25:
#line 178 "yacc.y"
	{ yyval.tree = 0; }
break;
case 26:
#line 179 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_LIT_SEQ,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,0,0,0);}
break;
case 27:
#line 183 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_KWWORD,0,0,0,0,0); }
break;
case 28:
#line 184 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_KWBOOL,0,0,0,0,0); }
break;
case 29:
#line 185 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_KWBYTE,0,0,0,0,0); }
break;
case 30:
#line 188 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 31:
#line 189 "yacc.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 32:
#line 196 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)yystack.l_mark[-3].node);
		yyval.tree = astreeCreate(ASTREE_VARDEC,yystack.l_mark[-4].tree,yystack.l_mark[-1].tree,0,0,yystack.l_mark[-3].node);
	
	 }
break;
case 33:
#line 200 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)yystack.l_mark[-3].node);
		yyval.tree = astreeCreate(ASTREE_PTRDEC,yystack.l_mark[-5].tree,yystack.l_mark[-1].tree,0,0,yystack.l_mark[-3].node);
	 }
break;
case 34:
#line 207 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)yystack.l_mark[-4].node); 
	
		yyval.tree = astreeCreate(ASTREE_VETORDEC,yystack.l_mark[-5].tree,astreeCreate(ASTREE_LIT_INT,0,0,0,0,yystack.l_mark[-2].node),0,0,yystack.l_mark[-4].node); /*gambiarra autorizada: nao pode ter literal, pois vetordec somente aceita inteiros como tamanho.*/
	}
break;
case 35:
#line 211 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)yystack.l_mark[-6].node);
		yyval.tree = astreeCreate(ASTREE_VETORDEC,yystack.l_mark[-7].tree,astreeCreate(ASTREE_LIT_INT,0,0,0,0,yystack.l_mark[-4].node),yystack.l_mark[-1].tree,0,yystack.l_mark[-6].node); /*gambiarra autorizada.*/
	 }
break;
case 36:
#line 221 "yacc.y"
	{ 
			yyval.tree = astreeCreate(ASTREE_SCALAR_ASS,yystack.l_mark[0].tree,0,0,0,yystack.l_mark[-2].node); /*$1 eh o identificador (na realidade o seu ponteiro para tab de simbolos)*/
			
			if(DEBUG) fprintf(stdout,"Var %s recebe um valor\n",(char*)yystack.l_mark[-2].node); /*astreePrint() */
	}
break;
case 37:
#line 226 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)yystack.l_mark[-2].node);
	
		yyval.tree = astreeCreate(ASTREE_PTR_ASS,yystack.l_mark[0].tree,0,0,0,yystack.l_mark[-2].node); /*ajustar alterar, nao eh SCALAR_ASS*/
	 }
break;
case 38:
#line 230 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)yystack.l_mark[-2].node);
		yyval.tree = astreeCreate(ASTREE_DEREF_ASS,yystack.l_mark[0].tree,0,0,0,yystack.l_mark[-2].node);
	 }
break;
case 39:
#line 235 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Vetor %s recebe uma string\n",(char*)yystack.l_mark[-5].node);
	yyval.tree = astreeCreate(ASTREE_VET_ASS,yystack.l_mark[-3].tree,yystack.l_mark[0].tree,0,0,yystack.l_mark[-5].node);		
	 }
break;
case 40:
#line 243 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_PARAM,yystack.l_mark[-1].tree,0,0,0,yystack.l_mark[0].node);}
break;
case 41:
#line 244 "yacc.y"
	{yyval.tree= astreeCreate(ASTREE_PTRPARAM,yystack.l_mark[-2].tree,0,0,0,yystack.l_mark[0].node);}
break;
case 42:
#line 249 "yacc.y"
	{ yyval.tree=0;}
break;
case 43:
#line 250 "yacc.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 44:
#line 251 "yacc.y"
	{ yyval.tree =  astreeCreate(ASTREE_PARAMSEQ,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 45:
#line 254 "yacc.y"
	{ 	
	if(DEBUG) fprintf(stdout,"funcao %s:\n",(char*)yystack.l_mark[-5].node);
		yyval.tree = astreeCreate(ASTREE_FUNDEC,yystack.l_mark[-6].tree,yystack.l_mark[-3].tree,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,yystack.l_mark[-5].node);
	 }
break;
case 46:
#line 263 "yacc.y"
	{
		if(DEBUG) fprintf(stdout,"Lido valor e armazenado em %s\n",(char*) yystack.l_mark[0].node);
		yyval.tree = astreeCreate(ASTREE_INPUT,0,0,0,0,yystack.l_mark[0].node);
	}
break;
case 47:
#line 270 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 48:
#line 271 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_OUTPUTSEQ,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);}
break;
case 49:
#line 274 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Valor escrito na saida padrao\n");
			yyval.tree=astreeCreate(ASTREE_OUTPUT,yystack.l_mark[0].tree,0,0,0,0);
	}
break;
case 50:
#line 279 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_RETURN,yystack.l_mark[0].tree,0,0,0,0); }
break;
case 51:
#line 284 "yacc.y"
	{ yyval.tree = 0;}
break;
case 52:
#line 285 "yacc.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 53:
#line 286 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_ARGSEQ,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 54:
#line 295 "yacc.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 55:
#line 296 "yacc.y"
	{ yyval.tree=astreeCreate(ASTREE_SYMBOL,0,0,0,0,yystack.l_mark[0].node);}
break;
case 56:
#line 297 "yacc.y"
	{
		yyval.tree = astreeCreate(ASTREE_VETCALL,yystack.l_mark[-1].tree,0,0,0,yystack.l_mark[-3].node);
	}
break;
case 57:
#line 300 "yacc.y"
	{
		yyval.tree = astreeCreate(ASTREE_FUNCALL,yystack.l_mark[-1].tree,0,0,0,yystack.l_mark[-3].node);
	}
break;
case 58:
#line 303 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_PTRADDR,0,0,0,0,yystack.l_mark[0].node);}
break;
case 59:
#line 304 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_PTRVALUE,0,0,0,0,yystack.l_mark[0].node);}
break;
case 60:
#line 305 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_PTRVALUE,yystack.l_mark[-1].tree,0,0,0,0);}
break;
case 61:
#line 306 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_EXPRESSION,yystack.l_mark[-1].tree,0,0,0,0);}
break;
case 62:
#line 307 "yacc.y"
	{ 
		yyval.tree=astreeCreate(ASTREE_MIN,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);
	}
break;
case 63:
#line 310 "yacc.y"
	{ 
		yyval.tree=astreeCreate(ASTREE_ADD,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);	
	}
break;
case 64:
#line 313 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_MUL,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 65:
#line 314 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_LE,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 66:
#line 315 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_GE,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 67:
#line 316 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_EQ,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 68:
#line 317 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_NE,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 69:
#line 318 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_AND,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 70:
#line 319 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_OR,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 71:
#line 320 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_DIV,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 72:
#line 321 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_L,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 73:
#line 322 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_G,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 74:
#line 330 "yacc.y"
	{ 
		if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");
		yyval.tree=astreeCreate(ASTREE_IF,yystack.l_mark[-3].tree,yystack.l_mark[0].tree,0,0,0);
	}
break;
case 75:
#line 334 "yacc.y"
	{
		if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");
		yyval.tree=astreeCreate(ASTREE_IF_ELSE,yystack.l_mark[-5].tree,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0);
	}
break;
case 76:
#line 340 "yacc.y"
	{
		if(DEBUG) fprintf(stdout,"Clausula loop avaliada\n");
		yyval.tree=astreeCreate(ASTREE_LOOP,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);
	}
break;
#line 1024 "y.tab.c"
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
