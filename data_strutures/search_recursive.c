#include <stdio.h>
#include <stdlib.h>

/*Busca recursiva 
  Seach recursive 


*/

void search_recursive(int *arr, int size, int target, int index) {
    //caso base: se o índice estiver fora dos limites, o elemento não foi encontrado
    // caso recursivo: verifica se o elemento atual corresponde ao alvo
    // Se corresponder, imprime o índice; caso contrário, chama a função recursivamente com o próximo índice
    // Esta função procura o valor alvo no array de forma recursiva
    // Ela recebe o array, seu tamanho, o valor alvo e o índice atual como parâmetros

    // Base case: if the index is out of bounds, the element is not found
    // Recursive case: check if the current element matches the target
    // If it does, print the index; otherwise, call the function recursively with the next index
    // This function searches for the target value in the array recursively
    // It takes the array, its size, the target value, and the current index as parameters
    if (index >= size) {
        printf("Element not found\n");
        return;
    }
    if (arr[index] == target) {
        printf("Element found at index: %d\n", index);
        return;
    }
    search_recursive(arr, size, target, index + 1);
}

// Function to initiate the recursive search
// This function is called by the user to start the search process
// It takes the array, its size, and the target value as parameters
// It initializes the index to 0 and calls the recursive search function
// This function is useful to hide the implementation details of the recursive search
void initiate_search(int *arr, int size, int target) {
    search_recursive(arr, size, target, 0); 
}   


int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    initiate_search(arr, size, target);

    return 0;
}