#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[10];
    int soma = 0;
    int negativos = 0;

    printf("Digite dez valores para o vetor:");
    for(int c = 0; c<10; c++) {
        scanf("%d", &vet[c]);

        if(vet[c] > 0) {
            soma += vet[c];
        }

        if(vet[c] < 0) {
            negativos++;
        }
    }

    printf("Soma de valores positivos: %d", soma);
    printf("\n");
    printf("Quantidade de valores negativos: %d", negativos);

    return 0;
}