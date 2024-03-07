#include <stdio.h>

int main() {
    int vetor[5];
    
    printf("Digite 5 números inteiros:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &vetor[i]);
    }

    int *ptr = vetor;

    printf("\nO dobro de cada valor lido:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", (*ptr) * 2);
        ptr++;
    }

    return 0;
}