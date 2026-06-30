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

  
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    // Realocando memória para um array maior
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