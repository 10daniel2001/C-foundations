#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Tabela hash simples (string -> int) com tratamento de colisão
  por encadeamento (chaining)
*/

#define Size_table 10 // tamanho da tabela

struct Node
{
    char* chave;
    int valor;
    struct Node* proximo;
};
// Nó da lista ligada usada em cada posição (bucket) da tabela

struct Node* table[Size_table]; // A tabela hash é só um array de ponteiros para nós

void init_table(){
    for (int i = 0; i < Size_table; i++)
    {
        table[i] = NULL;
        // Inicializar todos os buckets como vazio
        // Init all buckets with null
    }
    
}

// Função hash: soma os códigos ASCII dos caracteres e aplica módulo
unsigned int func_hash(const char* chave){
    unsigned int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++)
    {
        soma += chave[i];
    }
    return soma % Size_table;
}

// Insere (ou atualiza, se a chave já existir) um par chave/valor
void insert(const char* chave, int valor){
    unsigned int indice = func_hash(chave);

    struct Node* atual = table[indice];
    while (atual != NULL)
    {
        if (strcmp(atual->chave, chave) == 0)
        {
            atual->valor = valor;
            return;
        }
        atual = atual->proximo;
        
    }
    
}
