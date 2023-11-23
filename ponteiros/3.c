#include <stdio.h> 
#include <math.h> 

int main () {

    int a, b; 

    int *pA, *pB; 

    printf("Digite o valor de A e B:"); 
    scanf("%d %d", &a, &b);

    pA = &a; 
    pB = &b; 

    if(pA > pB) {
        printf("Endereço de A é maior: %d\n com valor: %d", pA, *pA);
    } else {
        printf("Endereço de B é maior: %d\n com valor: %d", pB, *pB);
    }
    
    return 0;
}