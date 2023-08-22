#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int escolha;
    int valores[2];
    int cont;

    printf("Digite dois valores!");

    for (cont = 0; cont < 2; cont++)
    {
        printf("Valor %d:", cont);
        scanf("%d", &valores[cont]);
        printf("\n");
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
        printf("%d", soma);
        break;
    }
    case 2:
    {
        int sub = valores[0] - valores[1];
        printf("%d", sub);
        break;
    }
    case 3:
    {
        int mult = valores[0] * valores[1];
        printf("%d", mult);
        break;
    }
    case 4:
    {
        float div = (float)valores[0] / (float)valores[1];
        printf("%f", div);
        break;
    }

    default:
        printf("Algo está errado!");
        break;
    }

    system("clear");

    return 0;
}