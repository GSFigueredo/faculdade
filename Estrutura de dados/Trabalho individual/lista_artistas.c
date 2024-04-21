#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct artistas{
    char nome[50];
    char tipoMusc[50];
    char naturalidade[50];
    char listaAlbuns[200][50];
    int quantidadeAlbuns;
} artistas;

void limparCaractere () {
    int limp; 
    while ((limp = getchar()) != '\n' && limp != EOF);
}

void iniciarLista(artistas listaArtistas[], int *posicaoArtista) {
    FILE *arquivo = fopen("artistas.txt", "r");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    while(!feof(arquivo)) {
        fscanf(arquivo, " %[^\n]", listaArtistas[*posicaoArtista].nome);
        fscanf(arquivo, " %[^\n]", listaArtistas[*posicaoArtista].tipoMusc);
        fscanf(arquivo, " %[^\n]", listaArtistas[*posicaoArtista].naturalidade);

        int limparCaractere;
        while ((limparCaractere = fgetc(arquivo)) != EOF && limparCaractere != '\n');

        listaArtistas[*posicaoArtista].quantidadeAlbuns = 0;
        while(1) {
            fscanf(arquivo, " %[^\n]", listaArtistas[*posicaoArtista].listaAlbuns[listaArtistas[*posicaoArtista].quantidadeAlbuns]);
            listaArtistas[*posicaoArtista].quantidadeAlbuns++;
            if (strncmp(listaArtistas[*posicaoArtista].listaAlbuns[listaArtistas[*posicaoArtista].quantidadeAlbuns - 1], "==========", strlen("==========")) == 0) {
                break;
            }
        }
        listaArtistas[*posicaoArtista].quantidadeAlbuns -= 1;
        (*posicaoArtista)++;
    }

    fclose(arquivo);
}

void inserirArtista (artistas listaArtistas[], int *posicaoArtista) {
    int quantidadeAlbuns = 0;
    int esc = 1;

    FILE *arquivo = fopen("artistas.txt", "a");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(EXIT_FAILURE);
    }

    fprintf(arquivo, "\n");
    limparCaractere();

    printf("\nNome do artista: ");
    fgets(listaArtistas[*posicaoArtista].nome, sizeof(listaArtistas[*posicaoArtista].nome), stdin);
    listaArtistas[*posicaoArtista].nome[strcspn(listaArtistas[*posicaoArtista].nome, "\n")] = '\0';
    fprintf(arquivo, "%s\n", listaArtistas[*posicaoArtista].nome);

    printf("\nTipo musical: ");
    fgets(listaArtistas[*posicaoArtista].tipoMusc, sizeof(listaArtistas[*posicaoArtista].tipoMusc), stdin);
    listaArtistas[*posicaoArtista].tipoMusc[strcspn(listaArtistas[*posicaoArtista].tipoMusc, "\n")] = '\0';
    fprintf(arquivo, "%s\n", listaArtistas[*posicaoArtista].tipoMusc);

    printf("\nNaturalidade: ");
    fgets(listaArtistas[*posicaoArtista].naturalidade, sizeof(listaArtistas[*posicaoArtista].naturalidade), stdin);
    listaArtistas[*posicaoArtista].naturalidade[strcspn(listaArtistas[*posicaoArtista].naturalidade, "\n")] = '\0';
    fprintf(arquivo, "%s\n", listaArtistas[*posicaoArtista].naturalidade);

    do {
        printf("Digite os albuns do artista, album %d: ", quantidadeAlbuns);
        fgets(listaArtistas[*posicaoArtista].listaAlbuns[quantidadeAlbuns], sizeof(listaArtistas[*posicaoArtista].listaAlbuns[quantidadeAlbuns]), stdin);
        listaArtistas[*posicaoArtista].listaAlbuns[quantidadeAlbuns][strcspn(listaArtistas[*posicaoArtista].listaAlbuns[quantidadeAlbuns], "\n")] = '\0';
        fprintf(arquivo, "%s\n", listaArtistas[*posicaoArtista].listaAlbuns[quantidadeAlbuns]);

        quantidadeAlbuns++;
        listaArtistas[*posicaoArtista].quantidadeAlbuns = quantidadeAlbuns;

        printf("\n[0] Digitar novo album. ");
        printf("\n[1] Encerrar ");
        scanf("\n%d", &esc);
        limparCaractere();
    } while (esc != 1);

    fprintf(arquivo, "%s", "==========");

    (*posicaoArtista)++;
}

int main () {
    artistas listaArtistas[200];
    int posicaoArtista = 0;
    int esc;

    iniciarLista(listaArtistas, &posicaoArtista);

    printf("==================== MENU ====================");
    printf("\n[1] Inserir novo artista\n");
    printf("[2] Remover artista\n");
    printf("[3] Editar artista\n");
    printf("[4] Buscar artista (Binária)\n");
    printf("[5] Buscar álbum\n");
    printf("[6] Encerrar programa\n");
    printf("==================== **** ====================");
    printf("\nO que deseja fazer? ");
    scanf("%d", &esc);

    switch(esc) {
        case 1:
            inserirArtista(listaArtistas, &posicaoArtista);
            break;

        case 2:
            printf("Remover artista");
            break;

        case 3:
            printf("Editar artista");
            break;

        case 4:
             printf("Buscar artista (binária)");
             break;

        case 5:
            printf("Buscar álbum");
            break;

        default:
            printf("Obrigado por utilizar nosso programa.");
            break;
    }

    printf("\n%s", listaArtistas[15].nome);
    printf("\n%s", listaArtistas[15].tipoMusc);
    printf("\n%s", listaArtistas[15].naturalidade);
    printf("\n%s", listaArtistas[15].listaAlbuns[0]);
    printf("\n%d", listaArtistas[15].quantidadeAlbuns);
    printf("\n%d", posicaoArtista);

    return 0;
}
