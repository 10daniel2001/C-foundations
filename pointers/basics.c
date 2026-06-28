/* Basico sobre ponteiros e memoria e allocacao de memoria
   Codigos basico estruturados para consilhar meus conhecimentos sobre a linguagem C 
   Operando ponteiros e memoria, para melhor uso do hardware
   aqui os conceitos comentarios e ensenciais e nao gerado por IA, pois o intuito e concretizar o aprendizado humano

   * ponteiro e um asteristico em C
   & significa para o ponteiro ler esse endereco de memoria

   #include e para uso de bibliotecas e apis em C
   codigo basico e explicativo

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 10; // Declarando uma variavel inteira
    int *p;     // Declarando um ponteiro para inteiro

    p = &a;     // Atribuindo o endereco de 'a' ao ponteiro 'p'

    printf("Valor de a: %d\n", a);          // Imprimindo o valor de 'a'
    printf("Endereco de a: %p\n", (void*)&a); // Imprimindo o endereco de 'a'
    printf("Valor do ponteiro p: %p\n", (void*)p); // Imprimindo o valor do ponteiro 'p'
    printf("Valor apontado por p: %d\n", *p); // Imprimindo o valor apontado por 'p'

    return 0;
}