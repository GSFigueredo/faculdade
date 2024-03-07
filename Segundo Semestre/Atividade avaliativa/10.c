#include <stdio.h>
#include <math.h>

int main()
{

    int ddd;
    int vei21, vei11, vei41, vei47, vei54;
    int ac21, ac11, ac41, ac47, ac54;
    int maior = 0, menor = 100;

    char indiceMaior[50];
    char indiceMenor[50];

    int quanA = 0;
    int acidentes;
    int resp = 1;

    do
    {
        quanA++;

        printf("Qual o código da cidade? RJ[21] / SP[11] / PR[41] / SC[47] / RS[54]");
        scanf("%d", &ddd);

        if (ddd == 21)
        {
            printf("Qual a quantidade de veículos no RJ em 1992?");
            scanf("%d", &vei21);
            printf("\n");
            printf("Qual a quantidade de acidentes com vítimas?");
            scanf("%d", &ac21);

            if(ac21 > maior) {
                maior = ac21;
                strcpy(indiceMaior, "RJ");
            }

            if(ac21 < menor) {
                menor = ac21;
                strcpy(indiceMenor, "RJ");
            }

        }
        else if (ddd == 11)
        {
            printf("Qual a quantidade de veículos em SP em 1992?");
            scanf("%d", &vei11);
            printf("Qual a quantidade de acidentes com vítimas?");
            scanf("%d", &ac11);

            if(ac11 > maior) {
                maior = ac11;
                strcpy(indiceMaior, "SP");
            }

            if(ac11 < menor) {
                menor = ac11;
                strcpy(indiceMenor, "SP");
            }

        }
        else if (ddd == 41)
        {
            printf("Qual a quantidade de veículos no PR em 1992?");
            scanf("%d", &vei41);
            printf("Qual a quantidade de acidentes com vítimas?");
            scanf("%d", &ac41);

            if(ac41 > maior) {
                maior = ac41;
                strcpy(indiceMaior, "PR");
            }

            if(ac41 < menor) {
                menor = ac41;
                strcpy(indiceMenor, "PR");
            }

        }
        else if (ddd == 47)
        {
            printf("Qual a quantidade de veículos em SC em 1992?");
            scanf("%d", &vei47);
            printf("Qual a quantidade de acidentes com vítimas?");
            scanf("%d", &ac47);

            if(ac47 > maior) {
                maior = ac47;
                strcpy(indiceMaior, "SC");
            }

            if(ac47 < menor) {
                menor = ac47;
                strcpy(indiceMenor, "SC");
            }

        }
        else if (ddd == 54)
        {
            printf("Qual a quantidade de veículos no RS em 1992?");
            scanf("%d", &vei54);
            printf("Qual a quantidade de acidentes com vítimas?");
            scanf("%d", &ac54);

            if(ac54 > maior) {
                maior = ac54;
                strcpy(indiceMaior, "RS");
            }

            if(ac21 < menor) {
                menor = ac54;
                strcpy(indiceMenor, "RS");
            }

        }

        printf("Novo registro? sim[1] / não[0]");
        scanf("%d", &resp);

    } while (resp == 1);

    float mediaV = (vei11+vei21+vei41+vei47+vei54)/5;
    float mediaAcS = (ac54+ac47+ac41)/3;
    
    printf("Maior índice de acidentes: %s com %d acidentes", indiceMaior, maior);
    printf("\n");
    printf("Menor índice de acidentes: %s com %d acidentes", indiceMenor, menor);
    printf("\n");
    printf("Média de veículos nas ruas brasileiras: %.2f", mediaV);
    printf("\n");
    printf("Média de acidentes com vítima nas cidades do sul: %2.f", mediaAcS);

    return 0;
}