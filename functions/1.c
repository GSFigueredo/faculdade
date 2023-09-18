#include <stdio.h>

int somarValores(int n1, int n2) {
        int soma = n1 +n2;

        return soma;
    }

int main() {

    int result = somarValores(2, 4);

    printf("Resultado: %d", result);

    return 0;
}