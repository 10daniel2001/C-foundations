#include <stdio.h>
#include <stdlib.h>

#define line 10
#define column 10

/*Create matrix for concept
criar matrix para conceito

matrix is a two-dimensional array that can be used to represent data in rows and columns. In this code, we define a matrix of size 10x10 and fill it with random numbers between 0 and 99. The create_matrix function initializes the matrix, and the main function prints the matrix to the console.

*/


void create_matrix(int matrix[line][column]) {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = rand() % 100; // Fill with random numbers between 0 and 99
        }
    }
    //Function to create a matrix of size 10x10 and fill it with random numbers between 0 and 99.
    // Função para criar uma matriz de tamanho 10x10 e preenchê-la com números aleatórios entre 0 e 99.
}

int main() {
    int matrix[line][column];
    create_matrix(matrix);
    

    // Print the matrix
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}