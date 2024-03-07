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

bool validarDadosT(float a, float b, float c) {
    int maior = a;
    int meio;
    int menor = a;

    if(b > maior) {
        maior = b;
    } else if (b < menor) {
        menor = b;
    }

    if(c > maior) {
        maior = c;
    } else if (c < menor) {
        menor = c;
    }

    if(a > menor && a < maior) {
        meio = a;
    } else if (b > menor && b < maior) {
        meio = b;
    } else {
        meio = c;
    }

    if ((meio+menor) >= maior) {
        return true;
    } else {
        return false;
    }
}

int main () {

    float a, b, c;

    printf("Digite o valor dos três lados de um triângulo:");
    scanf("%f %f %f", &a, &b, &c);

    if(validarDados(a, b, c) == true && validarDadosT(a, b, c) == true) {
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