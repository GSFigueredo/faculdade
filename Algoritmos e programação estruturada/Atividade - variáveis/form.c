#include <stdio.h>
#include <stdlib.h>

int main()
{

    // criação de variáveis
    char nome[20];
    int anoN;
    char matricula[20];

    char ender[30];
    char curso[25];
    int periodo;

    int quanDis;
    float mensalidade;
    char verificaDados[5];

    int contador;
    // código
    printf("Digite o seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Em que ano você nasceu? ");
    scanf("%d", &anoN);

    getchar();

    printf("Qual a sua matrícula? ");
    fgets(matricula, sizeof(matricula), stdin);

    printf("Qual o seu endereço? ");
    fgets(ender, sizeof(ender), stdin);

    printf("O que está cursando? ");
    fgets(curso, sizeof(curso), stdin);

    printf("Está em qual período? ");
    scanf("%d", &periodo);

    getchar();

    printf("Você tem quantas disciplinas no semestre? ");
    scanf("%d", &quanDis);

    getchar();

    char disciplinas[quanDis][30];

    for (contador = 1; contador <= quanDis; contador++)
    {
        printf("Digite a disciplina %d:", contador);
        fgets(disciplinas[contador], sizeof(disciplinas[contador]), stdin);
    }

    printf("Qual o valor da mensalidade?");
    scanf("%f", &mensalidade);

    getchar();

    system("clear");

    printf("Quer verificar seus dados? [Sim/Não]");
    fgets(verificaDados, sizeof(verificaDados), stdin);

    printf("\n");

    verificaDados[strcspn(verificaDados, "\n")] = '\0';

    if (strcmp(verificaDados, "Sim") == 0 || strcmp(verificaDados, "sim") == 0)
    {
        printf("Nome: %s", nome);
        printf("idade: %d", (2023 - anoN));

        printf("\nMatrícula: %s", matricula);
        printf("Endereço: %s", ender);

        printf("Curso: %s", curso);
        printf("Período: %d", periodo);

        printf("\nDisciplinas:");
        for (contador = 1; contador <= quanDis; contador++)
        {
            printf(" %s", disciplinas[contador]);
        }
        printf("Mensalidade: %.2f", mensalidade);
        printf("\n");
    }
    else
    {
        printf("Cadastro encerrado.");
    }

    return 0;
}