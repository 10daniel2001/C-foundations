#include <stdio.h>

/*Bubble sort function
  Conceituamente definido como um algoritmo de ordenação,
  o bubble sort é um dos métodos mais simples e intuitivos para ordenar uma lista de elementos.
  Ele funciona comparando pares adjacentes de elementos e trocando-os de posição se estiverem
  na ordem errada. Esse processo é repetido até que a lista esteja completamente ordenada.

  conceptually defined as a sorting algorithm, bubble sort is one of the simplest and most 
  intuitive methods for sorting a list of elements. It works by comparing adjacent pairs of
  elements and swapping them if they are in the wrong order. This process is repeated until 
  the list is completely sorted.
*/

void bubble_sort(int vetor[], int n){
    int temp, i, j;
    int trocou; // Variavel para sinalizar se foi feito alguma troca

    for ( i = 0; i < n - 1; i++) 
    {
        // Laço for externo para controle de numeros de passagens pelo vetor
        trocou = 0;

        for ( j = 0; j < n - 1 -i; j++)
        {
            // Laço for interno verifica o vetor e comparar os elementos adjacentes, e eefetua a troca 
             if (vetor[j] > vetor[j+1])
               //vetor[1] > vetor[2] suponha que vetor[1] e 10 e vetor[j+1] e 33
               //Entao if realiza a troca colocando o maior para o final 
             {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                trocou = 1;
             }
             
        }
        
    }
    

}