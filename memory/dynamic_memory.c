#include <stdio.h>
#include <stdlib.h>

/* Dynamic Memory Allocation 
   Alocaçao de memoria dinamica
   
 Conceito geral sobre memoria dinamica, criar um espaco em memoria durante a execucao do programa
 malloc cria um bloco de memoria dinamica, calloc cria um bloco de memoria dinamica e inicializa com zeros, realloc redimensiona um bloco de memoria dinamica 
 
 Memoria dinamica e muito ultilizada atualmente entender os conceitos  e ensecial para mim
 
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 */


 int main(){
    int* memoria_dinamica;
    memoria_dinamica = (int*) malloc(5 * sizeof(int)); // Alocaçao de memoria dinamica para 5 inteiros
    if(memoria_dinamica == NULL){
        printf("Erro ao alocar memoria dinamica\n");
        return 1;
    }

    //Inializando a memoria alocada dinamicamente com valores
    memoria_dinamica[0] = 10;
    memoria_dinamica[1] = 20;
    memoria_dinamica[2] = 30;
    memoria_dinamica[3] = 40;  
    memoria_dinamica[4] = 50;

    for(int i = 0; i < 5; i++){
        printf("memoria_dinamica[%d] = %d\n", i, memoria_dinamica[i]);
    }

    free(memoria_dinamica); // Libera a memoria alocada

    // Memoria pode conter lixo de memoria, por isso e importante inicializar a memoria alocada dinamicamente


    int *memoria_dinamica_calloc;
    memoria_dinamica_calloc = (int*) calloc(5, sizeof(int)); // Alocaçao de memoria dinamica para 5 inteiros e inicializa com zeros
    if(memoria_dinamica_calloc == NULL){
        printf("Erro ao alocar memoria dinamica\n");
        return 1;
    
    }

    for(int i = 0; i < 5; i++){
        printf("memoria_dinamica_calloc[%d] = %d\n", i, memoria_dinamica_calloc[i]);
    }   

        free(memoria_dinamica_calloc);

    // Memoria inicializada com calloc, nao contem lixo de memoria, por isso e importante inicializar a memoria alocada dinamicamente


    int vetor[5] = {1, 2, 3, 4, 5}; // Memoria estaticamente alocada, nao pode ser redimensionada
  
    for(int i = 0; i < 5; i++){
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }   
    // Nao necessario liberar memoria estaticamente alocada, pois ela e liberada automaticamente quando a funcao termina

    return 0;
 }