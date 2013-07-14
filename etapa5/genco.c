#include <stdio.h>
#include "tac.h"

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
            result = tac_create(TAC_SYMBOL,node->symbol, 0, 0); //para elem da lista que corresponde ao symbol (que eh um elem folha), insere (em target) o  ptr para sua tab de simbolos
            break;

        case ASTREE_LIT_INT:
            result =  tac_create(TAC_LIT_INT,node->symbol, 0, 0);
            break;

        case ASTREE_ADD:
            result = makeBinop(treeSons[0], treeSons[1], TAC_ADD);
            break;

        case ASTREE_MIN:
            result = makeBinop(treeSons[0], treeSons[1], TAC_MIN);
            break;

        case ASTREE_UMIN:
            result = makeBinop(treeSons[0], 0, TAC_UMIN);
            break;

        case ASTREE_MUL:
            result = makeBinop(treeSons[0], treeSons[1], TAC_MUL);
            break;

        case ASTREE_DIV:
            result = makeBinop(treeSons[0], treeSons[1], TAC_DIV);
            break;

        case ASTREE_SCALAR_ASS:
            result = tac_join(treeSons[0], tac_create(TAC_MOV,node->symbol, treeSons[0]?treeSons[0]->target:0, 0)); //obs, o primeiro filho eh o simbo q ja ta na tab d simbolos
            //fprintf(stderr,"TAC_MOV");
            break;

        case ASTREE_LIT_SEQ:
            result = tac_join(treeSons[0], tac_create(TAC_LIT_SEQ, treeSons[1]->target, 0, 0));
            break;

        case ASTREE_VARDEC:
            result = tac_create(TAC_VARDEC, node->symbol, treeSons[1]->target, 0);
            break;

        case ASTREE_ARGSEQ:
            break;

        case ASTREE_FUNCALL:
            break;

        case ASTREE_VETCALL:
            break;

        case ASTREE_PTRADDR:
            break;

        case ASTREE_PTRVALUE:
            break;

        case ASTREE_LIT_FALSE:
            result =  tac_create(TAC_LIT_FALSE, node->symbol, 0, 0);
            break;

        case ASTREE_LIT_TRUE:
            result =  tac_create(TAC_LIT_TRUE, node->symbol, 0, 0);
            break;

        case ASTREE_LIT_CHAR:
            result =  tac_create(TAC_LIT_CHAR, node->symbol, 0, 0);
            break;

        case ASTREE_VETORDEC:
            result = tac_create(TAC_VETORDEC, node->symbol, treeSons[1]->target, 0);
            break;

        case ASTREE_FUNDEC:
            break;

        case ASTREE_PARAMSEQ:
            break;

        case ASTREE_LOCALDECSEQ:
            break;

        case ASTREE_KWWORD:
            break;

        case ASTREE_KWBOOL:
            break;

        case ASTREE_KWBYTE:
            break;

        case ASTREE_PROGRAM:
            result= generateCode(node->son[0]);
            break;

        case ASTREE_LIT_STRING:
            break;

        case ASTREE_GLOBALSEQ:
            result = tac_join(treeSons[0],treeSons[1]);
            break;

        case ASTREE_INPUT:
            break;

        case ASTREE_OUTPUT:
            break;

        case ASTREE_RETURN:
            break;

        case ASTREE_PTR_ASS:
            break;

        case ASTREE_DEREF_ASS:
            break;

        case ASTREE_VET_ASS:
            break;

        case ASTREE_EXPRESSION:
            break;

        case ASTREE_OUTPUTSEQ:
            break;

        case ASTREE_IF:
            break;

        case ASTREE_IF_ELSE:
            break;

        case ASTREE_LOOP:
            break;

        case ASTREE_BLOCK:
            break;

        case ASTREE_PARAM:
            break;

        case ASTREE_PTRPARAM:
            break;

        case ASTREE_LE:
            result = makeBinop(treeSons[0], treeSons[1], TAC_LE);
            break;

        case ASTREE_GE:
            result = makeBinop(treeSons[0], treeSons[1], TAC_GE);
            break;

        case ASTREE_EQ:
            result = makeBinop(treeSons[0], treeSons[1], TAC_EQ);
            break;

        case ASTREE_NE:
            result = makeBinop(treeSons[0], treeSons[1], TAC_NE);
            break;

        case ASTREE_AND:
            result = makeBinop(treeSons[0], treeSons[1], TAC_AND);
            break;

        case ASTREE_OR:
            result = makeBinop(treeSons[0], treeSons[1], TAC_OR);
            break;

        case ASTREE_L:
            result = makeBinop(treeSons[0], treeSons[1], TAC_L);
            break;

        case ASTREE_G:
            result = makeBinop(treeSons[0], treeSons[1], TAC_G);
            break;

        case ASTREE_NOT:
            result = makeBinop(treeSons[0], 0, TAC_NOT);
            break;

        case ASTREE_COMMANDSEQ:
            break;

        case ASTREE_PTRDEC:
            break;

        default:
            result = 0;
            break;
        }

        return result;
}

//cria codigo de operacoes binarias. type eh o tipo da operacao
TAC* makeBinop(TAC * son0, TAC * son1, int type){
    TAC* nova;
    TAC* result;

    result = tac_join(son0, son1);
    nova = tac_create(type, makeTemp(), son0?son0->target:0, son1?son1->target:0);
    nova->prev = result;
    result = nova;

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

TAC * makeFun (HASH_NODE* symbol,TAC * son3 ){ //bloco da funcao eh o filho 3

    //completar o codigo abaixo.
    //return tac_join(tac_create(TAC_BEGINF,name,0,0), ...
}
