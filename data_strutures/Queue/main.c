#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
//Chamando o arquivo de cabeçalho que contem a estrutura da fila e as funçoes
//Calling the header file that contains the queue structure and functions
//Main function to demonstrate the usage of the queue data structure
//Função principal para demonstrar o uso da estrutura de dados fila


int main(void){
    Fila f; //Declaring a variable of type Fila to represent the queue
            //Declarando uma variável do tipo Fila para representar a fila
    
    Pessoa p; //Declaring a variable of type Pessoa to represent a person
              //Declarando uma variável do tipo Pessoa para representar uma pessoa        
    inicializar_init(&f);
    //Initializing the queue by calling the inicializar_init function
    //Inicializando a fila chamando a função inicializar_init


    Pessoa p1 = {"Carlos", 24};
    Pessoa p2 = {"Daniel", 22};
    Pessoa p3 = {"Engenheiro", 28};
    //Creating three Pessoa instances with names and ages
    //Criando três instâncias de Pessoa com nomes e idades
    //Adding the Pessoa instances to the queue by calling the queue function
    //Adicionando as instâncias de Pessoa à fila chamando a função queue


    queue(&f, &p1);
    queue(&f, &p2);
    queue(&f, &p3);
    //Printing the contents of the queue by calling the printss function
    //Imprimindo o conteúdo da fila chamando a função printss
    printss(&f);
    
    printf("Fila esta cheia? %s\n", fila_cheia(&f) ? "Sim" : "Nao");
    printf("Fila esta vazia? %s\n", fila_vazia(&f) ? "Sim" : "Nao");
    //Checking if the queue is full or empty by calling the fila_cheia and fila_vazia functions and printing the results
    //Verificando se a fila está cheia ou vazia chamando as funções fila_cheia e fila_vazia e imprimindo os resultados

    printf("Dequeueing elements from the queue:\n");
    dequeue(&f, &p);
    //Dequeueing two elements from the queue by calling the dequeue function
    //Desenfileirando dois elementos da fila chamando a função dequeue

    printss(&f);

    peek(&f, &p);
    //Peeking at the front element of the queue by calling the peek function
    //Visualizando o elemento da frente da fila chamando a função peek



clear(&f);
return 0;
}