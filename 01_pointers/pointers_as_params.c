#include <stdio.h>

/* Function to increment the value pointed to by ptr 
   Passagem por referencia com ponteiros 
   uma funçao vazia recebe um ponteiro como parametro 
   e incrementa o valor apontado 
   
   funçao somar receber um ponteiro como parametro e somar 10 ao valor apontado 
   
   observaçao sobre ponteiro com parametros e que ela permite modificar o valor da variável original 
   Por referencia nao modfica apenas o copia*/

void increment(int *ptr) {
    (*ptr)++;
    // pq () é necessário para garantir que a operação de incremento seja aplicada
    // ao valor apontado pelo ponteiro, e não ao próprio ponteiro.
}

void somar(int *a){
    *a = *a + 10; // A operação de desreferenciação é feita com o operador * para acessar o valor apontado pelo ponteiro a, e em seguida somamos 10 a esse valor.
}


int main() {
    int num = 5;
    printf("Before increment: %d\n", num);
    increment(&num);
    printf("After increment: %d\n", num);

    somar(&num);
    printf("After somar: %d\n", num);

    return 0;
}