#include <stdio.h>
#include <stdlib.h>

/* Reallocates memory for an array of elements  
   Realocando espacio en memoria usando realloc 
   codigo simples e funcional explicativo
*/
 
int main() {
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

  /*arr agora recebe valores para cada indice, serao na sequencia, atualizado para arr*/
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
        // Imprimindo os valores do array
        printf("%d ", arr[i]);
        // veremos que os valores foram armazenados corretamente, e quais sao 
        // sera de 1 a 5, pois o for vai de 0 a 4, e o valor armazenado e i+1 
    }

    // Realocando memória para um array maior
    /*Temp e um ponteiro do tipo int, e armazena o endereço da memória realocada
    ou seja temp e o novo endereço da memória alocada
    if para verifica se a realocação foi bem-sucedida 
    */
    int *temp = (int *)realloc(arr, 10 * sizeof(int));

    if (temp == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        free(arr); // Liberar a memória original antes de sair
        return 1;
    }
    arr = temp;

  
    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1;
    }


    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Liberando a memória alocada
    return 0;
}