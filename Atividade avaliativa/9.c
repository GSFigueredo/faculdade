#include <stdio.h> 
#include <math.h>

int main () {

    int voto;
    int voto1 = 0, voto2 = 0, voto3 = 0, voto4 = 0, voto5 = 0, voto6 = 0;
    int resp = 1;

    do {

    printf("Qual o seu candidato? [1] / [2] / [3] / [4] / nulo[5] / branco[6]");
    scanf("%d", &voto);

    if(voto == 1) {
        voto1++;
    } else if(voto ==2) {
        voto2++;
    } else if (voto ==3) {
        voto3++;
    } else if (voto == 4) {
        voto4++;
    } else if (voto == 5) {
        voto5++;
    } else if (voto == 6) {
        voto6++;
    }

    printf("\n");
    printf("Novo voto: sim[1] / não [0]");
    scanf("%d", &resp);

    } while (resp == 1);

    printf("Candidado 1: %d", voto1);
    printf("\n");
    printf("Candidato 2: %d", voto2);
    printf("\n");
    printf("Candidato 3: %d", voto3);
    printf("\n");
    printf("Candidato 4: %d", voto4);
    printf("\n");
    printf("Nulos: %d", voto5);
    printf("\n");
    printf("Brancos: %d", voto6);
    return 0;
}