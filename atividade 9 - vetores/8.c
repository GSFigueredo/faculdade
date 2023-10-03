#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[6];

    printf("Digite seis valores para o vetor:");
    for(int c = 0; c<6; c++) {
        scanf("%d", &vet[c]);
    }

    printf("Valores na ordem inversa:");
    printf("\n");

    for(int c = 5; c>-1; c--) {
        printf("%d", vet[c]);
        printf("\n");
    }

    return 0;
}