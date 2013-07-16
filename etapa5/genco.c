#include <stdio.h>
#include "tac.h"

TAC * generateCode(ASTREE * node){
    int i;
    TAC * treeSons[MAX_SONS];
    TAC * result;
    TAC * nova;

    if(!node) return;
    result=0;
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
            fprintf(stderr,"LIT_INT\n");
            result =  tac_create(TAC_LIT_INT,node->symbol, 0, 0);
            break;

        case ASTREE_ADD:
            fprintf(stderr,"ADD\n");
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
            fprintf(stderr,"SCALAR_ASS\n");
            result = tac_join(treeSons[0], tac_create(TAC_MOV,node->symbol, treeSons[0]?treeSons[0]->target:0, 0)); //obs, o primeiro filho eh o simbo q ja ta na tab d simbolos
            //fprintf(stderr,"TAC_MOV\n");
            break;

        case ASTREE_LIT_SEQ:
            result = tac_join(treeSons[0], tac_create(TAC_LIT_SEQ, treeSons[1]->target, 0, 0));
            break;

        case ASTREE_VARDEC:
            fprintf(stderr,"VARDEC\n");
            result = tac_create(TAC_VARDEC, node->symbol, treeSons[1]?treeSons[1]->target:0, 0);
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
            result = tac_create(TAC_VETORDEC, node->symbol, treeSons[1]?treeSons[1]->target:0, 0);
            break;

        case ASTREE_FUNDEC:
            fprintf(stderr,"FUNDEC\n");
            result = makeFun(node->symbol,treeSons[1],treeSons[3]);
            break;

        case ASTREE_PARAMSEQ:
		    result = tac_join(treeSons[0],treeSons[1]);
            break;

        case ASTREE_LOCALDECSEQ:
            result = tac_join(treeSons[0],treeSons[1]);
            break;

        case ASTREE_KWWORD:
            break;

        case ASTREE_KWBOOL:
            break;

        case ASTREE_KWBYTE:
            break;

        case ASTREE_PROGRAM:
            fprintf(stderr,"PROGRAM\n");
            result= treeSons[0];
            break;

        case ASTREE_LIT_STRING:
            break;

        case ASTREE_GLOBALSEQ:
            fprintf(stderr,"GLOBALSEQ\n");
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
            result = treeSons[0];
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
            fprintf(stderr,"COMMANDSEQ\n");	
            result = tac_join(treeSons[0],treeSons[1]);
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

    // Cria desvio para a condicao
    label=(HASH_NODE*)makeLabel();

    // Teste e desvio da condição
    nova1= tac_create(TAC_JZ,label,son0?son0->target:0,0); // TAC_JZ ou TAC_IF????

    // Caso seja verdadeiro
    nova2= tac_create(TAC_LABEL,label,0,0); //Rever essa linha: nao tenho ctz se esta ok

    return tac_join(tac_join(son0,nova1),nova2);
}

TAC *makeIfThenElse(TAC* condicao, TAC* if_true, TAC* if_false){
    TAC *tac_if;
    TAC *tac_pula_else; // JMP inconcicional executado após os comandos caso a condição seja verdadeira que "pula" a parte do else.
    TAC *tac_lbl_else;
    TAC *tac_lbl_end;

    HASH_NODE *hash_lbl_else;
    HASH_NODE *hash_lbl_end;

    // Cria desvio para a condição
    hash_lbl_else = (HASH_NODE*) makeLabel();
    hash_lbl_end = (HASH_NODE*) makeLabel();

    // Teste e desvio da condição
    tac_if = tac_create(TAC_JZ, hash_lbl_else, condicao?condicao->target:0, 0); // TAC_JZ ou TAC_IFELSE????
    tac_pula_else = tac_create(TAC_JMP, hash_lbl_end, 0, 0);

    // Róulos para o ELSE
    tac_lbl_else = tac_create(TAC_LABEL, hash_lbl_else, 0, 0);
    tac_lbl_end = tac_create(TAC_LABEL, hash_lbl_end, 0, 0);

    return tac_join(tac_join(tac_join(tac_join(tac_join(tac_join(condicao, tac_if), if_true), tac_pula_else), tac_lbl_else), if_false), tac_lbl_end);
}

TAC *makeLoop(TAC* condicao, TAC* comandos){
    TAC *tac_loop; // Testa consição e sai do laço
    TAC *tac_jmp_begin; // JMP inconcicional executado após os comandos e retorna para a condição de teste
    TAC *tac_lbl_begin;
    TAC *tac_lbl_end;

    HASH_NODE *hash_lbl_begin;
    HASH_NODE *hash_lbl_end;

    // Cria desvios
    hash_lbl_begin = (HASH_NODE*) makeLabel();
    hash_lbl_end = (HASH_NODE*) makeLabel();

    // Teste e desvio da condição
    tac_loop = tac_create(TAC_JZ, hash_lbl_end, condicao?condicao->target:0, 0); // TAC_JZ ou TAC_LOOP????
    tac_jmp_begin = tac_create(TAC_JMP, hash_lbl_begin, 0, 0);

    // Rótulos para marcar o bloco do comando
    tac_lbl_begin = tac_create(TAC_LABEL, hash_lbl_begin, 0, 0);
    tac_lbl_end = tac_create(TAC_LABEL, hash_lbl_end, 0, 0);

    return tac_join(tac_join(tac_join(tac_join(tac_join(tac_lbl_begin, condicao), tac_loop), comandos), tac_jmp_begin), tac_lbl_end);
}

TAC * makeFun (HASH_NODE* symbol,TAC * son1, TAC * son3 ){ //parametros eh o filho 1, bloco da funcao eh o filho 3

	TAC * begin;
	TAC * end;
    TAC * temp1, *temp2;

	begin = tac_create(TAC_BEGINF,symbol,0,0);
	end = tac_create(TAC_ENDF,symbol,0,0);
    fprintf(stderr,"makeFun()\n");	

    //fprintf(stderr,"    son1: %p, begin: %p\n",son1,begin);	
    temp1 = tac_join(son1,begin);
    //fprintf(stderr,"    temp1: %p, son3: %p\n",temp1,son3);	
    //temp2 = tac_join(temp1,son3); 
    fprintf(stderr,"    temp2\n");
    fprintf(stderr,"    temp3\n");	
   	
    return tac_join(temp1,end);
	//return tac_join(tac_join(tac_join(son1,begin),son3),end);
}





