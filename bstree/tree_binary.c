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


Node* create_node(int valor){
    Node* new = (Node*)malloc(sizeof(Node));
    if (new != NULL)
    {
        new->data = valor;
        new->esquerda = NULL;
        new->direita = NULL;

    }
    return new;
}

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
        printf("valor encontrado - %d -\n", resultado_recursive);
    }else{
        printf("Valor nâo encontrado\n");
    }

    Node* interative_busc = interative(raiz, 70);

    if (interative_busc != NULL)
    {
        printf("Busca interativa valor [%d] \n", interative_busc);
    }else{
        printf("Valor nao encontrado\n");
    }
    
    


}
