#include <stdio.h>
#include <math.h>

int main() { 

    int n1;
    int som = 0;
    int c = 0;

    printf("Digite um número:");
    scanf("%d", &n1);

    do {

        //sem usar estruturas condicionais

        c +=2;
        int imp = c-1;

        printf("\n%d", imp);

        som += imp;

    } while(c <= n1);


    printf("\nA soma entre os valores é: %d", som);
    return 0;
}