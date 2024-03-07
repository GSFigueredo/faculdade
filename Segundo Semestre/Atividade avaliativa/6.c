#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int testarValor(int x, int y) {
    if(x > 0 && y > 0) {
        return 1;
    } else if (x < 0 && y > 0) {
        return 2;
    } else if(x < 0 && y < 0) {
        return 3;
    } else if(x > 0 && y < 0) {
        return 4;
    } else if (x == 0 && y != 0){
        return 5;
    } else if (x != 0 && y == 0) {
        return 6;
    } else {
        return 0;
    }
}

int main () {

    int x, y;

    printf("Digite o valor de X e Y [respectivamente]");
    scanf("%d %d", &x, &y);

    int resultado = testarValor(x, y);

    if(resultado == 1) {
        printf("Primeiro quadrante (%d , %d)", x, y);
    } else if (resultado == 2) {
        printf("Segundo quadrante (%d , %d)", x, y);
    } else if (resultado == 3){
        printf("Terceiro quadrante (%d , %d)", x, y);
    } else if (resultado == 4) {
        printf("Quarto quadrante (%d , %d)", x, y);
    } else if(resultado == 5){
        printf("Eixo X (%d , %d)", x, y);
    } else if(resultado == 6) {
        printf("Eixo Y (%d , %d)", x, y);
    } else {
        printf("O ponto está na origem");
    }

    return 0;
}