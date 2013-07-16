#include <stdio.h>
#include "tac.h"

//tac Global
TAC * mainTAC;

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

TAC * tac_join(TAC *l1, TAC *l2){

    TAC * tac;

    if(!l1) return l2;
    if(!l2) return l1;
   
    //percorre ateh ultimo
    for(tac=l2; tac->prev;tac=tac->prev);
    tac->prev = l1;
   
    return l2;
}

//funcao OK
TAC * tacReverse(TAC * last){
    TAC * first = 0;

    if(!last) return 0;

    for(first=last;first->prev;first=first->prev)
       first->prev->next = first;

    return first;
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

        case TAC_MOV:
            fprintf(stderr,"TAC(TAC_MOV,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);
            break;
        
        /*case TAC_BEGINF:
             fprintf(stderr,"TAC(TAC_BEGINF)");
             break;

        case TAC_VARDEC:
             fprintf(stderr,"TAC(TAC_VARDEC)",tac->target);
             break;
*/
       
        default: break;

    }
}

void print_tac(TAC*tac){


    if(!tac) return;

    print_tac_single(tac);
    print_tac(tac->prev);
}
