#include <stdio.h> 
#include <math.h> 

void alterarValor(int *pA, int *pB) {

    if(*pA > *pB) {
        //faça nada
    } else {
        int a = *pA;

        *pA = *pB; 
        *pB = a; 
    }
}

int main () {

    int a1, a2; 

    printf("Digite o valor de A1 e A2:"); 
    scanf("%d %d", &a1, &a2);

    alterarValor(&a1, &a2);

    printf("Valor das variáveis em ordem: %d %d", a1, a2);


    return 0;
}