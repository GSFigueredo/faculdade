#include <stdio.h>

int main() {
    int vetor1[10];
    int vetor2[10];
    int i, j = 0; 

    printf("Digite 10 números inteiros no intervalo [0, 50]:\n");

    for (i = 0; i < 10; i++) {
        do {
            printf("Digite o %dº número: ", i + 1);
            scanf("%d", &vetor1[i]);
        } while (vetor1[i] < 0 || vetor1[i] > 50);

        if (vetor1[i] % 2 != 0) {
            vetor2[j] = vetor1[i];
            j++;
        }
    }

    printf("Primeiro vetor: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor1[i]);
    }
    printf("\n");

    printf("Segundo vetor (ímpares): ");
    for (i = 0; i < j; i++) {
        printf("%d ", vetor2[i]);
    }
    printf("\n");

    return 0;
}
