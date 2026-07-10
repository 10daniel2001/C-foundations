#ifndef STRUCTURE_H
#define STRUCTURE_H

/*Modular este exemplo de codigo para mostrar o uso de funçoes prontas
  começando com um arquivo cabeçalho em C, que sera usado em outros arquivos
  Em c usado .h para estructs e func
  
  */

#define Tamanho 10  

typedef struct 
{
    char nome[20];
    int idade;
}Pessoa; //peaple

typedef struct 
{
  Pessoa intens[Tamanho];
  int inicio;
  int fim;
  int total;
}Fila; //queue

void inicializar_init(Fila *f){};
int fila_cheia(Fila *f){};
int fila_vazia(Fila *f){};
void queue(Fila *f, Pessoa *p){};

void printss(Fila *f){};


#endif