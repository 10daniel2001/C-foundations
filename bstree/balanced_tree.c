#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* esquerdo;
    struct Node* direito;

}Node;

typedef Node arvore;

Node* criar_no(arvore raiz, int valor){
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL)
    {
        printf("Erro ao alocar espaço\n");
        return 1;
    }

    novo->data = valor;
    novo->esquerdo = NULL;
    novo->direito = NULL;


    return novo;
}