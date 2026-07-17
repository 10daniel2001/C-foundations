#include <stdio.h>
#include <stdlib.h>

/* Binary Tree or arvore binaria
*
*Representa uma estrutura de dados em que cada nó tem no máximo dois filhos, geralmente chamados de filho esquerdo e filho direito.
*
*
*
*/

struct Node {
    int data; // valor
    struct Node* left; // esquerda
    struct Node* right; // direita
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    //Craiando um novo nó e alocando memória para ele
    // Inicializando os valores do nó
    // Definindo o valor do nó, e os ponteiros para os filhos como NULL
    // retornando o novo nó criado
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}