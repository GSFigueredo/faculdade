#include <stdio.h> 
#include <math.h>

int main () {

    int ddd;
    int vei21, vei11, vei41, vei47, vei54;
    int ac21, ac11, ac41, ac47, ac54;
    int maior = 0, menor = 0;

    int quanA = 0;
    int acidentes;
    int resp = 1;

    do{
        quanA++;

    printf("Qual o código da cidade? RJ[21] / SP[11] / PR[41] / SC[47] / RS[54]");
    scanf("%d", &ddd);

    if(ddd == 21) {
        printf("Qual a quantidade de veículos no RJ em 1992?");
        scanf("%d", &vei21);
        printf("\n");
        printf("Qual a quantidade de acidentes com vítimas?");
        scanf("%d", &ac21);
    } else if(ddd == 11){
        printf("Qual a quantidade de veículos em SP em 1992?");
        scanf("%d", &vei11);
        printf("Qual a quantidade de acidentes com vítimas?");
        scanf("%d", &ac11);
    } else if(ddd == 41){
        printf("Qual a quantidade de veículos no PR em 1992?");
        scanf("%d", &vei41);
        printf("Qual a quantidade de acidentes com vítimas?");
        scanf("%d", &ac41);
    } else if(ddd == 47){
        printf("Qual a quantidade de veículos em SC em 1992?");
        scanf("%d", &vei47);
        printf("Qual a quantidade de acidentes com vítimas?");
        scanf("%d", &ac47);
    } else if(ddd == 54){
        printf("Qual a quantidade de veículos no RS em 1992?");
        scanf("%d", &vei54);
        printf("Qual a quantidade de acidentes com vítimas?");
        scanf("%d", &ac54);
    }

    printf("Novo registro?");
    scanf("%d", &resp);

    } while (resp == 1);

    return 0;
}