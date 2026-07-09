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