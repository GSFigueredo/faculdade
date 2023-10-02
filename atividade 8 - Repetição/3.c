#include <stdio.h>
#include <math.h>

int main()
{

    int termo;
    int valorAntigo, valorAtual, valorNovo;

    valorAntigo = 0;
    valorAtual = 1;

    printf("Até qual termo você deseja ver a sequencia fibonacci?");
    scanf("%d", &termo);

    for (int c = 0; c < termo; c++){
        printf("%d", valorAntigo);
        printf(" ");

        valorNovo = valorAntigo + valorAtual;
        valorAntigo = valorAtual;
        valorAtual = valorNovo;
    }

    return 0;
}