#include <stdio.h>
#include <math.h>
#include <stdbool.h>


bool validarDados(float a, float b, float c) {
    if(a <= 0 || b <= 0 || c<= 0) {
        return false;
    } else {
        return true;
    }
}

int main () {

    float a, b, c;

    printf("Digite o valor dos três lados de um triângulo:");
    scanf("%f %f %f", &a, &b, &c);

    if(validarDados(a, b, c) == true) {
        
    }

    return 0;
}