#include <stdio.h> 
#include <math.h> 

void alterarValor(int *pA, int *pB) {
    int a = *pA;

    *pA = *pB; 
    *pB = a;
}

int main () {

    int a, b; 

    printf("Digite o valor de A e B:"); 
    scanf("%d %d", &a, &b);

    printf("Valor de A e B antes da alteração: %d, %d", a, b);

    alterarValor(&a, &b);

    printf("\nValor de A e B depois da alteração: %d, %d", a, b);


    return 0;
}