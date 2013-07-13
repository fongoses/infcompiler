/**********************************************************************
 *Arvore Sintatica Abstrata  
 **********************************************************************
 * This code define the abstract syntax tree struct.
 **********************************************************************
 * Authors:
 * Luiz Gustavo Frozi de Castro e Souza (fongoses@gmail.com)
 * Mario Cesar Gasparoni Junior (mariogasparoni@gmail.com)
 **********************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#define MAX_SONS 4
#define ASTREE_SYMBOL 1
#define ASTREE_LIT_INT 2
#define ASTREE_ADD 3
#define ASTREE_MIN 4
#define ASTREE_MUL 5
#define ASTREE_DIV 6
#define ASTREE_SCALAR_ASS 7 
#define ASTREE_COMMANDSEQ 8 
#define ASTREE_LIT_SEQ 9 
#define ASTREE_VARDEC 10 
#define ASTREE_ARGSEQ 11 
#define ASTREE_FUNCALL 12 
#define ASTREE_VETCALL 13 
#define ASTREE_PTRADDR 14
#define ASTREE_PTRVALUE 15 
#define ASTREE_LIT_FALSE 16
#define ASTREE_LIT_TRUE 17
#define ASTREE_LIT_CHAR 18
#define ASTREE_VETORDEC 19
#define ASTREE_FUNDEC 20
#define ASTREE_PARAMSEQ 21
#define ASTREE_LOCALDECSEQ 22
#define ASTREE_KWWORD 23
#define ASTREE_KWBOOL 24
#define ASTREE_KWBYTE 25
#define ASTREE_PROGRAM 26
#define ASTREE_LIT_STRING 28
#define ASTREE_GLOBALSEQ 29
#define ASTREE_INPUT 31
#define ASTREE_OUTPUT 32
#define ASTREE_RETURN 33
#define ASTREE_PTR_ASS 34
#define ASTREE_DEREF_ASS 35
#define ASTREE_VET_ASS 36
#define ASTREE_EXPRESSION 37 //expressao entre parenteses: '('expressao ')'
#define ASTREE_OUTPUTSEQ 38
#define ASTREE_IF 39
#define ASTREE_IF_ELSE 40
#define ASTREE_LOOP 41
#define ASTREE_BLOCK 42
#define ASTREE_PARAM 43
#define ASTREE_PTRPARAM 44
#define ASTREE_LE 45
#define ASTREE_GE 46
#define ASTREE_EQ 47
#define ASTREE_NE 48
#define ASTREE_AND 49
#define ASTREE_OR 50
#define ASTREE_L 51
#define ASTREE_G 52
#define ASTREE_NOT 53
#define ASTREE_PTRDEC 54
#define DEC_OK -3
#define DEC_ERR -4
extern FILE *outputFile;


typedef struct astree_node{
		int type;
		HASH_NODE * symbol;
		int lineNumber;
		struct astree_node * son[MAX_SONS];
} ASTREE;



void getSymbolTypeName(char * dstbuffer, int code);
ASTREE * astreeCreate(int type, ASTREE * s0, ASTREE * S1, ASTREE * S2, ASTREE * S3, HASH_NODE * ptr);
void astreePrintSingle(ASTREE *node);
void astreePrintTree(ASTREE *node, int level);
void astreeCreateCode(ASTREE * node, int level);
int astreeCreateDeclaration(ASTREE * node);
void astreeCheckDeclarations(ASTREE * node);
void astreeCheckDeclarationsSingle(ASTREE * node);
int astreeCheckNature(ASTREE * node);
int astreeCheckMathExpression(ASTREE * node);
int astreeSetDeclarations(ASTREE * node);
int getItemNum(ASTREE * node);
void setType(ASTREE * node);
void astreeSetType(ASTREE * node);
void setItemType(ASTREE * node);
void astreeCheckUndeclaredAndDatatype(ASTREE * node);
void astreeCheckRedeclarations(ASTREE * node);
ASTREE * nodeFind(ASTREE * tree,int type,char * text);
