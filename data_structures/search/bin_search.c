#include <stdio.h>
#include <stdlib.h>

/*Busca binaria
  binary search
  
  */

void search(int vetor[], int n, int target){
    int i, j;
   
    for ( i = 0; i < n; i++)
    {
        if (vetor[i] == target)
        {
            printf("Target %d\n", vetor[i]);
          
        }
        
    }
    // Function to perform a binary search on an array to find a target value.
    // Função para realizar uma busca binária em um array para encontrar um valor alvo.
    
}

int main(){
    int veto[] = {2,5,4,8,9,7};
    int n = sizeof(veto)/sizeof(veto[0]);
    // Function to calculate the size of the array.
    // Função para calcular o tamanho do array.
    int target = 2;

    printf("Busca binaria\n");
    search(veto, n, target);

    return 0;
}