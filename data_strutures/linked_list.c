#include <stdio.h>
#include <stdlib.h>


/*Linked List ou lista ligada
  Conceito de lista ligada em C, para fins didadticos ultilizando ponteiros e estrutura
  
  concept the linked list in C, using pointers and structure

  Ultiliazmos o conceitos de elos ligados, onde cada elemento da lista aponta para o proximo elemento da lista, e o ultimo elemento aponta para NULL, indicando o fim da lista.
  Como se fosse um vetor dinamico, mas com a diferenca de que cada elemento da lista pode ter um tamanho diferente, e o tamanho da lista pode crescer ou diminuir dinamicamente.
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

void freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL; // Initialize the head of the linked list to NULL
                              // Inicializando o ponteiro do primeiro no da lista ligada para NULL

    // Insert elements into the linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);


    // Print the linked list
    printList(head);


    freeList(head); // Free the allocated memory for the linked list
    // Sempre liberando para que nao haja vazamento de memoria, liberando a memoria alocada para a lista ligada

    return 0;
}