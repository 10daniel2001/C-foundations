#include <stdio.h>
#include <stdlib.h>

/* Stack overflow example 
   estouro de pilha
   Usando função recursiva como exemplo pratico
   
   Na pratica acontece com chamadas recursivas sem condição de parada*/

void recursive_function(int count) {
    printf("Recursion depth: %d\n", count);
    recursive_function(count + 1); // Recursive call

}

int main() {
    recursive_function(1); // Start recursion with count 1
    return 0;
}