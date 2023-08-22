#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int escolha;
    int valores[2];
    int cont;

    printf("Digite dois valores!");

    printf("\n");

    for (cont = 0; cont < 2; cont++)
    {
        printf("Valor %d:", cont);
        scanf("%d", &valores[cont]);
    }

    printf("O que você deseja fazer com esses valores?");
    printf("\n [1] Soma , [2] Subtrair, [3] Multiplicar, [4] Dividir");

    printf("%d", valores[0]);
    printf("%d", valores[1]);

    scanf("%d", &escolha);

    printf("\n");

    switch (escolha) {

    case 1:
    {
        int soma = valores[0] + valores[1];
        printf("%d + %d = %d", valores[0], valores[1], soma);
        break;
    }
    case 2:
    {
        int sub = valores[0] - valores[1];
        printf("%d - %d = %d", valores[0], valores[1], sub);
        break;
    }
    case 3:
    {
        int mult = valores[0] * valores[1];
        printf("%d x %d = %d", valores[0], valores[1], mult);
        break;
    }
    case 4:
    {
        float div = valores[0] / valores[1];
        printf("%d / %d = %.1f", valores[0], valores[1], div);
        break;
    }

    default:
        printf("Algo está errado!");
        break;
    }

    return 0;
}