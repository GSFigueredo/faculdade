#include <stdio.h> 

/// selection sort

int main() { 
    int vetor [] = {24, 10, 2 , 3, 50};
    int temp;
    int maior = -1; 
    int posMaior = -1;

    for(int i = 0; i < 5; i++) {
        printf("%d \n", vetor[i]);
    }

    printf("------------------------------------------------------------");


    for(int j = 5; j > 0; j--) {
        maior = -1;

        for(int i = 0; i<= j; i++) {
            if(vetor[i] > maior) { 
                posMaior = i;
                maior = vetor[i];
            }
        }

        temp = vetor[posMaior];
        vetor[posMaior] = vetor[j];
        vetor[j] = temp;
    }

    for(int i = 0; i < 5; i++) {
        printf("%d \n", vetor[i]);
    }

    return 0;
}