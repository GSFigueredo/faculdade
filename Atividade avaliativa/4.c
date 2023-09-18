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
    int tipo;

    printf("Digite o valor dos três lados de um triângulo:");
    scanf("%f %f %f", &a, &b, &c);

    if(validarDados(a, b, c) == true) {
        if(a == b && b == c) {
            printf("Triangulo equilatero");
            tipo = 1;
        } else if (a != b && a != c && b != c) {
            printf("Triangulo escaleno");
            tipo = 2;
        } else {
            printf("Triangulo isóceles");
            tipo = 3;
        }

        
    }

    return 0;
}