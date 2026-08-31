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