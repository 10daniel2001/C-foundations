#include <stdio.h>
#include <stdlib.h>

/*Struct point ou struct ponto
  Nela esta duas variaveis inteiras guardadas 
  X sera meu array de inteiros e Y sera um inteiro simples
   
  No main
  chamo a struct Point p1, p1 e um ponteiro para struct Point, p1.x e p1.y sao ponteiros para inteiros
  Na linha 21 e 22 aloco memoria para p1.x e p1.y, p1.x e um array de 5 inteiros e p1.y e um inteiro simples

  Linha 26 e 27 verifico se a alocacao de memoria falhou, caso sim imprimo uma mensagem de erro e retorno 1

  Apos puxo um for para preencher o array p1.x com valores pares e imprimo os valores de p1.x

  finalizo com free para liberar a memoria alocada para p1.x e p1.y e retorno 0 para indicar que o programa terminou com sucesso
  
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