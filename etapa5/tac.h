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
    struct tac * next; // usado hoje: 11/06


} TAC;


#define TAC_ADD 1
#define TAC_MIN 2
#define TAC_MUL 3
#define TAC_DIV 4

#define TAC_SYMBOL 5
#define TAC_LIT_INT 6
#define TAC_MOV 7 //instrucao mov
#define TAC_JZ 8
#define TAC_LABEL 9
#define TAC_BEGINFUN 10 //solicitado pelo pro. Deve haver tb o nome da funcao nesse elem da tac
#define TAC_ENDFUN 11 // ||
#define TAC_ARG 12 //argumento de funcao para ir em BEGINFUN

//para vetores
#define TAC_VECTORWRITE 13 //quando vetor esta do lado esq do assign
#define TAC_VECTORREAD 14 //quando vetor esta do lado dir do assign
#define TAC_VARDEC 15
#define TAC_VETORDEC 16
#define TAC_LIT_SEQ 17

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
#define TAC_NOT 28

#define TAC_LIT_CHAR 29
#define TAC_UMIN 30


TAC * tac_create(int type, HASH_NODE * target, HASH_NODE *op1, HASH_NODE *op2);
TAC * generateCode(ASTREE * node);
void print_tac_single(TAC*tac);
TAC * tac_join(TAC *l1, TAC *l2);
#endif
