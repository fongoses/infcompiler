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
    extern TAC * reversedTAC;
#line 95 "yacc.y"
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
#line 51 "y.tab.c"

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
    0,    1,    3,    1,    1,    4,    4,    2,    2,    3,
    3,    2,    3,    3,    3,    3,    3,    3,    3,    3,
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
    0,   46,    0,    0,    0,    0,    0,   54,    0,    0,
    0,    0,    0,    0,    0,   18,    0,    0,    0,    0,
   58,    0,   59,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   60,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   64,   71,    0,
    0,    0,    0,    0,   76,   56,    0,   57,    0,    0,
    0,    0,    0,   75,
};
static const short yydgoto[] = {                          1,
   78,   79,   60,   49,   61,   41,   62,   63,  116,    6,
    7,    8,   24,   38,   25,   10,    2,   64,   65,   66,
   67,   81,   68,   69,   26,
};
static const short yysindex[] = {                         0,
    0,  -67,    0,    0,    0,    0,    0,    0,  -36,    0,
   27, -255,   42, -247,  -67,  -12,    0,    0,    0,    0,
    0,    4,  -61,  -11,  -35,    0,   42,    0,  -10,  -67,
    0,    0, -219,   15,    0,    0,    0,  -89,    0,    0,
  -56,   17,    0,    0,  -34,    0,    0,    0,  -33,   24,
   48,   65, -168,  -27,  -27,  -47, -161, -154,    0,   73,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -27,
  -27,    0,  -23, -142,  -27, -139,  -27,    0,  163,  163,
   98,  -27,  -27,   84,   86,    0,   59,   66,  -27,  -27,
    0,    5,    0,   88,  -27,  -27,  -27,  -27,  -27,  -27,
  -27,  -27,  -27,  -27,  -27,  -27,  -27,  136,  163,  -27,
  -27, -110,   -7,  142,  163,   43,    0,  -18,  -18,  -18,
  -18,  252,  252,  -18,  -18,    5,    5,    0,    0,  163,
   92,  163,  163,   -7,    0,    0,  -27,    0,  -27, -108,
  163,  163,   -7,    0,
};
static const short yyrindex[] = {                         0,
    0,  156,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   45,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -26,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -2,    0,    0,    0,    0,    0,  -51,  -40,
  -49,    0,    0,    0,    0,    0,    0,    0,    0,   54,
    0,   10,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -21,    0,
    0,    0,    0,    0,   71,    0,    0,   79,   81,  100,
  102,  108,  114,  116,  121,   21,   34,    0,    0,  -38,
    0,    2,   12,    0,    0,    0,    0,    0,    0,  104,
   93,   14,    0,    0,
};
static const short yygindex[] = {                         0,
    9,  366, -106,    0,  126,    0,    0,    0,    0,    0,
  128,    0,    0,    0,   18,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  141,
};
#define YYTABLESIZE 522
static const short yytable[] = {                         12,
   33,   12,   46,   47,   57,   48,  135,   50,   58,   49,
   74,   16,   77,   83,   76,   16,   90,   75,   47,    9,
   48,   22,   16,  105,  103,   23,  104,  140,  106,   31,
   57,   29,   30,   42,   58,   34,  144,   36,   55,   55,
   55,   55,   55,   82,   55,   27,  105,   36,   35,   47,
   62,  106,   62,   62,   62,   45,   55,   55,   39,   55,
   37,   63,   28,   63,   63,   63,   15,   89,   62,   62,
   38,   62,   39,   40,   61,   48,   61,   61,   61,   63,
   63,   13,   63,  138,   13,   42,  137,   70,   42,   42,
   55,   59,   61,   61,   51,   61,   16,   51,   16,  112,
  105,  103,   62,  104,   71,  106,  113,  105,  103,   72,
  104,   52,  106,   63,   52,   42,   84,   14,  101,   65,
  102,   66,   65,   85,   66,  101,   61,  102,  117,  105,
  103,   86,  104,   53,  106,   91,   53,   65,   93,   66,
   67,  107,   68,   67,  110,   68,  111,  101,   69,  102,
  134,   69,  139,  143,   70,    1,   72,   70,   67,   72,
   68,   73,   74,   43,   73,   44,   69,    3,    4,    5,
   37,   65,   70,   66,   72,    0,    0,  105,  103,   73,
  104,    0,  106,  105,  103,    0,  104,    0,  106,    3,
    4,    5,   67,    0,   68,  101,    0,  102,    0,    0,
   69,  101,    0,  102,  105,  103,   70,  104,   72,  106,
   50,    0,   49,   73,    0,    0,   17,   18,   19,   20,
   21,   47,  101,   48,  102,    0,   51,    0,  131,   52,
   53,   54,   55,   16,  136,    0,   16,   16,   16,   16,
   36,   11,   32,   50,   56,   17,   18,   19,   20,   21,
   73,   16,   51,    0,    0,   52,   53,   54,   55,   55,
    0,    0,    0,   37,   55,   55,   55,   55,   55,   55,
   56,   62,    0,   38,    0,   39,   62,   62,   62,   62,
   62,   62,   63,    0,    0,    0,    0,   63,   63,   63,
   63,   63,   63,  105,  103,   61,  104,    0,  106,    0,
   61,   61,   61,   61,   61,   61,    0,    0,    0,    0,
    0,  101,    0,  102,   17,   18,   19,   20,   21,    0,
    0,    0,    0,    0,    0,   95,   96,   97,   98,   99,
  100,    0,   95,   96,   97,   98,   99,  100,    0,    0,
   65,    0,   66,    0,    0,    0,    0,    0,    0,   65,
   65,   66,   66,    0,   95,   96,   97,   98,   99,  100,
    0,   67,    0,   68,    0,    0,    0,    0,    0,   69,
   67,   67,   68,   68,    0,   70,    0,   72,   69,   69,
    0,    0,   73,    0,   70,   70,   72,   72,    0,    0,
    0,   73,   73,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   95,   96,   97,   98,   99,  100,   95,   96,
   97,   98,   99,  100,    0,    0,    0,    0,    0,    0,
   80,    0,    0,    0,    0,    0,    0,    0,    0,   95,
   96,   97,   98,   99,  100,   87,   88,    0,    0,    0,
   92,    0,   94,    0,    0,    0,    0,  108,  109,    0,
    0,    0,    0,    0,  114,  115,    0,    0,    0,    0,
  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,
  128,  129,  130,    0,    0,  132,  133,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  141,    0,  142,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   95,   96,
   97,   98,
};
static const short yycheck[] = {                         36,
   36,   36,   59,   44,   38,   44,  113,   59,   42,   59,
   38,   38,   40,   61,   42,   42,   40,   45,   59,    2,
   59,   13,  278,   42,   43,  273,   45,  134,   47,   41,
   38,   93,   44,  123,   42,   27,  143,   59,   41,   42,
   43,   44,   45,   91,   47,   58,   42,   58,   59,   41,
   41,   47,   43,   44,   45,   38,   59,   60,  278,   62,
   59,   41,   59,   43,   44,   45,   40,   91,   59,   60,
   59,   62,   59,   59,   41,   59,   43,   44,   45,   59,
   60,   58,   62,   41,   58,   41,   44,   40,   44,  123,
   93,  125,   59,   60,   41,   62,  123,   44,  125,   41,
   42,   43,   93,   45,   40,   47,   41,   42,   43,  278,
   45,   41,   47,   93,   44,  123,  278,   91,   60,   41,
   62,   41,   44,  278,   44,   60,   93,   62,   41,   42,
   43,   59,   45,   41,   47,  278,   44,   59,  278,   59,
   41,   44,   41,   44,   61,   44,   61,   60,   41,   62,
  261,   44,   61,  262,   41,    0,   41,   44,   59,   44,
   59,   41,   59,   38,   44,   38,   59,  257,  258,  259,
   30,   93,   59,   93,   59,   -1,   -1,   42,   43,   59,
   45,   -1,   47,   42,   43,   -1,   45,   -1,   47,  257,
  258,  259,   93,   -1,   93,   60,   -1,   62,   -1,   -1,
   93,   60,   -1,   62,   42,   43,   93,   45,   93,   47,
  262,   -1,  262,   93,   -1,   -1,  273,  274,  275,  276,
  277,  262,   60,  262,   62,   -1,  260,   -1,   93,  263,
  264,  265,  266,  260,   93,   -1,  263,  264,  265,  266,
  262,  278,  278,  278,  278,  273,  274,  275,  276,  277,
  278,  278,  260,   -1,   -1,  263,  264,  265,  266,  262,
   -1,   -1,   -1,  262,  267,  268,  269,  270,  271,  272,
  278,  262,   -1,  262,   -1,  262,  267,  268,  269,  270,
  271,  272,  262,   -1,   -1,   -1,   -1,  267,  268,  269,
  270,  271,  272,   42,   43,  262,   45,   -1,   47,   -1,
  267,  268,  269,  270,  271,  272,   -1,   -1,   -1,   -1,
   -1,   60,   -1,   62,  273,  274,  275,  276,  277,   -1,
   -1,   -1,   -1,   -1,   -1,  267,  268,  269,  270,  271,
  272,   -1,  267,  268,  269,  270,  271,  272,   -1,   -1,
  262,   -1,  262,   -1,   -1,   -1,   -1,   -1,   -1,  271,
  272,  271,  272,   -1,  267,  268,  269,  270,  271,  272,
   -1,  262,   -1,  262,   -1,   -1,   -1,   -1,   -1,  262,
  271,  272,  271,  272,   -1,  262,   -1,  262,  271,  272,
   -1,   -1,  262,   -1,  271,  272,  271,  272,   -1,   -1,
   -1,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  267,  268,  269,  270,  271,  272,  267,  268,
  269,  270,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   55,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,
  268,  269,  270,  271,  272,   70,   71,   -1,   -1,   -1,
   75,   -1,   77,   -1,   -1,   -1,   -1,   82,   83,   -1,
   -1,   -1,   -1,   -1,   89,   90,   -1,   -1,   -1,   -1,
   95,   96,   97,   98,   99,  100,  101,  102,  103,  104,
  105,  106,  107,   -1,   -1,  110,  111,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  137,   -1,  139,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,  270,
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
"expressao : '-' expressao",
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
#line 356 "yacc.y"


int yyerror(char *s){
        fprintf(stderr, "Failed to compilate the code.\n");
    exit(3);

}


#line 457 "y.tab.c"

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
#line 118 "yacc.y"
	{
        yyval.tree = astreeCreate(ASTREE_PROGRAM,yystack.l_mark[0].tree,0,0,0,0);
        TREE = yyval.tree->son[0]; /*armazena arvore em variavel global, ja que algumas declaracoes precisam ser recuperadas durante o percurso da arvore*/
        if(outputFile) astreeCreateCode(yyval.tree,0);
        astreeCheckDeclarations(yyval.tree);
        if (astreeCheckNature(yyval.tree) == DATATYPE_INVALID) error = 1;
        mainTAC = generateCode(yyval.tree);
        /*print_tac(mainTAC);*/
        /*puts("----------");*/
        reversedTAC = tacReverse(mainTAC);
        /*print_tac_reverse(reversedTAC);*/
        generateASM(reversedTAC);
        /*astreePrintTree($$,0);*/
    
    ;}
break;
case 2:
#line 136 "yacc.y"
	{ yyval.tree = 0;}
break;
case 3:
#line 137 "yacc.y"
	{
        /*antes de criar no com declaracao, verifica declaracao*/
        yyval.tree = astreeCreate(ASTREE_GLOBALSEQ,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,0,0,0);
    /*  astreeCheckDeclarations($2); em astreeCreate*/
         }
break;
case 4:
#line 144 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 5:
#line 145 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree; }
break;
case 6:
#line 146 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree; }
break;
case 7:
#line 150 "yacc.y"
	{ yyval.tree = 0;}
break;
case 8:
#line 151 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_LOCALDECSEQ,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,0,0,0);}
break;
case 9:
#line 155 "yacc.y"
	{ yyval.tree =  yystack.l_mark[0].tree;}
break;
case 10:
#line 156 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 11:
#line 157 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 12:
#line 158 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 13:
#line 159 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 14:
#line 160 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 15:
#line 161 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 16:
#line 167 "yacc.y"
	{yyval.tree = 0; }
break;
case 17:
#line 168 "yacc.y"
	{ yyval.tree = 0; }
break;
case 18:
#line 169 "yacc.y"
	{
        yyval.tree = astreeCreate(ASTREE_COMMANDSEQ,yystack.l_mark[-2].tree,yystack.l_mark[-1].tree,0,0,0);
    }
break;
case 19:
#line 175 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_BLOCK,yystack.l_mark[-1].tree,0,0,0,0); }
break;
case 20:
#line 179 "yacc.y"
	{
            /*printf(" Achei integer %d\n",$1);*/
            /*$$ = $1; //valor associado ao literal inteiro lido eh o proprio valor do analisador lexico*/
            /*obs: necessario declarar o type para essa associacao.*/

            /*para gerar arvore:*/
            yyval.tree = astreeCreate(ASTREE_LIT_INT,0,0,0,0,yystack.l_mark[0].node); /*07/05: ptr da tabela de simbolos recebido pelo scanner*/

            }
break;
case 21:
#line 188 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_LIT_FALSE,0,0,0,0,yystack.l_mark[0].node); }
break;
case 22:
#line 189 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_LIT_TRUE,0,0,0,0,yystack.l_mark[0].node); }
break;
case 23:
#line 190 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_LIT_CHAR,0,0,0,0,yystack.l_mark[0].node); }
break;
case 24:
#line 191 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_LIT_STRING,0,0,0,0,yystack.l_mark[0].node);}
break;
case 25:
#line 195 "yacc.y"
	{ yyval.tree = 0; }
break;
case 26:
#line 196 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_LIT_SEQ,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,0,0,0);}
break;
case 27:
#line 200 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_KWWORD,0,0,0,0,0); }
break;
case 28:
#line 201 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_KWBOOL,0,0,0,0,0); }
break;
case 29:
#line 202 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_KWBYTE,0,0,0,0,0); }
break;
case 30:
#line 205 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 31:
#line 206 "yacc.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 32:
#line 213 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)yystack.l_mark[-3].node);
        yyval.tree = astreeCreate(ASTREE_VARDEC,yystack.l_mark[-4].tree,yystack.l_mark[-1].tree,0,0,yystack.l_mark[-3].node);

     }
break;
case 33:
#line 217 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)yystack.l_mark[-3].node);
        yyval.tree = astreeCreate(ASTREE_PTRDEC,yystack.l_mark[-5].tree,yystack.l_mark[-1].tree,0,0,yystack.l_mark[-3].node);
     }
break;
case 34:
#line 224 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)yystack.l_mark[-4].node);

        yyval.tree = astreeCreate(ASTREE_VETORDEC,yystack.l_mark[-5].tree,astreeCreate(ASTREE_LIT_INT,0,0,0,0,yystack.l_mark[-2].node),0,0,yystack.l_mark[-4].node); /*gambiarra autorizada: nao pode ter literal, pois vetordec somente aceita inteiros como tamanho.*/
    }
break;
case 35:
#line 228 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)yystack.l_mark[-6].node);
        yyval.tree = astreeCreate(ASTREE_VETORDEC,yystack.l_mark[-7].tree,astreeCreate(ASTREE_LIT_INT,0,0,0,0,yystack.l_mark[-4].node),yystack.l_mark[-1].tree,0,yystack.l_mark[-6].node); /*gambiarra autorizada.*/
     }
break;
case 36:
#line 238 "yacc.y"
	{
            yyval.tree = astreeCreate(ASTREE_SCALAR_ASS,yystack.l_mark[0].tree,0,0,0,yystack.l_mark[-2].node); /*$1 eh o identificador (na realidade o seu ponteiro para tab de simbolos)*/

            if(DEBUG) fprintf(stdout,"Var %s recebe um valor\n",(char*)yystack.l_mark[-2].node); /*astreePrint()*/
    }
break;
case 37:
#line 243 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)yystack.l_mark[-2].node);

        yyval.tree = astreeCreate(ASTREE_PTR_ASS,yystack.l_mark[0].tree,0,0,0,yystack.l_mark[-2].node); /*ajustar alterar, nao eh SCALAR_ASS*/
     }
break;
case 38:
#line 247 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)yystack.l_mark[-2].node);
        yyval.tree = astreeCreate(ASTREE_DEREF_ASS,yystack.l_mark[0].tree,0,0,0,yystack.l_mark[-2].node);
     }
break;
case 39:
#line 252 "yacc.y"
	{ if(DEBUG) fprintf(stdout,"Vetor %s recebe uma string\n",(char*)yystack.l_mark[-5].node);
    yyval.tree = astreeCreate(ASTREE_VET_ASS,yystack.l_mark[-3].tree,yystack.l_mark[0].tree,0,0,yystack.l_mark[-5].node);
     }
break;
case 40:
#line 260 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_PARAM,yystack.l_mark[-1].tree,0,0,0,yystack.l_mark[0].node);}
break;
case 41:
#line 261 "yacc.y"
	{yyval.tree= astreeCreate(ASTREE_PTRPARAM,yystack.l_mark[-2].tree,0,0,0,yystack.l_mark[0].node);}
break;
case 42:
#line 266 "yacc.y"
	{ yyval.tree=0;}
break;
case 43:
#line 267 "yacc.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 44:
#line 268 "yacc.y"
	{ yyval.tree =  astreeCreate(ASTREE_PARAMSEQ,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 45:
#line 271 "yacc.y"
	{
    if(DEBUG) fprintf(stdout,"funcao %s:\n",(char*)yystack.l_mark[-5].node);
        yyval.tree = astreeCreate(ASTREE_FUNDEC,yystack.l_mark[-6].tree,yystack.l_mark[-3].tree,yystack.l_mark[-1].tree,yystack.l_mark[0].tree,yystack.l_mark[-5].node);
     }
break;
case 46:
#line 280 "yacc.y"
	{
        if(DEBUG) fprintf(stdout,"Lido valor e armazenado em %s\n",(char*) yystack.l_mark[0].node);
        yyval.tree = astreeCreate(ASTREE_INPUT,0,0,0,0,yystack.l_mark[0].node);
    }
break;
case 47:
#line 287 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree;}
break;
case 48:
#line 288 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_OUTPUTSEQ,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);}
break;
case 49:
#line 291 "yacc.y"
	{if(DEBUG) fprintf(stdout,"Valor escrito na saida padrao\n");
            yyval.tree=astreeCreate(ASTREE_OUTPUT,yystack.l_mark[0].tree,0,0,0,0);
    }
break;
case 50:
#line 296 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_RETURN,yystack.l_mark[0].tree,0,0,0,0); }
break;
case 51:
#line 301 "yacc.y"
	{ yyval.tree = 0;}
break;
case 52:
#line 302 "yacc.y"
	{yyval.tree = yystack.l_mark[0].tree;}
break;
case 53:
#line 303 "yacc.y"
	{yyval.tree = astreeCreate(ASTREE_ARGSEQ,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 54:
#line 313 "yacc.y"
	{ yyval.tree = yystack.l_mark[0].tree; }
break;
case 55:
#line 314 "yacc.y"
	{ yyval.tree=astreeCreate(ASTREE_SYMBOL,0,0,0,0,yystack.l_mark[0].node); }
break;
case 56:
#line 315 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_VETCALL,yystack.l_mark[-1].tree,0,0,0,yystack.l_mark[-3].node); }
break;
case 57:
#line 316 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_FUNCALL,yystack.l_mark[-1].tree,0,0,0,yystack.l_mark[-3].node); }
break;
case 58:
#line 317 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_PTRADDR,0,0,0,0,yystack.l_mark[0].node); }
break;
case 59:
#line 318 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_PTRVALUE,0,0,0,0,yystack.l_mark[0].node); }
break;
case 60:
#line 319 "yacc.y"
	{ yyval.tree = astreeCreate(ASTREE_EXPRESSION,yystack.l_mark[-1].tree,0,0,0,0); }
break;
case 61:
#line 320 "yacc.y"
	{ yyval.tree=astreeCreate(ASTREE_MIN,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 62:
#line 321 "yacc.y"
	{ yyval.tree=astreeCreate(ASTREE_UMIN,yystack.l_mark[0].tree,0,0,0,0); }
break;
case 63:
#line 322 "yacc.y"
	{ yyval.tree=astreeCreate(ASTREE_ADD,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 64:
#line 323 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_MUL,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 65:
#line 324 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_LE,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 66:
#line 325 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_GE,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 67:
#line 326 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_EQ,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 68:
#line 327 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_NE,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 69:
#line 328 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_AND,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 70:
#line 329 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_OR,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 71:
#line 330 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_DIV,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 72:
#line 331 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_L,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 73:
#line 332 "yacc.y"
	{  yyval.tree=astreeCreate(ASTREE_G,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0); }
break;
case 74:
#line 339 "yacc.y"
	{
        if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");
        yyval.tree=astreeCreate(ASTREE_IF,yystack.l_mark[-3].tree,yystack.l_mark[0].tree,0,0,0);
    }
break;
case 75:
#line 343 "yacc.y"
	{
        if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");
        yyval.tree=astreeCreate(ASTREE_IF_ELSE,yystack.l_mark[-5].tree,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0);
    }
break;
case 76:
#line 349 "yacc.y"
	{
        if(DEBUG) fprintf(stdout,"Clausula loop avaliada\n");
        yyval.tree=astreeCreate(ASTREE_LOOP,yystack.l_mark[-2].tree,yystack.l_mark[0].tree,0,0,0);
    }
break;
#line 1033 "y.tab.c"
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
