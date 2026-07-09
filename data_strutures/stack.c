#include <stdio.h>
#include <stdlib.h>

/* Stack implementation
   Pilha implementação 
   
   Conceito LIFO (Last In, First Out)
   ultimo a entrar, primeiro a sair
    
   Ultiziando ponteiro para o topo da pilha
   */

struct Peaple {
    char nome[50];
    int idade;
};

struct Stack {
    struct Peaple *pessoas;
    int top;
    int capacity;
};

int stack_vazia(struct Stack *stack) {
    return stack->top == -1;
}

int stack_cheia(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void stack_push(struct Stack *stack, struct Peaple pessoa) {
    if (stack_cheia(stack)) {
        printf("Stack cheia! Não é possível adicionar mais pessoas.\n");
        return;
    }
    stack->pessoas[++stack->top] = pessoa;
}

void stack_pop(struct Stack *stack) {
    if (stack_vazia(stack)) {
        printf("Stack vazia! Não é possível remover pessoas.\n");
        return;
    }
    stack->top--;
}


int stack_top(struct Stack *stack, struct Peaple *pessoa) {
    if (stack_vazia(stack)) {
        printf("Stack vazia! Não há pessoas para mostrar.\n");
        return 0;
    }
    *pessoa = stack->pessoas[stack->top];
    return 1;
}

void stack_init(struct Stack *stack, int capacity) {
    stack->pessoas = (struct Peaple *)malloc(capacity * sizeof(struct Peaple));
    stack->top = -1;
    stack->capacity = capacity;
}

void stack_free(struct Stack *stack) {
    free(stack->pessoas);
    stack->pessoas = NULL;
    stack->top = -1;
    stack->capacity = 0;
}

void stack_print(struct Stack *stack) {
    if (stack_vazia(stack)) {
        printf("Stack vazia! Não há pessoas para mostrar.\n");
        return;
    }
    printf("Pessoas na stack:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("Nome: %s, Idade: %d\n", stack->pessoas[i].nome, stack->pessoas[i].idade);
    }
}
 
int main() {
    struct Stack stack;
    stack_init(&stack, 5);

    struct Peaple pessoa1 = {"Alice", 30};
    struct Peaple pessoa2 = {"Bob", 25};
    struct Peaple pessoa3 = {"Charlie", 35};

    stack_push(&stack, pessoa1);
    stack_push(&stack, pessoa2);
    stack_push(&stack, pessoa3);

    stack_print(&stack);

    struct Peaple topPessoa;
    if (stack_top(&stack, &topPessoa)) {
        printf("Pessoa no topo da stack: Nome: %s, Idade: %d\n", topPessoa.nome, topPessoa.idade);
    }

    stack_pop(&stack);
    stack_print(&stack);

    stack_free(&stack);
    return 0;
}