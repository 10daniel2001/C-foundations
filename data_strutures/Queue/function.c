#include <stdio.h>
#include <stdlib.h>
#include "structure.h" //Chamando o arquivo de cabeçalho que contem a estrutura da fila e as funçoes
//Calling the header file that contains the queue structure and functions

void inicializar_init(Fila *f){
    f->inicio = 0;
    f->fim = 0;
    f->total = 0; //Inicializando a fila com valores nulos para garantir que não haja lixo de memória

    // initialize the queue with null values to ensure there is no memory garbage

    //Vamos inicializar a fila com valores nulos para garantir que não haja lixo de memória
    for (int i = 0; i < Tamanho; i++)
    {
        f->intens[i].idade = 0;
        f->intens[i].nome[0] = '\0'; // Inicializando o nome como uma string vazia
    }   
}



int fila_cheia(Fila *f){
    return f->total == Tamanho;
    //Check if the queue is full by comparing the total number of elements with the maximum size (Tamanho)
    //Verifica se a fila está cheia comparando o número total de elementos com o tamanho máximo (Tamanho)
}



int fila_vazia(Fila *f){
    return f->total == 0; 
    //Check if the queue is empty by checking if the total number of elements is zero
    //Verifica se a fila está vazia verificando se o número total de elementos é zero
}



void queue(Fila *f, Pessoa *p){
    //Check if the queue is full before adding a new element
    //Verifica se a fila está cheia antes de adicionar um novo elemento
    if (fila_cheia(f))
    {
        printf("Fila esta cheia, nao e possivel inserir!\n");
        exit(1);
        //If the queue is full, print a message and exit the program
        //Se a fila estiver cheia, imprime uma mensagem e sai do programa
    }

    f->intens[f->fim] = *p;
    f->fim = (f->fim + 1) % Tamanho;
    f->total++;
    //Add the new element to the end of the queue, update the end index and increment the total number of elements
    //Adiciona o novo elemento ao final da fila, atualiza o índice do final e incrementa o número total de elementos    

}

void printss(Fila *f){
    printf("Mostrar Fila :\n");
    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx +1) % Tamanho)
    {
        printf("Nome >> %s -- Idade >> %d\n", f->intens[idx].nome, f->intens[idx].idade);
    }
    //Print the contents of the queue by iterating through the elements from the start index to the total number of elements
    //Imprime o conteúdo da fila iterando pelos elementos desde o índice inicial até o número
}

void dequeue(Fila *f, Pessoa *p){
    //Check if the queue is empty before removing an element
    //Verifica se a fila está vazia antes de remover um elemento
    if (fila_vazia(f))
    {
        printf("Fila esta vazia, nao e possivel remover!\n");
        exit(1);
        //If the queue is empty, print a message and exit the program
        //Se a fila estiver vazia, imprime uma mensagem e sai do programa
    }

    *p = f->intens[f->inicio];
    f->inicio = (f->inicio + 1) % Tamanho;
    f->total--;
    //Remove the element from the front of the queue, update the start index and decrement the total number of elements
    //Remove o elemento do início da fila, atualiza o índice inicial e decrementa o número total de elementos
}

void peek(Fila *f, Pessoa *p){
    //Check if the queue is empty before peeking at the front element
    //Verifica se a fila está vazia antes de espiar o elemento da frente
    if (fila_vazia(f))
    {
        printf("Fila esta vazia, nao e possivel espiar!\n");
        exit(1);
        //If the queue is empty, print a message and exit the program
        //Se a fila estiver vazia, imprime uma mensagem e sai do programa
    }

    *p = f->intens[f->inicio];
    //Peek at the front element of the queue without removing it
    //Espia o elemento da frente da fila sem removê-lo
}

void clear(Fila *f){
    f->inicio = 0;
    f->fim = 0;
    f->total = 0; //Reset the queue by setting the start index, end index, and total number of elements to zero
    //Limpa a fila definindo o índice inicial, o índice final e o número total de elementos como zero
}