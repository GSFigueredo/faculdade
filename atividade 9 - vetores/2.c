#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[6];

    printf("Digite seis valores:");
    for(int c = 0; c<6; c++) {
        scanf("%d", &vet[c]);
    }

    printf("Os valores digitados foram: ");
    printf("\n");
    for(int c = 0; c<6; c++) {
        printf("%d", vet[c]);
        printf("\n");
    }

    return 0;
}