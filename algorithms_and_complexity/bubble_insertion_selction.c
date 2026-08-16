#include <stdio.h>
#include <stdlib.h>

// Exemplo representativo de uma estrutura onde exite nome modelo e identificaçao de varios carros
// E vou usar ordenaçao para deixa los organizado de acordo com id 
struct Cars{
    char name[20];
    char model[20];
    int id;
};

//Funçao para realizar trocas para o selection sort, bubble
void trocar(struct Cars* a, struct Cars *b){
    struct Cars temp = *a;
    *a = *b;
    *b = temp;
}

//Bubble sort
void bubble_sort(struct Cars list[], int n){
    int i, j;

        // For externo para percorre a lista

    for ( i = 0; i < n; i++)
    {
        // For interno para ordenar
           
        for ( j = 0; j < n-1-i; j++)
        {
           if (list[j].id > list[j+1].id)
           {
              trocar(&list[j], &list[j+1]);
              // Chamando funçao trocar para realizar as efetivas trocas
           }
           
        }
        
    }
    
}