# Biblioteca Padrão do C — `stdio.h` e `time.h`

## 1. Biblioteca Padrão do C

Coleção essencial de funções predefinidas, macros e tipos de dados, especificada por padrões como ANSI C e ISO C.

Um componente-chave é a biblioteca `stdio.h`, responsável por operações de entrada e saída. O termo *stdio* deriva de *standard input and output*. Essa biblioteca oferece funções para leitura e escrita de dados, incluindo as conhecidas `printf()` e `scanf()`.

```c
#include <stdio.h>

int main() {
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Você tem %d anos.\n", idade);
    return 0;
}
```

---

## 2. Biblioteca Padrão do C para Data e Hora

Seção governada pelo cabeçalho `time.h`, que disponibiliza funções e tipos para manipulação de datas e horas — essenciais para medir tempos de execução e trabalhar com o sistema de datas e horas.

### Principais tipos de dados

| Tipo        | Descrição                                                              |
|-------------|--------------------------------------------------------------------------|
| `time_t`    | Representa o tempo em segundos desde o Epoch (1 de janeiro de 1970)      |
| `struct tm` | Armazena componentes de tempo "quebrados": ano, mês, dia, hora, etc.    |

```c
struct tm {
    int tm_sec;   // segundos (0-60)
    int tm_min;   // minutos (0-59)
    int tm_hour;  // horas (0-23)
    int tm_mday;  // dia do mês (1-31)
    int tm_mon;   // mês (0-11, janeiro = 0)
    int tm_year;  // anos desde 1900
    int tm_wday;  // dia da semana (0-6, domingo = 0)
    int tm_yday;  // dia do ano (0-365)
    int tm_isdst; // horário de verão
};
```

### Funções importantes

Funcionalidades essenciais para aplicativos que dependem de temporização ou trabalham com datas programaticamente.

| Função                    | O que faz                                                          |
|----------------------------|----------------------------------------------------------------------|
| `time()`                   | Obtém o tempo atual do sistema                                       |
| `gmtime()` / `localtime()` | Convertem `time_t` para `struct tm` em UTC ou horário local          |
| `mktime()`                 | Converte `struct tm` de volta para `time_t`                          |
| `strftime()`               | Formata data e hora de `struct tm` para uma string                   |
| `difftime()`               | Calcula a diferença em segundos entre dois tempos (`time_t`)         |
| `asctime()` / `ctime()`    | Convertem tempo para uma string legível                              |

### Exemplo prático

```c
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
```

---

## Referências rápidas

- [cppreference — `<stdio.h>`](https://en.cppreference.com/w/c/io)
- [cppreference — `<time.h>`](https://en.cppreference.com/w/c/chrono)