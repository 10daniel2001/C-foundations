#include <stdio.h>
#include <stdlib.h> // Inclui a biblioteca stdlib.h para usar a função malloc, que aloca memória dinamicamente.


int main() {

int* novo = malloc(sizeof(int)); // Aloca memória suficiente para armazenar um inteiro e retorna um ponteiro para essa memória. O ponteiro é armazenado na variável 'novo'.
     // new 
     
if (novo == NULL) { // Verifica se a alocação de memória falhou
    printf("Memory allocation failed\n");
    return 1; // Retorna 1 para indicar que houve um erro na alocação de memória.   
}

*novo = 10; // Atribui o valor 10 à memória alocada dinamicamente. Aqui, 'novo' é um ponteiro, então estamos armazenando o valor 10 no endereço de memória apontado por 'novo'.

printf("Value: %d\n", *novo); // Imprime o valor armazenado na memória alocada dinamicamente. O operador * é usado para acessar o valor apontado pelo ponteiro 'novo'.
free(novo); // Libera a memória alocada dinamicamente para evitar vazamentos de memória. É importante sempre liberar a memória alocada com malloc quando ela não é mais necessária.




}
