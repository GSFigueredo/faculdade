#include <stdio.h>

int main() {

    int vet[3];

    int a, b , c, cont;

    printf("Digite três valores:");
    scanf("%d %d %d", &a, &b, &c);

    int maior = a;
    int meio;
    int menor = a;

    if(b > maior) {
        maior = b;
    } else if (b < menor) {
        menor = b;
    }

    if(c > maior) {
        maior = c;
    } else if (c < menor) {
        menor = c;
    }

    if(a > menor && a < maior) {
        meio = a;
    } else if (b > menor && b < maior) {
        meio = b;
    } else {
        meio = c;
    }

    vet[0] = maior;
    vet[1] = meio;
    vet[2] = menor;

    for(cont = 0; cont<3; cont++) {
        printf("%d", vet[cont]);
        printf("\n");
    }

    return 0;
}