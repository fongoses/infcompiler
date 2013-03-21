	typedef struct hashnode {
	int code;
	int type;
	struct hashnode *next;
} HASH_NODE;


#define HASH_SIZE 997

HASH_NODE* TABLE[HASH_SIZE];



int hashAddress(char * text){

	int address = 1;
	int i=0;
	for(i=0;i<strlen(text);i++)
		address = (address * text[i]) % HASH_SIZE +1;

	return address - 1;
}

//insert the node in the hash table 'TABLE', returning its pointer.
HASH_NODE * hashInsert(char * text, int type){

	HASH_NODE * node;
	int address = hashAddress(text);
	//calcs the address and allocates at the table
	node = (HASH_NODE*)malloc(sizeof(HASH_NODE));	
	//node->code = ??;
	node->type = type;
	node->next = (void*)0;
	
	//insert at the table
	if(TABLE[address] == (void*)0) {
		TABLE[address] = node;
		return node;
	}

	HASH_NODE * ptr;
	ptr = TABLE[address];

	while(ptr->next != (void*)0) ptr = ptr->next;//insert at the end of the list
	ptr->next = node;
	
	return node;	
}


