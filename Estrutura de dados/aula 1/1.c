#include <stdio.h> 
#include <math.h> 

int main () {

    int *ponteiro;
    int numero = 200;

    ponteiro = &numero;

    *ponteiro = 150;

    printf("%d", *ponteiro); 

    return 0;
}