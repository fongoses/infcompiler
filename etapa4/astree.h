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
#define ASTREE_CMDL 8 
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
#define ASTREE_DEC 27

typedef struct astree_node{
		int type;
		//int valor: 07/05 ,valor para o literal: nao necessario, eh armazenado como symbol
		HASH_NODE * symbol;
		struct astree_node * son[MAX_SONS];
		int lineNumber;
} ASTREE;



ASTREE * astreeCreate(int type, ASTREE * s0, ASTREE * S1, ASTREE * S2, ASTREE * S3, HASH_NODE * ptr);
void astreePrintSingle(ASTREE *node);
void astreePrintTree(ASTREE *node);
