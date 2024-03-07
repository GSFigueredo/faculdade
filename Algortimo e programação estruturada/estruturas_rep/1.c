#include <stdio.h>
#include <math.h>

int main() {

    int n1;
    int c = 0;

    printf("Digite um número limite:");
    scanf("%d", &n1);

    while(c <= n1) {

        printf("\nValor: %d", c);

        c++;
    }
}