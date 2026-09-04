#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Liked list the char
  Lista ligada de caracteres

*/

struct No
{
    char* caracteres;
    struct No* esquerda;
    struct No* direita;
};

struct No* criar_no(const char* dados){
    struct No* novo_no = (struct No*)malloc(sizeof(struct No));
    if (novo_no == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    novo_no->caracteres = (char*)malloc(strlen(dados)+1);
    if (novo_no->caracteres == NULL)
    {
        free(novo_no);
        return NULL;
    }
    

    strcpy(novo_no->caracteres, dados);
    novo_no->esquerda = NULL;
    novo_no->direita = NULL;
    return novo_no;
    //
}
