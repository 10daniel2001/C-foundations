#include <stdio.h>
#include <stdlib.h>

/*Este codigo e proposto para demonstrar um vazamento de memoria 
  A nao chama free() para liberar a memória alocada, portanto, ocorre um vazamento de memoria 
  E nao funçao main essa funçao e chamada 3 vezes, Quando a função termina,
  LeakVar deixa de existir porque era uma variável local da stack.
  A memória continua ocupada no heap, mas não existe mais nenhum ponteiro para ela
  
  conteudo didatico 
  */

void memory_leak_example() {
  
    int *leakVar = (int *)malloc(sizeof(int));
    if (leakVar == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    *leakVar = 42;

   // free(leakVar);

}

// exemplo de uso da função memory_leak_example

int main() {
    memory_leak_example();


    char* nome = (char*)malloc(50 * sizeof(char));
    if (nome == NULL) {
        fprintf(stderr, "Memory allocation failed\n");  
        return 1;
    }
    // free(nome);

    return 0;
}