#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[5];
    int maior = 0, menor = 10, soma = 0; 

    printf("Digite cinco valores para o vetor:");
    for(int c = 0; c<6; c++) {
        scanf("%d", &vet[c]);

        if(vet[c] > maior) {
            maior = vet[c];
        }

        if(vet[c] < menor) {
            menor = vet[c];
        }

        soma += vet[c];
    }

    float media = soma/5;

    printf("Maior valor: %d", maior);
    printf("\n");
    printf("Menor valor: %d", menor);
    printf("\n");
    printf("Média: %.2f", media);

    return 0;
}