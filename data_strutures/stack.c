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
// Struct peaple representa uma pessoa com nome e idade
// struct peaple representing a person with name and age


struct Stack {
    struct Peaple *pessoas;
    int top;
    int capacity;
};
// Struct stack representa a pilha de pessoas
// struct stack representing the stack of people


int stack_vazia(struct Stack *stack) {
    return stack->top == -1;
}
// Função para verificar se a pilha está vazia
// Function to check if the stack is empty


int stack_cheia(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}
// Função para verificar se a pilha está cheia
// Function to check if the stack is full



void stack_push(struct Stack *stack, struct Peaple pessoa) {
    if (stack_cheia(stack)) {
        printf("Stack cheia! Não é possível adicionar mais pessoas.\n");
        return;
    }
    stack->pessoas[++stack->top] = pessoa;
}
// Função para adicionar uma pessoa à pilha
// Function to add a person to the stack



void stack_pop(struct Stack *stack) {
    if (stack_vazia(stack)) {
        printf("Stack vazia! Não é possível remover pessoas.\n");
        return;
    }
    stack->top--;
}
// Função para remover a pessoa do topo da pilha
// Function to remove the person from the top of the stack



int stack_top(struct Stack *stack, struct Peaple *pessoa) {
    if (stack_vazia(stack)) {
        printf("Stack vazia! Não há pessoas para mostrar.\n");
        return 0;
    }
    *pessoa = stack->pessoas[stack->top];
    return 1;
}
// Função para obter a pessoa do topo da pilha
// Function to get the person from the top of the stack




void stack_init(struct Stack *stack, int capacity) {
    stack->pessoas = (struct Peaple *)malloc(capacity * sizeof(struct Peaple));
    stack->top = -1;
    stack->capacity = capacity;
}
// Função para inicializar a pilha com uma capacidade específica
// Function to initialize the stack with a specific capacity




void stack_free(struct Stack *stack) {
    free(stack->pessoas);
    stack->pessoas = NULL;
    stack->top = -1;
    stack->capacity = 0;
}
// Função para liberar a memória alocada para a pilha
// Function to free the memory allocated for the stack




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
// Função para imprimir as pessoas na pilha
// Function to print the people in the stack



 
int main() {
    struct Stack stack;
    // Inicializa a pilha com capacidade para 5 pessoas
    // Initializes the stack with capacity for 5 people
    stack_init(&stack, 5);

    struct Peaple pessoa1 = {"carlos", 30};
    struct Peaple pessoa2 = {"daniel", 25};
    struct Peaple pessoa3 = {"Neymar", 35};

    stack_push(&stack, pessoa1);
    stack_push(&stack, pessoa2);
    stack_push(&stack, pessoa3);
    // Adiciona pessoas à pilha
    // Adds people to the stack

    stack_print(&stack);

    struct Peaple topPessoa;
    if (stack_top(&stack, &topPessoa)) {
        printf("Pessoa no topo da stack: Nome: %s, Idade: %d\n", topPessoa.nome, topPessoa.idade);
    }
    // Obtém a pessoa do topo da pilha
    // Gets the person from the top of the stack

    stack_pop(&stack);
    // Remove a pessoa do topo da pilha
    // Removes the person from the top of the stack


    stack_print(&stack);

    stack_free(&stack);
    return 0;
}