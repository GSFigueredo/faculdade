#include <stdio.h>
#include <math.h>
#include <string.h>

int main (){

    float vet[10];
    float result[10];

    printf("Digite 10 valores reais:");
    for(int c = 0; c<10; c++) {
        scanf("%f", &vet[c]);
    }

    for(int c = 0; c<10; c++) {
        result[c] = vet[c]*vet[c];
    }

    printf("Valores digitados:");
    for(int c = 0; c<10; c++) {
        printf("%.2f", vet[c]);
        printf("\n");
    }

    printf("Valores digitados ao quadrado:");
    for(int c = 0; c<10; c++) {
        printf("%.2f", result[c]);
        printf("\n");
    }

    return 0;
}