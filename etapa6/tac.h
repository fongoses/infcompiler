#ifndef __TACH__
#define __TACH__

#include "hashtable.h"
#include "astree.h"


typedef struct tac {

    int type;
    HASH_NODE * target;
    HASH_NODE * op1;
    HASH_NODE * op2;
    struct tac * prev;
    struct tac * next;


} TAC;


#define TAC_ADD 1
#define TAC_MIN 2
#define TAC_MUL 3
#define TAC_DIV 4

#define TAC_SYMBOL 5
#define TAC_LIT_INT 6
#define TAC_MOV 7 //instrucao mov
#define TAC_JFALSE 8
#define TAC_LABEL 9

//BEGINFUN E ENDFUN estao definidos mais abaixo como BEGINF e ENDF
//#define TAC_BEGINFUN 10 //solicitado pelo pro. Deve haver tb o nome da funcao nesse elem da tac
//#define TAC_ENDFUN 11 // 
#define TAC_ARG 12 //argumento de funcao para ir em BEGINFUN

//para vetores
//#define TAC_VECTORWRITE 13 //quando vetor esta do lado esq do assign
//#define TAC_VECTORREAD 14 //quando vetor esta do lado dir do assign
#define TAC_VARDEC 15
#define TAC_VETORDEC 16
#define TAC_LIT_SEQ 17 //especifica de vetor

// Booleanos
#define TAC_LIT_TRUE 18
#define TAC_LIT_FALSE 19
#define TAC_LE 20
#define TAC_GE 21
#define TAC_EQ 22
#define TAC_NE 23
#define TAC_AND 24
#define TAC_OR 25
#define TAC_L 26
#define TAC_G 27
//#define TAC_NOT 28
#define TAC_LIT_CHAR 29
#define TAC_UMIN 30
#define TAC_JMP 31 // Desvio incondicional
//#define TAC_FUNDEC 32
#define TAC_BEGINF 33
#define TAC_ENDF 34
#define TAC_FUNCALL 35
#define TAC_LIT_STRING 36
#define TAC_PTRADDR 37
#define TAC_PTRVALUE 39
#define TAC_INPUT 40
#define TAC_VETCALL 41
#define TAC_PARAM 42
#define TAC_PTRPARAM 43
#define TAC_BEGINEXP 44
#define TAC_ENDEXP 45
#define TAC_OUTPUT 46
#define TAC_RETURN 47

//TAC para tipos (utilizado em parametros na declaracao de funcao)
#define TAC_TWORD 48
#define TAC_TBYTE 49
#define TAC_TBOOL 50


TAC *tac_create(int type, HASH_NODE * target, HASH_NODE *op1, HASH_NODE *op2);
TAC *tac_join(TAC *l1, TAC *l2);
TAC *tacReverse(TAC * last);

void print_tac_single(TAC *tac);
void print_tac(TAC *tac);
void print_tac_reverse(TAC *tac);

// Protótipos do genco.c
TAC *generateCode(ASTREE *node);
void generateASM(TAC * first);
TAC *makeBinop(TAC *treeSon0, TAC *treeSon1, int type);
TAC *makeIfThen(TAC *son0, TAC *son1);
TAC *makeFun(HASH_NODE *symbol, TAC * son1, TAC *son3 );
TAC *makeVetcall(TAC* son0, HASH_NODE *symbol );
TAC *makeExpression(TAC * son0, HASH_NODE * symbol);
TAC *makeVetass(TAC* son0,TAC * son1, HASH_NODE *symbol );
TAC* makeIfThen(TAC* son0, TAC* son1);
TAC* makeIfThenElse(TAC* son0, TAC* son1, TAC* son2);
TAC* makeLoop(TAC* son0, TAC* son1);
#endif
