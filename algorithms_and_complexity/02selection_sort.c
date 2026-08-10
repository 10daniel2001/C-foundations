#include <stdio.h>
#include <stdlib.h>

/*Algoritimo selection sort 
Basicamente e uma implementaçao didatica para fins de estudo e pratica de logica
um algoritimo de ordençao


Sua logica e simples 
um funçao com parametros para passagem por referencia para realizar trocas entre pobteiros e variavel

funçao selection sort, contem dois parametros vetor e n -> refere se ao tamnho
inicializando variaveis inteira, mini_indice para o menor valor, i para o for externo j para o interno
ao iniciar o mini_indice recebe o primeiro indice que e 0 e contem um elemento

for externo 
a variavel j recebe i e soma com 1, no caso no inicio seria j = 0 + 1
no if verifica justamente o vetor com indice de j e vetor com mini_indice
se o indice do vetor j for maior que o inidce do vetor mini_indice a condicao e verdadeira
se nao a funçao trocar e chamada no for externo ao final 

*/

//Funçao para trocar dois elementos
void trocarr(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int vetor[], int n){
    int min_indice, i , j;

    for (i = 0; i < n - 1; i++)
    {                            //[10,20,56,78,99,77] elementos
        min_indice = i; // exemplo   0  1  2  3  4  5  inidces 

        for (j = i + 1; j < n; j++)
        {
            if (vetor[j] < vetor[min_indice])
            {
            // Se o elemento em vetor[j] for MENOR que o elemento em vetor[min_indice],
            // então encontramos um novo menor valor: atualiza min_indice para j
                 min_indice = j;
            }
            
        }
        if (min_indice != i)
        {
            trocarr(&vetor[i], &vetor[min_indice]);
        }
        

    }
    
}