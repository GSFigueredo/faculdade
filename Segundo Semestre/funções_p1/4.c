#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherMatriz(int matriz[61][10]) {
    for (int i = 0; i < 61; ++i) {
        for (int j = 0; j < 10; ++j) {
            matriz[i][j] = rand() % 100; 
        }
    }
}

void somarColunas(int matriz[61][10]) {
    for (int j = 0; j < 10; ++j) {
        int soma = 0;
        for (int i = 0; i < 61; ++i) {
            soma += matriz[i][j];
        }
        matriz[61][j] = soma;
    }
}

void exibirMatriz(int matriz[61][10]) {
    for (int i = 0; i < 62; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int matriz[61][10];

    preencherMatriz(matriz);

    printf("Matriz antes da operação:\n");
    exibirMatriz(matriz);

    somarColunas(matriz);

    printf("\nMatriz após a operação:\n");
    exibirMatriz(matriz);

    return 0;
}