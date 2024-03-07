#include <stdio.h>
#include <math.h>

float calcularImc(float quilos, float altura) {
    float imc = quilos / (altura * altura);

    return imc;
}

int main() {
    float quilos, altura;

    printf("Você pesa quantos quilos? [kg]: ");
    scanf("%f", &quilos);

    printf("Você tem quanto de altura? [M]: ");
    scanf("%f", &altura);

    float imc = calcularImc(quilos, altura);

    printf("O IMC é: %.2f", imc);

    return 0;
}
