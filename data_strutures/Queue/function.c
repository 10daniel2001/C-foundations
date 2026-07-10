#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

void inicializar_init(Fila *f){
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;

}

int fila_cheia(Fila *f){
    return f->total == Tamanho;
}
int fila_vazia(Fila *f){
    return f->total == 0; 
}

void queue(Fila *f, Pessoa *p){
    if (fila_cheia(f))
    {
        printf("Fila esta cheia, nao e possivel inserir!\n");
        exit(1);
    }

    f->intens[f->fim] = *p;
    f->fim = (f->fim + 1) % Tamanho;
    f->total++;

}

void printss(Fila *f){
    printf("Mostrar Fila :\n");
    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx +1) % Tamanho)
    {
        printf("Nome >> %s -- Idade >> %d\n", f->intens[idx].nome, f->intens[idx].idade);
    }
    
}