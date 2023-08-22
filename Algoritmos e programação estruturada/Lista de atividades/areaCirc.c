#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){ 

    float raio;

    printf("Digite o valor do raio:");
    scanf("%f", &raio);

    float area = pow(raio, 2)*3.14;

    printf("O valor da área é: %f", area);

    return 0;
}