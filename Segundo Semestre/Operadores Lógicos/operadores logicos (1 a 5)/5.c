#include <stdio.h>

int main() {

    int n1;

    printf("Digite um valor:");
    scanf("%d", &n1);

    if(n1 == 5 || n1 == 200 || n1 == 400 || (n1>= 500 && n1 <=1000)) {

        if(n1 == 5 || n1 == 200 || n1 == 400) {
            printf("O valor é igual a um dos valores fornecidos");
        }

        if (n1 >= 500 && n1 <=1000) {
            printf("O valor está entre 500 e 1000");
        }

    } else {
        printf("Não está dentro dos escopos fornecidos");
    }

}