#include <stdio.h>
#include "tac.h"

TAC * generateCode(ASTREE * node){
    int i;
    TAC * treeSons[MAX_SONS];
    TAC * result;
    TAC * nova;

    if(!node){
           fprintf(stderr,"NULL node\n");
         return 0;
    }
    //process children first recursivelly
    for(i=0;i<MAX_SONS;i++)
        if(node->son[i])
            treeSons[i]=generateCode(node->son[i]);
        else treeSons[i]=0;
    
    //proccess this node
    switch(node->type)
    {
       
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
            result = tac_join(treeSons[0], tac_create(TAC_MOV,node->symbol, treeSons[0]?treeSons[0]->target:0, 0)); //obs, o target de TAC_MOV eh o simbo q ja ta na tab d simbolos
            break;

        case ASTREE_LIT_SEQ:
            result = tac_join(treeSons[0], tac_create(TAC_LIT_SEQ,treeSons[1]?treeSons[1]->target:0,0,0));//especifico de vetor (lit_seq)
            break;

        case ASTREE_VARDEC:
            //fprintf(stderr,"VARDEC\n");
            result = tac_join(treeSons[1],tac_create(TAC_VARDEC, node->symbol, treeSons[1]?treeSons[1]->target:0, 0));
            break;
        
        case ASTREE_PTRDEC:
            //fprintf(stderr,"VARDEC\n");
            result = tac_join(treeSons[1],tac_create(TAC_PTRDEC, node->symbol, treeSons[1]?treeSons[1]->target:0, 0));
            break;

        case ASTREE_ARGSEQ:
            result = tac_join(treeSons[0],tac_create(TAC_ARG,treeSons[1]?treeSons[1]->target:0,0,0));
            break;

        case ASTREE_FUNCALL:
            //concatena argumentos com parametros. Obs, o target eh o retorno da funcao, para isso eh usado uma variavel temporaria
            result = tac_join(treeSons[0],tac_create(TAC_FUNCALL,makeTemp(),node->symbol,0));
            break;

        case ASTREE_VETCALL:
            result = makeVetcall(treeSons[0],node->symbol);
            break;

        case ASTREE_PTRADDR:
            //retorno da expressao de deref eh armazenado em uma temp
            result = tac_create(TAC_PTRADDR,makeTemp(),node->symbol,0);
            break;

        case ASTREE_PTRVALUE:    
            result = tac_create(TAC_PTRVALUE,makeTemp(),node->symbol,0);
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
            result = makeVetordec(treeSons[1],treeSons[2],node->symbol);
            break;

        case ASTREE_FUNDEC:
            //fprintf(stderr,"FUNDEC. Params: %p\n",treeSons[1]);
            result = makeFun(node->symbol,treeSons[1],treeSons[2],treeSons[3]);
            break;

        case ASTREE_PARAMSEQ:
            //fprintf(stderr,"PARAMSEQ\n");
		    result = tac_join(treeSons[0],treeSons[1]);
            break;
        

        case ASTREE_PARAM:
            result = tac_join(treeSons[0],tac_create(TAC_PARAM,node->symbol,0,0)); 
            break;

        case ASTREE_PTRPARAM:
            result = tac_create(TAC_PTRPARAM,node->symbol,0,0);
            break;

        case ASTREE_LOCALDECSEQ:
            result = tac_join(treeSons[0],treeSons[1]);
            break;

        case ASTREE_KWWORD:
            result = tac_create(TAC_TWORD,node->symbol,0,0);
            break;

        case ASTREE_KWBOOL:
            result = tac_create(TAC_TBOOL,node->symbol,0,0);
            break;

        case ASTREE_KWBYTE:
            result = tac_create(TAC_TBYTE,node->symbol,0,0);
            break;
        
        case ASTREE_PROGRAM:
            //fprintf(stderr,"PROGRAM\n");
            result= treeSons[0];
            break;

        case ASTREE_LIT_STRING:            
            result =  tac_create(TAC_LIT_STRING,node->symbol, 0, 0);
            break;

        case ASTREE_GLOBALSEQ:
            //fprintf(stderr,"GLOBALSEQ\n");
            result = tac_join(treeSons[0],treeSons[1]);
            break;

        case ASTREE_INPUT:            
            result = tac_join(treeSons[0],tac_create(TAC_INPUT,node->symbol, 0, 0));
            break;

        case ASTREE_OUTPUT:
            result = tac_join(treeSons[0],tac_create(TAC_OUTPUT,treeSons[0]?treeSons[0]->target:0,0,0));
            break;

        case ASTREE_RETURN:
            result = tac_join(treeSons[0],tac_create(TAC_RETURN,treeSons[0]?treeSons[0]->target:0,0,0));
            break;

        case ASTREE_PTR_ASS:
           result = tac_join(treeSons[0], tac_create(TAC_MOV,makeTemp(),node->symbol, treeSons[0]?treeSons[0]->target:0));
           break;

        case ASTREE_DEREF_ASS:
           result = tac_join(treeSons[0], tac_create(TAC_MOV,makeTemp(),node->symbol, treeSons[0]?treeSons[0]->target:0)); 
           break;

        case ASTREE_VET_ASS:           
            result = makeVetass(treeSons[0],treeSons[1],node->symbol);
            break;
 
        case ASTREE_EXPRESSION:
            result= makeExpression(treeSons[0],node->symbol);
            break;

        case ASTREE_OUTPUTSEQ:
            result=tac_join(treeSons[0],treeSons[1]);
            break;

        case ASTREE_IF:
            result = makeIfThen(treeSons[0],treeSons[1]);
            break;

        case ASTREE_IF_ELSE:
            result = makeIfThenElse(treeSons[0],treeSons[1],treeSons[2]);
            break;

        case ASTREE_LOOP:
            result = makeLoop(treeSons[0],treeSons[1]);
            break;

        case ASTREE_BLOCK:
            result = treeSons[0];
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
/*
        case ASTREE_NOT:
            result = makeBinop(treeSons[0], 0, TAC_NOT);
            break;
*/
        case ASTREE_COMMANDSEQ:
            result = tac_join(treeSons[0],treeSons[1]);
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
    nova1= tac_create(TAC_JFALSE,label,son0?son0->target:0,0); 

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

    /// Teste e desvio da condição
    tac_if = tac_create(TAC_JFALSE, hash_lbl_else, condicao?condicao->target:0, 0); // TAC_JZ ou TAC_IFELSE????
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
    tac_loop = tac_create(TAC_JFALSE, hash_lbl_end, condicao?condicao->target:0, 0); // TAC_JZ ou TAC_LOOP????
    tac_jmp_begin = tac_create(TAC_JMP, hash_lbl_begin, 0, 0);

    // Rótulos para marcar o bloco do comando
    tac_lbl_begin = tac_create(TAC_LABEL, hash_lbl_begin, 0, 0);
    tac_lbl_end = tac_create(TAC_LABEL, hash_lbl_end, 0, 0);
    //concatena label_begin com a tac da expressao da condicao, logo em seguida com a tac_loop (tac com o teste da condicao), logo em seguida com a tac dos comandos a serem executados caso seja true e logo em seguida com os a tac_jmp_begin (tac para recomeco do loop) e logo em seguida com a tac de fim do loop
    return tac_join(tac_join(tac_join(tac_join(tac_join(tac_lbl_begin, condicao), tac_loop), comandos), tac_jmp_begin), tac_lbl_end);
}

TAC * makeFun (HASH_NODE* symbol,TAC * son1, TAC* son2, TAC * son3 ){ //parametros eh o filho 1, bloco da funcao eh o filho 3

	TAC * begin;
	TAC * end;

	begin = tac_create(TAC_BEGINF,symbol,0,0);
	end = tac_create(TAC_ENDF,symbol,0,0);
    
   	return tac_join(tac_join(tac_join(tac_join(son1,begin),son2),son3),end);
}

TAC* makeVetcall(TAC * son0, HASH_NODE * symbol){
    TAC* result;
    result = tac_create(TAC_VETCALL, makeTemp() ,symbol,son0?son0->target:0);
    return result;
}

TAC * makeVetass(TAC * son0, TAC* son1, HASH_NODE * symbol){
    
    TAC * ladoesquerdo;
    TAC * ladodireito;
        
    //ladoesquerdo eh um vetcall. Aqui a gente cria esse vetcall, pois o analisador sintatico, por default, nao cria um vetcall como filho de um um vet_ass, mas sim apenas vetcall no lado direito de expressoes.

    ladoesquerdo = makeVetcall(son0,symbol);
    ladodireito = son1;
    return tac_join(ladoesquerdo, tac_create(TAC_MOV,ladoesquerdo?ladoesquerdo->target:0, ladodireito?ladodireito->target:0,0)); 

}

TAC * makeExpression (TAC* son0,HASH_NODE* symbol){ //parametros eh o filho 1, bloco da funcao eh o filho 3

	TAC * begin;
	TAC * end;

	begin = tac_create(TAC_BEGINEXP,symbol,0,0);
	end = tac_create(TAC_ENDEXP,symbol,0,0);
    
   	return tac_join(tac_join(son0,begin),end);
}

void * setTargetLitSeq(TAC*litseq,HASH_NODE * target){
    
    TAC* first;
    first = litseq;
    
    if(!first) return;
    
    while(first->type == TAC_LIT_SEQ){
        first->op1 = first->target;
        first->target = target;
        first=first->prev;
        if(!first) break;
    }
    
}

TAC * makeVetordec(TAC* son1, TAC * son2, HASH_NODE * symbol){
    
    
    setTargetLitSeq(son2,symbol); //seta target de todos elementos do vetor como o simbolo atual 
    return tac_join(son1,tac_join(son2,tac_create(TAC_VETORDEC, symbol, son1?son1->target:0, son2?son2->target:0)));

}


