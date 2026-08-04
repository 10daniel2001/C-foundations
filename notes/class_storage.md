# Classes de Armazenamento, Especificadores de Tipo e Operadores em C

Definem a vida útil (lifetime), a visibilidade (escopo) e o comportamento de variáveis ou funções na linguagem C.

---

## 1. Classes de Armazenamento

### `auto`
Usada para variáveis locais. É o padrão implícito de qualquer variável declarada dentro de um bloco ou função — desaparece assim que o bloco termina.

```c
void func() {
    auto int x = 10; // "auto" é opcional, esse é o comportamento padrão
}
```

### `static`
Preserva o valor da variável entre chamadas de função. Ideal para manter estados, como um contador de visitas.

```c
void contador() {
    static int visitas = 0;
    visitas++;
    printf("Visita número: %d\n", visitas);
}
```

### `extern`
Informa que a variável é definida em outro arquivo. Comum em programas com múltiplos arquivos-fonte (`.c`) que compartilham variáveis globais via `.h`.

```c
// arquivo1.c
int contador_global = 0;

// arquivo2.c
extern int contador_global; // referencia a variável definida em arquivo1.c
```

### `register`
Recomenda ao compilador que a variável seja armazenada em um registrador da CPU, visando acesso mais rápido — especialmente útil em loops frequentes. É apenas uma sugestão; o compilador pode ignorá-la.

```c
void loop() {
    register int i;
    for (i = 0; i < 1000000; i++) {
        // acesso rápido a i
    }
}
```

| Classe     | Escopo               | Tempo de vida           | Uso típico                        |
|------------|----------------------|--------------------------|------------------------------------|
| `auto`     | Local (bloco)         | Duração do bloco         | Variáveis comuns                   |
| `static`   | Local ou global        | Todo o programa           | Manter estado entre chamadas       |
| `extern`   | Global (multi-arquivo) | Todo o programa           | Compartilhar variáveis entre `.c`s |
| `register` | Local (bloco)          | Duração do bloco          | Otimização em loops                |

---

## 2. Especificadores / Modificadores de Tipo

Ajustam o alcance e o tamanho dos dados armazenados.

### `unsigned int`
Guarda apenas valores positivos (e zero), com alcance maior do que um `int` comum, pois não reserva bit de sinal. Ideal para contagens.

```c
unsigned int contagem = 4000000000; // valor positivo grande
```

### `long`
Aumenta a capacidade de armazenamento do tipo base. Adequado para números muito grandes.

```c
long populacao = 8000000000L;
long long numero_enorme = 9223372036854775807LL;
```

---

## 3. Operadores e Precedência

Essenciais para realizar operações matemáticas e lógicas.

### Tipos de operadores

- **Aritméticos**: `+`, `-`, `*`, `/`, `%`
- **Lógicos**: `&&`, `||`, `!`
- **De comparação**: `==`, `!=`, `>`, `<`, `>=`, `<=`
- **De atribuição**: `=`, `+=`, `-=`, `*=`, `/=`

### Precedência

A precedência define a ordem de avaliação das operações: operadores de maior precedência são avaliados primeiro. Parênteses `()` podem ser usados para alterar essa ordem.

```c
int resultado = (a + b) * c; // parênteses garantem que a + b é calculado antes da multiplicação
```

### Expressões e operadores de atribuição compostos

Expressões combinam valores, variáveis e operadores para produzir um novo valor. Operadores de atribuição compostos simplificam o código ao combinar aritmética com atribuição:

```c
int x = 10;
x += 5;  // equivalente a: x = x + 5;
x *= 2;  // equivalente a: x = x * 2;
```

---

## Referências rápidas

- [cppreference — Storage duration](https://en.cppreference.com/w/c/language/storage_duration)
- [cppreference — Operator precedence](https://en.cppreference.com/w/c/language/operator_precedence)