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

#line 59 "yacc.y"

/*	#include "hashtable.h" //pega tipo 'node'*/
	#include "astree.h" /*ja inclui hashtable.h*/
	#include <stdio.h>
	#include <stdlib.h>

	extern int yyin;


	#define DEBUG 0	
#line 72 "yacc.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int number; /*obs do professor: em vez do numero, deve haver um ponteiro*/
				/* para a tabela de simbolos*/
	HASH_NODE * node;
	char * text;
	char boolean; /* we are associating our boolean type to C's char type. */
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
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    8,    8,    8,   12,   12,    3,    3,    3,
    3,    3,    3,    3,    4,    4,    5,    1,    1,    1,
    1,    6,    6,   18,   18,   18,   14,   14,    9,    9,
   10,   10,    7,    7,    7,   13,   21,   21,   21,   21,
   21,   11,   15,   22,   22,   22,   22,   16,   17,   23,
   23,   23,   23,   23,   23,   23,   23,   23,   23,   23,
   23,   23,   23,   23,   24,   24,   24,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,   19,   19,
   20,
};
static const short yylen[] = {                            2,
    0,    2,    1,    1,    1,    0,    2,    1,    1,    1,
    1,    1,    1,    1,    0,    3,    3,    1,    1,    1,
    1,    0,    2,    1,    1,    1,    1,    1,    5,    6,
    6,    8,    3,    4,    4,    6,    0,    2,    3,    4,
    5,    7,    2,    1,    1,    3,    3,    2,    2,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    0,    1,    3,    1,    1,    4,
    4,    2,    2,    3,    3,    3,    3,    3,    8,    6,
    5,
};
static const short yydefred[] = {                         0,
   24,   25,   26,    0,    0,    3,    4,    5,    0,    2,
    0,    0,    0,    0,    0,    0,   18,   19,   20,   21,
    0,    0,    0,    0,    0,   29,    0,    0,    0,    0,
    0,   31,    0,    0,    0,    0,    0,    0,   30,    0,
    0,   40,    0,    7,    0,   42,    0,   23,   32,   41,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   14,    8,    9,   10,   11,   12,   13,   27,   28,    0,
    0,   43,    0,    0,    0,    0,   68,    0,    0,    0,
   48,    0,    0,    0,    0,    0,   17,    0,    0,    0,
    0,   73,    0,   72,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   16,    0,    0,    0,    0,    0,
   74,    0,    0,   77,   78,   47,   46,    0,    0,    0,
    0,   81,   70,    0,   71,    0,    0,    0,   36,    0,
   79,
};
static const short yydgoto[] = {                          4,
   77,   80,   59,   60,   61,   41,   62,    5,    6,    7,
    8,   37,   63,   64,   65,   66,   67,   23,   68,   69,
   24,   81,    0,  110,
};
static const short yysindex[] = {                      -155,
    0,    0,    0,    0, -155,    0,    0,    0,  -35,    0,
  -24, -248, -178, -241, -155,    8,    0,    0,    0,    0,
    9,  -18,  -34,   18, -178,    0,   32,   33, -194, -155,
   27,    0, -178, -155,   76, -155,   -5,  -33,    0, -178,
   66,    0, -155,    0,  -36,    0,   69,    0,    0,    0,
   89,   98, -134,  -21,  -27,  -37, -132, -131,   91,   26,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -21,
  -21,    0,  -22, -130,  -21, -126,    0,   94,  109,   88,
    0,  -21,  -21,   93,   95,  -36,    0,   29,   74,  -21,
  -21,    0,   81,    0,  -21,  -21,  -21,  -21,  -27,  -27,
  -20,   94,  -21,  -21,    0, -106,  -36,  -14,   94,   17,
    0,   36,   36,    0,    0,    0,    0,   96,   94,   94,
  -36,    0,    0,  -21,    0, -178, -104,   94,    0,  -36,
    0,
};
static const short yyrindex[] = {                       159,
    0,    0,    0,    0,  159,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  119,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  120,    0,   39,
    0,    0,  104,  119,  123,   39,    0,    0,    0,  104,
    0,    0,  119,    0,   40,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -4,    0,    0,    0,    0,  -55,  -54,  -52,
    0,    0,    0,    0,    0,   40,    0,    0,    0,    0,
   68,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -51,    0,    0,    0,    0,    0,    0,   99,    0,
    0,    1,    6,    0,    0,    0,    0,    0,  -50,  -49,
    0,    0,    0,    0,    0,    0,  107,  101,    0,    0,
    0,
};
static const short yygindex[] = {                       162,
   23,   10,  -95,   82,  132,  130,    0,    0,  -16,    0,
    0,  135,    0,    0,    0,    0,    0,   52,    0,    0,
   19,   11,    0,    0,
};
#define YYTABLESIZE 268
static const short yytable[] = {                         58,
   12,   29,   12,   49,   45,   57,   44,   33,   35,   34,
   76,  122,   75,   36,   74,   15,   76,   91,   75,   36,
   74,   97,   95,   83,   96,  127,   98,   97,   95,   16,
   96,   22,   98,   13,  131,   21,   69,   69,   69,   69,
   69,   76,   69,   76,   76,   76,   75,   31,   75,   75,
   75,    9,   42,   82,   69,   40,    9,  125,   30,   76,
  124,   50,   40,   78,   75,   25,   14,   26,   90,  106,
   97,   95,  118,   96,   27,   98,   34,   97,  123,   88,
   89,   38,   98,   35,   93,   39,   45,   38,   69,   33,
   32,  101,  102,   76,   17,   18,   19,   20,   75,  108,
  109,    1,    2,    3,  112,  113,  114,  115,   65,  116,
  117,   65,  119,  120,  107,   97,   95,   45,   96,   43,
   98,  111,   97,   95,   49,   96,   13,   98,   70,   97,
   95,  100,   96,  128,   98,   97,   95,   71,   96,   66,
   98,   67,   66,   72,   67,   84,   85,   92,  129,   86,
   87,   94,   99,  103,  121,  104,  126,  130,    1,   37,
   38,    6,   22,   39,   15,   80,   10,  105,   46,   48,
   44,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   49,   45,    0,   44,
   33,   35,   34,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   51,    0,    0,   52,   53,   54,   55,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   56,   11,   28,   47,   17,   18,   19,   20,   79,
   73,   17,   18,   19,   20,    0,   73,   69,    0,    0,
    0,    0,   76,    0,    0,    0,    0,   75,
};
static const short yycheck[] = {                         36,
   36,   36,   36,   59,   59,   42,   59,   59,   59,   59,
   38,  107,   40,   30,   42,   40,   38,   40,   40,   36,
   42,   42,   43,   61,   45,  121,   47,   42,   43,  278,
   45,  273,   47,   58,  130,   13,   41,   42,   43,   44,
   45,   41,   47,   43,   44,   45,   41,   25,   43,   44,
   45,    0,   34,   91,   59,   33,    5,   41,   41,   59,
   44,   43,   40,   54,   59,   58,   91,   59,   91,   41,
   42,   43,   93,   45,   93,   47,   44,   42,   93,   70,
   71,   30,   47,  278,   75,   59,  123,   36,   93,   58,
   59,   82,   83,   93,  273,  274,  275,  276,   93,   90,
   91,  257,  258,  259,   95,   96,   97,   98,   41,   99,
  100,   44,  103,  104,   41,   42,   43,  123,   45,   44,
   47,   41,   42,   43,   59,   45,   58,   47,   40,   42,
   43,   44,   45,  124,   47,   42,   43,   40,   45,   41,
   47,   41,   44,  278,   44,  278,  278,  278,  126,   59,
  125,  278,   44,   61,  261,   61,   61,  262,    0,   41,
   41,  123,   59,   41,  125,   59,    5,   86,   37,   40,
   36,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,  262,   -1,  262,
  262,  262,  262,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  260,   -1,   -1,  263,  264,  265,  266,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  278,  278,  278,  278,  273,  274,  275,  276,  277,
  278,  273,  274,  275,  276,   -1,  278,  262,   -1,   -1,
   -1,   -1,  262,   -1,   -1,   -1,   -1,  262,
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
"litseq :",
"litseq : literal litseq",
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
"varassign : '$' TK_IDENTIFIER '=' expressao",
"varassign : '*' TK_IDENTIFIER '=' expressao",
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
"expressao : expressao '/' expressao",
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
#line 306 "yacc.y"


int yyerror(char *s){
        fprintf(stderr, "Failed to compilate the code\n");
	exit(3); 
	
}


#line 407 "y.tab.c"

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
case 8:
#line 110 "yacc.y"
	{ yyval.tree = 0;}
break;
case 9:
#line 111 "yacc.y"
	{ yyval.tree = 0;}
break;
case 10:
#line 112 "yacc.y"
	{ yyval.tree = 0;}
break;
case 11:
#line 113 "yacc.y"
	{ yyval.tree = 0;}
break;
case 12:
#line 114 "yacc.y"
	{ yyval.tree = 0;}
break;
case 13:
#line 115 "yacc.y"
	{ yyval.tree = 0;}
break;
case 14:
#line 116 "yacc.y"
	{ yyval.tree = 0;}
break;
case 15:
#line 122 "yacc.y"
	{ yyval.tree = 0; }
break;
case 16:
#line 123 "yacc.y"
	{
		/*07/05: ok, de acordo com o codigo do professor*/
		astreeCreate(ASTREE_CMDL,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);
		}
break;
case 17:
#line 129 "yacc.y"
	{ yyval.tree = yystack.l_mark[-1].tree; astreePrintTree(yystack.l_mark[-1].tree); }
break;
case 18:
#line 133 "yacc.y"
	{
			/*printf(" Achei integer %d\n",$1);*/
			/*$$ = $1; //valor associado ao literal inteiro lido eh o proprio valor do analisador lexico */
			/*obs: necessario declarar o type para essa associacao.*/

			/*para gerar arvore:*/
			yyval.tree = astreeCreate(ASTREE_LIT_INT,0,0,0,0,(HASH_NODE*)yystack.l_mark[0].number); /*07/05: ptr da tabela de simbolos recebido pelo scanner*/
	
			}
break;
case 19:
#line 143 "yacc.y"
	{ }
break;
case 20:
#line 144 "yacc.y"
	{ }
break;
case 22:
#line 150 "yacc.y"
	{ yyval.tree = 0; }
break;
case 23:
#line 151 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_LIT_SEQ,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,0,0,0);}
break;
case 29:
#line 168 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)yystack.l_mark[-3].node); }
break;
case 30:
#line 169 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)yystack.l_mark[-3].node); }
break;
case 31:
#line 174 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)yystack.l_mark[-4].node); }
break;
case 32:
#line 175 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)yystack.l_mark[-6].node); }
break;
case 33:
#line 183 "yacc.y"
	{ 
			yyval.tree = astreeCreate(ASTREE_SCALAR_ASS,0,0,0,0,yystack.l_mark[-2].node); /*$1 eh o identificador (na realidade o seu ponteiro para tab de simbolos)*/
			
			if(DEBUG) fprintf(stdout,"Var %s recebe um valor\n",(char*)yystack.l_mark[-2].node); /*astreePrint() */
	}
break;
case 34:
#line 188 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)yystack.l_mark[-2].node); }
break;
case 35:
#line 189 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)yystack.l_mark[-2].node); }
break;
case 36:
#line 192 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Vetor %s recebe uma string\n",(char*)yystack.l_mark[-5].node); }
break;
case 42:
#line 205 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"funcao %s:\n",(char*)yystack.l_mark[-5].node); }
break;
case 43:
#line 211 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Lido valor e armazenado em %s\n",(char*) yystack.l_mark[0].node);}
break;
case 48:
#line 221 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Valor escrito na saida padrao\n");}
break;
case 68:
#line 256 "yacc.y"
	{
			 
		/*	$$ = $1; //acao default, nao necessaria */
			/*para a associacao acima '$$', que corresponde a asso*/
			/*ciacao de 'expressao' com literal, eh necessario*/
			/*declarar o tipo 'type' de expressao, que nessa regra*/
			/*eh um 'number'*/

			/*dia 07/05: a insercao deve ocorrer aqui ou em literal ?Literal*/
			yyval.tree = yystack.l_mark[0].tree; /*ok, apenas associa o valor recebido a expressao. No caso, eh o ponteiro da tab de simb	*/
			}
break;
case 69:
#line 267 "yacc.y"
	{ 
				yyval.tree=astreeCreate(ASTREE_SYMBOL,0,0,0,0,yystack.l_mark[0].node); /*scanner necessita retornar ptr para tab de simbolos (ok)*/
			 }
break;
case 75:
#line 276 "yacc.y"
	{ 
					yyval.tree=astreeCreate(ASTREE_ADD,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);
				}
break;
case 76:
#line 279 "yacc.y"
	{ 
					 /*adcionar if DEBUG aqui*/
					/*$$ = $1 + $3; //associado o valor da ex-*/
					/*pressao como o resultado da soma	*/
					/*printf("Soma %d\n",$1+$3);*/

					/*agora, gerando a arvore (anteriormente*/
					/*apenas interpretavamos o codigo)*/
					yyval.tree=astreeCreate(ASTREE_ADD,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);
				
	
				 }
break;
case 77:
#line 291 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_MUL,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 78:
#line 292 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_DIV,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 79:
#line 298 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");}
break;
case 80:
#line 299 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");}
break;
case 81:
#line 302 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Clausula loop avaliada\n");}
break;
#line 793 "y.tab.c"
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
