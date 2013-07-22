#ifndef HASH_HEADER
#define HASH_HEADER


typedef struct hash_node {
    char *text;
    int type;
    int dataType; //esse codigo eh setado pelo analisador sintatico, durante a construcao da arvore
    int decType;
    int lineNumber;
    char declared;
    int paramNum;
    struct hash_node *next;
   } HASH_NODE;

// Tamanho maximo da tabela hash
#define HASH_SIZE 997 

/* etapa4, valores a serem acrescentados na tabela de simbolos,
    para identificacao do tipo de uma variavel                                 
*/

#define DATATYPE_WORD 1 
#define DATATYPE_BYTE 2 
#define DATATYPE_BOOL 3  //boolean nao serah
#define DECTYPE_SCALAR 4
#define DECTYPE_VECTOR 5
#define DECTYPE_FUNCTION 6
#define DECTYPE_POINTER 7
#define DATATYPE_INT 8
#define DATATYPE_CHAR 9
#define DATATYPE_STRING 10
#define DATATYPE_ASSIGN 11
#define DATATYPE_VALID 12
#define DATATYPE_INVALID -1


#define DECTYPE_LABEL 13 //11/06
HASH_NODE * makeTemp(void);
void hashInit();
void initMe(); //adicionado( haviamos esquecido na etapa anterior)
int hashAddress(char *);
HASH_NODE *hashInsert(char *, int);
HASH_NODE *hashFind(char *);
void hashPrint();
void hashPrintFull();


#endif
