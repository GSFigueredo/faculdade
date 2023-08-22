#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    float salario;
    int reajuste;

    printf("Qual o salário do funcionário?");
    scanf("%f", &salario);

    getchar();

    printf("De quantos porcento será o reajuste?");
    scanf("%d", &reajuste);

    reajuste *= salario;
    reajuste /=100; 

    salario += reajuste;

    printf("Com o reajuste, o salário base é: %.2f", salario);

    return 0;
}