#include <stdio.h>
#include "tac.h"


TAC * tac_create(int type, HASH_NODE * target, HASH_NODE *op1, HASH_NODE *op2){

	TAC*tac;
	tac = (TAC*) calloc(1,sizeof(TAC));
	tac->type = type;
	tac->target = target;
	tac->op1= op1;
	tac->op2= op2;
	tac->prev=0;

}
TAC * generateCode(ASTREE * node){
	int i;
	TAC * treeSons[MAX_SONS];
	
	if(!node) return;

	//process children first recursivelly
	for(i=0;i<MAX_SONS;i++)
		if(node->son[i])
			treeSons[i]=generateCode(node->son[i]);

	//proccess this node
	switch(node->type)
	{
		case ASTREE_ADD:
		return tac_join(treeSons[0],
			tac_join(treeSons[1],
				tac_create(TAC_ADD,makeTemp(),
						treeSons[0]?treeSons[0]->target:0,
						treeSons[1]?treeSons[1]->target:0)));
		break;
		
		case ASTREE_SYMBOL: 
		return tac_create(TAC_SYMBOL,node->symbol,0,0); //para elem da lista que corresponde ao symbol (que eh um elem folha), insere (em target) o  ptr para sua tab de simbolos
		break;

		case ASTREE_LIT_INT:		
			return tac_create(TAC_LIT_INT,node->symbol,0,0);
			break;
		
		default: return 0;
	}
}



void print_tac_single(TAC*tac){

	if(!tac) return;

	switch(tac->type){
		case TAC_ADD: 
			fprintf(stderr,"TAC(TAC_ADD,temp,%s,%s)\n",tac->op1->text,tac->op2->text);
		break;
		case TAC_SYMBOL: 
			fprintf(stderr,"TAC(TAC_SYMBOL,%s,NULL,NULL)\n",tac->target->text);		
		break;

		case TAC_LIT_INT: 
			fprintf(stderr,"TAC(TAC_LIT_INT,%s,NULL,NULL)\n",tac->target->text);		
		break;


		default: break;
	}
}

void print_tac(TAC*tac){


	if(!tac) return;
		
	print_tac_single(tac);
	print_tac(tac->prev);
}


TAC * tac_join(TAC *l1, TAC *l2){

	TAC * tac;

	if(!l1) return l2;
	if(!l2) return l1;

	//percorre ateh ultimo
	for(tac=l2; tac->prev;tac=tac->prev);
	
	tac->prev = l1;

	return l2;
}
