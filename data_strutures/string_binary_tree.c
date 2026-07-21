#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*String Binary Tree
  Arvore binaria de strings
  

*/

typedef struct node {
    char *data; // Pointer to string data
    struct node *left;
    struct node *right;
} Node;

Node* createNode(const char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = strdup(data); // Duplicate the string, duplicar a string
    newNode->left = NULL;                                
    newNode->right = NULL;
    return newNode;
}

void insert(Node **root, const char *data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    if (strcmp(data, (*root)->data) < 0) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
    // Function to insert a new string into the binary tree,
    // função para inserir uma nova string na árvore binária
    // Compara a nova string com a string do nó atual e decide se deve ir para a esquerda 
    // ou para a direita
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s\n", root->data);
        inorderTraversal(root->right);
    }
}