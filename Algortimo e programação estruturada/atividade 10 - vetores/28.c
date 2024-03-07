#include <stdio.h>

int main() {
    int v[10];
    int v1[10];
    int v2[10];
    int i, j = 0, k = 0;

    for (i = 0; i < 10; i++) {
        printf("Digite o %dº número inteiro: ", i + 1);
        scanf("%d", &v[i]);
    }

    for (i = 0; i < 10; i++) {
        if (v[i] % 2 == 0) {
            v2[j] = v[i];
            j++;
        } else {
            v1[k] = v[i];
            k++;
        }
    }

    printf("Elementos utilizados de v1 (ímpares):\n");
    for (i = 0; i < k; i++) {
        printf("%d\n", v1[i]);
    }

    printf("Elementos utilizados de v2 (pares):\n");
    for (i = 0; i < j; i++) {
        printf("%d\n", v2[i]);
    }

    return 0;
}
