#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    float raio;

    printf("Digite o valor do raio:");
    scanf("%f", &raio);

    raio *= raio;
    float area = raio*3.14;

    printf("O valor da área é: %.2f", area);

    return 0;
}