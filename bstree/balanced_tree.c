#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node* esquerdo;
    struct Node* direito;

}Node;
//Sempre iniciando com uma struct para representar o NO, ou raiz da árvore, dados em inteiros

typedef Node* Arvore;
// Ponteiro arvore para a struct Node typedef para encurta a escrita
// Node criar no retorna um ponteiro novo, que aponta para um espaço na heap, cada espaço e um No que vai ocupar!

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

//Função de busca recursiva de valores na arvore
//01 verificando se a raiz e null OU se o No pai e igual ao valor buscado, caso true retorna a raiz
//02 se o valor buscado e menor que a raiz, faz um recursao ao lado esquerdo
//03 se nao for maior return recusivo para o lado direito 
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

// Funçâo para inserir nós na arvore
// 01 Sempre verificando se a arvore ou raiz e null, caso true retorna a funçao e cria com o valor inserido no parametro
// 02 verifica se o valor inserido ja esta na arvore, se sim retorna raiz, é ecoa um mensagem
// 03 Se o valor a ser inserido for menor que o Nò pai entao adiciona na subávore esquerda
// 04 Else se nao Insere na subávore direita é fim retorna a raiz 
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

// Funçâo que retorna inteiros, como calculo da altura da arvore
// 01 Verificando se a raiz e null, se true return -1 arvore vazia
// 02 altura esquerda recebe a funçao calcular altura com o parametro raiz acessando a subávore esquerda
// 03 altura direita recebe a funçao calcular altura com o parametro raiz acessando a subávore direita
// 04 retorna uma soma de 1+ com um operador ternario como as subávore maior 

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