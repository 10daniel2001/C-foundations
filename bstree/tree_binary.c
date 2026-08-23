#include <stdio.h>
#include <stdlib.h>

/*Iniciando arvores binarias e arvores de busca neste diretorio
  Contém codigos de exemplos funcionais para esssa estrutura de dados

*/

//Neste struct contém uma variavl do tipo inteira para os dados
//É dois ponteiro que sera para no filhos direito e esquerdo
typedef struct Node {
    int data;
    struct Node* esquerda;
    struct Node* direita;
}Node ;

//Ponteiro para raiz
typedef Node* arvore;


//Funçâo de busca recursiva
Node* recursive(arvore raiz, int valor){
    if (raiz == NULL || raiz->data == valor)
    {
        return raiz;
        //caso esteja vazia ou o valor encontrado
    }

    if (valor < raiz->data)
    {
        //Se caso o valor seja menor que a raiz, busca recursiva para lado esquerdo
        return recursive(raiz->esquerda, valor);
    }
    
    return recursive(raiz->direita, valor);
    //Caso seja maior que a raiz entao busca ao lado esquerdo
}


// Funçao interaiva 
Node* interative(arvore raiz, int valor){
    Node* atual = raiz;

    while (atual != NULL || atual->data != valor)
    {
        //While verifica se a arvore nao esta vazia ou se ja tenha encontrado o valor 
        if (valor < atual->data)
        {
            return atual = atual->esquerda;
        }else{
            atual = atual->direita;
        }
        
    }
    return atual;
}


Node* criate_node(int valor){
    Node* new = (Node*)malloc(sizeof(Node));
    if (new != NULL)
    {
        new->data = valor;
        new->esquerda = NULL;
        new->direita = NULL;

    }
    return new;
}