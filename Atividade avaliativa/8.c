#include <stdio.h> 
#include <math.h>

int main () { 

    float salario;
    float mediaS = 0;
    int filhos;
    float mediaF = 0;
    int resposta = 0;
    int quanP = 0;

    float salarioMenor = 0;
    float maior = 0;

    do {

    quanP++;

    printf("Qual o seu salário?");
    scanf("%f", &salario);

    printf("Possui quantos filhos?");
    scanf("%d", &filhos);

    mediaS += salario;
    mediaF += filhos;

    if(salario > maior) {
        maior = salario;
    }

    if(salario <= 100) {
        salarioMenor++;
    }

    printf("Novo questionário? sim[1] / não[0]");
    scanf("%d", &resposta); 

    } while (resposta == 1);

    system("clear");

    salarioMenor = (salarioMenor*100)/quanP;
    mediaF = mediaF/quanP;
    mediaS = mediaS/quanP;

    printf("Média salarial: %.1f", mediaS);
    printf("\n");
    printf("Média de filhos: %.1f", mediaF);
    printf("\n");
    printf("Porcentagem de pessoas com o salário menor ou igual a 100: %.2f", salarioMenor);

    return 0;
}