typedef struct hash_node {
    char *text;
    int type;
    struct hash_node *next;
} HASH_NODE;

//alteracao professor aula 09/04
#ifndef HASH_HEADER
#define HASH_HEADER
#endif

// Tamanho maximo da tabela hash
#define HASH_SIZE 997 

void hashInit();
int hashAddress(char *);
HASH_NODE *hashInsert(char *, int);
HASH_NODE *hashFind(char *);
void hashPrint();
void hashPrintFull();
