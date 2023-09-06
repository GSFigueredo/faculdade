#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){

    char prato[20];
    char sobremesa[20];
    char bebida[20];
    int pr, sob, beb;
    float kcalPr, kcalSob, kcalBeb;

    printf("--------------- Escolha o prato principal ---------------");

    printf("\n");
    printf("Vegetariano [1]");
    printf("\n");
    printf("Peixe [2]");
    printf("\n");
    printf("Frango [3]");
    printf("\n");
    printf("Carne [4]");
    printf("\n");

    scanf("%d", &pr);

    switch (pr){
    case 1:
            strcpy(prato, "vegetariano");
            kcalPr = 180;
        break;
    case 2:
            strcpy(prato, "Peixe");
            kcalPr = 230;
        break;
    case 3:
            strcpy(prato, "Frango");
            kcalPr = 250;
        break;
    case 4:
            strcpy(prato, "Carne");
            kcalPr = 350;
        break;
    default:
            strcpy(prato, "Sem prato principal");
            kcalPr = 0;
}

system("clear");

printf("--------------- Escolha a sobremesa ---------------");

    printf("\n");
    printf("Abacaxi [1]");
    printf("\n");
    printf("Sorvete diet [2]");
    printf("\n");
    printf("Mouse diet [3]");
    printf("\n");
    printf("Mouse de chocolate [4]");
    printf("\n");

    scanf("%d", &sob);

    switch (sob){
    case 1:
            strcpy(sobremesa, "Abacaxi");
            kcalSob = 75;
        break;
    case 2:
            strcpy(sobremesa, "Sorvete Diet");
            kcalSob = 110;
        break;
    case 3:
            strcpy(sobremesa, "Mouse Diet");
            kcalSob = 170;
        break;
    case 4:
            strcpy(sobremesa, "Mouse de chocolate");
            kcalSob = 200;
        break;
    default:
        strcpy(sobremesa, "Sem sobremesa");
        kcalSob = 0;
}

system("clear");

printf("--------------- Escolha a bebida ---------------");

    printf("\n");
    printf("Chá [1]");
    printf("\n");
    printf("Suco de laranja [2]");
    printf("\n");
    printf("Suco de limão [3]");
    printf("\n");
    printf("Refrigerante diet [4]");
    printf("\n");

    scanf("%d", &beb);

    switch (beb){
    case 1:
            strcpy(bebida, "Chá");
            kcalBeb = 20;
        break;
    case 2:
            strcpy(bebida, "Suco de laranja");
            kcalBeb = 70;
        break;
    case 3:
            strcpy(bebida, "Suco de limão");
            kcalBeb = 100;
        break;
    case 4:
            strcpy(bebida, "Refrigerante diet");
            kcalBeb = 65;
        break;
    default:
        strcpy(bebida, "Sem bebida");
        kcalBeb = 0;
}

float kcal = kcalPr+kcalSob+kcalBeb;

printf("Prato: %s", prato);
printf("\n");
printf("Sobremesa: %s", sobremesa);
printf("\n");
printf("Bebida: %s", bebida);
printf("\n");
printf("Calorias: %.2f", kcal);
printf("\n");

return 0;

}