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

Node* criar_no(int valor){
   Node* novo = (Node*)malloc(sizeof(Node));
    if (novo != NULL)
    {
    novo->dados = valor;
    novo->altura = 0;
    novo->falor_balanceamento = 0;
    novo->esquerda = NULL;
    novo->direita = NULL;
    }

    return novo;
}

ArvaoreAvl inserir(ArvaoreAvl* raiz, int valor){
    if (raiz == NULL)
    {
        return criar_no(valor);
    }
    
    
}

int altura_no(Node *no){
    if (no == NULL)
    {
        printf("Erro de analisar altura\n");
        return;
    }
    return no->altura;
    
}

int fator_balanceamento(Node* no){
    if (no == NULL)
    {
        printf("Erro de analisar fb\n");
        return;
    }

    return fator_balanceamento(no->esquerda) - fator_balanceamento(no->direita);
    
}

void atualizar_altura(Node* no){
    if (no != NULL)
    {
        int altura_esquerda = no->esquerda;
        int altura_direita = no->direita;
        no->altura = 1 + (altura_esquerda > altura_direita ? altura_esquerda : altura_direita);
        no->falor_balanceamento = fator_balanceamento(no);  
    }
    
}

void mostrar_resultado(){
    
}