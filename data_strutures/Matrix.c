#include <stdio.h>
#include <stdlib.h>

#define line 10
#define column 10

/*Create matrix for concept
criar matrix para conceito


*/


void create_matrix(int matrix[line][column]) {
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = rand() % 100; // Fill with random numbers between 0 and 99
        }
    }
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