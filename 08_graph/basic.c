#include <stdio.h>

#define Tamm 5
// Constante global com tamanho fixo definido
// Ou macro 

void grafos(){

    // Matriz do tipo inteiro para representar 
    int graphh[Tamm][Tamm] = {0};

    //Exemplo de uma matriz
    for(int g = 0; g < Tamm; g++){
        for (int i = 0; i < Tamm; i++)
        {
            printf("%d ", graphh[g][i]);
        }
        printf("\n");
    }

    graphh[0][1] = 1;
    graphh[0][0] = 0;
    graphh[1][2] = 1;
    graphh[2][1] = 1;
    graphh[4][3] = 0;
printf("\n");
    for (int i = 0; i < Tamm; i++)
    {
        for (int j = 0; j < Tamm; j++)
        {
            printf("%d ", graphh[i][j]);
        }
        
        printf("\n");
    }
    



}

int main(){

    grafos();

    return 0;
}