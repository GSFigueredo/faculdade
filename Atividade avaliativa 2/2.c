#include <stdio.h>
#include <string.h>

void verificaSalario(float salario) {
    if(salario < 1400) {
        printf("Salário: %.2f, abaixo do salário mínimo!", salario);
    } else if(salario == 1400) {
       printf("Salário: %.2f, igual ao salário mínimo!", salario);
    } else {
        printf("Salário: %.2f, acima do salário mínimo!", salario);
    }
}

void verificaSexo(char sexo) {

    int sexoV;

    if(sexo == 'M' || sexo == 'm') { 
        sexoV = 1;
    } else if(sexo == 'F' || sexo == 'f') {
        sexoV = 2;
    }
    
    switch (sexoV){
    case 1:
        printf("Sexo: masculino");
    break;
    case 2:
        printf("Sexo: feminino");
    }
}

void mostrarDados(char nome[200][40], char sexo[200][2], float salario[200], int id) {
    
    system("clear");

    printf("--------------- FICHA PESSOAL ---------------");
    printf("\n");

    for(int c = 0; c < id; c++) {
        printf("\n%s", nome[c]);
        verificaSexo(sexo[c][0]);
        printf("\n");
        verificaSalario(salario[c]);

        printf("\n---------------------------------------");
    }
}

int main() {

    system("clear");

    int resp;
    char nome[200][40];
    char sexo[200][2];
    float salario[200];
    int id = -1;
    int teste = 0;

    do {

        system("clear");
        int testeS = 0;
        resp = 0;

        printf("Você é um profissional com carteira assinada e assalariado? Sim [1] / Não [0] ");
        scanf("%d", &resp);

        if (resp == 0) {
            printf("\nNão está apto...");
            printf("\n");
        } else if (resp == 1) {
            id++;

            printf("Qual o seu nome? ");
            getchar();
            fgets(nome[id], sizeof(nome[id]), stdin);

            printf("Qual seu gênero? [M/F] ");
            scanf(" %c", sexo[id]);

            do {

                printf("Qual o seu salário? ");
                scanf("%f", &salario[id]);

                if(salario[id] < 1) {
                    testeS = 1;
                    printf("Salario deve ser maior de R$1,00");
                    printf("\n");
                } else {
                    testeS = 0;
                }

            } while(testeS == 1);

            printf("\n");
        }

        printf("PRÓXIMO REGISTRO [1] / ENCERRAR [0]: ");
        scanf("%d", &teste);

    } while (teste == 1);

    id++;
    mostrarDados(nome, sexo, salario, id);

    return 0;
}
