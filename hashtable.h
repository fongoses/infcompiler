typedef struct hashnode {
	int code;
	int type;
	struct hashnode *next;
} HASH_NODE;


#define HASH_SIZE 997

int hashAddress(char*);
HASH_NODE * hashInsert(char*,int);
HASH_NODE * hashFind(char*);
void hashInit();
