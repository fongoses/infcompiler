#include "astree.h"

ASTREE * astreeCreate(int type, ASTREE * S0, ASTREE * S1, ASTREE * S2, ASTREE * S3, HASH_NODE * n){

	ASTREE * node = 0;
	node = (ASTREE*) calloc(1,sizeof(ASTREE));
	

	//init
	node->type = type;
	node->symbol= n; //07/05 ponteiro para tb de simbolos
	node->son[0] = S0;
	node->son[1] = S1;
	node->son[2] = S2;	
	node->son[3] = S3;
	return node;
}

void astreePrintSingle(ASTREE * node){

	if(!node) return ;
	
	fprintf(stderr,"ASTREE(");
	switch( node->type){
		case  ASTREE_SYMBOL: fprintf(stdout,"ASTREE_SYMBOL"); break;
		case  ASTREE_CMDL: fprintf(stdout,"ASTREE_CMDL"); break;
		case  ASTREE_VETORDEC: fprintf(stdout,"ASTREE_VETORDEC");
		case  ASTREE_LIT_INT: fprintf(stdout,"ASTREE_LIT_INT");
		case  ASTREE_ADD: fprintf(stdout,"ASTREE_ADD");
		case  ASTREE_MIN: fprintf(stdout,"ASTREE_MIN");
		case  ASTREE_MUL: fprintf(stdout,"ASTREE_MUL");
		case  ASTREE_FUNCALL: fprintf(stdout,"ASTREE_FUNCALL");
		case  ASTREE_SCALAR_ASS: fprintf(stdout,"ASTREE_SCALAR_ASS");
		case  ASTREE_PTRVALUE: fprintf(stdout,"ASTREE_PTRVALUE");
		default: fprintf(stderr, "ASTREE UNKNOWN"); break;
	}
	
	fprintf(stderr,")\n");
	return;
}

void astreePrintTree(ASTREE * node) {
	int i =0;
	
	astreePrintSingle(node);
	for(i=0;i<MAX_SONS;i++)
		if(node->son[i])
			astreePrintTree(node->son[i]);

}

