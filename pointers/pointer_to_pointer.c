#include <stdio.h>


/* Pointer to Pointer Example 
   Exemplo de ponteiro paraponteiro 
   variavel inteira x recbe o valor 10
   variavel ponteiro ptr aponta para o endereco de x
   variavel ponteiro ptr_to_ptr aponta para o endereco de ptr
*/
int main() {
    int x = 10;
    int *ptr = &x;  // ptr points to the address of x
    int **ptr_to_ptr = &ptr;  // ptr_to_ptr points to the address of ptr

    printf("Value of x: %d\n", x);
    printf("Value pointed by ptr: %d\n", *ptr);
    printf("Value pointed by ptr_to_ptr: %d\n", **ptr_to_ptr);

    return 0;
}