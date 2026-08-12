#include <stdio.h>


/*Recursuve insertion sort, um algoritmo de ordenaçao 

*/


void insertion_sort(int vetor[], int n){
    if (n <= 1)
    return;

    insertion_sort(vetor, n-1);

    int key = vetor[n-1];
    int jj = n-2;

    while (jj >= 0 && vetor[jj] > key )
    {
        vetor[jj+1] = vetor[jj];
        jj--;
    }
   
    vetor[jj+1] = key;
    
}

