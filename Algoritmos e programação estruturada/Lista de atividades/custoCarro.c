#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float custoV;

    printf("Qual o preço de custo da fabricação do veículo?");
    scanf("%f", &custoV);

    float custoDist = (custoV*28)/100;
    float custoImpo = (custoV*45)/100;
    float custoCons = custoV+custoDist+custoImpo;

    printf("Custo distribuição: %.2f", custoDist);
    printf("\nImpostos aplicados: %.2f", custoImpo);
    printf("\nCusto ao consumidor: %.2f", custoCons);
    printf("\n");

    return 0;
}