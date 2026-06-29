#include <stdio.h>
#include <stdlib.h>

/*Struct point ou struct ponto
  Nela esta duas variaveis inteiras guardadas 
  */

struct Point {
    int* x;
    int* y;
};

int main() {
  struct Point p1;

  p1.x = (int*)malloc(5 * sizeof(int));  // Allocate memory for 5 integers for x
  p1.y = (int*)malloc(sizeof(int));

    if (p1.x == NULL || p1.y == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    for (int i = 0; i < 5; i++) {
        p1.x[i] = i * 2; // Assign values to x
        printf("p1.x[%d] = %d\n", i, p1.x[i]);
    }
    *p1.y = 20; // Assign value to y
    printf("Point coordinates: (%d, %d)\n", p1.x[2], *p1.y);


    free(p1.x); // Free allocated memory for x
    free(p1.y); // Free allocated memory for y  

    return 0;
}