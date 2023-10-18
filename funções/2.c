#include <stdio.h>
#include <math.h>

void mesValor(int mes) {
    if(mes >= 1 && mes <=6) {
        switch(mes) {
            case 1: printf("Janeiro, 31 dias");
            break;

            case 2: printf("Fevereiro, 28 dias");
            break;

            case 3: printf("Março, 31 dias");
            break;

            case 4: printf("Abril, 30 dias");
            break;

            case 5: printf("Maio, 31 dias");
            break;

            case 6: printf("Junho, 30 dias");
            break;
        }
    } else {
        mesValor2(mes);
    }
}

void mesValor2(mes) {
    switch(mes) {
            case 7: printf("Julho, 31 dias");
            break;

            case 8: printf("Agosto, 31 dias");
            break;

            case 9: printf("Setembro, 30 dias");
            break;

            case 10: printf("outubro, 31 dias");
            break;

            case 11: printf("Novembro, 30 dias");
            break;

            case 12: printf("Dezembro, 31 dias");
            break;
        }
}

int main () {

    int mes;

    printf("Digite um valor entre 1 e 12:");
    scanf("%d", &mes);

    mesValor(mes);

    return 0;
}