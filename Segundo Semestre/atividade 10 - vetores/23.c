#include <stdio.h>

int main() {
    double vetor1[5], vetor2[5];
    double produto_escalar = 0.0; 
    int i;

    printf("Digite 5 números reais para o primeiro vetor:\n");
    for (i = 0; i < 5; i++) {
        printf("vetor1[%d]: ", i);
        scanf("%lf", &vetor1[i]);
    }

    printf("Digite 5 números reais para o segundo vetor:\n");
    for (i = 0; i < 5; i++) {
        printf("vetor2[%d]: ", i);
        scanf("%lf", &vetor2[i]);
    }

    for (i = 0; i < 5; i++) {
        produto_escalar += vetor1[i] * vetor2[i];
    }

    printf("Primeiro vetor:\n");
    for (i = 0; i < 5; i++) {
        printf("vetor1[%d]: %lf\n", i, vetor1[i]);
    }

    printf("Segundo vetor:\n");
    for (i = 0; i < 5; i++) {
        printf("vetor2[%d]: %lf\n", i, vetor2[i]);
    }

    printf("Produto escalar: %lf\n", produto_escalar);

    return 0;
}
