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
    // Function to perform an inorder traversal of the binary tree,
    // função para realizar uma travessia em ordem da árvore binária
}

void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->data); // Free the duplicated string
        free(root);
    }
    // Function to free the memory allocated for the binary tree,
    // função para liberar a memória alocada para a árvore binária
}

int main() {
    Node *root = NULL;

    // Insert strings into the binary tree
    // Inserir strings na árvore binária
    // A Maior string vai para a direita e a menor para a esquerda
    // The largest string goes to the right and the smallest to the left
    insert(&root, "banana");
    insert(&root, "apple");
    insert(&root, "cherry");
    insert(&root, "date");
    insert(&root, "fig");
    insert(&root, "grape");

    printf("Inorder Traversal of the String Binary Tree:\n");
    inorderTraversal(root);

    freeTree(root);
    return 0;
}