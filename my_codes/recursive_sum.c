#include <stdio.h>
#include <stdlib.h>

/*Para representa como a funçao retorna e como pode haver um stack overflow
  mas neste caso nao a erro, pois o if verifica e termina a funçao
  Diria que a complexidade e linear temporal e linear de espacial
*/
void function_recursive(int value)
{
    if (value == 0)
    {
        printf("Fim\n");
        return;
    }

    printf("%d\n", value);

    function_recursive(value - 5);

    printf("Voltando %d\n", value);
}


int main(){
    
    function_recursive(25);


    return 0;
}