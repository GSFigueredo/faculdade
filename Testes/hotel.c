#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct quartos{
    char numeroQuarto[200];
    char status[200];
    char listaHospedes[200][10];
    int quantHospedesQuarto;
} quartos;

void limparCaractere(){
    int limp;
    while ((limp = getchar()) != '\n' && limp != EOF);
}

void limparString(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) {
        str++;
    }
    if (*str == 0) { 
        return;
    }

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    *(end + 1) = '\0';
}

void iniciarLista(quartos quarto[], int *posicaoQuarto){
    FILE *arquivo = fopen("hospedes.txt", "r");

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.");
        exit(EXIT_FAILURE);
    }

    while (!feof(arquivo)){
        fscanf(arquivo, " %[^\n]", quarto[*posicaoQuarto].numeroQuarto);
        fscanf(arquivo, " %[^\n]", quarto[*posicaoQuarto].status);

        int limparCaractere;
        while ((limparCaractere = fgetc(arquivo)) != EOF && limparCaractere != '\n');

        quarto[*posicaoQuarto].quantHospedesQuarto = 0;
        while (1){
            fscanf(arquivo, " %[^\n]", quarto[*posicaoQuarto].listaHospedes[quarto[*posicaoQuarto].quantHospedesQuarto]);
            quarto[*posicaoQuarto].quantHospedesQuarto++;
            if (strncmp(quarto[*posicaoQuarto].listaHospedes[quarto[*posicaoQuarto].quantHospedesQuarto - 1], "==========", strlen("==========")) == 0)
            {
                break;
            }
        }
        quarto[*posicaoQuarto].quantHospedesQuarto -= 1;
        (*posicaoQuarto)++;
    }

    fclose(arquivo);
}


void reescreverLista(quartos quarto[], int quantidadeQuartos) {

    FILE *arquivo = fopen("hospedes.txt", "w+");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    fseek(arquivo, 0, SEEK_SET);

    for(int cont = 0; cont < quantidadeQuartos; cont++) {

        limparString(quarto[cont].numeroQuarto);
        limparString(quarto[cont].status);
        for (int quanHosp = 0; quanHosp < quarto[cont].quantHospedesQuarto; quanHosp++) {
            limparString(quarto[cont].listaHospedes[quanHosp]);
        }

        fprintf(arquivo, "%s\n", quarto[cont].numeroQuarto);
        fprintf(arquivo, "%s\n", quarto[cont].status);
        for(int quanHosp = 0; quanHosp < quarto[cont].quantHospedesQuarto; quanHosp++) {
            fprintf(arquivo, "%s\n", quarto[cont].listaHospedes[quanHosp]);
        }

        if(cont == quantidadeQuartos -1) {
            fprintf(arquivo, "%s", "==========");
        }
        else {
            fprintf(arquivo, "%s\n", "==========");
        }
    } 

    fclose(arquivo);
} 

void inserirHospede(quartos quarto[], int quartoVazio){
    int quantHospedesQuarto = 0;
    long posicaoI = 0, posicaoF = 0;
    char linhaTxt[300];
    int esc = 1;
    int semQuart;

    FILE *arquivo = fopen("hospedes.txt", "r+");

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.");
        exit(EXIT_FAILURE);
    }

    while (fgets(linhaTxt, sizeof(linhaTxt), arquivo) != NULL){
        if (strstr(linhaTxt, quarto[quartoVazio].numeroQuarto) != NULL){
            posicaoI = ftell(arquivo) - strlen(linhaTxt);
            limparCaractere();

            do{
                printf("Digite o nome dos hóspedes, hospede %d: ", quantHospedesQuarto + 1);
                fgets(quarto[quartoVazio].listaHospedes[quantHospedesQuarto], sizeof(quarto[quartoVazio].listaHospedes[quantHospedesQuarto]), stdin);
                quarto[quartoVazio].listaHospedes[quantHospedesQuarto][strcspn(quarto[quartoVazio].listaHospedes[quantHospedesQuarto], "\n")] = '\0';

                quantHospedesQuarto++;
                quarto[quartoVazio].quantHospedesQuarto = quantHospedesQuarto;

                if(quantHospedesQuarto == 4) {
                    printf("\nLimite de quatro hóspedes por quarto.");
                    esc = 1;
                } else {
                    printf("\n[0] Digitar novo hospede |");
                    printf(" [1] Encerrar: ");
                    scanf("\n%d", &esc);
                    limparCaractere();
                }
            } while (esc != 1);

        }

        strcpy(quarto[quartoVazio].status, "reservado");
    }
    fclose(arquivo);
}

void liberarQuarto(quartos quarto[], int *posicaoQuarto) {
    char numeroQuarto[200];
    int encontrado = 0;

    printf("Digite o número do quarto que deseja liberar: ");
    scanf("%s", numeroQuarto);

    for (int i = 0; i < *posicaoQuarto; i++) {
        if (strcmp(quarto[i].numeroQuarto, numeroQuarto) == 0) {
            encontrado = 1;
            strcpy(quarto[i].status, "vazio");
            quarto[i].quantHospedesQuarto = 0;
            printf("O quarto %s foi liberado com sucesso.\n", numeroQuarto);
            break;
        }
    }

    if (!encontrado) {
        printf("Quarto não encontrado.\n");
        return;
    }

   /* FILE *arquivo = fopen("hospedes.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *posicaoQuarto; i++) {
        fprintf(arquivo, "%s\n", quarto[i].numeroQuarto);
        fprintf(arquivo, "%s\n", quarto[i].status);
        for (int j = 0; j < quarto[i].quantHospedesQuarto; j++) {
            fprintf(arquivo, "%s\n", quarto[i].listaHospedes[j]);
        }
        fprintf(arquivo, "%s\n", "==========");
    }

    fclose(arquivo); */

    reescreverLista(quarto, *posicaoQuarto);
}

void mostrarQuartosVazios(quartos quarto[], int quantidadeQuartos) {

    int vazio = 1;

    printf("Quartos vazios:\n");
    for (int i = 0; i < quantidadeQuartos; i++) {
        if (strcmp(quarto[i].status, "vazio") == 0) {
            printf("%s\n", quarto[i].numeroQuarto);

            vazio = 0;
        }
    }

    if(vazio == 1) {
        printf("\nNão há quartos vazios no momento.");
    }
}

int ordenarAlfabeticamente(const void *a, const void *b) {
    const char *hospedeA = (const char *)a;
    const char *hospedeB = (const char *)b;
    return strcmp(hospedeA, hospedeB);
}


void listarHospedes(quartos quarto[], int quantidadeQuartos) {
    char hospedesTemp[40][quantidadeQuartos-1]; 
    int totalHospedes = 0;

    for(int col = 0; col < quantidadeQuartos; col++) {
        for(int lin = 0; lin < quarto[col].quantHospedesQuarto; lin++) {
            strcpy(hospedesTemp[totalHospedes], quarto[col].listaHospedes[lin]);
            totalHospedes++;
        }
    }

    qsort(hospedesTemp, totalHospedes, sizeof(hospedesTemp[0]), ordenarAlfabeticamente);

    printf("\nLista de hóspedes:");
    for(int i = 0; i < totalHospedes; i++) {
        printf("\n%d. %s", i+1, hospedesTemp[i]);
    }
}

int main(){

    quartos quarto[100];
    int posicaoQuarto = 0;
    int esc;
    int resp = 0;
    int quartoVazio;
    int lotado;

    iniciarLista(quarto, &posicaoQuarto);

    do{
        system("clear");
        printf("==================== MENU ====================");
        printf("\n[1] Inserir hóspedes\n");
        printf("[2] Listar hóspedes por ordem alfabética\n");
        printf("[3] Buscar hóspede\n");
        printf("[4] Editar hóspede\n");
        printf("[5] Liberar quarto\n");
        printf("[6] Quartos vazios\n");
        printf("==================== **** ====================");
        printf("\nO que deseja fazer? ");
        scanf("%d", &esc);

        switch (esc){
        case 1:
            for (int c = 0; c < posicaoQuarto; c++){
                if (strcmp(quarto[c].status, "vazio") == 0){
                    quartoVazio = c;
                    lotado = 0;
                    break;
                } else {
                    lotado = 1;
                }
            }

            if(lotado == 0) {
                inserirHospede(quarto, quartoVazio);
                reescreverLista(quarto, posicaoQuarto);
            } else{
                printf("Não há quartos livres no momento.");
            }
            break;

        case 2:
            listarHospedes(quarto, posicaoQuarto);
            break;

        case 3:
            // buscar hóspede
            break;

        case 4:
            // editar hóspede
            break;

        case 5:
            liberarQuarto(quarto, &posicaoQuarto);
            break;

        case 6:
            mostrarQuartosVazios(quarto, posicaoQuarto);
            break;

        default:
            printf("Obrigado por utilizar nosso programa.");
            break;
        }

        printf("\nDeseja realizar mais uma interação? SIM [0] / NÃO [1] ");
        scanf("%d", &resp);

    } while (resp != 1);

    return 0;
}