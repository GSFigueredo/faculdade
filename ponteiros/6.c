#include <stdio.h> 
#include <math.h> 

int alterarValor(int *pA, int *pB) {

    *pA = *pA*2; 
    *pB = *pB*2; 
    int soma = *pA + *pB;

    return soma;
}

int main () {

    int a, b; 

    printf("Digite o valor de A1 e A2:"); 
    scanf("%d %d", &a, &b);

    int soma = alterarValor(&a, &b);

    printf("A soma entre o dobro dos valores é: %d", soma);


    return 0;
}