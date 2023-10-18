#include <stdio.h>
#include <math.h>

void maiorValor(int n1, int n2) {
    if(n1 > n2) {
        printf("Maior valor; %d", n1);
    } else {
        printf("Maior valor: %d", n2);
    }
}

int main () {

    int n1, n2;

    printf("Digite dois valores:");
    scanf("%d %d", &n1, &n2);

    maiorValor(n1, n2);

    return 0;
}