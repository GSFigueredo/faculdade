#include <stdio.h>

int main() {
    int a, b, c, d;

    printf("Digite quatro valores: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int maior = a;
    int menor = a;

    if (b > maior) {
        maior = b;
    } else if (b < menor) {
        menor = b;
    }

    if (c > maior) {
        maior = c;
    } else if (c < menor) {
        menor = c;
    }

    if (d > maior) {
        maior = d;
    } else if (d < menor) {
        menor = d;
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);

    return 0;
}