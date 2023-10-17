#include <stdio.h>
#include <math.h>

int mesValor(int mes) {
    if(mes >= 1 && mes <=6) {
        switch(mes) {
            case 1: printf("Janeiro");
            break;

            case 2: printf("Fevereiro");
            break;

            case 3: printf("Março");
            break;

            case 4: printf("Abril");
            break;

            case 5: printf("Maio");
            break;

            case 6: printf("Junho");
            break;
        }
    } else {
        testeMes2(mes);
    }
}

int testeMes2(mes) {
    
}

int main () {

    int mes;

    printf("Digite um valor entre 1 e 12:");
    scanf("%d", &mes);

    mesValor(mes);

    return 0;
}