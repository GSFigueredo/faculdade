#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{

    char nome[20], genero;
    int teste = 1;
    int resp, tot = 0, totMartPes = -1;
    int maior, idade, voto = 0, sam = 0, alex = 0, dzs = 0, amandine = 0, marta = 0;
    int votoFeminino = 0;
    char maiorNome[30];
    int pessoasIdadeTot[300];
    char martPes[300][20], pessoasNomeTot[300][20], pessoasSexoTot[300];

    do{

    tot++;

    printf("Qual o seu nome? ");
    fgets(nome, sizeof(nome), stdin);

    do {
    printf("Qual a sua idade?[12+] ");
    scanf("%d", &idade);
    getchar();
    } while (idade < 13);

    do {

        printf("Qual o seu gênero? [M/F] ");
        scanf("%c", &genero);

        getchar();

        if((genero == 'M' || genero == 'm') || (genero == 'F' || genero == 'f')) {
            teste = 1;
        } else {
            teste = 0;
        }

        if(genero == 'F' || genero == 'f') {
            votoFeminino++;
        }

    } while (teste == 0);


    system("clear");
    
    printf("\n");
    printf("[1] - Sam Kerr - Austrália");
    printf("\n");
    printf("[2] - Alex Morgan - EUA");
    printf("\n");
    printf("[3] - Dzsenifer Marozsan - Alemanha");
    printf("\n");
    printf("[4] - Amandine Henry - França");
    printf("\n");
    printf("[5] - Marta Viera - Brasil");
    printf("\n");

    do {
        printf("Qual o seu voto? ");
        scanf("%d", &voto);

        getchar();
    } while(voto != 1 && voto != 2 && voto != 3 && voto != 4 && voto != 5);

        switch(voto) {
            case 1: sam++;

            if(sam > maior) {
                maior = sam;
                strcpy(maiorNome, "Sam Kerr");
            }

            break;

            case 2: alex++;

            if(alex > maior) {
                maior = alex;
                strcpy(maiorNome, "Alex Morgan");
            }

            break;

            case 3: dzs++;

            if(dzs > maior) {
                maior = dzs;
                strcpy(maiorNome, "Dzsenifer Marozsan");
            }

            break;

            case 4: amandine++;

            if(amandine > maior) {
                maior = amandine;
                strcpy(maiorNome, "Amandine Henry");
            }

            break;

            case 5: marta++;

            if(marta > maior) {
                maior = marta;
                strcpy(maiorNome, "Marta Viera");
            }

            break;

        }

    if(voto == 5 && idade >= 18) {
        totMartPes++;
        strcpy(martPes[totMartPes], nome);
    }

    strcpy(pessoasNomeTot[tot], nome);
    pessoasIdadeTot[tot] = idade;
    pessoasSexoTot[tot] = genero;

    printf("Registrar novo voto? sim[1] / não[2] ");
    scanf("%d", &resp);

    getchar();

    system("clear");
    
    } while (resp == 1);

    printf("------------------- QUANTIDADE DE VOTOS -------------------");
    printf("\n");

    printf("Sam Kerr - Austrália: %d", sam);
    printf("\n");
    printf("Alex Morgan - EUA: %d", alex);
    printf("\n");
    printf("Dzsenifer Marozsan - Alemanha: %d", dzs);
    printf("\n");
    printf("Amandine Henry - França: %d", amandine);
    printf("\n");
    printf("Marta Viera - Brasil: %d", marta);
    printf("\n");

    printf("------------------- JOGADORA MAIS VOTADA -------------------");
    printf("\n");

    printf("%s, com %d votos", maiorNome, maior);
    printf("\n");

    printf("------------------- PESSOAS QUE VOTARAM -------------------");
    printf("\n");

    for(int c = 1; c < (tot + 1); c++) {

        printf("%s %d anos, gênero %c", pessoasNomeTot[c], pessoasIdadeTot[c], pessoasSexoTot[c]);
        printf("\n");
    }

    printf("------------------- VOTOS NA MARTA (MAIORES DE IDADE) -------------------");
    printf("\n");

    for(int c = 0; c <= totMartPes; c++) {
        printf("%s", martPes[c]);
        printf("\n");
    }

    printf("------------------- VOTOS FEMININOS -------------------");
    printf("\n");

    printf("Houve um total de %d votos femininos", votoFeminino);
    return 0;
}