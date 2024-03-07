#include <stdio.h>

int main() {

    char nome[50], sexo;
    float altura, peso;
    int numHomens = 0, numMulheres = 0;
    float alturaHomens = 0, alturaMulheres = 0, alturaTotal = 0;
    float pesoHomens = 0, pesoMulheres = 0, pesoTotal = 0;

    for (int i = 0; i < 10; ++i) {
        // Solicitar entrada do usuário
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", nome);

        printf("Digite o sexo (M/F): ");
        scanf(" %c", &sexo);

        printf("Digite a altura (em metros): ");
        scanf("%f", &altura);

        printf("Digite o peso (em quilogramas): ");
        scanf("%f", &peso);

        if (sexo == 'M' || sexo == 'm') {
            numHomens++;
            alturaHomens += altura;
            pesoHomens += peso;
        } else if (sexo == 'F' || sexo == 'f') {
            numMulheres++;
            alturaMulheres += altura;
            pesoMulheres += peso;
        } else {
            printf("Sexo inválido. Tente novamente.\n");
            i--;
        }

        alturaTotal += altura;
        pesoTotal += peso;
    }

    float mediaAlturaHomens = numHomens > 0 ? alturaHomens / numHomens : 0;
    float mediaAlturaMulheres = numMulheres > 0 ? alturaMulheres / numMulheres : 0;
    float mediaAlturaGrupo = alturaTotal / 10;
    float mediaPesoHomens = numHomens > 0 ? pesoHomens / numHomens : 0;
    float mediaPesoMulheres = numMulheres > 0 ? pesoMulheres / numMulheres : 0;
    float mediaPesoGrupo = pesoTotal / 10;

    printf("\n--- Resultados ---\n");
    printf("Número de homens: %d\n", numHomens);
    printf("Número de mulheres: %d\n", numMulheres);
    printf("Altura média dos homens: %.2f metros\n", mediaAlturaHomens);
    printf("Altura média das mulheres: %.2f metros\n", mediaAlturaMulheres);
    printf("Altura média do grupo: %.2f metros\n", mediaAlturaGrupo);
    printf("Peso médio dos homens: %.2f quilogramas\n", mediaPesoHomens);
    printf("Peso médio das mulheres: %.2f quilogramas\n", mediaPesoMulheres);
    printf("Peso médio do grupo: %.2f quilogramas\n", mediaPesoGrupo);

    return 0;
}