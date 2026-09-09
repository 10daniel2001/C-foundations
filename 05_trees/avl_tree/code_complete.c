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

// Tipo: Ponteiro para a raiz da árvore
typedef Node* ArvoreAvl;

// Declarações antecipadas das funções
Node* rotacao_direita(Node* raiz);
Node* rotacao_esquerda_avl(Node* raiz);
Node* rotacao_direita_esquerda(Node* raiz);
Node* rotacao_esquerda_direita(Node* raiz);
void atualizar_altura(Node* no);
int fator_balanceamento(Node* no); 

Node* criar_no(int valor){

    /*Aqui vamos allocar um espaço em mémoria tamanho referente a struct 
      Novo é um ponteiro para Node, que recebe um espaço em memoria do tamanho de Node
      Novo á chave para criar varios espaços em memória, onde irá armazena ponteiros e dados 
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

//Funçao para saber a altura da árvore 

// Função para calcular a altura de um nó
int altura_no(Node *no){
    // Se o nó é nulo, retorna altura 0
    if (no == NULL)
    {
        return 0;
    }
    // Retorna a altura armazenada no nó
    return no->altura;
    
}

// Calcula o fator de balanceamento (diferença de altura entre subárvores)
int fator_balanceamento(Node* no){
    // Se o nó é nulo, retorna 0
    if (no == NULL)
    {
        return 0;
    }

    // Fator = altura esquerda - altura direita
    return altura_no(no->esquerda) - altura_no(no->direita);
    
}


// Função que verifica e aplica as rotações necessárias
Node* balancear(ArvoreAvl raiz){

    if (raiz == NULL)
    {
        return raiz;
    }

    // Calcula o fator de balanceamento
    int fator = fator_balanceamento(raiz);

    // Caso LL: Desbalanceamento à esquerda-esquerda
    if (fator > 1 && fator_balanceamento(raiz->esquerda) >= 0)
    {
        return rotacao_direita(raiz);
    }
    // Caso RR: Desbalanceamento à direita-direita
    if (fator < -1 && fator_balanceamento(raiz->direita) <= 0)
    {
        return rotacao_esquerda_avl(raiz);
    }
    // Caso LR: Desbalanceamento à esquerda-direita
    if (fator > 1 && fator_balanceamento(raiz->esquerda) < 0) {
        return rotacao_esquerda_direita(raiz);
    }
    // Caso RL: Desbalanceamento à direita-esquerda
    if (fator < -1 && fator_balanceamento(raiz->direita) > 0) {
        return rotacao_direita_esquerda(raiz);
    }
    // Nó já está balanceado, retorna como está
    return raiz;
    
}

void atualizar_altura(Node* no){
    if (no != NULL)
    {
        // Pega a altura da subárvore esquerda
        int altura_esquerda = (no->esquerda == NULL) ? 0 : no->esquerda->altura;
        // Pega a altura da subárvore direita
        int altura_direita = (no->direita == NULL) ? 0 : no->direita->altura;
        // Calcula a altura do nó atual (máximo das duas + 1)
        no->altura = 1 + (altura_esquerda > altura_direita ? altura_esquerda : altura_direita);
        // Atualiza o fator de balanceamento
        no->falor_balanceamento = fator_balanceamento(no);  
    }
    
}


// Rotação simples para a direita (caso LL)
Node* rotacao_direita(Node* raiz){
    // Verifica se consegue rotacionar
    if (raiz == NULL || raiz->esquerda == NULL)
    {
        return raiz;
    }
    // O nó esquerdo vira a nova raiz
    Node* nova_raiz = raiz->esquerda;
    // Salva o filho direito do nó esquerdo
    Node* subavore_temp = nova_raiz->direita;

    // Realiza a rotação
    nova_raiz->direita = raiz;
    raiz->esquerda = subavore_temp;

    // Atualiza as alturas dos nós
    atualizar_altura(raiz);
    atualizar_altura(nova_raiz);
    // Retorna a nova raiz
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

// Rotação dupla direita-esquerda (caso RL)
Node* rotacao_direita_esquerda(Node* raiz){
    // Verifica se consegue fazer a rotação
    if (raiz == NULL || raiz->direita == NULL)
    {
        return raiz;
    }

    // Primeiro rotaciona a direita para a esquerda
    raiz->direita = rotacao_esquerda_avl(raiz->direita);
    // Depois rotaciona o resultado para a direita
    return rotacao_esquerda_avl(raiz);

}
Node* rotacao_esquerda_direita(Node* raiz){
        // Verifica se consegue fazer a rotação
        if (raiz == NULL || raiz->esquerda == NULL)
        {
            return raiz;
        }

        // Primeiro rotaciona a esquerda
        raiz->esquerda = rotacao_esquerda_avl(raiz->esquerda);
        // Depois rotaciona a direita
        return rotacao_direita(raiz);
        
}

// Insere um novo valor na árvore AVL
ArvoreAvl inserir(ArvoreAvl raiz, int valor){
    // Se a árvore está vazia, cria um novo nó
    if (raiz == NULL)
    {
        return criar_no(valor);
    }
    // Se o valor é menor, vai para a esquerda
    if (valor < raiz->dados)
    {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    // Se o valor é maior, vai para a direita
    else if (valor > raiz->dados)
    {
        raiz->direita = inserir(raiz->direita, valor);
    }
    // Se o valor já existe, não insere
    else {
        printf("Valor %d já existe na árvore\n", valor);
        return raiz;
    }
    
    // Atualiza a altura do nó atual
    atualizar_altura(raiz);
    // Balanceia a árvore se necessário
    return balancear(raiz);

    
}


void mostrar_resultado(){
    // Inicializa a raiz como nula
    ArvoreAvl raiz = NULL;
    // Array com valores que serão inseridos
    int valores[] = {30, 20, 40, 10, 25, 35, 50};
    int tamanho = sizeof(valores) / sizeof(valores[0]); 
    
    // Insere cada valor na árvore
    for (int i = 0; i < tamanho; i++)
    {
        raiz = inserir(raiz, valores[i]);
    }   

    // Mostra mensagem de sucesso
    printf("Árvore AVL construída com sucesso!\n");
    // Lista todos os valores inseridos
    for (int i = 0; i < tamanho; i++)
    {
        printf("Valor %d inserido na árvore.\n", valores[i]);
    }
}

int main() {
    mostrar_resultado();
    return 0;
}