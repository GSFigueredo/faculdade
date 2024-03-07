#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {

    int vet[10];
    int vetGP[10] = {0}; 

    printf("Digite dez valores:");
    for (int c = 0; c < 10; c++) {
        scanf("%d", &vet[c]);
    }

    for (int c = 0; c < 10; c++) {
        for (int c1 = c + 1; c1 < 10; c1++) {
            if (vet[c] == vet[c1]) {
                vetGP[c1] = vet[c];
            }
        }
    }

    printf("Valores repetidos:\n"); 
    for (int c = 0; c < 10; c++) {
        if (vetGP[c] != 0) {
            printf("%d\n", vetGP[c]);
        }
    }

    return 0;
}
