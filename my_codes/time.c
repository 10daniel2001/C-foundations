#include <stdio.h>
#include <time.h>

int main() {
    time_t agora = time(NULL);
    struct tm *local = localtime(&agora);

    char buffer[64];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", local);
    printf("Data e hora atual: %s\n", buffer);

    // Medindo tempo de execução
    time_t inicio = time(NULL);
    for (long i = 0; i < 500000000; i++); // laço de exemplo
    time_t fim = time(NULL);

    printf("Tempo decorrido: %.2f segundos\n", difftime(fim, inicio));

    return 0;
}