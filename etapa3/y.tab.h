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
extern YYSTYPE yylval;
