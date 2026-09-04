#include <stdio.h>
#include <stdlib.h>

// Em ingles 
// Example of a structure where there is a name, model, and identification of various cars
// struct representing a car with name, model, and id
// function to perform swaps for selection sort and bubble sort
// Function bubble_sort implements the bubble sort algorithm to sort an array of Cars based on their id
// Function selection_sort implements the selection sort algorithm to sort an array of Cars based on their id
// function insertion_sort implements the insertion sort algorithm to sort an array of Cars based on their id

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

// Algoritmo insertion sort
// If para condição de parada, se n for menor ou igual a 1, retorna
void insertion_sort(struct Cars list[], int n){
    if (n <= 1)
    // condition of stopping the recursion,
    // if n is less than or equal to 1, return
    return;
   
    insertion_sort(list, n-1);
    // Recursive call to insertion_sort with n-1, reducing the size of the list to be sorted

    int key = list[n-1].id; // key receives the id of the last element in the current sublist
    // key e inicializado com o id do ultimo elemento da sublista atual
    int jj = n-2; // jj is initialized to the index of the second last element in the current sublist
    // jj e inicializado com o indice do penultimo elemento da sublista atual

    while (jj >= 0 && list[jj].id > key)
    // While loop to find the correct position for key in the sorted sublist
    // O while loop procura a posiçao correta para key na sublista ordenada
    // jj >= 0 checks if we have not reached the beginning of the list
    // list[jj].id > key checks if the current element is greater than key
    // Se jj >= 0 verifica se nao chegamos ao inicio da lista
    // list[jj].id > key verifica se o elemento atual e maior que key

    {
        list[jj+1] = list[jj];
        jj--;
    }
    list[jj+1].id = key;

}

int main(){
    struct Cars list[] = {
        {"CarA", "ModelX", 5},
        {"CarB", "ModelY", 3},
        {"CarC", "ModelZ", 8},
        {"CarD", "ModelW", 1},
        {"CarE", "ModelV", 4}
    };
    int n = sizeof(list)/sizeof(list[0]);

    printf("Original list of cars:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Model: %s, ID: %d\n", list[i].name, list[i].model, list[i].id);
    }

    insertion_sort(list, n);

    printf("\nSorted list of cars by ID:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Model: %s, ID: %d\n", list[i].name, list[i].model, list[i].id);
    }

    return 0;
}