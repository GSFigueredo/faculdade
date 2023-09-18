#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{

    system("clear");

    char sexo[20];
    int sex;

    char olhos[20];
    int zoi;

    char cabelo[20];
    int cab;

    int idade;

    int testeL = 0;
    int filtro = 0;

    float salario;
 

    int resp = 1;
    int quanP;
    int pessoasFilt;

    do
    {
        int idTes = 0;
        int salTes = 0;
        quanP++;

        printf("Digite o sexo: [m/f]");
        fgets(sexo, sizeof(sexo), stdin);

        getchar();

        if (strcmp(sexo, "m") == 0 || strcmp(sexo, "M") == 0)
        {
            sex = 1;
        }
        else if (strcmp(sexo, "f") == 0 || strcmp(sexo, "F") == 0)
        {
            sex = 2;
        }

        switch (sex)
        {

        case 1:
            strcpy(sexo, "Masculino");
            break;

        case 2:
            strcpy(sexo, "Feminino");
            break;

        default:
            testeL = 1;
        }

        system("clear");

        printf("Digite a cor dos olhos: [a/c/v/p]");
        fgets(olhos, sizeof(olhos), stdin);

        getchar();

        if (strcmp(olhos, "a") == 0 || strcmp(olhos, "A") == 0)
        {
            zoi = 1;
        }
        else if (strcmp(olhos, "c") == 0 || strcmp(olhos, "C") == 0)
        {
            zoi = 2;
        }
        else if (strcmp(olhos, "v") == 0 || strcmp(olhos, "V") == 0)
        {
            zoi = 3;
        }
        else if (strcmp(olhos, "p") == 0 || strcmp(olhos, "P") == 0)
        {
            zoi = 4;
        }

        switch (zoi)
        {

        case 1:
            strcpy(olhos, "Azuis");
            break;

        case 2:
            strcpy(olhos, "Castanhos");
            break;

        case 3:
            strcpy(olhos, "Verdes");
            break;

        case 4:
            strcpy(olhos, "Pretos");
            break;

        default:
            testeL = 2;
        }

        system("clear");

        printf("Digite a cor dos cabelos: [l/c/p/r]");
        fgets(cabelo, sizeof(cabelo), stdin);

        getchar();

        if (strcmp(cabelo, "l") == 0 || strcmp(cabelo, "L") == 0)
        {
            cab = 1;
        }
        else if (strcmp(cabelo, "c") == 0 || strcmp(cabelo, "C") == 0)
        {
            cab = 2;
        }
        else if (strcmp(cabelo, "p") == 0 || strcmp(cabelo, "P") == 0)
        {
            cab = 3;
        }
        else if (strcmp(cabelo, "r") == 0 || strcmp(cabelo, "R") == 0)
        {
            cab = 4;
        }

        switch (cab)
        {

        case 1:
            strcpy(cabelo, "Loiro");
            break;

        case 2:
            strcpy(cabelo, "Castanho");
            break;

        case 3:
            strcpy(cabelo, "Preto");
            break;

        case 4:
            strcpy(cabelo, "Ruivo");
            break;

        default:
            testeL = 3;
        }

        system("clear");

        while (idTes == 0)
        {

            idTes = 1;

            if (idTes == 1)
            {
                printf("Digite a idade: ");
                scanf("%d", &idade);

                getchar();
            }

            if (idade < 10 || idade > 100)
            {
                idTes = 0;
                printf("A idade não está dentro das possibilidades");
            }
        }

        system("clear");

        while (salTes == 0)
        {

            salTes = 1;

            if (salTes == 1)
            {
                printf("\nDigite o salário:");
                scanf("%f", &salario);
                getchar();
            }

            if (salario <= 0)
            {
                salTes = 0;
                printf("O salário não está dentro das possibilidades");
            }
        }

        if ((idade >= 18 && idade <= 35) && (sex == 2 && zoi == 2 && cab == 2) ){
            filtro++;
            printf("Entrou no filtro");
        }

        system("clear");

        printf("Gênero: %s", sexo);
        printf("\n");
        printf("Olhos: %s", olhos);
        printf("\n");
        printf("Cabelo: %s", cabelo);
        printf("\n");
        printf("Idade: %d", idade);
        printf("\n");
        printf("Salário: %.2f", salario);
        printf("\n");
        printf("Filtro: %d", filtro);

        printf("Quer registrar um novo colaborador? sim[1] / não[-1]");
        scanf("%d", &resp);

        getchar();

    } while (resp == 1);

    pessoasFilt = ((filtro * quanP)/ 100);


        printf("Quantidade de pessoas(total): %d", quanP);
        printf("\n");
        printf("Porcentagem de pessoas do sexo feminino, com idade entre 18 e 35 anos e que tenham olhos castanhos e cabelos castanhos: %d", pessoasFilt);

    return 0;
}