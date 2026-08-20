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
	int pivo = vetor[alto]; // Pivo recebe o ulemetos como pivo
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