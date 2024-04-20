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

        listaArtistas[*posicaoArtista].quantidadeAlbuns = 0;
        while(1) {
            fscanf(arquivo, " %[^\n]", listaArtistas[*posicaoArtista].listaAlbuns[listaArtistas[*posicaoArtista].quantidadeAlbuns]);
            listaArtistas[*posicaoArtista].quantidadeAlbuns++;
            if (strncmp(listaArtistas[*posicaoArtista].listaAlbuns[listaArtistas[*posicaoArtista].quantidadeAlbuns - 1], "==========", strlen("==========")) == 0) {
                break;
            }
        }



        (*posicaoArtista)++;
    }

    fclose(arquivo);
}

void inserirArtista (int posicaoArtista) {
    
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
    //printf("\nO que deseja fazer? ");
    //scanf("%d", &esc);

    printf("%s", listaArtistas[0].nome);

    switch(esc) {
        case 1:
            inserirArtista(posicaoArtista);
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

    return 0;
}
