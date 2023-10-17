#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {

    char nome[3][30];
    float notas[3][3], media, soma = 0;

    for (int c = 0; c < 3; c++) {
        printf("Digite um nome: \n");
        fgets(nome[c], sizeof(nome[c]), stdin);
    }

    for(int l = 0; l < 3; l++) {

        soma = 0;

        for (int c = 0; c < 3; c++) {
            printf("Digite as três notas do aluno(a) %s", nome[l]);
            scanf("%f", &notas[l][c]);

            soma += notas[l][c];
        }

        media = soma/3;

        printf("Aluno %s", nome[l]);
        printf("Media: %.2f", media);
        printf("\n");
        printf("-------------");
        printf("\n");
    }

    return 0;
}