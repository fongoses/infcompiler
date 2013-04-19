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

#line 52 "yacc.y"

	#include "hashtable.h" /*pega tipo 'node'*/
	#define DEBUG 1	
	#define TESTE_MANUAL 0
#line 59 "yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int number;
	HASH_NODE * node;
	char * text;
	char boolean; /* we are associating our boolean type to C's char type. */
	int tipo;
	int exp;
	int operator;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 41 "y.tab.c"

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
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    1,    1,    5,    5,    6,    6,    6,
    6,    6,    6,    6,   14,   14,   13,   15,   15,   15,
   15,   16,   16,   17,   17,   17,    9,    9,    2,    2,
   16,   16,    3,    3,    7,    7,    8,   21,   21,   21,
   21,   21,    4,   10,   22,   22,   22,   22,   11,   12,
   23,   23,   23,   23,   23,   23,   23,   23,   23,   23,
   23,   23,   23,   23,   23,   24,   24,   24,   24,   24,
   20,   20,   20,   20,   20,   20,   20,   20,   18,   18,
   19,
};
static const short yylen[] = {                            2,
    0,    2,    1,    1,    1,    0,    2,    1,    1,    1,
    1,    1,    1,    1,    0,    3,    3,    1,    1,    1,
    1,    1,    2,    1,    1,    1,    1,    1,    5,    6,
    1,    2,    6,    8,    3,    4,    6,    0,    2,    3,
    4,    5,    7,    2,    1,    1,    3,    3,    2,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    0,    1,    1,    3,    3,
    1,    1,    4,    4,    2,    2,    3,    3,    8,    6,
    5,
};
static const short yydefred[] = {                         0,
   24,   25,   26,    0,    0,    3,    4,    5,    0,    2,
    0,    0,    0,    0,    0,    0,   18,   19,   20,   21,
    0,    0,    0,    0,    0,   29,    0,    0,    0,    0,
    0,   33,    0,    0,    0,    0,    0,    0,   30,    0,
    0,   41,    0,    7,    0,   43,    0,    0,   34,   23,
   42,    0,    0,    0,    0,    0,    0,    0,    0,    8,
    9,   10,   11,   12,   13,   14,    0,   27,   28,    0,
    0,   44,    0,    0,    0,    0,   71,    0,    0,    0,
   49,    0,    0,    0,    0,   17,    0,    0,    0,    0,
    0,   76,   75,   51,   52,   53,   54,   55,   56,   57,
   58,   59,   60,   61,   62,   63,   64,   65,    0,    0,
    0,    0,    0,    0,   16,    0,    0,    0,   68,   67,
    0,   77,    0,   48,   47,    0,    0,    0,   81,   73,
    0,   74,    0,    0,   70,   69,   37,    0,   79,
};
static const short yydgoto[] = {                          4,
    5,    6,    7,    8,   37,   59,   60,   61,   62,   63,
   64,   65,   66,   67,   77,   41,   23,   68,   69,   80,
   24,   81,  109,  121,
};
static const short yysindex[] = {                      -208,
    0,    0,    0,    0, -208,    0,    0,    0,  -35,    0,
  -26, -268, -190, -240, -208,  -22,    0,    0,    0,    0,
  -15,  -40,  -34,   28, -190,    0,    1,   26, -207, -208,
   15,    0, -190, -208,   48, -208,  -30,  -33,    0, -190,
  -55,    0, -208,    0,  -36,    0,   36, -190,    0,    0,
    0,   62,   64, -180,  -21,  -27,  -49, -172,   49,    0,
    0,    0,    0,    0,    0,    0,  -11,    0,    0,  -21,
  -21,    0,  -24,  -21, -169, -168,    0,  134,   69,   19,
    0,  -21,  -21,   61,  -36,    0,   35,   58,  -21,  -42,
   74,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -21,  -27,
  -27,   95,  134,  -21,    0, -138,  -36,  111,    0,    0,
  -16,    0,  134,    0,    0,   65,  134,  -36,    0,    0,
   -3,    0, -190, -137,    0,    0,    0,  -36,    0,
};
static const short yyrindex[] = {                       129,
    0,    0,    0,    0,  129,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   89,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   90,    0,    9,
    0,    0,    0,   89,   94,    9,    0,    0,    0,   80,
    0,    0,   89,    0,   16,    0,    0,   84,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -4,    0,    0,    0,    0,  -54,  -53,  -52,
    0,    0,    0,    0,   16,    0,    0,    0,    0,  -14,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -51,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   31,    0,    0,    0,  -50,    0,    0,    0,
    0,    0,    0,   86,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                       141,
    0,  -10,    0,    0,  112,  -93,    0,    0,    0,    0,
    0,    0,  110,   66,  149,  119,   18,    0,    0,  226,
  -12,  -64,    0,    0,
};
#define YYTABLESIZE 406
static const short yytable[] = {                         58,
   12,   29,   12,   49,   50,   46,   45,   35,   36,   16,
   76,   83,   74,   15,   75,   90,   76,    9,   74,   36,
   75,   42,    9,  129,  132,   36,   66,  131,   72,   66,
   51,   13,   22,   72,  134,   25,   72,   72,   72,   72,
   72,   82,   72,   26,  139,  124,  125,   38,    1,    2,
    3,  106,   27,   38,   72,   72,  107,   72,   33,   32,
  102,  100,  111,  101,   14,  108,   89,  106,   30,   34,
   35,   78,  107,   39,   78,  116,  102,  100,  104,  101,
  105,  108,   17,   18,   19,   20,   45,   72,   72,   78,
  106,   43,   45,   13,  104,  107,  105,   72,  117,  102,
  100,   70,  101,   71,  108,   84,  106,   85,   92,   93,
  103,  107,  110,   86,  122,  102,  100,  104,  101,  105,
  108,  114,  128,   78,  138,  133,  103,  106,    1,   38,
   39,    6,  107,  104,   40,  105,  102,  100,   22,  101,
   15,  108,   32,  106,   80,   10,   46,   44,  107,  103,
  115,    0,  102,  100,  104,  101,  105,  108,   48,    0,
    0,   21,    0,    0,    0,  103,  106,    0,    0,    0,
  104,  107,  105,   31,    0,  102,  100,    0,  101,    0,
  108,   40,    0,    0,    0,    0,  103,  126,   40,   50,
    0,    0,    0,  104,    0,  105,   50,    0,    0,    0,
    0,    0,  103,  130,    0,    0,    0,   50,   46,   45,
   35,   36,    0,    0,    0,    0,    0,   17,   18,   19,
   20,    0,    0,   52,    0,  103,   53,   54,   55,   56,
   17,   18,   19,   20,    0,  119,    0,    0,  120,    0,
    0,   57,   11,   28,   47,   17,   18,   19,   20,   79,
   73,   17,   18,   19,   20,    0,   73,   72,    0,    0,
    0,    0,   72,   72,   72,   72,   72,   72,    0,   17,
   18,   19,   20,    0,  135,    0,    0,    0,    0,  136,
   78,  137,    0,    0,    0,   94,   95,   96,   97,   98,
   99,    0,   78,    0,    0,   87,   88,    0,    0,   91,
    0,   94,   95,   96,   97,   98,   99,  112,  113,    0,
    0,    0,    0,    0,  118,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   94,   95,   96,   97,   98,   99,
    0,    0,    0,    0,  123,    0,    0,    0,    0,  127,
   94,   95,   96,   97,   98,   99,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   94,   95,   96,   97,   98,   99,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   94,   95,   96,
   97,   98,   99,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   94,   95,   96,   97,   98,   99,
};
static const short yycheck[] = {                         36,
   36,   36,   36,   59,   59,   59,   59,   59,   59,  278,
   38,   61,   40,   40,   42,   40,   38,    0,   40,   30,
   42,   34,    5,  117,   41,   36,   41,   44,   33,   44,
   43,   58,  273,   38,  128,   58,   41,   42,   43,   44,
   45,   91,   47,   59,  138,  110,  111,   30,  257,  258,
  259,   33,   93,   36,   59,   60,   38,   62,   58,   59,
   42,   43,   44,   45,   91,   47,   91,   33,   41,   44,
  278,   41,   38,   59,   44,   41,   42,   43,   60,   45,
   62,   47,  273,  274,  275,  276,  123,   92,   93,   59,
   33,   44,  123,   58,   60,   38,   62,  278,   41,   42,
   43,   40,   45,   40,   47,  278,   33,   59,  278,  278,
   92,   38,   44,  125,   41,   42,   43,   60,   45,   62,
   47,   61,  261,   93,  262,   61,   92,   33,    0,   41,
   41,  123,   38,   60,   41,   62,   42,   43,   59,   45,
  125,   47,   59,   33,   59,    5,   37,   36,   38,   92,
   85,   -1,   42,   43,   60,   45,   62,   47,   40,   -1,
   -1,   13,   -1,   -1,   -1,   92,   33,   -1,   -1,   -1,
   60,   38,   62,   25,   -1,   42,   43,   -1,   45,   -1,
   47,   33,   -1,   -1,   -1,   -1,   92,   93,   40,   41,
   -1,   -1,   -1,   60,   -1,   62,   48,   -1,   -1,   -1,
   -1,   -1,   92,   93,   -1,   -1,   -1,  262,  262,  262,
  262,  262,   -1,   -1,   -1,   -1,   -1,  273,  274,  275,
  276,   -1,   -1,  260,   -1,   92,  263,  264,  265,  266,
  273,  274,  275,  276,   -1,  278,   -1,   -1,   90,   -1,
   -1,  278,  278,  278,  278,  273,  274,  275,  276,  277,
  278,  273,  274,  275,  276,   -1,  278,  262,   -1,   -1,
   -1,   -1,  267,  268,  269,  270,  271,  272,   -1,  273,
  274,  275,  276,   -1,  278,   -1,   -1,   -1,   -1,  131,
   55,  133,   -1,   -1,   -1,  267,  268,  269,  270,  271,
  272,   -1,  262,   -1,   -1,   70,   71,   -1,   -1,   74,
   -1,  267,  268,  269,  270,  271,  272,   82,   83,   -1,
   -1,   -1,   -1,   -1,   89,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,
   -1,   -1,   -1,   -1,  109,   -1,   -1,   -1,   -1,  114,
  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,
  270,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  267,  268,  269,  270,  271,  272,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 279
#if YYDEBUG
static const char *yyname[] = {

"end-of-file","SYMBOL_LIT_INTEGER","SYMBOL_LIT_FLOATING","SYMBOL_LIT_TRUE",
"SYMBOL_LIT_FALSE","SYMBOL_LIT_CHAR","SYMBOL_LIT_STRING","SYMBOL_IDENTIFIER",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'!'",0,0,"'$'",0,"'&'",0,"'('",
"')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,"':'","';'","'<'",
"'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",
"'\\\\'","']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",
0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_WORD","KW_BOOL","KW_BYTE","KW_IF","KW_THEN",
"KW_ELSE","KW_LOOP","KW_INPUT","KW_RETURN","KW_OUTPUT","OPERATOR_LE",
"OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE","OPERATOR_AND","OPERATOR_OR",
"LIT_INTEGER","LIT_FALSE","LIT_TRUE","LIT_CHAR","LIT_STRING","TK_IDENTIFIER",
"TOKEN_ERROR",
};
static const char *yyrule[] = {
"$accept : program",
"program :",
"program : dec program",
"dec : vardec",
"dec : vetordec",
"dec : fundec",
"localdecseq :",
"localdecseq : vardec localdecseq",
"comando : varassign",
"comando : vetorassign",
"comando : controlefluxo",
"comando : input",
"comando : output",
"comando : return",
"comando : blococomandos",
"comandosseq :",
"comandosseq : comando ';' comandosseq",
"blococomandos : '{' comandosseq '}'",
"literal : LIT_INTEGER",
"literal : LIT_FALSE",
"literal : LIT_TRUE",
"literal : LIT_CHAR",
"litseq : literal",
"litseq : litseq literal",
"tipos : KW_WORD",
"tipos : KW_BOOL",
"tipos : KW_BYTE",
"controlefluxo : condif",
"controlefluxo : loop",
"vardec : tipos TK_IDENTIFIER ':' literal ';'",
"vardec : tipos '$' TK_IDENTIFIER ':' literal ';'",
"litseq : literal",
"litseq : literal litseq",
"vetordec : tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ';'",
"vetordec : tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ':' litseq ';'",
"varassign : TK_IDENTIFIER '=' expressao",
"varassign : '$' TK_IDENTIFIER '=' expressao",
"vetorassign : TK_IDENTIFIER '[' expressao ']' '=' literal",
"paramseq :",
"paramseq : tipos TK_IDENTIFIER",
"paramseq : tipos '$' TK_IDENTIFIER",
"paramseq : tipos TK_IDENTIFIER ',' paramseq",
"paramseq : tipos '$' TK_IDENTIFIER ',' paramseq",
"fundec : tipos TK_IDENTIFIER '(' paramseq ')' localdecseq blococomandos",
"input : KW_INPUT TK_IDENTIFIER",
"outputexp : expressao",
"outputexp : LIT_STRING",
"outputexp : expressao ',' outputexp",
"outputexp : LIT_STRING ',' outputexp",
"output : KW_OUTPUT outputexp",
"return : KW_RETURN expressao",
"operador : OPERATOR_LE",
"operador : OPERATOR_GE",
"operador : OPERATOR_EQ",
"operador : OPERATOR_NE",
"operador : OPERATOR_AND",
"operador : OPERATOR_OR",
"operador : '+'",
"operador : '-'",
"operador : '*'",
"operador : '\\\\'",
"operador : '<'",
"operador : '>'",
"operador : '!'",
"operador : '&'",
"operador : '/'",
"argseq :",
"argseq : literal",
"argseq : TK_IDENTIFIER",
"argseq : argseq ',' literal",
"argseq : argseq ',' TK_IDENTIFIER",
"expressao : literal",
"expressao : TK_IDENTIFIER",
"expressao : TK_IDENTIFIER '[' expressao ']'",
"expressao : TK_IDENTIFIER '(' argseq ')'",
"expressao : '&' TK_IDENTIFIER",
"expressao : '*' TK_IDENTIFIER",
"expressao : '(' expressao ')'",
"expressao : expressao operador expressao",
"condif : KW_IF '(' expressao ')' KW_THEN comando KW_ELSE comando",
"condif : KW_IF '(' expressao ')' KW_THEN comando",
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
#line 233 "yacc.y"


#include <stdio.h>
#include <stdlib.h>

extern int yyin;

int yyerror(char *s){
	fprintf(stderr, "Failed to compilate the code\n");
	exit(3); 
	
}


int main(){



		initMe();	
		yyparse(); //if something goes wrong, then yyerror will be called and the program dies here.
		
		fprintf(stdout,"Compilation Successfull.\n");
		exit(0); //successfull compilation: exits with 0
	


}

#line 445 "y.tab.c"

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
case 29:
#line 136 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)yystack.l_mark[-3].node); }
break;
case 30:
#line 137 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)yystack.l_mark[-3].node); }
break;
case 33:
#line 147 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)yystack.l_mark[-4].node); }
break;
case 34:
#line 148 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)yystack.l_mark[-6].node); }
break;
case 35:
#line 155 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s recebe um valor\n",(char*)yystack.l_mark[-2].node); }
break;
case 36:
#line 156 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)yystack.l_mark[-2].node); }
break;
case 37:
#line 159 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Vetor %s recebe uma string\n",(char*)yystack.l_mark[-5].node); }
break;
case 43:
#line 173 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"funcao %s:\n",(char*)yystack.l_mark[-5].node); }
break;
case 44:
#line 179 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Lido valor e armazenado em %s\n",(char*) yystack.l_mark[0].node);}
break;
case 49:
#line 189 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Valor escrito na saida padrao\n");}
break;
case 79:
#line 225 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");}
break;
case 80:
#line 226 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");}
break;
case 81:
#line 229 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Clausula loop avaliada\n");}
break;
#line 703 "y.tab.c"
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
