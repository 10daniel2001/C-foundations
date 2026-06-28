#include <stdio.h>

void increment(int *ptr) {
    (*ptr)++;
}

void somar(int *a){
    *a = *a + 10;
}


int main() {
    int num = 5;
    printf("Before increment: %d\n", num);
    increment(&num);
    printf("After increment: %d\n", num);

    somar(&num);
    printf("After somar: %d\n", num);

    return 0;
}