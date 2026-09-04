#include <stdio.h>

/*Estouro de pilha
  Stack overflow
  
  Onde uma função recursiva é chamada repetidamente sem uma condição de parada adequada,
  resultando em um estouro de pilha.

  in this example, the recursive_function is called with a large value (1000000),
  which causes the function to call itself repeatedly until the stack space is exhausted,
  leading to a stack overflow error.
*/


void recursive_function(int n) {
    if (n <= 0) {
        // Base case: stop recursion when n is less than or equal to 0
        // Caso base: parar a recursão quando n for menor ou igual a 0
        return;
        // O motivo de não haver uma condição de parada adequada é que a função continua chamando a si mesma 
        // com n - 1, sem nunca atingir o caso base para valores grandes de n.
    }
    recursive_function(n - 1);
    // Recursive function 
}

int main() {
    recursive_function(1000000); // This will cause a stack overflow
    // isso causará um estouro de pilha
    return 0;

    // Nao compila 
}