#include <stdio.h> 
#include <math.h> 

void alterarValor(int *pA, int *pB) {

    *pA = *pA+*pB; 
}

int main () {

    int a, b; 

    printf("Digite o valor de A1 e A2:"); 
    scanf("%d %d", &a, &b);

    alterarValor(&a, &b);

   printf("Soma em A: %d\nValor em B: %d", a, b);

    return 0;
}