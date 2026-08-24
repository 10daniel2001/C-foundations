#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* esquerdo;
    struct Node* direito;

}Node;

typedef Node* Arvore;

Node* criar_no(int valor){
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo != NULL)
    {
    novo->data = valor;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    }

    return novo;
}

int calcular_altura(Arvore raiz){
    if (raiz == NULL)
    {
        return -1; // arvores vazia tem -1
    }
    int altura_esquerda = calcular_altura(raiz->esquerdo);
    int altura_direita = calcular_altura(raiz->direito);
    return 1 + (altura_esquerda > altura_direita) ? altura_esquerda : altura_direita;
    
}
int fator_balanceamento(Arvore raiz){
    if (raiz == NULL)
    {
        return 0;
    }
    return calcular_altura(raiz->esquerdo) - calcular_altura(raiz->direito);
    
}