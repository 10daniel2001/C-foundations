#include <stdio.h>
#include <stdlib.h>


/*fase 01
  Criação da vine (espinha): transforma a árvore em uma lista ligada linear (vine) exclusivamente com filhos
  à direita, utilizando rotações à direita

  fase 02
  Balanceamento: converte a vine em uma árvore perfeitamente balanceada (ou quase balanceada, 
  dependendo do número de nós) por meio de rotações controladas à esquerda.
*/


// O codigo e o mesmo dos outros arquivos 

typedef struct Node
{
    int data;
    struct Node* esquerdo;
    struct Node* direito;
}Node;

typedef Node* Arvore;

Node* criar_no(int valor){
    Node* novo = (Node*)malloc(sizeof(Node));

    if (novo != NULL){
    novo->data = valor;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    }
    return novo;
}

Arvore rotaçao_direita(Arvore raiz){
    if (raiz == NULL || raiz->esquerdo == NULL)
    {
        return raiz;
    }
    Node* nova_raiz = raiz->esquerdo;
    raiz->esquerdo = nova_raiz->direito;
    nova_raiz->direito = raiz;
    return nova_raiz;
    
}

Arvore rotaçao_direita(Arvore raiz){
    if (raiz == NULL || raiz->direito == NULL)
    {
        return raiz;
    }
    Node* nova_raiz = raiz->direito;
    raiz->direito = nova_raiz->esquerdo;
    nova_raiz->esquerdo = raiz;
    return nova_raiz;
}


// Faze 01 criaçao do vine 
int criar_vine(Arvore* raiz){
    int contador = 0;
    Node* pseudo_raiz = (Node*)malloc(sizeof(Node));
    pseudo_raiz->direito = *raiz;
    pseudo_raiz->esquerdo = NULL;
    Node* atual = pseudo_raiz;

    while (atual != NULL){
        if (atual->direito->esquerdo != NULL)
        {
            Node* temp = atual->direito;
            atual->direito = rotaçao_direita(temp);
        }else
        {
            atual = atual->direito;
            contador++;
        }
        
        
    }
    *raiz = pseudo_raiz->direito;
    free(pseudo_raiz);
    return contador;
}

//Balançeamento, cobertendo uma lista ligado e uma árvore balançeada
int calcular_arvore(int n){
    
}