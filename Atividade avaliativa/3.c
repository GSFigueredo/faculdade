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
        if(a == b && b == c) {
            printf("Triangulo equilatero");
        } else if (a != b && a != c && b != c) {
            printf("Triangulo escaleno");
        } else {
            printf("Triangulo isóceles");
        }
    } else {
        printf("Valores não suportados");
    }

    return 0;
}