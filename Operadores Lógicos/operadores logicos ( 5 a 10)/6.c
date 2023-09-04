#include <stdio.h>

int main() {

    int n1;

    printf("Digite um número:");
    scanf("%d", &n1);


    if(n1%2 == 0){
        printf("Número %d é par", n1);
    } else {
        printf("Número %d é impar", n1);
    }

}