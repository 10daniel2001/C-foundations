#include <stdio.h>
#include <stdlib.h>

/*Busca binaria*/

void search(int vetor[], int n, int target){
    int i, j;

    for ( i = 0; i < n; i++)
    {
        if (vetor[i] == target)
        {
            printf("Target %d\n", vetor[i]);
          
        }
        
    }
    
}

int main(){
    int veto[] = {2,5,4,8,9,7};
    int n = sizeof(veto)/sizeof(veto[0]);
    int target = 2;

    printf("Busca binaria\n");
    search(veto, n, target);

    return 0;
}