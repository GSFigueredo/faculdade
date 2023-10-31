#include <stdio.h> 
#include <math.h>
#include <string.h> 

void trocarLinha(int mat[10][10]) {

    int aux[10][10];
    int aux2[10][10];

    for(int c = 0; c<10; c++) {
        aux[2][c] = mat[2][c];
        aux2[8][c] = mat[8][c];
    }
    
    for(int c = 0; c<10; c++) {
        mat[2][c] = aux2[8][c];
        mat[8][c] = aux[2][c];
    }

    for(int l = 0; l < 10; l++) {

        printf("\n");

        for(int c = 0; c < 10; c++) {
            printf("%d\t", mat[l][c]);
        }
    }
}

void trocaColuna(int mat[10][10]) {
    int aux[10][10];
    int aux2[10][10];

    for(int c = 0; c<10; c++) {
        aux[c][4] = mat[c][4];
        aux2[c][10] = mat[c][10];
    }
    
    for(int c = 0; c<10; c++) {
        mat[c][4] = aux2[c][10];
        mat[c][10] = aux[c][4];
    }

    for(int l = 0; l < 10; l++) {

        printf("\n");

        for(int c = 0; c < 10; c++) {
            printf("%d\t", mat[l][c]);
        }
    }
}

int main() {

    int mat[10][10];

    for(int l = 0; l < 10; l++) {

        for(int c = 0; c < 10; c++) {
            mat[l][c] = rand() % 100+1;
        }

    }

    for(int l = 0; l < 10; l++) {

        printf("\n");

        for(int c = 0; c < 10; c++) {
            printf("%d\t", mat[l][c]);
        }

    }

    printf("\n");
    printf("------------------------------------------------------------------------");
    printf("\n");
    trocarLinha(mat);
    printf("\n-----------------------------------------------------------------------------------");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    for(int l = 0; l < 10; l++) {

        printf("\n");

        for(int c = 0; c < 10; c++) {
            printf("%d\t", mat[l][c]);
        }

    }

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    trocaColuna(mat);

    return 0;
}