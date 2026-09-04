#include <stdio.h>

float soma01(float a, float b){
    
    float reslr = (a + b) * b;
                 //Priorizando a soma primeiro 
    return reslr;
    // vai retorna numero com casas decimais
}



int main(){
    float resultado = soma01(10, 20);
                          // 10.0 + 20.0 = 30.0 and 30.0 X 20.0 = 600.0
                          
    printf("Resultado esperado %.2f\n", resultado);                      

    return 0;
}