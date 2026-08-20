#include <stdio.h>
#include <stdlib.h>

//Quick sort algoritmo de ordenaçao efetivo e recursivo

void trocar(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}//fim da funçao
