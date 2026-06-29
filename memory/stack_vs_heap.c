#include <stdio.h>
#include <stdlib.h>

/* Porque os endereços de memória são diferentes para variáveis alocadas na pilha e no heap
   
   A pilha (stack) e o heap são duas regiões diferentes da memória usadas para armazenar dados em um programa. 
   A pilha é usada para armazenar variáveis locais e informações de controle de função, enquanto o heap é usado para 
   alocação dinâmica de memória.

   Quando você declara uma variável local dentro de uma função, ela é alocada na pilha. A pilha tem um tamanho limitado 
   e é gerenciada automaticamente pelo compilador. As variáveis na pilha são desalocadas automaticamente quando a função 
   retorna.

   Por outro lado, quando você aloca memória dinamicamente usando funções como malloc(), a memória é alocada no heap. 
   O heap tem um tamanho maior e é gerenciado manualmente pelo programador. Você precisa liberar a memória alocada no 
   heap usando free() quando não precisar mais dela.

   Devido a essas diferenças, os endereços de memória das variáveis alocadas na pilha e no heap são diferentes.
   
   
*/

int main() {
    // Stack allocation
    int *stackVar;
    printf("Stack variable: %p\n", (void *)stackVar); // This will lead to undefined behavior since stackVar is uninitialized

    // Heap allocation
    int *heapVar = (int *)malloc(sizeof(int));
    if (heapVar == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    *heapVar = 20;
    printf("Heap variable: %p\n", (void *)heapVar);

    // Free heap memory
    free(heapVar);

    return 0;
}