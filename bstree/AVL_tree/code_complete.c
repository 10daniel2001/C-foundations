#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int dados;
    int altura;
    int falor_balanceamento;
    struct Node* esquerda;
    struct Node* direita;

}Node;

typedef Node* ArvaoreAvl;

Node criar_no(int valor){
   Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL)
    {
        printf("Falha ao criar nó\n");
        return ;
    }
    novo->dados = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
}

int altura_no(Node *no){
    if (no == NULL)
    {
        printf("Erro de analisar altura\n");
        return;
    }
    return no->altura;
    
}