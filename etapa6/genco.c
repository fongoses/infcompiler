#include <stdio.h>
#include "tac.h"

//PROTOTYPES
TAC* makeBinop(TAC * treeSon0,TAC* treeSon1, int type); //cria codigo de operacoes binarias. type eh o tipo da operacao



//em tac.c ? (professor criou arquivo tac.c)
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
	TAC * result;
    TAC * nova;

	if(!node) return;

	//process children first recursivelly
	for(i=0;i<MAX_SONS;i++)
		if(node->son[i])
			treeSons[i]=generateCode(node->son[i]);

	//proccess this node
	switch(node->type)
	{
		/*case ASTREE_ADD:
		result =  tac_join(treeSons[0],
			tac_join(treeSons[1],
				tac_create(TAC_ADD,makeTemp(),
						treeSons[0]?treeSons[0]->target:0,
						treeSons[1]?treeSons[1]->target:0)));
                        
		break;
        */
		
		case ASTREE_SYMBOL: 
		return tac_create(TAC_SYMBOL,node->symbol,0,0); //para elem da lista que corresponde ao symbol (que eh um elem folha), insere (em target) o  ptr para sua tab de simbolos
		break;

		case ASTREE_LIT_INT:		
			result =  tac_create(TAC_LIT_INT,node->symbol,0,0);
			break;	
        case ASTREE_ADD:
            result = makeBinop(treeSons[0],treeSons[1], TAC_ADD);
            break;
        case ASTREE_MIN:
            result = makeBinop(treeSons[0],treeSons[1], TAC_MIN);
            break;        
        case ASTREE_MUL:
            result = makeBinop(treeSons[0],treeSons[1], TAC_MUL);
            break;
        case ASTREE_DIV:
            result = makeBinop(treeSons[0],treeSons[1], TAC_DIV);
            break;

        case ASTREE_SCALAR_ASS:
            result = tac_join(treeSons[0],tac_create(TAC_MOV,node->symbol,treeSons[0]?treeSons[0]->target:0,0)); //obs, o primeiro filho eh o simbo q ja ta na tab d simbolos
            break;
        case ASTREE_IF:
        
            	
		default: return 0;
	}

    return result;
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


TAC* makeBinop(TAC * son0, TAC * son1, int type){
    TAC* nova;
    TAC* result;

    switch(type){    
        case TAC_ADD:
            result = tac_join(son0,son1);
            nova = tac_create(TAC_ADD,makeTemp(),son0?son0->target:0,son1?son1->target:0);
            nova->prev=result;
            result = nova;   
            return result;
            break;
         case TAC_MIN:
            result = tac_join(son0,son1);
            nova = tac_create(TAC_MIN,makeTemp(),son0?son0->target:0,son1?son1->target:0);
            nova->prev=result;
            result = nova;   
            return result;
            break;

         case TAC_MUL:
            result = tac_join(son0,son1);
            nova = tac_create(TAC_MUL,makeTemp(),son0?son0->target:0,son1?son1->target:0);
            nova->prev=result;
            result = nova;   
            return result;
            break;

         case TAC_DIV:
            result = tac_join(son0,son1);
            nova = tac_create(TAC_DIV,makeTemp(),son0?son0->target:0,son1?son1->target:0);
            nova->prev=result;
            result = nova;   
            return result;
            break;


        default: result= 0;
    }
    return result;
}

TAC* makeIfThen(TAC* son0, TAC* son1){
    TAC * nova1;
    TAC * nova2;
    HASH_NODE * label;
    label=(HASH_NODE*)makeLabel();
    nova1= tac_create(TAC_JZ,label,son0?son0->target:0,0);
    nova2= tac_create(TAC_LABEL,label,0,0); //Rever essa linha: nao tenho ctz se esta ok
    return tac_join(tac_join(son0,nova1),nova2);
}

//funcao OK
TAC * tacReverse(TAC * last){
    TAC * first = 0;

    if(!last) return 0;
    
    for(first=last;first->prev;first=first->prev)
       first->prev->next = first;
    
    return first;
}


//ASSEMBLER.

//nao eh recursiva
void generateASM(TAC * first){

	TAC * tac=0;
	FILE fout = 0; //arquivo de saida

	for(tac=firs;tac;tac=tac->next){
		switch(tac->type){

			case TAC_BEGINF: fprintf(fout,".globl %s\n"
			".type\n"
			"   main, @function",tac->target->text); //nome da funcao em %s
			break;
			case TAC_ENDF: break;
			case TAC_MOV: break;
			case TAC_ADD: 	
				fprintf(fout," movl    a, %%eax\n"
        				"addl    $2, %%eax"
        				"movl    %%eax, a");
			
			break;
			case TAC_OUTPUT: 
				//printf
				fprintf(fout,"movl    a, %%eax\n"
        			"movl    %%eax, 4(%%esp)\n"
        			"movl    $.LC0, (%%esp)\n"
        				"call    printf\n"

				
			break;
			default: break;

		}
	}	


}


