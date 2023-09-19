#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool validarDados(float a, float b, float c, float d) {
    if(a <= 0 || b <= 0 || c<= 0 || d<= 0) {
        return false;
    } else {
        return true;
    }
}

int main () {

    float x1, y1, x2, y2;

    printf("Digite os quatro valores:");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    if(validarDados(x1, y1, x2, y2) == true) {
        float resultado = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));

        printf("%.4f", resultado);
    } else {
        printf("Valores inválidos");
    }

    return 0;
}