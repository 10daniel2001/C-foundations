#include <stdio.h>
#include <stdlib.h>

//Quick sort algoritmo de ordenaçao efetivo e recursivo

//Funçao tradicional para uso em alguns algoritmos
void trocar(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}//fim da funçao troca

//Particionar o array
int partes(int vetor[], int baixo, int alto){
	int pivo = vetor[alto]; //  recebe o ulemetos como pivo
    int i = (baixo - 1);  // Indice do menor elemento
	
	for (int j = baixo; j <= alto - 1;j++){
    		if(vetor[j] < pivo){
     			i++;
			trocar(&vetor[i], &vetor[j]);
			}//fim if

	}//fim for
	trocar(&vetor[i+1], &vetor[alto]);
	return (i+1);
}// Fim da funçao partes

//Funçao de ordenaçao
void quickSort(int vetor[], int baixo, int alto){
	if(baixo < alto){
		int pivo = partes(vetor, baixo, alto);
		quickSort(vetor, baixo, pivo - 1);
		quickSort(vetor, pivo + 1, alto);
	}//fim if		
}//fim da funçao quickSort	

int main(){
	int vetor[] = {10, 7, 8, 9, 1, 5};

	int n = sizeof(vetor)/sizeof(vetor[0]);

	quickSort(vetor, 0, n-1);
	printf("Vetor ordenado: \n");
	for(int i=0; i < n; i++)
		printf("%d ", vetor[i]);
	return 0;
}//fim da funçao main

/*Nota: O algoritmo de ordenação rápido (Quick Sort) é um algoritmo eficiente e amplamente utilizado para ordenar elementos em um array. Sua complexidade
  de tempo média é O(n log n), mas pode chegar a O(n^2) em casos específicos. 
 
  A escolh de um pivô adequado é crucial para o desempenho do algoritmo. Neste código, 
  o último elemento do array é escolhido como pivô. A função 'partes' reorganiza os elementos em
  torno do pivô, garantindo que todos os elementos menores que o pivô fiquem à esquerda e todos
  os maiores fiquem à direita. A função 'quickSort' é chamada recursivamente para ordenar as 
  sublistas resultantes.

  Um pivo não ideal pode levar a um desempenho ruim, especialmente em listas já ordenadas ou quase ordenadas.
  O quick sort é um algoritmo O (nlogn) no caso médio, in-place e não estável 
  */

  /*
    Note: The quick sort algorithm is a divide-and-conquer algorithm that works by selecting a
	'pivot' element from the array and partitioning the other elements into two sub-arrays,
	according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.
	This implementation uses the last element as the pivot, which can lead to poor performance on already sorted arrays. 

	
  */