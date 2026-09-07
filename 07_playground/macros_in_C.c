#include <stdio.h>


/*Conceitos de macros em C

macros são criadas usando o pré-processador,
através da diretiva #define. O pré-processador substitui 
o texto da macro no código antes da compilação propriamente dita


*/

//Macro basica 
#define PI 3.14159
#define TAMANHO 50

void macro_basica(){
    int vetor[TAMANHO];//vetor de 50 indices
    double area = PI ; // area e o valor de PI
}
// Toda vez que o compilador encontra PI ou MAX_TAMANHO, ele substitui pelo valor literal antes de compilar.

//Macro com parâmetros (função-like)
//Macros também podem se comportar como funções:
#define QUADRADO(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a):(b))

void macro_com_parametros(){
    int result = QUADRADO(5); // 5x5=25
    int maior = MAX(10, 50); // 10 > 50 = false = 50
}