#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    /*Está struct é a base da estrutura da árvore
      Dados será o dado que cada nó terá 
      Altura refere-sé a cada altura da subávore ate a raiz
      fator balanceamento é a difrença da alturas das duas subávores 
      Ponteiro esquerda refere ao lado esquerdo da árvore
      ponteiro para estruct Node

    */
    int dados;
    int altura;
    int falor_balanceamento;
    struct Node* esquerda;
    struct Node* direita;

}Node;

typedef Node* ArvaoreAvl;
// Ponteiro para a struct Node 

Node* criar_no(int valor){

    /*Aqui vamos allocar um espaço em mémoria tamanho referente a struct 
      Novo é um ponteiro para Node, que recebe um espaço em memoria do tamanho de Node
      Novo á chave para criar varios espaços em memória 
    */

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


Node* rotacao_direita(Node* raiz){
    if (raiz == NULL || raiz->esquerda == NULL)
    {
        return NULL;
    }
    Node* nova_raiz = raiz->esquerda;
    Node* subavore_temp = nova_raiz->direita;

    nova_raiz->direita = raiz;
    raiz->esquerda = subavore_temp;

    atualizar_altura(raiz);
    atualizar_altura(nova_raiz);
    return nova_raiz;
    
}

Node* rotacao_esquerda_avl(Node* raiz) {
    if (raiz == NULL || raiz->direita == NULL) {
        return raiz;  // Não é possível rotacionar
    }
    // Salva referências importantes
    Node* nova_raiz = raiz->direita;
    Node* subarvore_temp = nova_raiz->esquerda;
    // Executa a rotação
    nova_raiz->esquerda = raiz;
    raiz->direita = subarvore_temp;
    // Atualiza alturas
    atualizar_altura(raiz);
    atualizar_altura(nova_raiz);
    return nova_raiz;
}

Node* rotacao_direita_esquerda(Node* raiz){
    if (raiz == NULL || raiz->esquerda == NULL)
    {
        return raiz
    }

    
}



ArvaoreAvl inserir(ArvaoreAvl raiz, int valor){
    if (raiz == NULL)
    {
        return criar_no(valor);
    }
    if (valor < raiz->dados)
    {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }else if (valor > raiz->dados)
    {
        raiz->direita = inserir(raiz->direita, valor);
    }else {
        printf("Valor %d já existe na árvore\n", valor);
        return raiz;
    }
    
    atualizar_altura(raiz);
    return ;

    
}


void mostrar_resultado(){
    
}