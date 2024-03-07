#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[8];
    int x, y;

    printf("Digite oito valores para o vetor:");
    for(int c = 0; c<9; c++) {
        scanf("%d", &vet[c]);
    }

    printf("Digite os valores de X e Y respectivamente:");
    scanf("%d %d", &x, &y);

    int soma = vet[x] + vet[y];

    printf("A soma é: %d", soma);

    return 0;
}