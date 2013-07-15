/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 78 "yacc.y"


    #include "astree.h" //ja inclui hashtable.h
    #include "tac.h"
    #include <stdio.h>
    #include <stdlib.h>

    #define DEBUG 0
    extern char error;
    extern int yyin;
    extern FILE * outputFile;
    extern ASTREE * TREE ; //no com a lista de declaracoes globais
    extern TAC * mainTAC; //tac global


/* Line 268 of yacc.c  */
#line 87 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SYMBOL_LIT_UNDEFINED = 0,
     KW_WORD = 258,
     KW_BOOL = 259,
     KW_BYTE = 260,
     KW_IF = 261,
     KW_THEN = 262,
     KW_ELSE = 263,
     KW_LOOP = 264,
     KW_INPUT = 265,
     KW_RETURN = 266,
     KW_OUTPUT = 267,
     OPERATOR_LE = 268,
     OPERATOR_GE = 269,
     OPERATOR_EQ = 270,
     OPERATOR_NE = 271,
     OPERATOR_AND = 272,
     OPERATOR_OR = 273,
     LIT_INTEGER = 274,
     LIT_FALSE = 275,
     LIT_TRUE = 276,
     LIT_CHAR = 277,
     LIT_STRING = 278,
     TK_IDENTIFIER = 279,
     TOKEN_ERROR = 280,
     SYMBOL_LIT_INTEGER = 1,
     SYMBOL_LIT_FLOATING = 2,
     SYMBOL_LIT_TRUE = 3,
     SYMBOL_LIT_FALSE = 4,
     SYMBOL_LIT_CHAR = 5,
     SYMBOL_LIT_STRING = 6,
     SYMBOL_IDENTIFIER = 7,
     IFX = 281
   };
#endif
/* Tokens.  */
#define SYMBOL_LIT_UNDEFINED 0
#define KW_WORD 258
#define KW_BOOL 259
#define KW_BYTE 260
#define KW_IF 261
#define KW_THEN 262
#define KW_ELSE 263
#define KW_LOOP 264
#define KW_INPUT 265
#define KW_RETURN 266
#define KW_OUTPUT 267
#define OPERATOR_LE 268
#define OPERATOR_GE 269
#define OPERATOR_EQ 270
#define OPERATOR_NE 271
#define OPERATOR_AND 272
#define OPERATOR_OR 273
#define LIT_INTEGER 274
#define LIT_FALSE 275
#define LIT_TRUE 276
#define LIT_CHAR 277
#define LIT_STRING 278
#define TK_IDENTIFIER 279
#define TOKEN_ERROR 280
#define SYMBOL_LIT_INTEGER 1
#define SYMBOL_LIT_FLOATING 2
#define SYMBOL_LIT_TRUE 3
#define SYMBOL_LIT_FALSE 4
#define SYMBOL_LIT_CHAR 5
#define SYMBOL_LIT_STRING 6
#define SYMBOL_IDENTIFIER 7
#define IFX 281




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 94 "yacc.y"

    HASH_NODE * node;
    char * text;
    int boolean; /* we are associating our boolean type to C's int type. */
    int tipo;
    int exp;
    int operator;
    ASTREE * tree;
    HASH_NODE * symbol;



/* Line 293 of yacc.c  */
#line 204 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 216 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,    26,    27,    28,    29,    30,    31,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,     2,    48,     2,    35,     2,
      53,    54,    41,    39,    52,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    44,
      33,    51,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,    38,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,    36,    46,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    13,    15,    16,
      19,    21,    23,    25,    27,    29,    31,    33,    34,    36,
      40,    44,    46,    48,    50,    52,    54,    55,    58,    60,
      62,    64,    66,    68,    74,    81,    88,    97,   101,   106,
     111,   118,   121,   125,   126,   128,   132,   140,   143,   145,
     149,   152,   155,   156,   158,   162,   164,   166,   171,   176,
     179,   182,   186,   190,   193,   197,   201,   205,   209,   213,
     217,   221,   225,   229,   233,   237,   244,   253
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    57,    -1,    -1,    57,    58,    -1,    67,
      -1,    68,    -1,    73,    -1,    -1,    59,    67,    -1,    69,
      -1,    70,    -1,    66,    -1,    74,    -1,    76,    -1,    77,
      -1,    62,    -1,    -1,    44,    -1,    61,    60,    44,    -1,
      45,    61,    46,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,    -1,    64,    63,    -1,     3,    -1,
       4,    -1,     5,    -1,    80,    -1,    81,    -1,    65,    24,
      47,    63,    44,    -1,    65,    48,    24,    47,    63,    44,
      -1,    65,    24,    49,    19,    50,    44,    -1,    65,    24,
      49,    19,    50,    47,    64,    44,    -1,    24,    51,    79,
      -1,    35,    24,    51,    79,    -1,    41,    24,    51,    79,
      -1,    24,    49,    79,    50,    51,    79,    -1,    65,    24,
      -1,    65,    48,    24,    -1,    -1,    71,    -1,    72,    52,
      71,    -1,    65,    24,    53,    72,    54,    59,    62,    -1,
      10,    24,    -1,    79,    -1,    75,    52,    79,    -1,    12,
      75,    -1,    11,    79,    -1,    -1,    79,    -1,    78,    52,
      79,    -1,    63,    -1,    24,    -1,    24,    49,    79,    50,
      -1,    24,    53,    78,    54,    -1,    35,    24,    -1,    41,
      24,    -1,    53,    79,    54,    -1,    79,    40,    79,    -1,
      40,    79,    -1,    79,    39,    79,    -1,    79,    41,    79,
      -1,    79,    13,    79,    -1,    79,    14,    79,    -1,    79,
      15,    79,    -1,    79,    16,    79,    -1,    79,    17,    79,
      -1,    79,    18,    79,    -1,    79,    42,    79,    -1,    79,
      33,    79,    -1,    79,    34,    79,    -1,     6,    53,    79,
      54,     7,    60,    -1,     6,    53,    79,    54,     7,    60,
       8,    60,    -1,     9,    53,    79,    54,    60,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   130,   131,   138,   139,   140,   144,   145,
     149,   150,   151,   152,   153,   154,   155,   161,   162,   163,
     169,   173,   182,   183,   184,   185,   189,   190,   194,   195,
     196,   199,   200,   207,   211,   218,   222,   232,   237,   241,
     246,   254,   255,   260,   261,   262,   265,   274,   281,   282,
     285,   290,   295,   296,   297,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   333,   337,   343
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "SYMBOL_LIT_UNDEFINED", "error", "$undefined", "KW_WORD", "KW_BOOL",
  "KW_BYTE", "KW_IF", "KW_THEN", "KW_ELSE", "KW_LOOP", "KW_INPUT",
  "KW_RETURN", "KW_OUTPUT", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_NE", "OPERATOR_AND", "OPERATOR_OR", "LIT_INTEGER", "LIT_FALSE",
  "LIT_TRUE", "LIT_CHAR", "LIT_STRING", "TK_IDENTIFIER", "TOKEN_ERROR",
  "SYMBOL_LIT_INTEGER", "SYMBOL_LIT_FLOATING", "SYMBOL_LIT_TRUE",
  "SYMBOL_LIT_FALSE", "SYMBOL_LIT_CHAR", "SYMBOL_LIT_STRING",
  "SYMBOL_IDENTIFIER", "'<'", "'>'", "'&'", "'|'", "'!'", "'\\\\'", "'+'",
  "'-'", "'*'", "'/'", "IFX", "';'", "'{'", "'}'", "':'", "'$'", "'['",
  "']'", "'='", "','", "'('", "')'", "$accept", "program", "globalseq",
  "dec", "localdecseq", "comando", "comandosseq", "blococomandos",
  "literal", "litseq", "tipos", "controlefluxo", "vardec", "vetordec",
  "varassign", "vetorassign", "param", "paramseq", "fundec", "input",
  "outputseq", "output", "return", "argseq", "expressao", "condif", "loop", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,     1,     2,     3,     4,
       5,     6,     7,    60,    62,    38,   124,    33,    92,    43,
      45,    42,    47,   281,    59,   123,   125,    58,    36,    91,
      93,    61,    44,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    61,
      62,    63,    63,    63,    63,    63,    64,    64,    65,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    69,
      70,    71,    71,    72,    72,    72,    73,    74,    75,    75,
      76,    77,    78,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    80,    80,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     3,
       3,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     5,     6,     6,     8,     3,     4,     4,
       6,     2,     3,     0,     1,     3,     7,     2,     1,     3,
       2,     2,     0,     1,     3,     1,     1,     4,     4,     2,
       2,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     6,     8,     5
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,    28,    29,    30,     4,     0,     5,
       6,     7,     0,     0,     0,     0,    43,     0,    21,    22,
      23,    24,    25,     0,     0,     0,    44,     0,     0,    33,
       0,    41,     0,     0,     8,     0,    35,    26,    42,    45,
       0,    34,     0,    17,    46,     0,     9,    36,    27,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,    16,    12,    10,    11,    13,    14,    15,    31,
      32,     0,     0,    47,    56,     0,     0,     0,     0,    55,
      51,    50,    48,     0,     0,     0,     0,    19,     0,     0,
       0,    52,    59,    63,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,    53,    61,    66,
      67,    68,    69,    70,    71,    73,    74,    64,    62,    65,
      72,    49,     0,    38,    39,     0,    77,    57,     0,    58,
       0,    75,    54,    40,     0,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     7,    40,    61,    50,    62,    79,    42,
      25,    63,     9,    10,    64,    65,    26,    27,    11,    66,
      81,    67,    68,   116,    80,    69,    70
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -107
static const yytype_int16 yypact[] =
{
    -107,    17,    72,  -107,  -107,  -107,  -107,  -107,   -15,  -107,
    -107,  -107,   -28,     2,   146,    18,    72,    11,  -107,  -107,
    -107,  -107,  -107,    22,    28,     6,  -107,    39,   146,  -107,
      21,  -107,    59,    72,  -107,    23,  -107,  -107,  -107,  -107,
       8,  -107,   218,    71,  -107,    33,  -107,  -107,  -107,  -107,
     102,    52,    63,    65,    95,   -17,   -17,    43,    96,    99,
    -107,    80,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,   -17,   -17,  -107,   -39,   101,   -17,   108,   -17,  -107,
     184,    81,   184,   -17,   -17,    83,    85,  -107,    46,    56,
     -17,   -17,  -107,   -10,  -107,    88,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   142,
     184,   -17,   -17,   137,   129,   172,    55,   184,  -107,   194,
     194,   194,   194,   216,   216,   194,   194,   -10,   -10,  -107,
    -107,   184,    98,   184,   184,   129,  -107,  -107,   -17,  -107,
     -17,   138,   184,   184,   129,  -107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -107,  -107,  -107,  -107,  -107,  -106,  -107,   110,   103,  -107,
      -1,  -107,   111,  -107,  -107,  -107,   119,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,   -56,  -107,  -107
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      82,     8,    18,    19,    20,    21,    22,    74,   136,    12,
      90,     4,     5,     6,    91,    88,    89,     3,    75,    14,
      93,    15,    95,    76,    77,    16,    17,   109,   110,   141,
      31,   106,   107,    13,   115,   117,    78,    24,   145,    45,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    43,    32,   133,   134,    51,    28,    96,
      97,    98,    99,   100,   101,    36,    29,    41,    37,    96,
      97,    98,    99,   100,   101,     4,     5,     6,    30,   102,
     103,    13,   142,    38,   143,   104,   105,   106,   107,   102,
     103,    33,    83,    34,    84,   104,   105,   106,   107,    14,
     113,    96,    97,    98,    99,   100,   101,   138,    52,   139,
     114,    53,    54,    55,    56,    49,    71,    23,    72,    73,
      85,   102,   103,    86,    87,    92,    57,   104,   105,   106,
     107,    35,    94,   108,   111,    52,   112,    58,    53,    54,
      55,    56,   118,    59,   135,    48,   144,    43,    60,   140,
      44,    46,    39,    57,     0,    96,    97,    98,    99,   100,
     101,     0,     0,     0,    58,    18,    19,    20,    21,    22,
      59,     0,     0,     0,    43,   102,   103,     0,     0,     0,
       0,   104,   105,   106,   107,    96,    97,    98,    99,   100,
     101,     0,   132,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,     0,     0,   102,   103,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,     0,     0,   102,   103,     0,
       0,     0,   137,   104,   105,   106,   107,    -1,    -1,    96,
      97,    98,    99,   104,   105,   106,   107,    18,    19,    20,
      21,    22,     0,     0,     0,     0,     0,     0,     0,   102,
     103,     0,     0,     0,     0,   104,   105,   106,   107,     0,
       0,     0,    47
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-107))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-1))

static const yytype_int16 yycheck[] =
{
      56,     2,    19,    20,    21,    22,    23,    24,   114,    24,
      49,     3,     4,     5,    53,    71,    72,     0,    35,    47,
      76,    49,    78,    40,    41,    53,    24,    83,    84,   135,
      24,    41,    42,    48,    90,    91,    53,    19,   144,    40,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    45,    48,   111,   112,    24,    47,    13,
      14,    15,    16,    17,    18,    44,    44,    44,    47,    13,
      14,    15,    16,    17,    18,     3,     4,     5,    50,    33,
      34,    48,   138,    24,   140,    39,    40,    41,    42,    33,
      34,    52,    49,    54,    51,    39,    40,    41,    42,    47,
      54,    13,    14,    15,    16,    17,    18,    52,     6,    54,
      54,     9,    10,    11,    12,    44,    53,    14,    53,    24,
      24,    33,    34,    24,    44,    24,    24,    39,    40,    41,
      42,    28,    24,    52,    51,     6,    51,    35,     9,    10,
      11,    12,    54,    41,     7,    42,     8,    45,    46,    51,
      40,    40,    33,    24,    -1,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    35,    19,    20,    21,    22,    23,
      41,    -1,    -1,    -1,    45,    33,    34,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    13,    14,    15,    16,    17,
      18,    -1,    50,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    -1,    -1,    33,    34,    13,    14,    15,
      16,    39,    40,    41,    42,    -1,    -1,    33,    34,    -1,
      -1,    -1,    50,    39,    40,    41,    42,    33,    34,    13,
      14,    15,    16,    39,    40,    41,    42,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,
      -1,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    57,     0,     3,     4,     5,    58,    65,    67,
      68,    73,    24,    48,    47,    49,    53,    24,    19,    20,
      21,    22,    23,    63,    19,    65,    71,    72,    47,    44,
      50,    24,    48,    52,    54,    63,    44,    47,    24,    71,
      59,    44,    64,    45,    62,    65,    67,    44,    63,    44,
      61,    24,     6,     9,    10,    11,    12,    24,    35,    41,
      46,    60,    62,    66,    69,    70,    74,    76,    77,    80,
      81,    53,    53,    24,    24,    35,    40,    41,    53,    63,
      79,    75,    79,    49,    51,    24,    24,    44,    79,    79,
      49,    53,    24,    79,    24,    79,    13,    14,    15,    16,
      17,    18,    33,    34,    39,    40,    41,    42,    52,    79,
      79,    51,    51,    54,    54,    79,    78,    79,    54,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    50,    79,    79,     7,    60,    50,    52,    54,
      51,    60,    79,    79,     8,    60
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 117 "yacc.y"
    {
        (yyval.tree) = astreeCreate(ASTREE_PROGRAM,(yyvsp[(1) - (1)].tree),0,0,0,0);
        TREE = (yyval.tree)->son[0]; //armazena arvore em variavel global, ja que algumas declaracoes precisam ser recuperadas durante o percurso da arvore
        if(outputFile) astreeCreateCode((yyval.tree),0);
        astreeCheckDeclarations((yyval.tree));
        if (astreeCheckNature((yyval.tree)) == DATATYPE_INVALID) error = 1;
        mainTAC = generateCode((yyval.tree));
        print_tac(mainTAC);
            //astreePrintTree($$,0);
    ;}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 130 "yacc.y"
    { (yyval.tree) = 0;}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 131 "yacc.y"
    {
        //antes de criar no com declaracao, verifica declaracao
        (yyval.tree) = astreeCreate(ASTREE_GLOBALSEQ,(yyvsp[(1) - (2)].tree),(yyvsp[(2) - (2)].tree),0,0,0);
    //  astreeCheckDeclarations($2); em astreeCreate
         }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 138 "yacc.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 139 "yacc.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 140 "yacc.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 144 "yacc.y"
    { (yyval.tree) = 0;}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 145 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_LOCALDECSEQ,(yyvsp[(1) - (2)].tree),(yyvsp[(2) - (2)].tree),0,0,0);}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 149 "yacc.y"
    { (yyval.tree) =  (yyvsp[(1) - (1)].tree);}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 150 "yacc.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 151 "yacc.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 152 "yacc.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 153 "yacc.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 154 "yacc.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 155 "yacc.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 161 "yacc.y"
    {(yyval.tree) = 0; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 162 "yacc.y"
    { (yyval.tree) = 0; }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 163 "yacc.y"
    {
        (yyval.tree) = astreeCreate(ASTREE_COMMANDSEQ,(yyvsp[(1) - (3)].tree),(yyvsp[(2) - (3)].tree),0,0,0);
    }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 169 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_BLOCK,(yyvsp[(2) - (3)].tree),0,0,0,0); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 173 "yacc.y"
    {
            //printf(" Achei integer %d\n",$1);
            //$$ = $1; //valor associado ao literal inteiro lido eh o proprio valor do analisador lexico
            //obs: necessario declarar o type para essa associacao.

            //para gerar arvore:
            (yyval.tree) = astreeCreate(ASTREE_LIT_INT,0,0,0,0,(yyvsp[(1) - (1)].node)); //07/05: ptr da tabela de simbolos recebido pelo scanner

            }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 182 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_LIT_FALSE,0,0,0,0,(yyvsp[(1) - (1)].node)); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 183 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_LIT_TRUE,0,0,0,0,(yyvsp[(1) - (1)].node)); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 184 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_LIT_CHAR,0,0,0,0,(yyvsp[(1) - (1)].node)); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 185 "yacc.y"
    {(yyval.tree) = astreeCreate(ASTREE_LIT_STRING,0,0,0,0,(yyvsp[(1) - (1)].node));}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 189 "yacc.y"
    { (yyval.tree) = 0; }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 190 "yacc.y"
    {(yyval.tree) = astreeCreate(ASTREE_LIT_SEQ,(yyvsp[(1) - (2)].tree),(yyvsp[(2) - (2)].tree),0,0,0);}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 194 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_KWWORD,0,0,0,0,0); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 195 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_KWBOOL,0,0,0,0,0); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 196 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_KWBYTE,0,0,0,0,0); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 199 "yacc.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 200 "yacc.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 207 "yacc.y"
    { if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)(yyvsp[(2) - (5)].node));
        (yyval.tree) = astreeCreate(ASTREE_VARDEC,(yyvsp[(1) - (5)].tree),(yyvsp[(4) - (5)].tree),0,0,(yyvsp[(2) - (5)].node));

     }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 211 "yacc.y"
    { if(DEBUG) fprintf(stdout,"Var %s inicializada\n",(char*)(yyvsp[(3) - (6)].node));
        (yyval.tree) = astreeCreate(ASTREE_PTRDEC,(yyvsp[(1) - (6)].tree),(yyvsp[(5) - (6)].tree),0,0,(yyvsp[(3) - (6)].node));
     }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 218 "yacc.y"
    {if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)(yyvsp[(2) - (6)].node));

        (yyval.tree) = astreeCreate(ASTREE_VETORDEC,(yyvsp[(1) - (6)].tree),astreeCreate(ASTREE_LIT_INT,0,0,0,0,(yyvsp[(4) - (6)].node)),0,0,(yyvsp[(2) - (6)].node)); //gambiarra autorizada: nao pode ter literal, pois vetordec somente aceita inteiros como tamanho.
    }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 222 "yacc.y"
    {if(DEBUG) fprintf(stdout,"Vetor %s declarado e inicializado\n",(char*)(yyvsp[(2) - (8)].node));
        (yyval.tree) = astreeCreate(ASTREE_VETORDEC,(yyvsp[(1) - (8)].tree),astreeCreate(ASTREE_LIT_INT,0,0,0,0,(yyvsp[(4) - (8)].node)),(yyvsp[(7) - (8)].tree),0,(yyvsp[(2) - (8)].node)); //gambiarra autorizada.
     }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 232 "yacc.y"
    {
            (yyval.tree) = astreeCreate(ASTREE_SCALAR_ASS,(yyvsp[(3) - (3)].tree),0,0,0,(yyvsp[(1) - (3)].node)); //$1 eh o identificador (na realidade o seu ponteiro para tab de simbolos)

            if(DEBUG) fprintf(stdout,"Var %s recebe um valor\n",(char*)(yyvsp[(1) - (3)].node)); //astreePrint()
    }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 237 "yacc.y"
    { if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)(yyvsp[(2) - (4)].node));

        (yyval.tree) = astreeCreate(ASTREE_PTR_ASS,(yyvsp[(4) - (4)].tree),0,0,0,(yyvsp[(2) - (4)].node)); //ajustar alterar, nao eh SCALAR_ASS
     }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 241 "yacc.y"
    { if(DEBUG) fprintf(stdout,"Var %s recebe uma string\n",(char*)(yyvsp[(2) - (4)].node));
        (yyval.tree) = astreeCreate(ASTREE_DEREF_ASS,(yyvsp[(4) - (4)].tree),0,0,0,(yyvsp[(2) - (4)].node));
     }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 246 "yacc.y"
    { if(DEBUG) fprintf(stdout,"Vetor %s recebe uma string\n",(char*)(yyvsp[(1) - (6)].node));
    (yyval.tree) = astreeCreate(ASTREE_VET_ASS,(yyvsp[(3) - (6)].tree),(yyvsp[(6) - (6)].tree),0,0,(yyvsp[(1) - (6)].node));
     }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 254 "yacc.y"
    {(yyval.tree) = astreeCreate(ASTREE_PARAM,(yyvsp[(1) - (2)].tree),0,0,0,(yyvsp[(2) - (2)].node));}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 255 "yacc.y"
    {(yyval.tree)= astreeCreate(ASTREE_PTRPARAM,(yyvsp[(1) - (3)].tree),0,0,0,(yyvsp[(3) - (3)].node));}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 260 "yacc.y"
    { (yyval.tree)=0;}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 261 "yacc.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 262 "yacc.y"
    { (yyval.tree) =  astreeCreate(ASTREE_PARAMSEQ,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 265 "yacc.y"
    {
    if(DEBUG) fprintf(stdout,"funcao %s:\n",(char*)(yyvsp[(2) - (7)].node));
        (yyval.tree) = astreeCreate(ASTREE_FUNDEC,(yyvsp[(1) - (7)].tree),(yyvsp[(4) - (7)].tree),(yyvsp[(6) - (7)].tree),(yyvsp[(7) - (7)].tree),(yyvsp[(2) - (7)].node));
     }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 274 "yacc.y"
    {
        if(DEBUG) fprintf(stdout,"Lido valor e armazenado em %s\n",(char*) (yyvsp[(2) - (2)].node));
        (yyval.tree) = astreeCreate(ASTREE_INPUT,0,0,0,0,(yyvsp[(2) - (2)].node));
    }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 281 "yacc.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 282 "yacc.y"
    {(yyval.tree) = astreeCreate(ASTREE_OUTPUTSEQ,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0);}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 285 "yacc.y"
    {if(DEBUG) fprintf(stdout,"Valor escrito na saida padrao\n");
            (yyval.tree)=astreeCreate(ASTREE_OUTPUT,(yyvsp[(2) - (2)].tree),0,0,0,0);
    }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 290 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_RETURN,(yyvsp[(2) - (2)].tree),0,0,0,0); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 295 "yacc.y"
    { (yyval.tree) = 0;}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 296 "yacc.y"
    {(yyval.tree) = (yyvsp[(1) - (1)].tree);}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 297 "yacc.y"
    {(yyval.tree) = astreeCreate(ASTREE_ARGSEQ,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 307 "yacc.y"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 308 "yacc.y"
    { (yyval.tree)=astreeCreate(ASTREE_SYMBOL,0,0,0,0,(yyvsp[(1) - (1)].node)); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 309 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_VETCALL,(yyvsp[(3) - (4)].tree),0,0,0,(yyvsp[(1) - (4)].node)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 310 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_FUNCALL,(yyvsp[(3) - (4)].tree),0,0,0,(yyvsp[(1) - (4)].node)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 311 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_PTRADDR,0,0,0,0,(yyvsp[(2) - (2)].node)); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 312 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_PTRVALUE,0,0,0,0,(yyvsp[(2) - (2)].node)); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 313 "yacc.y"
    { (yyval.tree) = astreeCreate(ASTREE_EXPRESSION,(yyvsp[(2) - (3)].tree),0,0,0,0); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 314 "yacc.y"
    { (yyval.tree)=astreeCreate(ASTREE_MIN,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 315 "yacc.y"
    { (yyval.tree)=astreeCreate(ASTREE_UMIN,(yyvsp[(2) - (2)].tree),0,0,0,0); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 316 "yacc.y"
    { (yyval.tree)=astreeCreate(ASTREE_ADD,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 317 "yacc.y"
    {  (yyval.tree)=astreeCreate(ASTREE_MUL,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 318 "yacc.y"
    {  (yyval.tree)=astreeCreate(ASTREE_LE,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 319 "yacc.y"
    {  (yyval.tree)=astreeCreate(ASTREE_GE,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 320 "yacc.y"
    {  (yyval.tree)=astreeCreate(ASTREE_EQ,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 321 "yacc.y"
    {  (yyval.tree)=astreeCreate(ASTREE_NE,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 322 "yacc.y"
    {  (yyval.tree)=astreeCreate(ASTREE_AND,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 323 "yacc.y"
    {  (yyval.tree)=astreeCreate(ASTREE_OR,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 324 "yacc.y"
    {  (yyval.tree)=astreeCreate(ASTREE_DIV,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 325 "yacc.y"
    {  (yyval.tree)=astreeCreate(ASTREE_L,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 326 "yacc.y"
    {  (yyval.tree)=astreeCreate(ASTREE_G,(yyvsp[(1) - (3)].tree),(yyvsp[(3) - (3)].tree),0,0,0); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 333 "yacc.y"
    {
        if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");
        (yyval.tree)=astreeCreate(ASTREE_IF,(yyvsp[(3) - (6)].tree),(yyvsp[(6) - (6)].tree),0,0,0);
    }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 337 "yacc.y"
    {
        if(DEBUG) fprintf(stdout,"Clausula if avaliada\n");
        (yyval.tree)=astreeCreate(ASTREE_IF_ELSE,(yyvsp[(3) - (8)].tree),(yyvsp[(6) - (8)].tree),(yyvsp[(8) - (8)].tree),0,0);
    }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 343 "yacc.y"
    {
        if(DEBUG) fprintf(stdout,"Clausula loop avaliada\n");
        (yyval.tree)=astreeCreate(ASTREE_LOOP,(yyvsp[(3) - (5)].tree),(yyvsp[(5) - (5)].tree),0,0,0);
    }
    break;



/* Line 1806 of yacc.c  */
#line 2189 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 349 "yacc.y"



int yyerror(char *s){
        fprintf(stderr, "Failed to compilate the code.\n");
    exit(3);

}



