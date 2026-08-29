#include <stdio.h>
#include <stdlib.h>


/*fase 01
  Criação da vine (espinha): transforma a árvore em uma lista ligada linear (vine) exclusivamente com filhos
  à direita, utilizando rotações à direita

  fase 02
  Balanceamento: converte a vine em uma árvore perfeitamente balanceada (ou quase balanceada, 
  dependendo do número de nós) por meio de rotações controladas à esquerda.

  Essa abordagem é eficiente, pois a criação da vine é linear em relação ao número de nós, e o balanceamento é logarítmico,
  resultando em uma complexidade geral de O(n) para o processo completo.

  ingles 
  creation of the vine (spine): transforms the tree into a linear linked list (vine) exclusively with
  right children, using right rotations
  balancing: converts the vine into a perfectly balanced tree (or almost balanced, depending on the number 
  of nodes)

  
*/


// O codigo e o mesmo dos outros arquivos 
// the code is the same as in the other files

typedef struct Node
{
    int data; // dados em inteiros 
    struct Node* esquerdo; // No esquerdo
    struct Node* direito;  // No direito
}Node;

// Árvore  um ponteiro para o No
typedef Node* Arvore;

Node* criar_no(int valor){
    Node* novo = (Node*)malloc(sizeof(Node));
    //Criando um espaço para um novo no

    if (novo != NULL){
        //Verificando se o espaço foi alocado corretamente 
    novo->data = valor;
    //O valor inserido ao parametro sera atribuido para No raiz
    novo->esquerdo = NULL; // Inicializando o Nó ou subávore esquerdo como vazio
    novo->direito = NULL; // Da mesma forma para o Nó ou subávore direita 
    }
    return novo;
    //Retorna um novo espaco ou Nó
}


/*Rotaçao a direita é basicamente pegar todos os nós da árvore e criar um lista ligada na subávore direita
  Uma lista lígada linear sem hierárquia 
  
  Iniciando com um paramétro, com o ponteiro raiz
  Um if paa verificar se a raiz esta vazia ou o no esuerdo esta vazio, caso verdadeiro retorna a raiz
  Abaixo de if, após ser false, segue a continuação 
  Um ponteiro chamado nova raiz é criado e recebe a raiza esquerda
  raiz esquerda recebe a nova raiz direita   
*/
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
    int altura = (int)floor(log2(n+1));
    return (1 << altura) - 1 ;
}

void balancear_vine(Arvore* raiz, int n){
    int m = calcular_arvore(n);
    int rotacoes = n - m;

    Node* pseudo_raiz = (Node*)malloc(sizeof(Node));
    pseudo_raiz->direito = *raiz;
    pseudo_raiz->esquerdo = NULL;
    Node* atual = pseudo_raiz;

    for (int i = 0; i < rotacoes; i++){
        if (atual->direito != NULL)
        {
            Node* temp = atual->direito;
            atual->direito = rotaçao_esquerda(temp);
            atual = atual->direito;
        }
        
    }

    while (m > 1){
        m /= 2;
        atual = pseudo_raiz;
        for (int i = 0; i < m; i++){
            if (atual->direito != NULL)
            {
                Node* temp = atual->direito;
                atual->direito = rotaçao_esquerda(temp);
                atual = atual->direito;
            }
            
        }
        
    }
    *raiz = pseudo_raiz->direito;
    free(pseudo_raiz);
}