#include <stdio.h>
#include <math.h>

float calcularX(int x) {
    float result = (((5*x + 3)) / sqrt(x*x - 16));

    return result;
}

int main () {

    int x;

    printf("Digite o valor de X:"); 
    scanf("%d", &x);

    float result = calcularX(x);

    printf("f(x) = %.2f", result);

    return 0;
}