#ifndef __TACH__
#define __TACH__

#include "hashtable.h"
#include "astree.h"
typedef struct tac {

	int type;
	HASH_NODE * target;
	HASH_NODE * op1;
	HASH_NODE * op2;	
	struct tac * prev;
	//struct tac * next; n usado hoje: 06/05


} TAC;


#define TAC_ADD 1 
#define TAC_SYMBOL 2
#define TAC_LIT_INT 3

TAC * tac_create(int type, HASH_NODE * target, HASH_NODE *op1, HASH_NODE *op2);
TAC * generateCode(ASTREE * node);
void print_tac_single(TAC*tac);
TAC * tac_join(TAC *l1, TAC *l2);



#endif
