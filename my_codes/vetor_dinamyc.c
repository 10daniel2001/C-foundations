#include <stdio.h>
#include <stdlib.h>

/*Neste codigo estou criando um vetor dinamico com malloc
  Inicialmente o vetor criar espaco para 5 inteiro na heap  
*/



int main(){

  //arrays the number int
  int* new_memory = (int*)malloc(5 * sizeof(int));

  //arrays the character char, dinamic!
  char* new_character = malloc(10 * sizeof(char));

for (int i = 0; i < 10; i++)
{
    new_character[i] = 'A' + i;
    printf("%c\n", new_character[i]);
}
  

  
  //new_memory[0] = 10;
  //new_memory[1] = 20;
  //new_memory[3] = 30;
  //Exemple

  for (int i = 0; i < 5; i++)
  {
    new_memory[i] = i+10;
    printf("%d\n", new_memory[i]);
  }



  free(new_character);
  free(new_memory);
  
    return 0;
}