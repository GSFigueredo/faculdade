#include <stdio.h> 
#include <math.h> 
#include <string.h>

int main () {

    int tot = 0;
    int elevA = 0, elevB = 0, elevC = 0, mat, vesp, not;
    int maior = 0, menor = 10, maiorP = 0, menorP = 10;
    char elev, periodo, elevMais, elevMedio, elevMenos, periodoMais, periodoMenos;

    for(int c = 0; c < 6; c++) {

        tot++;

        printf("Qual o elevador que você usa com mais frequência? [A/B/C]");
        scanf("%c", &elev);

        getchar();

        if (strcmp(elev, "A") == 0 || strcmp(elev, "a") == 0) {
            elevA++;

            if(elevA > maior) {
                maior = elevA;
                strcpy(elevMais, "A");
            }

            if(elevA < menor) {
                menor = elevA;
                strcpy(elevMenos, "A");
            }
        }

        if (strcmp(elev, "B") == 0 || strcmp(elev, "b") == 0) {
            elevB++;

            if(elevB > maior) {
                maior = elevB;
                strcpy(elevMais, "B");
            }

            if(elevB < menor) {
                menor = elevB;
                strcpy(elevMenos, "B");
            }
        }

        if (strcmp(elev, "C") == 0 || strcmp(elev, "c") == 0) {
            elevC++;

            if(elevC > maior) {
                maior = elevC;
                strcpy(elevMais, "C");
            }

            if(elevC < menor) {
                menor = elevC;
                strcpy(elevMenos, "V");
            }
        }

        printf("Qual o período que você mais utiliza? [M/V/N]");
        scanf("%c", &periodo);

        if(strcmp(periodo, "M") == 0 || strcmp(periodo, "m") == 0) {

            mat++;

             if(mat > maiorP) {
                maiorP = mat;
                strcpy(periodoMais, "M");
            }

            if(mat < menorP) {
                menorP = mat;
                strcpy(periodoMenos, "M");
            }
        }

        if(strcmp(periodo, "V") == 0 || strcmp(periodo, "v") == 0) {

            vesp++;

             if(vesp > maiorP) {
                maiorP = vesp;
                strcpy(periodoMais, "V");
            }

            if(vesp < menorP) {
                menorP = vesp;
                strcpy(periodoMenos, "V");
            }
        }

        if(strcmp(periodo, "N") == 0 || strcmp(periodo, "n") == 0) {

            not++;

             if(not > maiorP) {
                maiorP = not;
                strcpy(periodoMais, "N");
            }

            if(not < menorP) {
                menorP = not;
                strcpy(periodoMenos, "N");
            }
        }

    }

    if(strcmp(elevMais, "A") && strcmp(elevMenos, "B")) {
        strcpy(elevMedio, "C");
    } else if(strcmp(elevMais, "B") && strcmp(elevMenos, "A")) {
        strcpy(elevMedio, "C");
    } else if (strcmp(elevMais, "A") && strcmp(elevMenos, "C")) {
        strcpy(elevMedio, "B");
    } else if (strcmp(elevMais, "C") && strcmp(elevMenos, "A")) {
        strcpy(elevMedio, "B");
    } else if (strcmp(elevMais, "B") && (elevMenos, "C")) {
        strcpy(elevMedio, "A");
    } else if (strcmp(elevMais, "C") && (elevMenos, "B")) {
        strcpy(elevMedio, "A");
    }

    printf("O período mais utilizado: %c e o elevador que pertence: %c", periodoMais, elevMais);
    printf("\n");
    printf("o elevador mais frequentado: %c", elev);
    printf("\n");

    float porcento = (maiorP*100)/tot;
    float porcentoMedio = (elevMedio*100)/tot;

    printf("Diferença percentual entre o horário mais usado e o menos usado: %.2f", porcento);
    printf("\n");
    printf("Elevador de média utilização em comparação ao total: %.2f", porcentoMedio);

    return 0;
}