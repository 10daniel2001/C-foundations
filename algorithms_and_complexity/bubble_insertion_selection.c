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

//Algoritmo Bubble sort
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

// Algoritmo selection sort
void selection_sort(struct Cars list[], int n){
    int i , j, indice_menor;
     // i e j sao casos bases dos laços for
     // indice menor guarda o menor elemento no indice 
    for ( i = 0; i < n-1; i++)
    {
        indice_menor = i;
        // indice menor inicializa com valores de i 

        for ( j = i+1; j < n; j++)
        {
            if (list[j].id > list[j+1].id)
            {
                indice_menor = j;
                //Pos verificaçao if se true o indice menor recebr o elemento j
            }
            
        }
        
        if (indice_menor != i)
        {
            trocar(&list[i], &list[indice_menor]);
        }
        
    }
    
}