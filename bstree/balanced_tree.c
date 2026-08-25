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

Node* busca_recursiva(Arvore raiz, int valor){
    if (raiz == NULL || raiz->data == valor)
    {
        return raiz;
    }
    if (valor < raiz->data)
    {
        return busca_recursiva(raiz->esquerdo, valor);
    }
    
    return busca_recursiva(raiz->direito, valor);
    
}

Arvore inserir(Arvore raiz, int valor){
    if (raiz == NULL)
    {
        return criar_no(valor);
    }
    if (valor == raiz->data)
    {
        printf("Valor ja inserido %d\n", valor);
        return raiz;
    }
    if (valor < raiz->data)
    {
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    }else{
        raiz->direito = inserir(raiz->direito, valor);
    }
    
    return raiz;
    
}

int calcular_altura(Arvore raiz){
    if (raiz == NULL)
    {
        return -1; // arvores vazia tem -1
    }
    int altura_esquerda = calcular_altura(raiz->esquerdo);
    int altura_direita = calcular_altura(raiz->direito);
    return 1 + (altura_esquerda > altura_direita ? altura_esquerda : altura_direita);
    
}
int fator_balanceamento(Arvore raiz){
    if (raiz == NULL)
    {
        return 0;
    }
    return calcular_altura(raiz->esquerdo) - calcular_altura(raiz->direito);
    
}

void free_arvore(Arvore raiz){
    if (raiz == NULL) return;
    free_arvore(raiz->esquerdo);
    free_arvore(raiz->direito);
    free(raiz);
    //Libera a memória alocada para a árvore
    //Frees the memory allocated for the tree
}
void in_rdem(Arvore raiz){
    if (raiz == NULL) return;
    in_rdem(raiz->esquerdo);
    printf("--%d--\n", raiz->data);
    in_rdem(raiz->direito);
}


void montar_tree(){
    Arvore raiz = criar_no(50);
    raiz->esquerdo = criar_no(30);
    raiz->direito = criar_no(80);
    raiz->direito->direito = criar_no(65);
    raiz->esquerdo->esquerdo = criar_no(22);
    raiz->esquerdo->direito = criar_no(20);
    raiz->direito->esquerdo = criar_no(96);


    in_rdem(raiz);

    int altura = calcular_altura(raiz);
    printf("Altura da arvore e > %d\n", altura);
    int fator_ba = fator_balanceamento(raiz);
    printf("Fator de balanceamento e > %d\n", fator_ba);


    free_arvore(raiz);
}

int main(){

    montar_tree();
}