#include <stdio.h>

void merge_sort(int vetor[], int inicio, int meio, int fim){
	int n1 = meio - fim + 1;
        int n2 = fim - meio;

	int vetesquerdo[n1];
        int vetdireito[n2];

        for(int i = 0; i < n1; i++) vetesquerdo[i] = vetor[inicio + 1];
        for(int j = 0; j < n2; j++) vetdireito[j] = vetor[meio+1+j]; 

        int i = 0, j = 0, k = inicio;
	while(i < n1 && j < n2){
  
           if (vetesquerdo[i] <= vetdireito[j]){
	        vetor[k] = vetesquerdo[i++];
              
           }else{
                vetor[k] = vetdireito[j++];
    
         }// fim do if 

  }//Fim do while
   	k++;
	
    	while(i < n1) vetor[k++] = vetesquerdo[i++];
 	while(j < n2) vetor[k++] = vetdireito[j++];

}//fim da funçao
