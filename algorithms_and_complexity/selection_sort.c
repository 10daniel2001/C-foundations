#include <stdio.h>
#include <stdlib.h>

/*Algoritimo selection sort 
Basicamente e uma implementaçao didatica para fins de estudo e pratica de logica
um algoritimo de ordençao


Sua logica e simples 

*/

//Funçao para trocar dois elementos
void trocarr(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}