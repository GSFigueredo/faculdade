#include <stdio.h> 
#include <math.h> 
#include <string.h>

int main () {

    int tot = 0;
    int elevMedioV = 0;
    int elevA = 0, elevB = 0, elevC = 0, mat = 0, vesp = 0, not = 0;
    int maior = 0, menor = 10, maiorP = 0, menorP = 10;
    char elev, periodo, elevMais, elevMenos, periodoMais, periodoMenos;

    for(int c = 0; c < 51; c++) {

        system("clear");

        tot++;

        printf("Qual o elevador que você usa com mais frequência? [A/B/C]");
        scanf("%c", &elev);

        getchar();

        if (elev == 'A' || elev == 'a') {
            elevA++;

            if(elevA > maior) {
                maior = elevA;
                elevMais = 'A';
            }

            if(elevA < menor) {
                menor = elevA;
                elevMenos = 'A';
            }
        }

        if (elev == 'B' || elev == 'b') {
            elevB++;

            if(elevB > maior) {
                maior = elevB;
                 elevMais = 'B';
            }

            if(elevB < menor) {
                menor = elevB;
                elevMenos = 'B';
            }
        }

        if ((elev == 'C' || elev == 'c')) {
            elevC++;

            if(elevC > maior) {
                maior = elevC;
                 elevMais = 'C';
            }

            if(elevC < menor) {
                menor = elevC;
                elevMenos = 'V';
            }
        }

        printf("Qual o período que você mais utiliza? [M/V/N]");
        scanf("%c", &periodo);

        getchar();

        if(periodo == 'M' || periodo == 'm') {

            mat++;

             if(mat > maiorP) {
                maiorP = mat;
                periodoMais = 'M';
            }

            if(mat < menorP) {
                menorP = mat;
                periodoMenos = 'M';
            }
        }

        if(periodo == 'V' || periodo == 'v') {

            vesp++;

             if(vesp > maiorP) {
                maiorP = vesp;
                periodoMais = 'V';
            }

            if(vesp < menorP) {
                menorP = vesp;
                periodoMenos = 'V';
            }
        }

        if(periodo == 'N' || periodo == 'n'){

            not++;

             if(not > maiorP) {
                maiorP = not;
                periodoMais = 'N';
            }

            if(not < menorP) {
                menorP = not;
                periodoMenos = 'N';
            }
        }

        elevMedioV = maior - menor;
        
    }

    system("clear");

    printf("O período mais utilizado: %c e o elevador que pertence: %c", periodoMais, elevMais);
    printf("\n");
    printf("o elevador mais frequentado: %c", elev);
    printf("\n");

    float porcento = (maiorP*100)/tot;
    float porcentoMedio = (elevMedioV*100)/tot;

    printf("Diferença percentual entre o horário mais usado e o menos usado: %.2f", porcento);
    printf("\n");
    printf("Elevador de média utilização em comparação ao total: %.2f", porcentoMedio);

    return 0;
}