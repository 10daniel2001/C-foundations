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
		
	merge_sort(vetor, inicio, fim);
	merge_sort(vetor, meio + 1, fim);
  
	merge(vetor, inicio, meio fim);  
     }// fim if
}//fim da funçao


