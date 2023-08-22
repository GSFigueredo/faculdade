#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float custo;
    float frete;

    float event;
    float venda;

    printf("Qual o custo da mercadoria?");
    scanf("%f", &custo);

    getchar();

    printf("Qual o valor do frete?");
    scanf("%f", &frete);

    getchar();

    printf("Quais os valores eventuais da produção?");
    scanf("%f", &event);

    getchar();

    printf("Qual o valor de venda do produto?");
    scanf("%f", &venda);

    getchar();

    float margem = venda - (frete+custo+event);

    float lucro = (margem/venda) * 100;

    printf("Com os valores fornecidos, é possível saber que a porcentagem de lucro é: %.3f porcento", lucro);

    return 0;
}