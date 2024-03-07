#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int a[6];

    a[0] = 1;
    a[1] = 0;
    a[2] = 5;
    a[3] = -2;
    a[4] = -5;
    a[5] = 7;


    int soma = a[0] + a[1] + a[5];

    a[4] = 100;

    printf("Soma: %d", soma);

    for(int c = -1; c<6; c++) {
        printf("%d", a[c]);
        printf("\n");
    }

    return 0;
}