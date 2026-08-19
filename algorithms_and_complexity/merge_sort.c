#include <stdio.h>

/*Um algoritmo ja poderoso para ordençao usando recursao,e devidindo em partes menores
  No fim problemas dividos e partes menores, ultilizando recursao, e uma memoria extra 
*/

void merge(int vetor[], int inicio, int meio, int fim){
	int n1 = meio - inicio + 1;
        int n2 = fim - meio;
 // Declarei 2 variaveis para uso, n1 é n2, nelas contem dados do meio subtraindo com fim + 1, é e meio - fim
	int vetesquerdo[n1]; // Armazena o lado esquerdo do vetor ja dividido
        int vetdireito[n2];  // Armazena o lado direito do vetor tambem ja ordenando

        for(int i = 0; i < n1; i++) vetesquerdo[i] = vetor[inicio + i];
        for(int j = 0; j < n2; j++) vetdireito[j] = vetor[meio+1+j]; 

        int i = 0, j = 0, k = inicio;
	while(i < n1 && j < n2){
  
                 if (vetesquerdo[i] <= vetdireito[j]){
	          vetor[k] = vetesquerdo[i++];
              
                }else{
                  vetor[k] = vetdireito[j++];
    
                }// fim do if 
   	  k++;
            
        }//Fim do while
   
	
    	while(i < n1) vetor[k++] = vetesquerdo[i++];
 	while(j < n2) vetor[k++] = vetdireito[j++];

}//fim da funçao

// Lembrando este codigo esta sendo feito com o editor de texto nano do linux
// por isso o uso de comentarios ao fim das chaves


void merge_sort(int vetor[], int inicio, int fim){
     if (inicio < fim){
        int meio = inicio + (fim - inicio) / 2;
		
	merge_sort(vetor, inicio, meio);
	merge_sort(vetor, meio + 1, fim);
  
	merge(vetor, inicio, meio ,fim);  
     }// fim if
}//fim da funçao

int main(){
    int v1[] = {5, 3, 1, 4, 2};
    int n1 = sizeof(v1) / sizeof(v1[0]);
    merge_sort(v1, 0, n1 - 1);
    printf("Teste 1: ");
    for (int i = 0; i < n1; i++) printf("%d ", v1[i]);
    printf("\n");

    int v2[] = {1, 2, 3, 4, 5}; 
    int n2 = sizeof(v2) / sizeof(v2[0]);
    merge_sort(v2, 0, n2 - 1);
    printf("Teste 2: ");
    for (int i = 0; i < n2; i++) printf("%d ", v2[i]);
    printf("\n");

    int v3[] = {4, 4, 2, 2, 1}; // com repetidos
    int n3 = sizeof(v3) / sizeof(v3[0]);
    merge_sort(v3, 0, n3 - 1);
    printf("Teste 3: ");
    for (int i = 0; i < n3; i++) printf("%d ", v3[i]);
    printf("\n");

    int v4[] = {7}; // 1 elemento
    merge_sort(v4, 0, 0);
    printf("Teste 4: %d\n", v4[0]);

    return 0;
}

/*Notaçao Big O
  O(n log n)
  Merge sort é um algoritmo de ordenação eficiente que utiliza a técnica de divisão
   e conquista. Ele divide o array em duas metades, ordena cada metade recursivamente e
   em seguida, mescla as duas metades ordenadas. A complexidade de tempo do merge sort é O(n log n)
   onde n é o número de elementos no array. Isso ocorre porque o array é dividido logaritmicamente (log n) 
   e cada nível de divisão requer uma operação linear (n) para mesclar os elementos.

   Ele e tem uma complexidade de espaço adicional de O(n) devido à necessidade de armazenar os 
   elementos temporariamente durante a mesclagem.
*/