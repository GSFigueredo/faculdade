#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){ 

    float compr;
    float larg;

    printf("Digite o valor do comprimento da sala:");
    scanf("%f", &compr);

    printf("Digite o valor da largura da sala:");
    scanf("%f", &larg);
    
    float area = compr*larg;

    printf("Sua área é: %.3f", area);

    return 0;
}