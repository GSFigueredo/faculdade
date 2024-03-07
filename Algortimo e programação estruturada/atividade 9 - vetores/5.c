#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[10];
    int par = 0;

    printf("Digite dez valores para o vetor:");
    for(int c = 0; c<10; c++) {
        scanf("%d", &vet[c]);

        if(vet[c] % 2 == 0) {
            par++;
        }
    }

    printf("Possuí %d valores pares", par);

    return 0;
}