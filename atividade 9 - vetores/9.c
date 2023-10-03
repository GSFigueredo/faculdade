#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){

    int vet[6];

    printf("Digite seis valores pares para o vetor:");
    for (int c = 0; c < 6; c++){

        scanf("%d", &vet[c]);

        if (vet[c] % 2 != 0){
            printf("Valor inválido");
            return 0;
        }

    }


    printf("Valores na ordem inversa:");
    printf("\n");

    for (int c = 5; c > -1; c--){
        printf("%d", vet[c]);
        printf("\n");
    }

    return 0;
}