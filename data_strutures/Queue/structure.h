#ifndef STRUCTURE_H
#define STRUCTURE_H

/*Modular este exemplo de codigo para mostrar o uso de funçoes prontas
  começando com um arquivo cabeçalho em C, que sera usado em outros arquivos
  Em c usado .h para estructs e func

  Arquivo de cabeçalho para a estrutura de dados Fila (Queue) e suas operações.

  file for the data structure Queue and its operations.
  implementation of a queue data structure in C, with functions to initialize, check if full or empty, enqueue, and print the queue contents.
  
  */

#define Tamanho 10  
//constante para definir o tamanho máximo da fila (queue) como 10.
//constant to define the maximum size of the queue as 10.


typedef struct 
{
    char nome[20];
    int idade;
}Pessoa; //peaple

typedef struct 
{
  Pessoa intens[Tamanho]; //array of Pessoa to hold the elements in the queue
  int inicio;
  int fim;
  int total;
}Fila; //queue


//Function prototypes for queue operations
//Prototipos de funçoes para as operações da fila
void inicializar_init(Fila *f);
int fila_cheia(Fila *f);
int fila_vazia(Fila *f);
void queue(Fila *f, Pessoa *p);

void printss(Fila *f);

//End of the header file
//Fim do arquivo de cabeçalho
#endif