#include <stdio.h>
#include <stdlib.h>

/* Dangling pointer example 
   pointer que aponta para memoria que foi liberada 
   
   exemplo praticos deste tipo de erro*/

void dangling_pointer() {
    int *ptr = (int *)malloc(5 * sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Bloco de código para inicializar o array, alocado espaco para 5 inteiros em heap memory, e atribuindo valores a cada elemento do array
    // Initializing the array with values
    // A seguir o ptr sera !
    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;
    ptr[3] = 40;
    ptr[4] = 50;

    free(ptr); 
    printf("Memory freed\n");

    // ORDEM INVERTIDA DE PROPÓSITO: normalmente ptr = NULL viria logo após o free()
    // Aqui acessamos primeiro para demonstrar o comportamento indefinido do dangling pointer

    
    printf("Accessing dangling pointer: %d\n", ptr[0]); 
    // Accessing freed memory (undefined behavior)
    // Aqui estamos tentando acessar a memoria ja liberada, e causar o dangling pointer!

   
    ptr = NULL;
    if (ptr == NULL) {
        printf("Pointer is now NULL, safe to use\n");
        // Ponteiro foi definido como NULL, evitando o dangling pointer
    }
}
/*********************************************************************************************** */
int main() {
    dangling_pointer();
    
    return 0;


    /*

    ESSa foi a saida do programa !

    Memory freed
    Accessing dangling pointer: 1431655769
    Pointer is now NULL, safe to use
    */
}