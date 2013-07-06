typedef struct hash_node {
    char *text;
    int type;
    int dataType; // 09/05: tipo do nodo
    struct hash_node *next;
} HASH_NODE;

//alteracao professor aula 09/04
#ifndef HASH_HEADER
#define HASH_HEADER
#endif

// Tamanho maximo da tabela hash
#define HASH_SIZE 997 

/* etapa4, valores a serem acrescentados na tabela de simbolos,
    para identificacao do tipo de uma variavel                                 
*/


#define SYMBOL_SCALAR
#define SYMBOL_VECTOR
#define SYMBOL_FUNCTION
#define SYMBOL_POINTER
#define DATATYPE_WORD 1 
#define DATATYPE_BYTE 2 
#define DATATYPE_BOOL 3  //boolean nao serah

void hashInit();
void initMe(); //adicionado( haviamos esquecido na etapa anterior)
int hashAddress(char *);
HASH_NODE *hashInsert(char *, int);
HASH_NODE *hashFind(char *);
void hashPrint();
void hashPrintFull();
