#include <stdio.h>
#include <stdlib.h> // Inclui a biblioteca stdlib.h para usar a função malloc, que aloca memória dinamicamente.


int main() {

    int* ptr = malloc(sizeof(int)); // Aloca memória suficiente para armazenar um inteiro e retorna um ponteiro para essa memória. O ponteiro é armazenado na variável 'novo'.
     // new 

    if (ptr == NULL) { // Verifica se a alocação de memória falhou
    printf("Memory allocation failed\n");
    return 1; // Retorna 1 para indicar que houve um erro na alocação de memória.   
    }

    *ptr = 10; // Atribui o valor 10 à memória alocada dinamicamente. Aqui, 'novo' é um ponteiro, então estamos armazenando o valor 10 no endereço de memória apontado por 'novo'.

    printf("Value: %d\n", *ptr); // Imprime o valor armazenado na memória alocada dinamicamente. O operador * é usado para acessar o valor apontado pelo ponteiro 'novo'.
    free(ptr); // Libera a memória alocada dinamicamente para evitar vazamentos de memória. É importante sempre liberar a memória alocada com malloc quando ela não é mais necessária.

    int* arr = (int*)malloc(5 * sizeof(int)); // Aloca memória para um array de 5 inteiros e retorna um ponteiro para essa memória. O ponteiro é armazenado na variável 'arr'.
   
    if (arr == NULL) { // Verifica se a alocação de memória falhou
        printf("Memory allocation failed\n");
        return 1; // Retorna 1 para indicar que houve um erro na alocação de memória.   
    }

    arr[0] = 10; // Atribui o valor 10 ao primeiro elemento do array alocado dinamicamente. Aqui, 'arr' é um ponteiro para o primeiro elemento do array, então podemos usar a notação de índice para acessar os elementos do array.
    arr[1] = 20; // Atribui o valor 20 ao segundo elemento do array alocado dinamicamente.
    arr[2] = 30; // Atribui o valor 30 ao terceiro elemento do array alocado dinamicamente.
    arr[3] = 40; // Atribui o valor 40 ao quarto elemento do array alocado dinamicamente.
    arr[4] = 50; // Atribui o valor 50 ao quinto elemento do array alocado dinamicamente. 

    printf("Array values: ");

    for (int i = 0; i < 5; i++) { // Itera sobre os elementos do array alocado dinamicamente e imprime seus valores.
        printf("%d \n", arr[i]); // Imprime o valor do elemento atual do array.
    }


    free(arr); 
  return 0;
}
