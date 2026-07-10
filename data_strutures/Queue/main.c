#include <stdio.h>
#include <stdlib.h>
#include "structure.h"


int main(void){
    Fila f;
    
    inicializar_init(&f);

    Pessoa p1 = {"Carlos", 24};
    Pessoa p2 = {"Daniel", 22};
    Pessoa p3 = {"Engenheiro", 28};

    queue(&f, &p1);
    queue(&f, &p2);
    queue(&f, &p3);


    printss(&f);





return 0;
}