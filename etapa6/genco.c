#include <stdio.h>
#include <string.h>
#include "tac.h"
#include "hashtable.h"
#include "y.tab.h"
int labelCount = 0;
extern HASH_NODE *Table[HASH_SIZE];
char tempString[STRING_MAX_SIZE];
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
            if(treeSons[0]) {
                if(treeSons[0]->type != TAC_ARG){
                    result=tac_join(tac_join(treeSons[0],tac_create(TAC_ARG,treeSons[0]?treeSons[0]->target:0,0,0)),tac_join(treeSons[1],tac_create(TAC_ARG,treeSons[1]?treeSons[1]->target:0,0,0)));
                    break;
                }       
            }           
            result = tac_join(treeSons[0],tac_join(treeSons[1],tac_create(TAC_ARG,treeSons[1]?treeSons[1]->target:0,0,0)));
            break;            
            

        case ASTREE_FUNCALL:
                       result = makeFuncall(treeSons[0],node->symbol);
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
            //result = tac_join(treeSons[0],tac_create(TAC_OUTPUT,treeSons[0],node->symbol,0,0);
            result = makeOutput(treeSons[0],makeTemp());
            break;

        case ASTREE_RETURN:
            result = tac_join(treeSons[0],tac_create(TAC_RETURN,treeSons[0]?treeSons[0]->target:0,0,0));
            break;

        case ASTREE_PTR_ASS:
           result = tac_join(treeSons[0], tac_create(TAC_MOV,makeTemp(),node->symbol, 0));
           break;

        case ASTREE_DEREF_ASS:
           result = tac_join(treeSons[0], tac_create(TAC_MOV,node->symbol,treeSons[0]?treeSons[0]->target:0,0)); 
           break;

        case ASTREE_VET_ASS:           
            result = makeVetass(treeSons[0],treeSons[1],node->symbol);
            break;
 
        case ASTREE_EXPRESSION:
            result= makeExpression(treeSons[0],makeTemp());
            break;

        case ASTREE_OUTPUTSEQ:                       
           /* 
            if(treeSons[0]) result = tac_join(tac_join(treeSons[0],tac_create(TAC_OUTPUTSEQ,treeSons[0]?treeSons[0]->target:0,0,0)),tac_create(TAC_OUTPUTSEQ,treeSons[1]?treeSons[1]->target:0,0,0));
            else result = tac_join(treeSons[1],tac_create(TAC_OUTPUTSEQ,treeSons[1]?treeSons[1]->target:0,0,0));
*/
            if(treeSons[0])
                if(treeSons[0]->type != TAC_OUTPUTSEQ){
                        result = tac_join(tac_join(treeSons[0],tac_create(TAC_OUTPUTSEQ,treeSons[0]->target,0,0)),tac_join(treeSons[1],tac_create(TAC_OUTPUTSEQ,treeSons[1]?treeSons[1]->target:0,0,0)));
                    break;
                    }
            result = tac_join(treeSons[0],tac_join(treeSons[1],tac_create(TAC_OUTPUTSEQ,treeSons[1]?treeSons[1]->target:0,0,0)));
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

    ladoesquerdo = son0;//makeVetcall(son0,symbol);
    ladodireito = son1;
    return tac_join(tac_join(ladoesquerdo,ladodireito),tac_create(TAC_VETMOV,symbol,ladoesquerdo?ladoesquerdo->target:0, ladodireito?ladodireito->target:0)); 

}

TAC * makeExpression (TAC* son0,HASH_NODE* symbol){ //parametros eh o filho 1, bloco da funcao eh o filho 3

	TAC * begin;
	TAC * end;

	begin = tac_create(TAC_BEGINEXP,symbol,0,0);
	end = tac_create(TAC_ENDEXP,symbol,0,0);
    
   	return tac_join(tac_join(begin,son0),end);
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

void * setTargetOutputSeq(TAC*outputseq,HASH_NODE * target){
    
    TAC* first;
    first = outputseq;
    
    if(!first) return;
    
    while(first->type == TAC_OUTPUTSEQ){
        first->op1 = first->target;
        first->target = target;
        first=first->prev;
        if(!first) break;
    }
    
}

TAC * makeVetordec(TAC* son1, TAC * son2, HASH_NODE * symbol){
    
    
    setTargetLitSeq(son2,symbol); //seta target de todos elementos do vetor como o simbolo atual 
    return tac_join(son2,tac_join(son1,tac_create(TAC_VETORDEC, symbol, son1?son1->target:0, son2?son2->target:0)));

}

TAC * makeFuncall(TAC * son0, HASH_NODE * symbol){

    TAC * newSon;
//concatena argumentos com parametros. Obs, o target eh o retorno da funcao, para isso eh usado uma variavel temporaria
    if(son0)
        if(son0->type != TAC_ARG){
            newSon = tac_join(son0,tac_create(TAC_ARG,son0->target,0,0));
            return tac_join(newSon,tac_create(TAC_FUNCALL,makeTemp(),symbol,0));            
        }
   
   return tac_join(son0,tac_create(TAC_FUNCALL,makeTemp(),symbol,0));
}

TAC * makeOutput(TAC* son0, HASH_NODE * symbol){
   TAC * newSon;  
 
   if(son0)
        if(son0->type != TAC_OUTPUTSEQ){
            newSon = tac_join(son0,tac_create(TAC_OUTPUTSEQ,son0->target,0,0));
            return tac_join(newSon,tac_create(TAC_OUTPUT,son0->target,0,0));
            }
   return tac_join(son0,tac_create(TAC_OUTPUT,son0->target,0,0));
}

//Etapa 6 
//ASSEMBLER.
void generateASM(TAC*first){
    FILE * fout;    
	fout=fopen("assembly.s","w+");

    generateDeclaratives(fout);
    generateASMVARDEC(fout,first); // 1ª varrida. Declaracao de variaveis e vetores
    generateASM_OTHERS(fout,first); //2 ª varrida. Gera resto do codigo
    
}


//nao eh recursiva..
void generateASM_OTHERS(FILE * fout,TAC * first){

	TAC * tac=0;   
    fprintf(fout,"\t.text\n");    
	for(tac=first;tac;tac=tac->next){
		switch(tac->type){

            case TAC_BEGINF: 
                fprintf(fout,
                "\t.globl %s\n"
                "\t.type  %s, @function\n"
                "%s:\n" //label da funcao
                ".LFB%d:\n"
                "\t.cfi_startproc\n"
                "\tpushl\t%%ebp\n"                                                   
                "\t.cfi_def_cfa_offset 8\n"
                "\t.cfi_offset 5, -8\n"                                   
                "\tmovl\t%%esp, %%ebp\n"                
                " \t.cfi_def_cfa_register 5\n"
                ,tac->target->text,tac->target->text,tac->target->text,labelCount);

            break;

            case TAC_ENDF:
                fprintf(fout,
                //"\tpopl\t%%ebp\n" //essa pop causa problema na main
                "\t.cfi_restore 5\n"
                "\t.cfi_def_cfa 4, 4\n"
                "\tret\n"
                "\t.cfi_endproc\n"
                ".LFE%d:\n"
                "\t.size\t%s, .-%s\n",labelCount,tac->target->text,tac->target->text);                
                labelCount++;
            break;                    

			case TAC_MOV:
                 if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,            
                    "\tmovl\t%s, %%eax\n"
                    "\tmovl\t%%eax, %s",tac->op1->text,tac->target->text);
                
                 if(tac->target->decType == DATATYPE_BYTE)
                    fprintf(fout,            
                    "\tmovb\t%s, %%eax\n"
                    "\tmovb\t%%eax, %s",tac->op1->text,tac->target->text);

                if(tac->target->decType == DATATYPE_BOOL)
                    fprintf(fout,            
                    "\tmovb\t%s, %%eax\n"
                    "\tmovb\t%%eax, %s",tac->op1->text,tac->target->text);

            
            break;
            
            case TAC_VETMOV:
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\tmovl\t$%s, %%eax\n"
                    "\tmovl\t%%eax, %s+%d\n",tac->target->text,tac->target->text,mySizeOf(tac->target)*atoi(tac->op1->text));
                 
                if(tac->target->decType == DATATYPE_BYTE)
                    fprintf(fout,
                    "\tmovb\t$%s, %%eax\n"
                    "\tmovb\t%%eax, %s+%d\n",tac->target->text,tac->target->text,mySizeOf(tac->target)*atoi(tac->op1->text));
                
                if(tac->target->decType == DATATYPE_BOOL)
                    fprintf(fout,
                    "\tmovb\t$%s, %%eax"
                    "\tmovb\t%%eax, %s+%d\n",tac->target->text,tac->target->text,mySizeOf(tac->target)*atoi(tac->op1->text));

            break;
 
           case TAC_VETCALL:
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\tmovl\t%s, %%eax\n"
                    "\tmovl\t%s(,%%eax,%d), %%eax\n"
                    "\tmovl\t%%eax,%s\n", //move para scarryTemporary
                    tac->op2->text,
                    tac->target->text,mySizeOf(tac->target),
                    tac->target->text);       
                break;
       
           

			case TAC_ADD: 	
				/*fprintf(fout,"  SOMA\n"/* movl    a, %%eax\n"
        				"addl    $2, %%eax"
        				"movl    %%eax, a");*/
			
			break;

            case TAC_INPUT:                
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\t$-16, %%esp\n"
                    "\tsubl\t$16, %%esp\n"
                    "\tmovl\t$%s, 4(%%esp)\n"
                    "\tmovl\t$.PoRcEnToD, (%%esp)\n"
                    "\tcall\tscanf\n",tac->target->text);
                   
                if(tac->target->decType == DATATYPE_BYTE)
                    fprintf(fout,
                    "\t$-16, %%esp\n"
                    "\tsubl\t$16, %%esp\n"
                    "\tmovl\t$:%s, 1(%%esp)\n"
                    "\tmovl\t$.PoRcEnToD, (%%esp)\n"
                    "\tcall\tscanf\n",tac->target->text); 
                
                if(tac->target->decType == DATATYPE_BOOL)
                    fprintf(fout,
                    "\t$-16, %%esp\n"
                    "\tsubl\t$16, %%esp\n"
                    "\tmovl\t$%s, 1(%%esp)\n"
                    "\tmovl\t$.PoRcEnToD, (%%esp)\n"
                    "\tcall\tscanf\n",tac->target->text); 

                if(tac->target->decType == DATATYPE_STRING){
                    clearTempString();
                    getLabelFromString(tempString,tac->target->text);
                    fprintf(fout,
                    "\t$-16, %%esp\n"
                    "\tsubl\t$16, %%esp\n"
                    "\tmovl\t$%s, 4(%%esp)\n"
                    "\tmovl\t$.PoRcEnToS, (%%esp)\n"
                    "\tcall\tscanf\n",tempString);

                    
                }
    
             break;
                

			case TAC_OUTPUT:
                if(tac->target->decType == DATATYPE_WORD)
                    fprintf(fout,
                    "\tmovl\t%s, %%eax\n"
                    "\tmovl\t%%eax, 4(%%esp)\n"
                    "\tmovl\t$.PoRcEnToD, (%%esp)\n"
                    "\tcall\tprintf\n"
                    "\tleave\n"
                    ,tac->target->text);
 

                if(tac->target->decType == DATATYPE_BYTE)
                    fprintf(fout,
                    "\tmovl\t%s, %%eax\n"
                    "\tmovl\t%%eax, 4(%%esp)\n"
                    "\tmovl\t$.PoRcEnToD, (%%esp)\n"
                    "\tcall\tprintf\n"
                    "\tleave\n",tac->target->text);
 
                if(tac->target->decType == DATATYPE_BOOL)
                    fprintf(fout,
                    "\tmovl\t%s, %%eax\n"
                    "\tmovl\t%%eax, 4(%%esp)\n"
                    "\tmovl\t$.PoRcEnToD, (%%esp)\n"
                    "\tcall\tprintf\n"
                    "\tleave\n",tac->target->text);
 
                if(tac->target->decType == DATATYPE_STRING)
                    clearTempString();
                    getLabelFromString(tempString,tac->target->text);
                    fprintf(fout,
                    "\tmovl\t$%s, (%%esp)\n"
                    //"\tmovl\t$.PoRcEnToS, (%%esp)\n"
                    "\tcall\tprintf\n"
                    "\tleave\n",tempString); 
							
			break;
        
                   
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
                fprintf(stderr,"TAC(TAC_SYMBOL,%s,null,null)\n",tac->target->text);
                break;

            case TAC_LIT_INT:
                fprintf(stderr,"TAC(TAC_LIT_INT,%s,null,null)\n",tac->target->text);
                break;
     
      
            case TAC_LIT_STRING:
                fprintf(stderr,"TAC(TAC_LIT_STRING,%s,null,null)\n",tac->target->text);
                break;

            case TAC_LIT_FALSE:
                fprintf(stderr,"TAC(TAC_LIT_FALSE,%s,null,null)\n",tac->target->text);
                break;

            case TAC_LIT_TRUE:
                fprintf(stderr,"TAC(TAC_LIT_TRUE,%s,null,null)\n",tac->target->text);
                break;

            case TAC_LIT_CHAR:
                fprintf(stderr,"TAC(TAC_LIT_CHAR,%s,null,null)\n",tac->target->text);
                break;

            case TAC_UMIN:
                fprintf(stderr,"TAC(TAC_UMIN,%s,null,null)\n",tac->target->text);
                break;

            
            case TAC_JMP:
                fprintf(stderr,"TAC(TAC_JMP,%s,null,null)\n",tac->target->text);
                break;
     
            case TAC_JFALSE:
                fprintf(stderr,"TAC(TAC_JFALSE,%s,null,null)\n",tac->target->text);
                break;       
             
            case TAC_PARAM:
                 fprintf(stderr,"TAC(TAC_PARAM,%s,null,null)\n",tac->target->text);
                 break;  

            case TAC_PTRPARAM:
                 fprintf(stderr,"TAC(TAC_PTRPARAM,%s,null,null)\n",tac->target->text);
                 break; 

            case TAC_ARG:
                 fprintf(stderr,"TAC(TAC_ARG,%s,null,null)\n",tac->target->text);
                 break;
     
           
            case TAC_FUNCALL:
                 fprintf(stderr,"TAC(TAC_FUNCALL,%s,%s,null)\n",tac->target->text,tac->op1?tac->op1->text:0);
                 break;

            case TAC_PTRADDR:
                 fprintf(stderr,"TAC(TAC_PTRADDR,%s,%s,null)\n",tac->target->text,tac->op1->text);
                 break;

            case TAC_PTRVALUE:
                 fprintf(stderr,"TAC(TAC_PTRVALUE,%s,%s,null)\n",tac->target->text,tac->op1->text);
                 break;

            case TAC_RETURN:
                 fprintf(stderr,"TAC(TAC_RETURN,%s,null,null)\n",tac->target->text);
                 break;
     
            case TAC_LABEL:
                 fprintf(stderr,"TAC(TAC_LABEL,%s,null,null)\n",tac->target->text);
                 break;
                      
			default: break;

		}
	}
}


int mySizeOf(HASH_NODE* symbol){

    if(!symbol) {
        return 0;
    }

        //fprintf(stderr,"Tipo da declaracao: %d\n",symbol->decType);
    switch(symbol->decType){ //no nosso trabalho, decType esta trocado por dataType, infelizemente.

        case DATATYPE_WORD: 
            return 4;
            break;

        case DATATYPE_BYTE: 
            return 1;
            break;

        case DATATYPE_BOOL: 
            return 1;
            break;

        default: return 0;
            
    }
}

void generateDeclaratives(FILE * fout){
    
    int i;
    HASH_NODE * node;
    fprintf(fout,
            ".data \n"
            ".PoRcEnToD:\n"
            "\t.string \"%%d\\12\\0\"\n");
    
    fprintf(fout,
            ".PoRcEnToS:\n"
            "\t.string \"%%s\\12\\0\"\n");
    

    for(i=0;i<HASH_SIZE;i++)
        for(node=Table[i];node;node=node->next)
            switch(node->type){
                //case SYMBOL_SCALAR:
                case SYMBOL_LIT_INTEGER:
                    fprintf(fout,
                    "%s:\n\t.value %s\n",
                    node->text,
                    node->text);
                    break;

                case SYMBOL_LIT_STRING:
                    clearTempString();
                    getLabelFromString(tempString,node->text);
                    fprintf(fout,
                    "%s:\n\t.string %s\n",
                    tempString,
                    node->text);          
                    break;
                
                case SYMBOL_LIT_CHAR:
                    fprintf(fout,
                    "%s:\n\t.byte %s\n",
                    node->text,
                    node->text);
                    break;

                case DATATYPE_TEMP: //Usei o datatype mesmo para indicar as scarryTemporary
                    fprintf(fout,
                    "%s:\n\t.value 0\n",
                    node->text);
                    break;
 
                
            }
            
}

//gera vardec e vetordec
void generateASMVARDEC(FILE * fout,TAC* first){

          TAC * tac=0;
          TAC * tempTac = 0;
          int i;
          if (!fout) return;

          for(tac=first;tac;tac=tac->next){
                switch(tac->type){
                    case TAC_VARDEC:
                        fprintf(fout,
                        "\n\t.globl  %s\n"        
                        "\t.data\n"
                        "\t.align 4\n"
                        "\t.type\t%s, @object\n"
                        "\t.size\t%s, %d\n"
                        "%s:\n"
                        "\t.long\t%s\n", tac->target->text,
                        tac->target->text,
                        tac->target->text,mySizeOf(tac->target),
                        tac->target->text,
                        (!strcmp(tac->op1->text,"TRUE"))?"1":((!strcmp(tac->op1->text,"FALSE"))?"0":tac->target->text));
                    break;
      
                    case TAC_VETORDEC:
                        if(tac->prev)
                            if(tac->prev->prev)
                                if(tac->prev->prev->type == TAC_LIT_SEQ){ //Esta inicializado!{
                            
                                    tempTac = tac->prev->prev;
                                        fprintf(fout,
                                            "\t.type\t%s, @object\n"
                                            "\t.size\t%s, %d\n"
                                            "%s:\n",tac->target->text,
                                            tac->target->text,mySizeOf(tac->target)*atoi(tac->op1->text),tac->target->text);
                                        
                                
                                    for(i=0;i<atoi(tac->op1->text);i++) tempTac = tempTac->prev;
                                    for(i=0;i<atoi(tac->op1->text);i++){        
                                        tempTac=tempTac->next;
                                        if(mySizeOf(tac->target)==4) {                                        
                                            fprintf(fout,
                                            "\t.long\t%s\n",tempTac->op1->text);
                                        }else{
                                            fprintf(fout,
                                             "\t.byte\t%s\n",tempTac->op1->text);
                                        }
                                        
                                    }
                                break;
                                }
                            
                        
                        fprintf(fout,
                        "\t.comm %s,%d",tac->target->text,atoi(tac->op1->text)*mySizeOf(tac->target));

                        break;
                            


                    default: break;
                }
         }
}




void generateASMALOCASTRING(TAC * first,FILE * fout){

	TAC * tac=0;
    
    if(!fout) return;
    
	for(tac=first;tac;tac=tac->next){
		switch(tac->type){

			
			case TAC_OUTPUTSEQ: 
                fprintf(fout,
                        ".STRING_ALOCADA"//%s:" //target (scarryTemporary da string)
                        ".string %s" //operando (valor) da string
                        ,tac->target->text //ver se eh no target ou no op1
                        ); 
                        

            break;
            
            default: break;

        }
    }
}

void getLabelFromString(char * dst,char * src){

    int i;
    int size;

    if ((!dst) || (!src)) return;
   

    size=strlen(src);
    if (size > STRING_MAX_SIZE) return;

    //substitui espacos em branco
    for(i=1;i<size-1;i++){  
        if(src[i] == '\0') break;
        if(src[i] == ' ') dst[i]= '_';
        else if(src[i] == '\\') dst[i]= '_';
        else dst[i] = src[i];       
    }

    //substitui aspas inicial e final
    dst[0]='_';
    dst[i-1]='_';

}

void clearTempString(){
    memset(tempString,0,STRING_MAX_SIZE);
}	
