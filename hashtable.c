/**********************************************************************
 * HASHTABLE
 **********************************************************************
 * This library has functions to manipulate a simple hashtable
 **********************************************************************
 * Authors:
 * Luiz Gustavo Frozi de Castro e Souza (fongoses@gmail.com)
 * Mario Cesar Gasparoni Junior (mariogasparoni@gmail.com)
 **********************************************************************
 * Updates:
 * 24/03/2013
 * - Included hashInit(), hashPrint()
 **********************************************************************/

// STANDARD LIBs
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// HEADERS
#include "hashtable.h"

// GLOBAL VARs
HASH_NODE *Table[HASH_SIZE];

// FUNCTIONS
void hashInit() {
    int i;

    for(i = 0; i < HASH_SIZE; i++)
        Table[i] = (void *) 0;
}

int hashAddress(char *text) {
    int address = 1;
    int i = 0;

    for(i = 0; i < strlen(text); i++)
        address = ((address * text[i]) % HASH_SIZE) + 1;

    return address - 1;
}

HASH_NODE *hashInsert(char *text, int type) { // Insert the node in the hash table 'Table', returning its pointer.
    HASH_NODE *node;

    //if the token already exists , ignore its insertion
    if (hashFind(text) != (void*)0) return (void*)0; 

    int address = hashAddress(text);
    
    // Calc the address and allocates the node
    node = (HASH_NODE *) malloc(sizeof(HASH_NODE));

    node->text = (char *) calloc(strlen(text) + 1, sizeof(char));
    strcpy(node->text, text);

    node->type = type;

    node->next = (void *) 0;

    // Insert at the table
    if(Table[address] == (void *) 0) {
        // Normal insertion, no collision
        Table[address] = node;
    } else {
        // With collision, creates a list
        HASH_NODE *ptr;
        ptr = Table[address];

        // Searches for the last list node
        while(ptr->next != (void *) 0) 
            ptr = ptr->next;
        
        // Insert at the end of the list
        ptr->next = node;
    }
    return node;
}

HASH_NODE *hashAdd(char *text, int type) { // Insert the node in the hash table 'Table', returning its pointer.
    HASH_NODE *node;

    int address = hashAddress(text);
    
    // Calc the address and allocates the node
    node = (HASH_NODE *) malloc(sizeof(HASH_NODE));

    node->text = (char *) calloc(strlen(text) + 1, sizeof(char));
    strcpy(node->text, text);

    node->type = type;

    node->next = (void *) 0;

    // Insert at the table
    if(Table[address] == (void *) 0) {
        // Normal insertion, no collision
        Table[address] = node;
    } else {
        // With collision, creates a list
        HASH_NODE *ptr;
        ptr = Table[address];

        // Searches for the last list node
        while(ptr->next != (void *) 0) 
            ptr = ptr->next;
        
        // Insert at the end of the list
        ptr->next = node;
    }
    return node;
}
HASH_NODE *hashFind(char *text) { // Return the node that match with text, otherwise return 0
    HASH_NODE *node = (void *) 0;

    int address = hashAddress(text);
    int achou = 0;

    if(Table[address] != (void *) 0) {
        // Verify if the node match or the node is a list (collision)
        node = Table[address];
        if(strcmp(text, node->text)) {
            // Different strings, search in list (Collision)
            achou = 0;
            while((node->next != (void *) 0) && !achou) {
                node = node->next;
                achou = strcmp(text, node->text) == 0;
            }
            if(!achou)
                node = (void *) 0;
        } else {
            // Equal strings, node is the match
            achou = 1;
        }
    }

    return node;
}

void hashPrint() {
    HASH_NODE *node;

    int i;

    for(i = 0; i < HASH_SIZE; i++) {
        if(Table[i]) {
            printf("Table [%d]: ", i);
            for(node = Table[i]; node; node = node->next) {
                printf("Node(%s , %d) ", node->text, node->type);
            }
            printf("\n");
        }
    }
}

void hashPrintFull() {
    HASH_NODE *node;

    int i;

    for(i = 0; i < HASH_SIZE; i++) {
        printf("Table [%d]: ", i);
        for(node = Table[i]; node; node = node->next) {
            printf("Node(%s, %d) ", node->text, node->type);
        }
        printf("\n");
    }
}
