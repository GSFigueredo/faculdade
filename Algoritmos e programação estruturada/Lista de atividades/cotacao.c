#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() { 

    float valor;

    printf("Quantos reais você deseja converter para dolar?");
    scanf("%f", &valor);

    valor /= 4.98;

    printf("O dólar está $4.98, o valor em dolar é: %.3f dólares!", valor);

    return 0;
}