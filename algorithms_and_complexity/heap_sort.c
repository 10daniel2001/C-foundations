#include <stdio.h>

//Iniciando jeap sort um dosmelhores algoritmos em questâo de desenpenho e espaço

void trocar(int *a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}//fim da funçâo trocar


void heap_fuc(int vetor[], int n, int i){
	int maior = i; //Iniicalizando maior como raiz da subarvore
	int esqu = 2*i+1; //Indice do filho da esquerda
	int dire = 2*i+2; //indice do filha da direita

       	//Verifica se o filho da esquerda e maior que a raiz
       	if(esqu < n && vetor[esqu] > vetor[maior]) maior = esqu;
	//Verifica se o filho direito existe ou e maior que a raiz
	if(dire < n && vetor[dire] > vetor[maior]) maior = dire;
       
 	// Se o maior não for a raiz, troca e continua a "consertar" para baixo
	if(maior != i){
	    trocar(&vetor[i], &vetor[maior]);
            heap_fuc(vetor, n, maior);	
	}//fim do if
}// fim da funçâo heap_fy

void heap_sort(int vetor[], int n){
	//Construindo o heap (reorganizando o vetor)
	for(int i = n/2 - 1; i >= 0; i--){
		heap_fuc(vetor, n, i);
	}//fim do for

	//Um por um extrai um elemento do heap
	for(int i = n-1; i >= 0; i--){
		//Move a raiz atual para o final
		trocar(&vetor[0], &vetor[i]);
		//Chama heapify no heap reduzido
		heap_fuc(vetor, i, 0);
	}//fim do for
}//fim da funçâo heap_sort