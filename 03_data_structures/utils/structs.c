#include <stdio.h>

/*Tema struct em C
  Uma forma de agrupar dados de diferentes tipos, como em uma caixa
  bastante pratico e facil de usar
  Alguns dados que sao permitido em structs
  inteiros ponteiros e outros tipos */

  struct Caixa {
    int largura;
    int altura;
    int profundidade;
  } caixa1, caixa2;

  int main() {
    // Inicializando os valores da caixa1
    caixa1.largura = 10;
    caixa1.altura = 20;
    caixa1.profundidade = 30;

    // Inicializando os valores da caixa2
    caixa2.largura = 15;
    caixa2.altura = 25;
    caixa2.profundidade = 35;   

    printf("Caixa 1: Largura: %d, Altura: %d, Profundidade: %d\n", 
           caixa1.largura, caixa1.altura, caixa1.profundidade);
    printf("Caixa 2: Largura: %d, Altura: %d, Profundidade: %d\n",
           caixa2.largura, caixa2.altura, caixa2.profundidade); 
           
    return 0;
    }