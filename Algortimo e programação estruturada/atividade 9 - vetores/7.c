#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[10];
    int posicao;
    int maior = 0;

    printf("Digite dez valores para o vetor:");
    for(int c = 0; c<10; c++) {
        scanf("%d", &vet[c]);

        if(vet[c] > maior) {
            maior = vet[c];
            posicao = c;
        }
    }

    for(int c = 0; c<10; c++) {
        printf("%d", vet[c]);
        printf("\n");
    }

    printf("Maior valor: %d", maior);
    printf("\n");
    printf("Posição do maior valor: %d", posicao);

    return 0;
}