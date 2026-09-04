#include <stdio.h> // Include the standard input-output library
#include <stdlib.h> // Include the standard library for memory allocation

/*Arithmetic operations with pointers
  Aritmética com ponteiros
  
  funçao principal main, demostrando a aritmética de ponteiros com um array de inteiros.
  arr e um array de inteiro com 5 elementos, inicializado com valores de 10 a 50.
  ptr e um ponteiro para inteiro, inicializado para apontar para o primeiro elemento do array.
  O programa imprime os elementos do array usando aritmética de ponteiros, incrementando o ponteiro para acessar cada elemento do array.
  */



int main() {
    int arr[5] = {10, 20, 30, 40, 50}; // Declare and initialize an array of integers
    int *ptr = arr; // Declare a pointer and initialize it to point to the first element of the array

    printf("Array elements using pointer arithmetic:\n"); // Print a message indicating the start of output
    for (int i = 0; i < 5; i++) { // Loop through the array elements
        printf("%d ", *(ptr + i)); // Print the value at the current pointer position using pointer arithmetic
    }
    printf("\n"); // Print a newline for better formatting


    return 0; // Return 0 to indicate successful execution
}  