#include <stdio.h>
#include <stdlib.h>

/*Iniciando arvores binarias e arvores de busca neste diretorio
  Contém codigos de exemplos funcionais para esssa estrutura de dados

  Starting binary trees and search trees in this directory
  Contains functional example codes for this data structure

*/

//Neste struct contém uma variavl do tipo inteira para os dados
//É dois ponteiro que sera para no filhos direito e esquerdo
//In this struct contains a variable of type integer for the data
//It is two pointers that will be for the right and left child nodes
typedef struct Node {
    int data;
    struct Node* esquerda;
    struct Node* direita;
}Node ;

//Pointer to root
//Ponteiro para raiz
typedef Node* arvore;

//Function to search for a value in the binary tree
//Funçâo de busca recursiva
Node* recursive(arvore raiz, int valor){
    if (raiz == NULL || raiz->data == valor)
    {
        return raiz;
        //caso esteja vazia ou o valor encontrado
        //case if it is empty or the value found
    }

    if (valor < raiz->data)
    {
        //Se o valor for menor que o valor da raiz, chama a função recursivamente para a subárvore esquerda
        //If the value is less than the root value, call the function recursively for the left subtree
        return recursive(raiz->esquerda, valor);
    }
    
    return recursive(raiz->direita, valor);
    //Se o valor for maior que o valor da raiz, chama a função recursivamente para a subárvore direita
    //If the value is greater than the root value, call the function recursively for the right subtree
  
}


// Funçao interaiva 
//Iterative function
Node* interative(arvore raiz, int valor){
    Node* atual = raiz;
    //While verifies if the tree is not empty or if the value has already been found
    //Enquanto verifica se a arvore nao esta vazia ou se o valor ja foi encontrado
    while (atual != NULL && atual->data != valor)
    {
        //While verifies if the tree is not empty or if the value has already been found
        //Enquanto verifica se a arvore nao esta vazia ou se o valor ja foi encontrado
        if (valor < atual->data)
        {    
            //Interative search for the left subtree
            //Busca interativa para a subárvore esquerda
            atual = atual->esquerda;
        }else{
            atual = atual->direita;
            //Interative search for the right subtree
            //Busca interativa para a subárvore direita
        }
        
    }
    return atual;
    //Retorna o nó encontrado ou NULL se não encontrado
    //Returns the found node or NULL if not found
}


Node* create_node(int valor){
    Node* new = (Node*)malloc(sizeof(Node));
    //Aloca memória para um novo nó
    //Allocates memory for a new node
    if (new != NULL)
    {
        //Atribui o valor ao nó e inicializa os ponteiros para NULL
        //Assigns the value to the node and initializes the pointers to NULL
        new->data = valor;
        new->esquerda = NULL;
        new->direita = NULL;

    }
    return new;
}

// demonstration function
// Função de demonstração
void demonstrar_busca() {
    // Construindo uma árvore de exemplo
    arvore raiz = create_node(50);
    raiz->esquerda = create_node(40);
    raiz->direita = create_node(60);
    raiz->esquerda->esquerda = create_node(30);
    raiz->direita->direita = create_node(70);
    raiz->esquerda->direita = create_node(20);
    raiz->direita->esquerda = create_node(80);

    Node* resultado_recursive = recursive(raiz, 30);

    if (resultado_recursive != NULL)
    {
        printf("valor encontrado - %d -\n", resultado_recursive->data);
    }else{
        printf("Valor nâo encontrado\n");
    }

    Node* interative_busc = interative(raiz, 70);

    if (interative_busc != NULL)
    {
        printf("Busca interativa valor [%d] \n", interative_busc->data);
    }else{
        printf("Valor nao encontrado\n");
    }
    
}

void free_arvore(arvore raiz){
    if (raiz == NULL) return;
    free_arvore(raiz->esquerda);
    free_arvore(raiz->direita);
    free(raiz);
    //Libera a memória alocada para a árvore
    //Frees the memory allocated for the tree
}


int main(){
    demonstrar_busca();

    return 0;
}