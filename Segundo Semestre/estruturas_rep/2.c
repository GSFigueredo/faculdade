#include <stdio.h>
#include <math.h>

int main() {

    int n1;

    printf("Digite um número limite:");
    scanf("%d", &n1);

    while( n1 >=0) {

        printf("\nValor: %d", n1);

        n1--;
    }
}