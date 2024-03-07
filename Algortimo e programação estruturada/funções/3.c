#include <stdio.h>
#include <math.h>

float converteGraus(int graus) {
    float grausC = graus - 32;
    grausC = (grausC*5)/9;

    return grausC;
}

int main () {

    int graus;

    printf("Qual a temperatura? [F]");
    scanf("%d", &graus);

    float grausC = converteGraus(graus);

    printf("%d graus fahrenheit equivalem a %.2f graus celsius", graus, grausC);

    return 0;
}