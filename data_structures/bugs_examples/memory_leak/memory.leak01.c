#include <stdio.h>
#include <stdlib.h>

/*Vazamento de memória
  Memória alocada dinamicamente não é liberada, resultando em vazamento de memória.

  Memory leak
  memory allocated dynamically is not freed, resulting in a memory leak.
*/

int function() {
    int *ptr = (int *)malloc(sizeof(int) * 10); // Alocação de memória para 10 inteiros
    if (ptr == NULL) {
        return -1; // Falha na alocação de memória
    }
    
    // Uso da memória alocada
    for (int i = 0; i < 10; i++) {
        ptr[i] = i;
    }

    // A memória alocada não é liberada, resultando em vazamento de memória
    return 0;


    //Note: The memory allocated with malloc is not freed using free(ptr), which causes a memory leak.
    // Note a memória alocada com malloc não é liberada usando free(ptr), o que causa um vazamento de memória.

    //free ?
    // free(ptr) ?
}

int main() {
    function();
    return 0;
}