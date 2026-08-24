#include <stdio.h>
#include <stdlib.h>


/*
Complexidade temporal
Melhor caso (árvore balanceada): O(log n).
Pior caso (árvore degenerada): O(n).
Caso médio: O(log n).

Complexidade espacial
Versão recursiva: O(h), em que h é a altura da árvore.
Versão iterativa: O(1).
*/

typedef struct Node
{
    int data;
    struct Node* esquerda;
    struct Node* direita;
}Node;

typedef Node* arvore;

Node* criar_no(int valor){

    Node* novo = (Node*) malloc(sizeof(Node));
    if (novo != NULL){
    novo->data = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    }

    return novo;
}


//inserir recursivo

/*
Algoritmo de inserção recursiva
Em uma árvore binária de busca, a operação de inserção deve manter a propriedade de ordenação 
enquanto adiciona novos elementos. O algoritmo segue o mesmo caminho que uma busca seguiria, 
mas quando encontra uma posição vazia NULL, cria um nó naquela posição
*/
arvore insertion_recursive(arvore raiz, int valor){
    if (raiz == NULL)
    {
        return criar_no(valor);
    }
    if (valor == raiz->data)
    {
        printf("Valores ja inserido %d\n", valor);
        return raiz;
    }
    if (valor < raiz->data)
    {
        raiz->esquerda = insertion_recursive(raiz->esquerda, valor);
    }else
    {
        raiz->direita = insertion_recursive(raiz->direita, valor);
    }
    
    
    return raiz;
    
}

arvore interative_insertion(arvore raiz, int valor){
    Node* novo = criar_no(valor);

    if (novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return raiz;
    }
    if (raiz == NULL)
    {
        return novo;
    }
    Node* atual = raiz;
    Node* pai = NULL;

    while (atual != NULL)
    {
        pai = atual;
        if (valor == atual->data)
        {
            printf("Valor %d já existe na árvore\n", valor);
            free(novo);
            return raiz;
        }
        if (valor < atual->data)
        {
            atual = atual->esquerda;
        }else
        {
            atual = atual->direita;
        }
        
    }
        if (valor < pai->data)
        {
            pai->esquerda = novo;
        }else
        {
            pai->direita = novo;
        }
        
    
    return raiz;

}


void free_arvore(arvore raiz){
    if (raiz == NULL) return;
    free_arvore(raiz->esquerda);
    free_arvore(raiz->direita);
    free(raiz);
    //Libera a memória alocada para a árvore
    //Frees the memory allocated for the tree
}

void em_ordem(arvore raiz){
    if (raiz == NULL) return;
    em_ordem(raiz->esquerda);
    printf("No pai--%d--\n", raiz->data);
    em_ordem(raiz->direita);
}

void visualizar(){
    arvore arvore1 = NULL;

    int valores_balanceados[] = {50, 30, 90, 20, 40, 100};
    int n1 = sizeof(valores_balanceados) / sizeof(valores_balanceados[0]);

    for (int i = 0; i < n1; i++)
    {
        arvore1 = insertion_recursive(arvore1, valores_balanceados[i]);
    }

    arvore arvore2 = NULL;
    int valores_crescentes[] = {20, 30, 40, 50, 90, 100};
    int n2 = sizeof(valores_crescentes) / sizeof(valores_crescentes[0]);
    for (int i = 0; i < n2; i++) {
        arvore2 = insertion_recursive(arvore2, valores_crescentes[i]);
    }
    printf("---------------------\n");
    em_ordem(arvore1);
    printf("------------------------\n");
    em_ordem(arvore2);

    free_arvore(arvore1);
    free_arvore(arvore2);
}

int main(){

    visualizar();
  
}