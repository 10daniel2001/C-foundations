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