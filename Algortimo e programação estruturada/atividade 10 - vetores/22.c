#include <stdio.h>

int main() {
    int vetor1[10], vetor2[10], resultado[20];
    int i;

    printf("Digite 10 números inteiros para o primeiro vetor:\n");
    for (i = 0; i < 10; i++) {
        printf("vetor1[%d]: ", i);
        scanf("%d", &vetor1[i]);
    }

    printf("Digite 10 números inteiros para o segundo vetor:\n");
    for (i = 0; i < 10; i++) {
        printf("vetor2[%d]: ", i);
        scanf("%d", &vetor2[i]);
    }

    for (i = 0; i < 10; i++) {
        resultado[2 * i] = vetor1[i];
        resultado[2 * i + 1] = vetor2[i];
    }

    printf("Vetor resultado:\n");
    for (i = 0; i < 20; i++) {
        printf("resultado[%d]: %d\n", i, resultado[i]);
    }

    return 0;
}
