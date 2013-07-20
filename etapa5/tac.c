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
            fprintf(stderr,"TAC(TAC_ADD,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);         break;

        case TAC_MIN:
            fprintf(stderr,"TAC(TAC_MIN,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);         break;

        case TAC_MUL:
            fprintf(stderr,"TAC(TAC_MUL,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);         break;

        case TAC_DIV:
            fprintf(stderr,"TAC(TAC_DIV,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);         break;

        case TAC_LE:
            fprintf(stderr,"TAC(TAC_LE,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);        
            break;


        case TAC_GE:
            fprintf(stderr,"TAC(TAC_GE,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);         
            break;

        case TAC_EQ:
            fprintf(stderr,"TAC(TAC_EQ,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);         
            break;

        case TAC_NE:
            fprintf(stderr,"TAC(TAC_NE,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);         
            break;


        case TAC_AND:
            fprintf(stderr,"TAC(TAC_AND,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);        
            break;


         case TAC_OR:
            fprintf(stderr,"TAC(TAC_OR,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);          
            break;

         case TAC_L:
            fprintf(stderr,"TAC(TAC_L,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);         
            break;

        case TAC_G:
            fprintf(stderr,"TAC(TAC_G,%s,%s,%s)\n",tac->target->text,tac->op1->text,tac->op2->text);         
            break;
    
/*
        case TAC_NOT:
            fprintf(stderr,"TAC(TAC_NOT,%s,%s,0)\n",tac->target->text,tac->op1->text);
            break;
*/
      case TAC_SYMBOL:
            fprintf(stderr,"TAC(TAC_SYMBOL,%s,NULL,NULL)\n",tac->target->text);
            break;

        case TAC_LIT_INT:
            fprintf(stderr,"TAC(TAC_LIT_INT,%s,NULL,NULL)\n",tac->target->text);
            break;

        case TAC_LIT_STRING:
            fprintf(stderr,"TAC(TAC_LIT_STRING,%s,NULL,NULL)\n",tac->target->text);
            break;

        case TAC_LIT_FALSE:
            fprintf(stderr,"TAC(TAC_LIT_FALSE,%s,NULL,NULL)\n",tac->target->text);
            break;

        case TAC_LIT_TRUE:
            fprintf(stderr,"TAC(TAC_LIT_TRUE,%s,NULL,NULL)\n",tac->target->text);
            break;

        case TAC_LIT_CHAR:
            fprintf(stderr,"TAC(TAC_LIT_CHAR,%s,NULL,NULL)\n",tac->target->text);
            break;

        case TAC_UMIN:
            fprintf(stderr,"TAC(TAC_UMIN,%s,NULL,NULL)\n",tac->target->text);
            break;

        
        case TAC_JMP:
            fprintf(stderr,"TAC(TAC_JMP,%s,NULL,NULL)\n",tac->target->text);
            break;
 
        case TAC_JFALSE:
            fprintf(stderr,"TAC(TAC_JFALSE,%s,NULL,NULL)\n",tac->target->text);
            break;       
         
        case TAC_MOV:
            fprintf(stderr,"TAC(TAC_MOV,%s,%s)\n",tac->target->text,tac->op1->text,0);
            break;
        
        case TAC_BEGINF:
             fprintf(stderr,"TAC(TAC_BEGINF,%s,0,0)\n",tac->target->text);
             break;
       
        case TAC_ENDF:
             fprintf(stderr,"TAC(TAC_ENDF,%s,0,0)\n",tac->target->text);
             break;  

        case TAC_PARAM:
             fprintf(stderr,"TAC(TAC_PARAM,%s,0,0)\n",tac->target->text);
             break;  

        case TAC_PTRPARAM:
             fprintf(stderr,"TAC(TAC_PTRPARAM,%s,0,0)\n",tac->target->text);
             break;  



        case TAC_VARDEC:
             fprintf(stderr,"TAC(TAC_VARDEC,%s,0,0)\n",tac->target->text);
             break;
  
        case TAC_VETORDEC:
             fprintf(stderr,"TAC(TAC_VETORDEC,%s,0,0)\n",tac->target->text);
             break;

        case TAC_LIT_SEQ:
             fprintf(stderr,"TAC(TAC_ARG,%s,0,0)\n",tac->target->text);
             break;

        case TAC_ARG:
             fprintf(stderr,"TAC(TAC_ARG,%s,0,0)\n",tac->target->text);
             break;
 
        case TAC_VETCALL:
             fprintf(stderr,"TAC(TAC_VETCALL,%s,0,0)\n",tac->target->text);
             break;
       
        case TAC_FUNCALL:
             fprintf(stderr,"TAC(TAC_FUNCALL,%s,0,0)\n",tac->target->text);
             break;

        case TAC_PTRADDR:
             fprintf(stderr,"TAC(TAC_PTRADDR,%s,%s,0)\n",tac->target->text,tac->op1->text);
             break;

        case TAC_PTRVALUE:
             fprintf(stderr,"TAC(TAC_PTRVALUE,%s,%s,0)\n",tac->target->text,tac->op1->text);
             break;

        case TAC_INPUT:
             fprintf(stderr,"TAC(TAC_INPUT,%s,0,0)\n",tac->target->text);
             break;

        case TAC_BEGINEXP:
             fprintf(stderr,"TAC(TAC_BEGINEXP,%s,0,0)\n",tac->target->text);
             break;

        case TAC_ENDEXP:
             fprintf(stderr,"TAC(TAC_ENDEXP,%s,0,0)\n",tac->target->text);
             break;

        case TAC_OUTPUT:
             fprintf(stderr,"TAC(TAC_OUTPUT,%s,0,0)\n",tac->target->text);
             break;

        case TAC_RETURN:
             fprintf(stderr,"TAC(TAC_RETURN,%s,0,0)\n",tac->target->text);
             break;
       
        default: break;

    }
}

void print_tac(TAC*tac){


    if(!tac) return;

    print_tac_single(tac);
    print_tac(tac->prev);
}
