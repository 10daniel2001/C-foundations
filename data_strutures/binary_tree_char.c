#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Binary tree with character 
// Arvare binaria com caracteres

//typedef is used to create an alias for a data type. In this case, it is used to define a structure called Node that represents a node in a binary tree. The structure contains a character data field and two pointers to the left and right child nodes.
//typedef e usado para criar um alias para um tipo de dado. Neste caso, é usado para definir uma estrutura chamada Node que representa um nó em uma árvore binária. A estrutura contém um campo de dados do tipo caractere e dois ponteiros para os nós filhos esquerdo e direito.
typedef struct Node {
    char data;
    struct Node* left; // esquerda
    struct Node* right; // direita
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, char data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
    // Esta função insere um novo nó na árvore binária. ]
    //Se a raiz for nula, cria um novo nó com o dado fornecido. Caso contrário,
    // compara o dado com o valor do nó atual e decide se deve inserir à esquerda
    // ou à direita da árvore.
}