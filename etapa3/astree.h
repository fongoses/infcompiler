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
#define MAX_SONS 4
#define ASTREE_SYMBOL 1
#define ASTREE_LIT_INT 2
#define ASTREE_ADD 3
#define ASTREE_MIN 4
#define ASTREE_MUL 5
#define ASTREE_DIV 6

typedef struct astree_node{
		int type;
		struct astree_node * son[MAX_SONS];
	} ASTREE;



ASTREE * astreeCreate(int type, ASTREE * s0, ASTREE * S1, ASTREE * S2, ASTREE * S3);
void astreePrintSingle(ASTREE *node);
void astreePrintTree(ASTREE *node);
