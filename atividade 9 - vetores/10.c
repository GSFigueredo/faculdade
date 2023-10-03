#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[15];
    float soma;

    printf("Digite a nota dos 15 alunos");
    for(int c = 0; c<15; c++) {
        scanf("%d", &vet[c]);

        soma += vet[c];
    }

    float media = soma/15;

    printf("A média entre as notas é: %.2f", media);

    return 0;
}