#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[10];

    printf("Digite dez valores:");
    for(int c = 0; c < 10; c++) {
        scanf("%d", &vet[c]);

        if(vet[c] < 0) {
            vet[c] = 0;
        }
    }

    for(int c = 0; c < 10; c++) {
        printf("%d", vet[c]);
        printf("\n");
    }

    return 0;

}