#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[5];
    int maior = 0, menor = 10; 
    int posicaoMa = 0, posicaoMe = 0;

    printf("Digite cinco valores para o vetor:");
    for(int c = 0; c<6; c++) {
        scanf("%d", &vet[c]);

        if(vet[c] > maior) {
            maior = vet[c];
            posicaoMa = c;
        }

        if(vet[c] < menor) {
            menor = vet[c];
            posicaoMe = c;
        }
    }

    printf("Maior valor: %d na posição %d", maior, posicaoMa);
    printf("\n");
    printf("Menor valor: %d na posição %d", menor, posicaoMe);
    printf("\n");

    
    return 0;
}