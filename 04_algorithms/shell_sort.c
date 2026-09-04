#include <stdio.h>

/*Shell sort representando como um algoritmo de ordenaçao in place, é no fim e apenas um insertion sort

shell usa gap para comparar elementos distantes do primeiro elemento, é a cada volta este gap reduz

*/

void shell_sort(int vetor[], int n){

    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Faz um insertion sort "espaçado" pelo gap
        for (int i = gap; i < n; i++) {
            int temp = vetor[i];
            int j = i;

            while (j >= gap && vetor[j - gap] > temp) {
            vetor[j] = vetor[j - gap];
            j -= gap;
        }
        vetor[j] = temp;

     }
  }
}