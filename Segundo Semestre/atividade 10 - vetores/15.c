#include <stdio.h>
#include <math.h>
#include <string.h>

int main () {

    int vet[10];

    printf("Digite dez valores:");
    for(int c = 0; c < 10; c++) {
        scanf("%d", &vet[c]);
    }

    for(int c = 0; c < 10; c++) {
        for(int c1 = c+1; c1 < 10; c1++) {
            if(vet[c] == vet[c1]) {
                vet[c] = 0;
                vet[c1] = 0;

                getchar();
            }

        if(vet[c] != 0)
            printf("%d", vet[c]);
        }
    }
    
    

    return 0;
}