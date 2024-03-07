#include <stdio.h>

int main() {
    int A[10], B[10], C[10];
    int i;

    printf("Digite 10 números inteiros para o vetor A:\n");
    for (i = 0; i < 10; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("Digite 10 números inteiros para o vetor B:\n");
    for (i = 0; i < 10; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    for (i = 0; i < 10; i++) {
        C[i] = A[i] - B[i];
    }

    printf("Vetor C (A - B):\n");
    for (i = 0; i < 10; i++) {
        printf("C[%d]: %d\n", i, C[i]);
    }

    return 0;
}
