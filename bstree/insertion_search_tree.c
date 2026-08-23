#include <stdio.h>
#include <stdlib.h>


/*


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
        
    
    return novo;

}


void free_arvore(arvore raiz){
    if (raiz == NULL) return;
    free_arvore(raiz->esquerda);
    free_arvore(raiz->direita);
    free(raiz);
    //Libera a memória alocada para a árvore
    //Frees the memory allocated for the tree
}
