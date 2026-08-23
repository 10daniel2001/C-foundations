#include <stdio.h>
#include <stdlib.h>

/*Iniciando arvores binarias e arvores de busca neste diretorio
  Contém codigos de exemplos funcionais para esssa estrutura de dados

*/

//Neste struct contém uma variavl do tipo inteira para os dados
//É dois ponteiro que sera para no filhos direito e esquerdo
struct Node {
    int data;
    struct Node* esquerda;
    struct Node* direita;
};