#include <stdio.h> 
#include <math.h>

int main () { 

    float notaM1, notaB1, notaM2, notaB2;

    printf("Nota mensal primeiro bimestre:");
    scanf("%f", &notaM1);

    getchar();

    printf("Nota bimestral primeiro bimestre:");
    scanf("%f", &notaB1);

    printf("Nota mensal segundo bimestre:");
    scanf("%f", &notaM2);

    getchar();

    printf("Nota bimestral segundo bimestre:");
    scanf("%f", &notaB2);

    float mediaS = (notaM1 + notaB1 + notaM2 + notaB2)/4;

    system("clear");

    printf("Média: %.2f", mediaS);

    printf(" ");

    if(mediaS >= 7) { 
        printf("Aprovado");
    } else if (mediaS >= 4 && mediaS < 7) {
        printf("Recuperação");
    } else { 
        printf("Reprovado");
    }

    printf("\n");
}