#include <stdio.h>
#include <stdlib.h>

// Exemplo representativo de uma estrutura onde exite nome modelo e identificaçao de varios carros
// E vou usar ordenaçao para deixa los organizado de acordo com id 
struct Cars{
    char name[20];
    char model[20];
    int id;
};

void trocar(struct Cars* a, struct Cars *b){
    struct Cars temp = *a;
    *a = *b;
    *b = temp;
}