#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[10];
    int maior = 0, menor = 10; 

    printf("Digite dez valores para o vetor:");
    for(int c = 0; c<10; c++) {
        scanf("%d", &vet[c]);

        if(vet[c] > maior) {
            maior = vet[c];
        }

        if(vet[c] < menor) {
            menor = vet[c];
        }
    }

    printf("Maior valor: %d", maior);
    printf("\n");
    printf("Menor valor: %d", menor);

    return 0;
}