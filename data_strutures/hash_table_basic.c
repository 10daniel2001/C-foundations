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
         // Verifica se a chave já existe nesse bucket -> atualiza o valor
        if (strcmp(atual->chave, chave) == 0)
        {
            atual->valor = valor;
            return;
        }
        atual = atual->proximo;
        
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Erro falha ao aaloca memoria\n");
        return;
    }

    new_node->chave = (char*)malloc(strlen(chave)+1);
    if (new_node->chave == NULL)
    {
        free(new_node);
        fprintf(stderr, "Erro ao alocar\n");
        return;
    }
    strcpy(new_node->chave, chave);
    new_node->valor = valor;
    new_node->proximo = table[indice];
    // insere no início (mais simples e rápido)
    table[indice] = new_node;
    
}

// Busca o valor associado a uma chave. Retorna 1 se achou (e preenche *valor), 0 se não achou
int buscar(const char* chave, int* valor) {
    unsigned int indice = func_hash(chave);
    struct Node* atual = table[indice];
 
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            *valor = atual->valor;
            return 1;
        }
        atual = atual->proximo;
    }
    return 0; // não encontrado
}

//REmover
void remover(const char* chave){
    unsigned int indice = func_hash(chave);
    struct Node* atual = table[indice];
    struct Node* anterior = NULL;

    while (atual != NULL)
    {
        if (strcmp(atual->chave, chave) == 0)
        {
            if (anterior == NULL)
            {
                table[indice] = atual->proximo;
            }else{
                anterior->proximo = atual->proximo;
            }
            
            free(atual->chave);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
        
    }
    
}

// Libera toda a memória alocada pela tabela
void liberar_tabela() {
    for (int i = 0; i < Size_table; i++) {
        struct Node* atual = table[i];
        while (atual != NULL) {
            struct Node* proximo = atual->proximo;
            free(atual->chave);
            free(atual);
            atual = proximo;
        }
        table[i] = NULL;
    }
}

int main(){
   
    init_table();
    // Funçao para iniciar a tabela antes de inserir


    // Inserindo strings e numeros inteiros 
    insert("joao", 25);
    insert("joa", 25);
    insert("maria", 30);
    insert("ana", 22);
    insert("joao", 26); // atualiza o valor de "joao"


    int valor;
    if (buscar("maria", &valor)) {
        printf("maria -> %d\n", valor);
    }
    if (buscar("joao", &valor)) {
        printf("joao -> %d\n", valor);
    }
    if (!buscar("pedro", &valor)) {
        printf("pedro nao encontrado\n");
    }
 
    remover("ana");
    if (!buscar("ana", &valor)) {
        printf("ana removida com sucesso\n");
    }
 
    // Para liberar tudo que foi alocado, chamada de funçao
    liberar_tabela();
    return 0;
}
 
