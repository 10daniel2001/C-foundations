#include <stdio.h>
#include <stdio.h>

// Implentação da estrutura de árvore AVL
typedef struct NoAvl{
    int valor;
    int altura;
    int fator_balanceamento;
    struct NoAvl* esquerdo;
    struct NoAvl* direito;
}NoAvl;

struct NoAvl* Arvore_AVL;

int altura(NoAvl* no){
    if (no == NULL)
    {
        return -1;
    }
    return no->altura;
}

int fator_balanced(NoAvl *no){
    if (no == NULL)
    {
        return 0;
    }

    return fator_balanced(no->esquerdo) - fator_balanced(no->direito);
    
}
/*
Fator = 0: as subárvores têm alturas iguais (perfeitamente balanceado)
 
Fator = 1: a subárvore esquerda é uma unidade mais alta que a direita
 
Fator = -1: a subárvore direita é uma unidade mais alta que a esquerda
 
Fator > 1 ou < -1: violação da propriedade AVL (requer rebalanceamento)
*/

// Funçao para atualizar a altura de num nó
void atualizar_altura(NoAvl* no){
    if (no != NULL)
    {
        int altura_esquerda = altura(no->esquerdo);
        int altura_direita = altura(no->direito);
        no->altura = 1 + (altura_esquerda > altura_direita ? altura_esquerda : altura_direita);
        no->fator_balanceamento = fator_balanced(no); 
    }
    
}


double altura_maxima_teorica(int n) {
    if (n <= 0) return -1;
    return 1.44 * log2(n + 2) - 0.328;
}
// Função para analisar eficiência da árvore AVL
void analisar_eficiencia_avl(NoAvl* raiz) {
    if (raiz == NULL) {
        printf("Árvore vazia\n");
        return;
    }
    int num_nos = contar_nos_avl(raiz);
    int altura_atual = altura_no(raiz);
    double altura_teorica = altura_maxima_teorica(num_nos);
    double altura_ideal = log2(num_nos + 1) - 1;
    printf("=== Análise de Eficiência AVL ===\n");
    printf("Número de nós: %d\n", num_nos);
    printf("Altura atual: %d\n", altura_atual);
    printf("Altura ideal: %.2f\n", altura_ideal);
    printf("Altura máxima teórica: %.2f\n", altura_teorica);
    printf("Eficiência: %.2f%% da altura ideal\n", 
           (altura_ideal / altura_atual) * 100);
    if (verificar_propriedade_avl(raiz)) {
        printf("Status: Árvore AVL válida ✓\n");
    } else {
        printf("Status: Propriedade AVL violada ✗\n");
    }
}


/*Em uma árvore binária comum há um certo risco de se degenerar em inserçoes linear crescente ou decrescente pode se torna uma lista lígada
  operações que deveriam ser O(log n) virarem O(n).

  Já a árvore AVL se alto balançeia, impondo uma regra, para cada nó, a diferença de altura entre a suávore esquerda é a subávore direita não pode ser maior que 1
  

*/