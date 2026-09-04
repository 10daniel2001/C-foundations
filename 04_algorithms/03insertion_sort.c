#include <stdio.h>


/*Recursive insertion sort um algoritmo de ordenaçao 

   N-1 e a condiçao de parada para a funçao recursviva, sera empilhada no frame X vezes, e desinpilhada X vezes
   variavel key recebe 
*/


void insertion_sort(int vetor[], int n){
    if (n <= 1)
    return;

    insertion_sort(vetor, n-1);

    int key = vetor[n-1]; // total de indices e 4 entao 4-1 = 3, key [3]
    int jj = n-2;   // jj = 4-2 = 2

    // Exemplos [30,50,40,20,10] Elementos 
    // Indice   [ 0, 1, 2, 3, 4 ]  
    while (jj >= 0 && vetor[jj] > key )
    {   // jj >= 0 i is true end vetor[40] > key = 20 , elementos 
        // true 
        vetor[jj+1] = vetor[jj];
       //vetor[3] = veteor[2] 
        jj--;
        // jj _ 1-2 = 1
    }
   
    vetor[jj+1] = key;
    //vetor[3] = key = 20
}

void imprimir(int vet[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("vetor __ %d \n", vet[i]);
    }
    printf("\n");
    
}

int main(){
    int vetor[] = {9,5,7,6,1,4,3,2,8};
    int n = sizeof(vetor)/sizeof(vetor[0]);

    printf("Vetor original: \n");
    imprimir(vetor, n);

    insertion_sort(vetor, n);

    printf("Vetor ordenado: \n");
    imprimir(vetor, n);

    return 0;

}
/*Insertion sort, e de complexidade temporal Quadratica, isto no pior caso, pois contem percorrimentos mesmo se a sublista tiver organizada
  No melhor caso ele pode chegar a ser linear  O(n), claro em caso de lista ordenadas
  
  A complexidade de espaço Insertion e linear pois usa um espaço na stack, a sua recursao empilha e desipilha
  Insertion se da como estavel, se astabilidade for um requisito !
  
  */
