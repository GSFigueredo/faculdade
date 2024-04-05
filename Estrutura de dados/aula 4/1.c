#include <stdio.h> 

/// bubble sort

int main() { 
    int vetor [] = {50, 10, 2 , 3, 24};
    int temp;

    for(int i = 0; i < 5; i++) {
        printf("%d \n", vetor[i]);
    }
    
    printf("------------------------------------------------------------");

for(int j = 0; j < 5; j++){
    for(int i = 0; i < 5 ; i++) {
        if(vetor[i] > vetor[i+1]) { 
            temp = vetor[i];
            vetor[i] = vetor[i+1]; 
            vetor[i+1] = temp;
        }
    }
}

    for(int i = 0; i < 5; i++) {
        printf("\n%d ", vetor[i]);
    }

    return 0;
}