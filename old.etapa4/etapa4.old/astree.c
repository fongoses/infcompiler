#include "astree.h"
#include "y.tab.h"
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
	node->lineNumber = getLineNumber();
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

void astreeSetDeclarations(ASTREE * node) {
	int i =0;
	if(!node)
		return;

	//verificar declaracoes multiplas, setando o tipo SYMBOL_SCALAR, ou VECTOR, etc. para os tipos  SYMBOL_IDENTIFIER existentes na tabela.


	if(node->type ==  ASTREE_VARDEC)
	{
		if(node->symbol->type == SYMBOL_LIT_STRING){
			
		}
		
	}

	//na tabela hash, o que sobra como SYMBOL_IDENTIFIER, eh variaval que
	//nao foi encontrada, logo nao declarada.
	//isso serah realizado pela funcao hashVerifyUndeclared().
	for(i=0;i<MAX_SONS;i++)
		if(node->son[i])
			astreeSetDeclarations(node->son[i]);

}


void hashVerifyUndeclared(){

	//verificar tabela de simbolos, procurando identificadores
	//que nao possuem tipos associados (ou seja, possuem tipo i
	//SYMBOL_IDENTIFIER em vez do seu tipo verdadeiro. 
	//Antes dessa funcao deve ser chamada astreeSetDeclarations 


}

void astreePrintTree(ASTREE * node) {
	int i =0;
	
	astreePrintSingle(node);
	for(i=0;i<MAX_SONS;i++)
		if(node->son[i])
			astreePrintTree(node->son[i]);

}


//verificar subtipo de expressoes, recursivamente, para verificar natureza dos filhos
void astreeCheckNature(ASTREE * node) {
	int i =0;
	if(!node)
		return;

	//verificar declaracoes multiplas, setando o tipo SYMBOL_SCALAR, ou VECTOR, etc. para os tipos  SYMBOL_IDENTIFIER existentes na tabela.


	if(node->type ==  ASTREE_VARDEC)
	{
		if(node->symbol->type == SYMBOL_LIT_STRING){
			
		}
		
	}

	//na tabela hash, o que sobra como SYMBOL_IDENTIFIER, eh variaval que
	//nao foi encontrada, logo nao declarada.
	//isso serah realizado pela funcao hashVerifyUndeclared().
	for(i=0;i<MAX_SONS;i++)
		if(node->son[i])
			astreeCheckNature(node->son[i]);

}

