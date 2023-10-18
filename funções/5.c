#include <stdio.h>
#include <math.h>

float calcularVolume(float raio) {
    float volume = 4/3*3.14;
    volume = volume*(raio*raio*raio);

    return volume;
}

int main () {

    float raio;

    printf("Qual o valor do raio da esfera?");
    scanf("%f", &raio);

    float volume = calcularVolume(raio);

    printf("O valor do volume é: %.2f", volume);

    return 0;
}