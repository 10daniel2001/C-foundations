#include <stdio.h>
#include <stdlib.h>
// Sempre vai te ruma mistura de ingles e portugues, mas vou tentar usar o inglês para os comentários e português para o texto explicativo.

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
   
   saida esperada:
   Stack variable: (endereço de memória da variável na pilha)
   Heap variable: (endereço de memória da variável no heap)
   Stack variable: 0x7ffd7f473340
   Heap variable: 0x5a2ed06cf6b0


*/

int main() {
    // Stack allocation
    int *stackVar;
    printf("Stack variable: %p\n", (void *)stackVar);

    // Heap allocation
    int *heapVar = (int *)malloc(sizeof(int));
    if (heapVar == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    *heapVar = 20;
    printf("Heap variable: %p\n", (void *)heapVar);

    
    free(heapVar);

    return 0;
}