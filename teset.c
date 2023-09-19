#include <stdio.h>
#include <string.h>
#include <math.h>

int somarValores(int n1, int n2) {
    int soma = n1 + n2;

    return soma;
}

int main () {

    int x = 2;
    int y = 5;

    int resultado = somarValores(5, 23);

    printf("%d", resultado);

}