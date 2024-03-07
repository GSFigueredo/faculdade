#include <stdio.h> 
#include <math.h> 

int mudarValor(int *p) {
    *p = 500; 
}

int main () {

    int a = 10; 

    int *pA;

    printf("variavel a: %d", a);
    printf("\n");

    mudarValor(&a);

    printf("variavel a: %d", a);
    printf("\n");

    return 0;
}