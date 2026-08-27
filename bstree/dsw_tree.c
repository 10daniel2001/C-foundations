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


