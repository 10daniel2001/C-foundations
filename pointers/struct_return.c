#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Caixa {
    int tamanho;
    char nome[20];
};

struct Caixa* criarcaixa(int tamanho, const char* nome) {
    struct Caixa* caixa = (struct Caixa*)malloc(sizeof(struct Caixa));
    if (caixa == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a caixa.\n");
        exit(EXIT_FAILURE);
    }
    caixa->tamanho = tamanho;
    caixa->nome[0] = '\0'; // Inicializa a string com o caractere nulo
    strncpy(caixa->nome, nome, sizeof(caixa->nome) - 1);
    caixa->nome[sizeof(caixa->nome) - 1] = '\0'; // Garante que a string seja terminada com nulo
    return caixa;
}

int main() {
    // Usuario fornece os valores para a caixa
    int tamanho;
    char nome[20];
    printf("Digite o tamanho da caixa: ");
    scanf("%d", &tamanho);
    printf("Digite o nome da caixa: ");
    scanf("%s", nome);  

    struct Caixa* minhaCaixa = criarcaixa(tamanho, nome);
    printf("Caixa criada: Tamanho = %d, Nome = %s\n", minhaCaixa->tamanho, minhaCaixa->nome);
    free(minhaCaixa); // Libera a memória alocada para a caixa

    return 0;
}