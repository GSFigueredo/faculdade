#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int testeNotas(char nota[1]){

    if (strcmp(nota, "A") == 0 || strcmp(nota, "a") == 0){
        return 1;
    } else if (strcmp(nota, "B") == 0 || strcmp(nota, "b") == 0){
        return 2;
    } else if (strcmp(nota, "C") == 0 || strcmp(nota, "c") == 0){
        return 3;
    } else if (strcmp(nota, "D") == 0 || strcmp(nota, "d") == 0){
        return 4;
    } else if (strcmp(nota, "E") == 0 || strcmp(nota, "e") == 0){
        return 5;
    } else {
        return 0;
    }
}

int main()
{
    int total = 0;
    int idade, idadeOt, idadeRuSom = 0, idadeRu, idadePe = 0;
    int maiorOt = 0, maiorPe = 0, maiorRu = 0;
    char nota[1];
    int nA = 0, nB = 0, nC = 0, nD = 0, nE = 0;

    for (int c = 0; c < 101; c++){
        printf("Qual a sua idade? ");
        scanf("%d", &idade);

        getchar();

        printf("Qual a sua nota para o filme? A[Ótimo] / B[Bom] / C[Regular] / D[Ruim] / E[Péssimo] ");
        scanf("%s", &nota);

        fflush(stdin);

        int valor = testeNotas(nota);

       switch(valor) {
        case 1: 
           total++;
            nA += 1;
            idadeOt = idade;

            if(idadeOt > maiorOt) {
                maiorOt = idadeOt;
            }
        break;

        case 2: 
            total++;
            nB += 1;
        break;

        case 3: 
            total++;
            nC += 1;
        break;

        case 4:
            total++;
            nD += 1;
            idadeRuSom += idade;
            idadeRu = idade;

            if(idadeRu > maiorRu) {
                maiorRu = idadeRu;
            }
        break;

        case 5: 
            total++;
            nE += 1;
            idadePe = idade;

            if(idadePe > maiorPe) {
                maiorPe = idadePe;
            }
        break;
       }
        
    }

    if(total <= 0) {
        total = 1;
    }

    if(nD <= 0) {
        nD = 1;
    }

    float dnA_nB = (((nB * 100)/total) - ((nC*100)/total));
    float mediaRuId = idadeRuSom/nD;

    float perPe = ((nE * 100)/total);
    int difermA_mR = maiorOt - maiorRu;

    if(dnA_nB < 0) {
        dnA_nB = dnA_nB*-1;
    }

    if(difermA_mR < 0) {
        difermA_mR = difermA_mR*-1;
    }

    printf("Quantidade de respostas ótimo: %d", nA);
    printf("\n");
    printf("Diferença percentual entre respostas 'bom' e 'regular': %.2f", dnA_nB);
    printf("\n");
    printf("Média de idade das pessoas que responderam ruim: %.2f", mediaRuId);
    printf("\n");
    printf("A porcentagem de respostas 'péssimo': %.2f , a maior idade: %d", perPe, maiorPe);
    printf("\n");
    printf("Diferença de idade entre a maior idade que respondeu 'ótimo' e a maior idade que respondeu 'ruim': %d", difermA_mR);
}