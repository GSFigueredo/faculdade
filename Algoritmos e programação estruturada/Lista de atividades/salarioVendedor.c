#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int carrosVend;
    float vendasTot;

    float salario;
    float comissaoPorCarro;
    float comissaoPorVenda;

    printf("Quantos carros foram vendidos pelo colaborador?");
    scanf("%d", &carrosVend);

    getchar();

    printf("Qual o valor total das vendas do colaborador?");
    scanf("%f", &vendasTot);

    getchar();

    printf("Qual o salário do colaborador?");
    scanf("%f", &salario);

    getchar();

    printf("Quanto o colaborador recebe de comissão por carro vendido?");
    scanf("%f", &comissaoPorCarro);

    getchar();

    comissaoPorCarro *= carrosVend;
    comissaoPorVenda = (vendasTot*5)/100;

    float salarioFinal = salario+comissaoPorCarro+comissaoPorVenda;

    printf("Salário final do colaborador: %.2f", salarioFinal);


}