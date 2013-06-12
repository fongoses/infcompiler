typedef struct hash_node {
    char *text;
    int type;
    int dataType; //esse codigo eh setado pelo analisador sintatico, durante a construcao da arvore
    int lineNumber;
    char declared;
    struct hash_node *next;
   } HASH_NODE;

#ifndef HASH_HEADER
#define HASH_HEADER
#endif
// Tamanho maximo da tabela hash
#define HASH_SIZE 997 

/* etapa4, valores a serem acrescentados na tabela de simbolos,
    para identificacao do tipo de uma variavel                                 
*/

#define DATATYPE_WORD 1 
#define DATATYPE_BYTE 2 
#define DATATYPE_BOOL 3  //boolean nao serah
#define DATATYPE_SCALAR 4
#define DATATYPE_VECTOR 5
#define DATATYPE_FUNCTION 6
#define DATATYPE_POINTER 7
#define DATATYPE_INT 8
#define DATATYPE_CHAR 9
#define DATATYPE_STRING 10

void hashInit();
void initMe(); //adicionado( haviamos esquecido na etapa anterior)
int hashAddress(char *);
HASH_NODE *hashInsert(char *, int);
HASH_NODE *hashFind(char *);
void hashPrint();
void hashPrintFull();
