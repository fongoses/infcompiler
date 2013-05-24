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
	
	fprintf(stdout,"ASTREE(");
	switch( node->type){
		case  ASTREE_SYMBOL: fprintf(stdout,"ASTREE_SYMBOL {%s}",node->symbol->text); break;
		case  ASTREE_LIT_INT: fprintf(stdout,"ASTREE_LIT_INT"); break;
		case  ASTREE_ADD: fprintf(stdout,"ASTREE_ADD"); break;
		case  ASTREE_MIN: fprintf(stdout,"ASTREE_MIN"); break;
		case  ASTREE_MUL: fprintf(stdout,"ASTREE_MUL"); break;
		case  ASTREE_DIV: fprintf(stdout,"ASTREE_DIV"); break;
		case  ASTREE_SCALAR_ASS: fprintf(stdout,"ASTREE_SCALAR_ASS {%s}",node->symbol->text); break;
		case  ASTREE_LIT_SEQ: fprintf(stdout,"ASTREE_LIT_SEQ"); break;
		case  ASTREE_VARDEC: fprintf(stdout,"ASTREE_VARDEC {%s}",node->symbol->text); break;
		case  ASTREE_ARGSEQ: fprintf(stdout,"ASTREE_ARGSEQ"); break;
		case  ASTREE_FUNCALL: fprintf(stdout,"ASTREE_FUNCALL {%s}",node->symbol->text); break;
		case  ASTREE_VETCALL: fprintf(stdout,"ASTREE_VETCALL {%s}",node->symbol->text); break;
		case  ASTREE_PTRADDR: fprintf(stdout,"ASTREE_PTRADDR {%s}",node->symbol->text); break;
		case  ASTREE_PTRVALUE: fprintf(stdout,"ASTREE_PTRVALUE {%s}",node->symbol->text); break;
		case  ASTREE_LIT_FALSE: fprintf(stdout,"ASTREE_LIT_FALSE {%s}",node->symbol->text); break;
		case  ASTREE_LIT_TRUE: fprintf(stdout,"ASTREE_LIT_TRUE {%s}",node->symbol->text); break;
		case  ASTREE_LIT_CHAR: fprintf(stdout,"ASTREE_LIT_CHAR {%s}",node->symbol->text); break;
		case  ASTREE_VETORDEC: fprintf(stdout,"ASTREE_VETORDEC {%s}",node->symbol->text); break;
		case  ASTREE_FUNDEC: fprintf(stdout,"ASTREE_FUNDEC {%s}",node->symbol->text); break;
		case  ASTREE_PARAMSEQ: fprintf(stdout,"ASTREE_PARAMSEQ"); break;
		case  ASTREE_LOCALDECSEQ: fprintf(stdout,"ASTREE_LOCALDECSEQ"); break;
		case  ASTREE_KWWORD: fprintf(stdout,"ASTREE_KWWORD"); break;
		case  ASTREE_KWBOOL: fprintf(stdout,"ASTREE_KWBOOL"); break;
		case  ASTREE_KWBYTE: fprintf(stdout,"ASTREE_KWBYTE"); break;
		case  ASTREE_PROGRAM: fprintf(stdout,"ASTREE_PROGRAM"); break;
		case  ASTREE_LIT_STRING: fprintf(stdout,"ASTREE_LIT_STRING {%s}",node->symbol->text); break;
		case  ASTREE_GLOBALSEQ: fprintf(stdout,"ASTREE_GLOBALSEQ"); break;
		case  ASTREE_CONTROLEFLUXO: fprintf(stdout,"ASTREE_CONTROLEFLUXO"); break;
		case  ASTREE_INPUT: fprintf(stdout,"ASTREE_INPUT {%s}",node->symbol->text); break;
		case  ASTREE_OUTPUT: fprintf(stdout,"ASTREE_OUTPUT"); break;
		case  ASTREE_RETURN: fprintf(stdout,"ASTREE_RETURN"); break;
		case  ASTREE_PTR_ASS: fprintf(stdout,"ASTREE_PTR_ASS {%s}",node->symbol->text); break;
		case  ASTREE_DEREF_ASS: fprintf(stdout,"ASTREE_DEREF_ASS {%s}",node->symbol->text); break;
		case  ASTREE_VET_ASS: fprintf(stdout,"ASTREE_VET_ASS {%s}",node->symbol->text); break;
		case  ASTREE_EXPRESSION: fprintf(stdout,"ASTREE_EXPRESSION"); break;
		case  ASTREE_OUTPUTSEQ: fprintf(stdout,"ASTREE_OUTPUTSEQ"); break;
		case  ASTREE_IF: fprintf(stdout,"ASTREE_IF"); break;
		case  ASTREE_IF_ELSE: fprintf(stdout,"ASTREE_IF_ELSE"); break;
		case  ASTREE_LOOP: fprintf(stdout,"ASTREE_LOOP"); break;
		case  ASTREE_BLOCK: fprintf(stdout,"ASTREE_BLOCK"); break;
		case  ASTREE_PARAM: fprintf(stdout,"ASTREE_PARAM {%s}",node->symbol->text); break;
		case  ASTREE_PTRPARAM: fprintf(stdout,"ASTREE_PTRPARAM {%s}",node->symbol->text); break;
		case  ASTREE_LE: fprintf(stdout,"ASTREE_LE"); break;
		case  ASTREE_GE: fprintf(stdout,"ASTREE_GE"); break;
		case  ASTREE_EQ: fprintf(stdout,"ASTREE_EQ"); break;
		case  ASTREE_NE: fprintf(stdout,"ASTREE_NE"); break;
		case  ASTREE_AND: fprintf(stdout,"ASTREE_AND"); break;
		case  ASTREE_OR: fprintf(stdout,"ASTREE_OR"); break;
		case  ASTREE_L: fprintf(stdout,"ASTREE_L"); break;
		case  ASTREE_G: fprintf(stdout,"ASTREE_G"); break;
		case  ASTREE_NOT: fprintf(stdout,"ASTREE_NOT"); break;
		case  ASTREE_COMMANDSEQ: fprintf(stdout,"ASTREE_COMMANDSEQ"); break;
		case  ASTREE_PTRDEC: fprintf(stdout,"ASTREE_PTRDEC {%s}",node->symbol->text); break;
		default: fprintf(stdout, "ASTREE UNKNOWN"); break;
	}
	
	fprintf(stdout,")\n");
	return;
}

void astreePrintTree(ASTREE * node, int level) {
	int i =0;
		
	if(!node) return;
	for(i=0;i< level; i++)
		fprintf(stdout,"    ");
		
	astreePrintSingle(node);

	for(i=0;i<MAX_SONS;i++)
		if(node->son[i])
			astreePrintTree(node->son[i],level+1);

}

