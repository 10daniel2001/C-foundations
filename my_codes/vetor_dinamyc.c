#include <stdio.h>
#include <stdlib.h>

/*Neste codigo estou criando um vetor dinamico com malloc
  Inicialmente o vetor criar espaco para 5 inteiro na heap  
*/



int main(){

  int* new_memory = (int*)malloc(5 * sizeof(int));

  for (int i = 0; i < 5; i++)
  {
    new_memory[i] = i+5;
    printf("%d\n", new_memory[i]);
  }



  free(new_memory);
  
    return 0;
}