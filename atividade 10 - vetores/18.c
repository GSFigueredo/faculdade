#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[10];
    int x = 0;

    printf("Digite dez valores:");
    for(int c = 0; c < 10; c++) {
        scanf("%d", &vet[c]);
    }

    printf("Digite um valor para X:");
    scanf("%d", &x);


    printf("Multiplos de %d:", x);
    printf("\n");
    
    for(int c = 0; c < 10; c++) {
        if(x%vet[c] == 0) {
            printf("%d\n", vet[c]);
        }
    }

}