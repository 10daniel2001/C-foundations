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

        for ( j = 0; j < n - i -1; j++)
        {
            // Laço for interno verifica o vetor e comparar os elementos adjacentes, e efetua a troca 
             if (vetor[j] > vetor[j+1])
               //vetor[1] > vetor[2] suponha que vetor[1] e 10 e vetor[j+1] e 33
               //Entao if realiza a troca colocando o maior para o final 
             {
                temp = vetor[j]; // Temp recebe o vetor[j]
                vetor[j] = vetor[j+1]; //vetor[j] recebe o vetor[j+1]
                vetor[j+1] = temp; // vetor[j+1] recebe temp
                trocou = 1; // Troca sinalizada com 1, recebe 1, troca feita
             }
             
        }
        if (!trocou)
        {
            break;
            //Aqui invert trocou, se nenhum troca foi feita ja esta ordenando
        }
        
        
    }
    

}

int main(){
    int vetor[] = {22,55,45,78,98,75,48};
    int n = sizeof(vetor)/sizeof(vetor[0]);

    printf("** Vetor desordenado **\n");
    for (int j = 0; j < n; j++)
    {
        printf(" _[%d]_ \n", vetor[j]);
        
    }
    
    //Chamando a funçao Bubble sort
    bubble_sort(vetor, n);

    printf("Tamanho da entrada - %d\n", n);

    printf("++ Vetor ordenando ++\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%d]\n", vetor[i]);
    }
    

    return 0;
}

/* -- Analise assintótica -- 
Bubble sort e in-place, ou seja nao necessita de memoria extra para executar a ordenaçao
sendo assim sua complexidade espacial e O(1) constante 

Nos cenario de medio e pior caso o bubble sort  e quadratico O(n²), ao utilizar dois for aninhados — um controlando o 
número de passagens e outro percorrendo o vetor a cada passagem 
— o número total de comparações cresce proporcionalmente a n², podendo ser ineficiente em grandes entradas

portanto  
No melhor caso, quando o vetor já está ordenado, a versão otimizada do algoritmo executa apenas 
uma passagem e não realiza trocas. Isso diminui basante o número de operações, aproximando a 
complexidade de O(n). Esse cenário mostra como pequenas otimizações podem ter um impacto real no 
desempenho


*/
