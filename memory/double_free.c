#include <stdio.h>
#include <stdlib.h>


/*double free example
Liberacao dupla de memoria 

funçao cria um espaco de memoria e libera duas vezes 
e chamada no bloco principal

Lembrando que isso pode causar comportamento indefinido 
*/

void double_free() {
    int *ptr = (int *)malloc(5 * sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;
    ptr[3] = 40;
    ptr[4] = 50;

    free(ptr); // First free
    free(ptr); // Second free (double free)
    printf("Double free occurred\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]); // Accessing freed memory (undefined behavior)
    }

    // Esse Codigo nao funciona corretamente, pois o ponteiro ptr foi liberado duas vezes,
    
}


int main() {
    double_free();

    free(NULL); 


    double_free(); // Call again to demonstrate double free
    // Segunda função chamada para demonstrar o double free
    
    return 0;
}