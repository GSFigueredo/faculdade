#include <stdio.h> 
#include <math.h>

int main () { 
    
    int idade;
    float salario, altura, peso;

    printf("Digite sua idade:");
    scanf("%d", &idade);

    getchar();

    printf("Digite seu salário:");
    scanf("%f", &salario);

    getchar();

    printf("Qual a sua altura?");
    scanf("%f", &altura);

    getchar();

    printf("Qual o seu peso?");
    scanf("%f", &peso);

    getchar();

    system("clear");

    if(idade >= 18 ) { 
       printf("Maior de 18");
    } else { 
        printf("Menor de 18");
    }

    if(salario > 1320) { 
        printf("Mais de um salário minimo");
    } else {
        printf("Menos de um salário minimo");
    }

    if (altura > 1.80) { 
        printf("Mais de 1.80");
    } else { 
        printf("Menos de 1.80");
    }

    if (peso > 60) {
        printf("Mais de 60kg");
    } else { 
        printf("Menos de 60kg");
    }

      return 0;
}