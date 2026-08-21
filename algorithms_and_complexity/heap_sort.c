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
       	if(esqu < n && vetor[esqu] > vetor[meior]) maior = esqu;
	//Verifica se o filho direito existe ou e maior que a raiz
	if(dire < n && vetor[dire] > vetor[meior]) meior = dire;
       
 	// Se o maior não for a raiz, troca e continua a "consertar" para baixo
	if(maior != i){
	    trocar(&vetor[i], &trocar[maior]);
            heap_fuc(vetor, n, maior);	
	}//fim do if
}// fim da funçâo heap_fy
