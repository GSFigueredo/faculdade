#include <stdio.h> 
#include <math.h>

int main () { 

    printf("\n");

    float notas = 0;

    for(int c = 0; c <31; c++) {

    float nota1, nota2, nota3;

    printf("\n");
    printf("Nota 1:");
    scanf("%f", &nota1);

    getchar();

    printf("Nota 2:");
    scanf("%f", &nota2);

    printf("Nota 3:");
    scanf("%f", &nota3);

    getchar();

    float mediaS = ((nota1*2) + (nota2*4) + (nota3*3))/10;

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

    notas += mediaS;

    }

    notas = notas/30;
    
    printf("\n");
    printf("Média geral: %.2f", notas);
}