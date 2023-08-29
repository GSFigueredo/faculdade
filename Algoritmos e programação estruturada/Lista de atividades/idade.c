#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {

    int ano;
    int mes; 
    int dia;
    int diasV;

    printf("Data de nascimento: (dia/mês/ano)");
    scanf("%d %d %d", &dia, &mes, &ano);

    getchar();

    int anoV = 2023 - ano;
    int anoD = anoV*365;

    diasV = anoD+dia;

    printf("Nascido(a) em %d/%d/%d, portanto, possui %d dias de vida aproximadamente.", dia, mes, ano, diasV);

    return 0;
}