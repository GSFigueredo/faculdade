#include <stdio.h>

int main()
{

    float vet[3];
    int cont;

    for (cont = 0; cont < 3; cont++)
    {
        printf("Digite o valor da nota %d:", cont);
        scanf("%f", &vet[cont]);
    }

    float media = ((vet[0] * 1) + (vet[1] * 1) + (vet[2] * 2)) / (1+1+2);

    if (media >= 7)
    {
        printf("Aluno com média %.2f [APROVADO]", media);
    } else {
        printf("Aluno com média %.2f [REPROVADO]", media);
    }
}