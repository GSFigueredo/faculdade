#include <stdio.h> 
#include <math.h> 

int main () {

    float a[10]; 

    for(int c = 0; c <10; c++) {
        printf("endereço do elemento 'a' na posição %d: %d", c+1, &a[c]);
        printf("\n");
    }

    return 0;
}