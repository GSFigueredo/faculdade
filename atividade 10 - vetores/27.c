#include <stdio.h>
#include <math.h>

int ehPrimo(int numero) {
    if (numero <= 1) return 0;
    if (numero <= 3) return 1;
    if (numero % 2 == 0 || numero % 3 == 0) return 0;
    
    for (int i = 5; i * i <= numero; i += 6) {
        if (numero % i == 0 || numero % (i + 2) == 0)
            return 0;
    }
    
    return 1;
}

int main() {
    int vetor[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("Digite o %dº número inteiro: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Números primos no vetor e suas posições:\n");
    for (i = 0; i < 10; i++) {
        if (ehPrimo(vetor[i])) {
            printf("Vetor[%d] = %d\n", i, vetor[i]);
        }
    }

    return 0;
}
