#include <stdio.h>

#include "hashtable.h"

int main(int argc, char *argv[]) {
    HASH_NODE *node;
    
    printf("\n\n\nTeste do hashInit(). Lista Vazia Inicializada...\n");
    hashInit();
    hashPrintFull();

    printf("\n\n\nTeste do hashInsert(). Adicionados A, A, A, AA, B, teste\n");
    hashInsert("A", 11);
    hashInsert("A", 12);
    hashInsert("A", 13);
    hashInsert("AA", 20);
    hashInsert("B", 30);
    hashInsert("teste", 40);
    hashPrint();

    printf("\n\n\nTeste do hashAddress()\n");
    printf("hashAddress(A) = %d\n", hashAddress("A"));
    printf("hashAddress(A) = %d\n", hashAddress("A"));
    printf("hashAddress(A) = %d\n", hashAddress("A"));
    printf("hashAddress(AA) = %d\n", hashAddress("AA"));
    printf("hashAddress(B) = %d\n", hashAddress("B"));
    printf("hashAddress(teste) = %d\n", hashAddress("teste"));
    hashPrint();
    
    printf("\n\n\nTeste do hashFind()\n");
    node = hashFind("A");
    if(node) printf("Tipo de %s: %d\n", node->text, node->type); else printf("Nao encontrado\n");
    node = hashFind("teste");
    if(node) printf("Tipo de %s: %d\n", node->text, node->type); else printf("Nao encontrado\n");
    node = hashFind("AA");
    if(node) printf("Tipo de %s: %d\n", node->text, node->type); else printf("Nao encontrado\n");
    node = hashFind("B");
    if(node) printf("Tipo de %s: %d\n", node->text, node->type); else printf("Nao encontrado\n");
    node = hashFind("A");
    if(node) printf("Tipo de %s: %d\n", node->text, node->type); else printf("Nao encontrado\n");
    node = hashFind("X");
    if(node) printf("Tipo de %s: %d\n", node->text, node->type); else printf("Nao encontrado\n");

}
