#include <stdio.h>
#include <stdlib.h>

/* Binary Tree or arvore binaria
*
*
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
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}