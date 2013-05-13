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
		case  ASTREE_SYMBOL: fprintf(stderr,"ASTREE_SYMBOL"); break;
		case  ASTREE_CMDL: fprintf(stderr,"ASTREE_CMDL"); break;
		
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

