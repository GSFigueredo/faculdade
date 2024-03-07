#include <stdio.h>
#include <math.h>

int main()
{

    int prato, quan;
    float preco;

    printf("--------------- Escolha um prato ---------------");

    printf("\n");
    printf("Cachorro quente [100]");
    printf("\n");
    printf("Bauro simples [101]");
    printf("\n");
    printf("Bauro com ovo [102]");
    printf("\n");
    printf("Hambúrguer [103]");
    printf("\n");
    printf("Cheesburguer [104]");
    printf("\n");

    scanf("%d", &prato);

    printf("Quantos você irá levar?");
    scanf("%d", &quan);

    switch (prato)
    {
    case 100:
        preco = 10.10 * quan;

        printf("Valor total: %.2f", preco);
        break;
    case 101:
        preco = 8.30 * quan;
        printf("Valor total: %.2f", preco);
        break;
    case 102:
        preco = 8.50 * quan;
        printf("Valor total: %.2f", preco);
        break;
    case 103:
        preco = 12.50 * quan;
        printf("Valor total: %.2f", preco);
        break;
    case 104:
        preco = 13.25 * quan;
        printf("Valor total: %.2f", preco);
        break;
    default:
        printf("Vai ficar com fome...");
    }

    return 0;
}