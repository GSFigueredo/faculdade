#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int dobro;

    printf("Digite um valor:");
    scanf("%d", &dobro);

    dobro *= 2;

    printf("O dobro do valor é: %d", dobro);

    return 0;
}