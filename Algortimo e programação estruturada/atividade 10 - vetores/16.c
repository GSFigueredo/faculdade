#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    float vet[5];
    int cod;

    printf("Digite 5 valores:");
    for(int c = 0; c < 5; c++) {
        scanf("%f", &vet[c]);
    }

    printf("Digite o código:");
    scanf("%d", &cod);

    if(cod == 0) {
        return 0;
    } else if (cod == 1) {
        for(int c = 0; c < 5; c++) {
            printf("%.2f", vet[c]);
            printf("\n");
        }
    } else if(cod == 2) {
        for(int c = 5; c > 0; c--) {
            printf("%.2f", vet[c]);
            printf("\n");
        }
    } else {
        printf("Código inválido...");
    }

    return 0;
}