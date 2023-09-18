#include <stdio.h>
#include <math.h>

int main () {

    float altC = 1.50;
    float altZ = 1.10;
    int ano = 0;

    while (altZ < altC) {
        altC += 0.2;
        altZ += 0.3;

        ano++;
    }

    printf("Foram necessários %d anos, para Zé ficar maior que Chico.", ano);

    return 0;
}