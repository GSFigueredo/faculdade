#include <stdio.h> 
#include <math.h> 

int main () {

    int a = 10; 
    int b = 20; 

    int *pA;
    int *pB; 

    pA = &a; 
    pB = &b; 

    if(pA > pB) {
        printf("Endereço de A é maior");
    } else {
        printf("Endereço de B é maior");
    }
    
    return 0;
}