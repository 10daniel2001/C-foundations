#include <stdio.h>
#include <stdlib.h>

/* arithmetic operations in C

   aritmético em C 
   Conceitos importante usando ponteiros e arrays 
   # stdio e a biblioteca padrao para input output em C e outras funcoes
   # stdlib e a biblioteca padrao para criar espacos na memoria com malloc e free
   
   arr e um arrays de inteiros  com 5 indices 
   ptr e um ponteiro para o primeiro elemento do array */

int main() {

    int arr[5] = {10, 20, 30, 40, 50}; // Declaring an array of integers
    int *ptr = arr; // Pointer to the first element of the array

    // Ou eu poderia fazer assim: int *ptr = &arr[0]; // Pointer to the first element of the array

    printf("Array elements using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(ptr + i)); // Accessing array elements using pointer arithmetic
    }   


return 0;
}