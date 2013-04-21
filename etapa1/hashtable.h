typedef struct hash_node {
    char *text;
    int type;
    struct hash_node *next;
} HASH_NODE;

// Tamanho maximo da tabela hash
#define HASH_SIZE 997 

void hashInit();
void initMe();
int hashAddress(char *);
HASH_NODE *hashInsert(char *, int);
HASH_NODE *hashFind(char *);
void hashPrint();
void hashPrintFull();
