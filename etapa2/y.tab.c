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

#line 58 "yacc.y"
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
#line 40 "y.tab.c"

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
#define bloco 280
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    1,    1,    1,    1,    1,    1,    1,
   10,   10,   10,   10,   10,   11,   11,   11,   12,   12,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   12,   12,   12,    9,    9,    2,    2,   15,   15,    3,
    3,    4,    4,    4,    5,   16,   16,   16,   16,   16,
   17,   17,   17,   17,   17,   17,   17,    7,   18,   18,
   18,    8,    6,    6,    6,    6,    6,   13,   14,
};
static const short yylen[] = {                            2,
    2,    0,    1,    1,    1,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    5,    6,    0,    2,    6,
    8,    4,    5,    7,    8,    0,    2,    3,    4,    5,
    0,    1,    1,    1,    1,    1,    1,    3,    0,    1,
    3,    3,    1,    3,    3,    2,    2,    6,    4,
};
static const short yydefred[] = {                         0,
   16,   17,   18,    0,    0,    0,   11,   12,   13,   14,
   15,    0,    0,    0,    0,    0,    0,    0,    3,    4,
    5,    6,    0,    8,    9,   10,   63,    0,   34,   35,
    0,    0,    0,    0,    0,    0,    0,   67,   66,    0,
    0,    1,   19,   20,   21,   22,   23,   24,    7,   25,
   26,   27,   28,   29,   30,   31,   32,   33,    0,    0,
    0,    0,   58,    0,    0,   62,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   64,   61,    0,   42,
    0,   69,    0,    0,    0,    0,    0,    0,    0,   43,
   36,    0,    0,    0,    0,    0,   68,    0,   40,    0,
    0,    0,    0,   37,   44,    0,    0,   49,    0,   53,
   54,    0,   55,   56,   57,    0,    0,   39,   41,   50,
    0,   45,
};
static const short yydgoto[] = {                         17,
   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,
   85,   59,   29,   30,  107,   86,  117,   35,
};
static const short yysindex[] = {                       -36,
    0,    0,    0,  -25, -261,   -7,    0,    0,    0,    0,
    0,  -54, -251, -240, -239,   -7,    0,  -36,    0,    0,
    0,    0,  -13,    0,    0,    0,    0,  -35,    0,    0,
   -7,  -15,   -7,   12,  -11,   -7, -264,    0,    0,  -10,
   20,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   -7,    2,
 -226,   43,    0,   54,   -7,    0,   77,    5, -264, -214,
   85, -264, -202, -189,   17, -184,    0,    0,   22,    0,
   19,    0,   30,    7,  -33,   57, -264, -178, -264,    0,
    0,  -37,   63, -170,  -12,   58,    0,   66,    0, -264,
 -189,   69,  -36,    0,    0, -264,   67,    0, -189,    0,
    0,   85,    0,    0,    0,  -31,    4,    0,    0,    0,
   75,    0,
};
static const short yyrindex[] = {                       136,
    0,    0,    0,    0,    0,   79,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  136,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   81,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   79,    0,    0,    0,    0,  -19,
   50,    0,    0,  100,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  101,    0,    0,    0,    0,    0,    0,   89,
  100,  108,   25,    0,    0,   89,    0,    0,  100,    0,
    0,   26,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const short yygindex[] = {                       134,
    0,   51,    0,   52,    0,  128,   53,   55,   59,   94,
   18,    0,    0,    0,   47,  -93,    0,   92,
};
#define YYTABLESIZE 357
static const short yytable[] = {                         15,
   61,   14,   94,   16,   61,   13,   37,  108,    7,    8,
    9,   10,   11,   64,   31,  120,   32,   28,   64,   56,
  100,   99,   64,   64,   57,   64,   38,   64,   52,   50,
   14,   51,   33,   58,   13,   28,   36,   39,   40,   64,
   64,   74,   64,   63,   56,   49,   54,   66,   55,   57,
   69,   75,   56,   52,   50,   65,   51,   57,   58,   72,
   70,   52,   50,   80,   51,   82,   58,    1,    2,    3,
   84,   54,   64,   55,   87,   56,   88,   90,   53,   54,
   57,   55,   89,   76,   52,   50,   56,   51,   91,   58,
   65,   57,   73,   65,   77,   52,   50,   95,   51,   92,
   58,   97,   54,   53,   55,   64,  101,  102,   65,   56,
  103,   53,  109,   54,   57,   55,  104,   56,   52,   50,
  116,   51,   57,   58,  105,  119,   52,   50,  122,   51,
   68,   58,   72,   34,   53,    2,   54,   59,   55,   60,
   46,   47,   65,   41,   54,   53,   55,   38,   48,   51,
   52,   42,  118,  110,  111,  113,   78,  114,   62,    0,
   64,  115,   81,   67,    0,   83,    0,    0,   53,   79,
    0,    0,    0,    0,   65,    0,   53,    0,    0,    0,
   96,    0,   98,    0,    0,    0,   71,    0,    0,    0,
    0,    0,   34,  106,    0,    0,    0,    0,    0,  106,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1,    2,    3,    4,    0,    0,    0,    5,    0,    6,
  112,    0,    0,    0,    0,    0,    7,    8,    9,   10,
   11,   12,   60,    0,   93,    0,  121,   64,   64,   64,
   64,   64,   64,   43,   44,   45,   46,   47,   48,    0,
    0,    0,    0,    0,    0,    7,    8,    9,   10,   11,
    0,    0,    0,    0,    0,    0,    0,    0,   43,   44,
   45,   46,   47,   48,    0,    0,   43,   44,   45,   46,
   47,   48,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   43,
   44,   45,   46,   47,   48,    0,    0,    0,    0,    0,
   43,   44,   45,   46,   47,   48,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   43,   44,   45,   46,   47,   48,    0,
    0,   43,   44,   45,   46,   47,   48,
};
static const short yycheck[] = {                         36,
   36,   38,   36,   40,   36,   42,   61,  101,  273,  274,
  275,  276,  277,   33,   40,  109,  278,    0,   38,   33,
   58,   59,   42,   43,   38,   45,  278,   47,   42,   43,
   38,   45,   40,   47,   42,   18,   91,  278,  278,   59,
   60,   40,   62,   59,   33,   59,   60,   59,   62,   38,
   61,  278,   33,   42,   43,   44,   45,   38,   47,   58,
   41,   42,   43,   59,   45,  280,   47,  257,  258,  259,
  273,   60,   92,   62,   58,   33,  261,   59,   92,   60,
   38,   62,   61,   41,   42,   43,   33,   45,   59,   47,
   41,   38,   91,   44,   41,   42,   43,   41,   45,   93,
   47,  280,   60,   92,   62,  125,   44,  278,   59,   33,
  123,   92,   44,   60,   38,   62,   59,   33,   42,   43,
  103,   45,   38,   47,   59,   59,   42,   43,  125,   45,
   37,   47,   58,    6,   92,    0,   60,   59,   62,   59,
   41,   41,   93,   16,   60,   92,   62,   59,   41,  125,
  125,   18,  106,  103,  103,  103,   65,  103,   31,   -1,
   33,  103,   69,   36,   -1,   72,   -1,   -1,   92,   93,
   -1,   -1,   -1,   -1,  125,   -1,   92,   -1,   -1,   -1,
   87,   -1,   89,   -1,   -1,   -1,   59,   -1,   -1,   -1,
   -1,   -1,   65,  100,   -1,   -1,   -1,   -1,   -1,  106,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,   -1,   -1,   -1,  264,   -1,  266,
  103,   -1,   -1,   -1,   -1,   -1,  273,  274,  275,  276,
  277,  278,  278,   -1,  278,   -1,  278,  267,  268,  269,
  270,  271,  272,  267,  268,  269,  270,  271,  272,   -1,
   -1,   -1,   -1,   -1,   -1,  273,  274,  275,  276,  277,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,  270,  271,  272,   -1,   -1,  267,  268,  269,  270,
  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,
  268,  269,  270,  271,  272,   -1,   -1,   -1,   -1,   -1,
  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,   -1,
   -1,  267,  268,  269,  270,  271,  272,
};
#define YYFINAL 17
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
0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_WORD","KW_BOOL","KW_BYTE","KW_IF","KW_THEN",
"KW_ELSE","KW_LOOP","KW_INPUT","KW_RETURN","KW_OUTPUT","OPERATOR_LE",
"OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE","OPERATOR_AND","OPERATOR_OR",
"LIT_INTEGER","LIT_FALSE","LIT_TRUE","LIT_CHAR","LIT_STRING","TK_IDENTIFIER",
"TOKEN_ERROR","bloco",
};
static const char *yyrule[] = {
"$accept : program",
"program : dec program",
"program :",
"dec : vardec",
"dec : vetordec",
"dec : varassign",
"dec : fundec",
"dec : expressao ';'",
"dec : input",
"dec : output",
"dec : controlefluxo",
"literal : LIT_INTEGER",
"literal : LIT_FALSE",
"literal : LIT_TRUE",
"literal : LIT_CHAR",
"literal : LIT_STRING",
"tipos : KW_WORD",
"tipos : KW_BOOL",
"tipos : KW_BYTE",
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
"controlefluxo : condif",
"controlefluxo : loop",
"vardec : tipos TK_IDENTIFIER ':' literal ';'",
"vardec : tipos '$' TK_IDENTIFIER ':' literal ';'",
"vetorini :",
"vetorini : literal vetorini",
"vetordec : tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ';'",
"vetordec : tipos TK_IDENTIFIER '[' LIT_INTEGER ']' ':' vetorini ';'",
"varassign : TK_IDENTIFIER '=' literal ';'",
"varassign : '$' TK_IDENTIFIER '=' literal ';'",
"varassign : TK_IDENTIFIER '[' expressao ']' '=' literal ';'",
"fundec : tipos TK_IDENTIFIER '(' funparam ')' '{' body '}'",
"funparam :",
"funparam : tipos TK_IDENTIFIER",
"funparam : tipos '$' TK_IDENTIFIER",
"funparam : tipos TK_IDENTIFIER ',' funparam",
"funparam : tipos '$' TK_IDENTIFIER ',' funparam",
"body :",
"body : expressao",
"body : vardec",
"body : varassign",
"body : input",
"body : output",
"body : controlefluxo",
"input : KW_INPUT TK_IDENTIFIER ';'",
"outputexp :",
"outputexp : expressao",
"outputexp : expressao ',' outputexp",
"output : KW_OUTPUT outputexp ';'",
"expressao : literal",
"expressao : '(' expressao ')'",
"expressao : expressao operador expressao",
"expressao : '&' TK_IDENTIFIER",
"expressao : '*' TK_IDENTIFIER",
"condif : KW_IF '(' expressao ')' KW_THEN bloco",
"loop : '(' expressao ')' bloco",

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
#line 192 "yacc.y"

#include <stdio.h>
#include <stdlib.h>



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

#line 411 "y.tab.c"

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
case 7:
#line 81 "yacc.y"
	{fprintf(stdout,"Expressao!\n");}
break;
case 36:
#line 121 "yacc.y"
	{ fprintf(stdout,"Var %s inicializada\n",(char*)yystack.l_mark[-3].node); }
break;
case 37:
#line 122 "yacc.y"
	{ fprintf(stdout,"Var %s inicializada\n",(char*)yystack.l_mark[-3].node); }
break;
case 40:
#line 132 "yacc.y"
	{fprintf(stdout,"Vetor %s declarado sem inicializacao\n",(char*)yystack.l_mark[-4].node); }
break;
case 41:
#line 133 "yacc.y"
	{fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)yystack.l_mark[-6].node); }
break;
case 42:
#line 140 "yacc.y"
	{ fprintf(stdout,"Var %s recebe um valor\n",(char*)yystack.l_mark[-3].node); }
break;
case 43:
#line 141 "yacc.y"
	{ fprintf(stdout,"Var %s recebe uma string\n",(char*)yystack.l_mark[-3].node); }
break;
case 44:
#line 142 "yacc.y"
	{ fprintf(stdout,"Vetor %s recebe uma string\n",(char*)yystack.l_mark[-6].node); }
break;
case 45:
#line 149 "yacc.y"
	{ fprintf(stdout,"funcao:\n > %s \n",(char*)yystack.l_mark[-6].node); }
break;
case 58:
#line 165 "yacc.y"
	{fprintf(stdout,"Lido valor e armazenado em %s\n",(char*) yystack.l_mark[-1].node);}
break;
case 62:
#line 173 "yacc.y"
	{fprintf(stdout,"Valor escrito na saida padrao\n");}
break;
#line 661 "y.tab.c"
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
