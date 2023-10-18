#include <stdio.h>
#include <math.h>

int calcularVolume(float alt, float rai) {
    float volume = 3.14 * (rai*rai)*alt;

    return volume;
}

int main() {

    float raio, altura;

    printf("Qual a altura do cilindro:");
    scanf("%f", &altura);

    printf("\n");

    printf("Qual o raio do cilindro:");
    scanf("%f", &raio);

    float volume = calcularVolume(altura, raio);

    printf("O volume do cilindro é: %.2f", volume);

    return 0;
}