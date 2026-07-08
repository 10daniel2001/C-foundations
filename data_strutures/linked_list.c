#include <stdio.h>
#include <stdlib.h>


/*Linked List ou lista ligada
  Conceito de lista ligada em C, para fins didadticos ultilizando ponteiros e estrutura
  
  concept the linked list in C, using pointers and structure
  */

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head_ref, int new_data) {
    // Allocate memory for a new node
    // Create a new node and assign data to it
    // alocando memoria para um novo no
    // criando um novo no e atribuindo dados a ele
    // head_ref e um ponteiro para o ponteiro do primeiro no da lista
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    // Print the linked list
    // imprimindo a lista ligada
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}