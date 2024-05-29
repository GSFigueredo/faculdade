#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct musicas{
    char nomeArtista[100];
    char nomeMusica[100];
    int idMusica;
    struct musicas *anteriorMusica;
    struct musicas *proximaMusica;
} musicas;

void limparCaractere () {
    int limp; 
    while ((limp = getchar()) != '\n' && limp != EOF);
}

void iniciarLista(musicas listaMusicas[], int *posicaoMusica) {
    FILE *arquivo = fopen("musicas.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    char linhaTxt[200];
    while (fgets(linhaTxt, sizeof(linhaTxt), arquivo)) {
        listaMusicas[*posicaoMusica].idMusica = *posicaoMusica;
        char *separador = strtok(linhaTxt, ";");
        if (separador != NULL) {
            strcpy(listaMusicas[*posicaoMusica].nomeArtista, separador);
            separador = strtok(NULL, "\n");
            if (separador != NULL) {
                strcpy(listaMusicas[*posicaoMusica].nomeMusica, separador);
                (*posicaoMusica)++;
            }

        }
    }

    fclose(arquivo);
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

void reescreverLista(musicas listaMusicas[], int quantidadeMusicas) {
    int primeiraMusica = 0;
    int ultimaMusica = 0;

    FILE *arquivo = fopen("musicas.txt", "w+");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    fseek(arquivo, 0, SEEK_SET);

    for(int cont = 0; cont < quantidadeMusicas; cont++) {

        limparString(listaMusicas[cont].nomeArtista);
        limparString(listaMusicas[cont].nomeMusica);

        if((cont == 0)) {
            listaMusicas[cont].anteriorMusica = &listaMusicas[quantidadeMusicas-1]; 
            primeiraMusica = cont;
        } else { 
            listaMusicas[cont].anteriorMusica = &listaMusicas[cont-1];
        }

        if(listaMusicas[cont+1].idMusica == NULL) {
            listaMusicas[cont].proximaMusica = &listaMusicas[primeiraMusica]; 
        } else { 
            listaMusicas[cont].proximaMusica = &listaMusicas[cont+1];
        }

        fprintf(arquivo, "%s", listaMusicas[cont].nomeArtista);
        fprintf(arquivo, "%s", ";");
        fprintf(arquivo, "%s\n", listaMusicas[cont].nomeMusica);
    } 

    fclose(arquivo);
} 

void exibirPlaylistCadastro (musicas listaMusicas[], int quantidadeMusicas) {
    for(int cont = 0; cont < quantidadeMusicas; cont++) {
            printf("\n%d. %s, %s",cont+1, listaMusicas[cont].nomeArtista, listaMusicas[cont].nomeMusica);
        }
    }

void inserirMusica(musicas listaMusicas[], int *posicaoMusica) {

    printf("\nDigite o nome do artista: ");
    fgets(listaMusicas[*posicaoMusica].nomeArtista, sizeof(listaMusicas[*posicaoMusica].nomeArtista), stdin);
    listaMusicas[*posicaoMusica].nomeArtista[strcspn(listaMusicas[*posicaoMusica].nomeArtista, "\n")] = '\0';

    printf("\nDigite o nome da música: ");
    fgets(listaMusicas[*posicaoMusica].nomeMusica, sizeof(listaMusicas[*posicaoMusica].nomeMusica), stdin);
    listaMusicas[*posicaoMusica].nomeMusica[strcspn(listaMusicas[*posicaoMusica].nomeMusica, "\n")] = '\0';

    (*posicaoMusica)++;
}

void removerMusica(musicas listaMusicas[], int *posicaoMusica, char nomeMusica[100]) {
    int indice = -1;

    for(int c = 0; c < *posicaoMusica; c++) {
        if(strcmp(nomeMusica, listaMusicas[c].nomeMusica) == 0) {
            indice = c;
            break;
        }
    }

    if (indice != -1) {
        for (int i = indice; i < *posicaoMusica - 1; i++) {
            listaMusicas[i] = listaMusicas[i + 1];
        }
        (*posicaoMusica)--;

        reescreverLista(listaMusicas, *posicaoMusica);
        
        printf("Musica removida com sucesso.\n");
    } else {
        printf("Musica não encontrada.\n");
    }
}

void buscarMusica(musicas listaMusicas[], int quanMusicas, char nomeMusica[200]) {

    int encontro = 0;

    for(int cont = 0; cont < quanMusicas; cont++) {
        if(strcmp(listaMusicas[cont].nomeMusica, nomeMusica) == 0) { 
            printf("\nMusica encontrada... ");
            printf("\nArtista: %s", listaMusicas[cont].nomeArtista);
            printf("\nMúsica: %s", listaMusicas[cont].nomeMusica);

            encontro = 1;
        }
    }

    if(encontro == 0) {
        printf("\nNenhuma música encontrada.");
    }
}

int compararMusicas(const void *a, const void *b) {
    musicas *musicaA = (musicas *)a;
    musicas *musicaB = (musicas *)b;
    return strcasecmp(musicaA->nomeMusica, musicaB->nomeMusica);
}

void exibirPlaylistOrdenadaMusica(musicas listaMusicas[], int quantidadeMusicas) {

    musicas listaMusicasCopia[500];

    for(int cont = 0; cont < quantidadeMusicas; cont++) {
        strcpy( listaMusicasCopia[cont].nomeArtista, listaMusicas[cont].nomeArtista);
        strcpy( listaMusicasCopia[cont].nomeMusica, listaMusicas[cont].nomeMusica);
        listaMusicasCopia[cont].idMusica = listaMusicas[cont].idMusica;
        listaMusicasCopia[cont].anteriorMusica = listaMusicas[cont].anteriorMusica;
        listaMusicasCopia[cont].proximaMusica = listaMusicas[cont].proximaMusica;
    }

    qsort(listaMusicasCopia, quantidadeMusicas, sizeof(musicas), compararMusicas);

    printf("\nPlaylist ordenada pelo nome das músicas:");
    for (int cont = 0; cont < quantidadeMusicas; cont++) {
        printf("\n%d. %s, %s", cont+1, listaMusicasCopia[cont].nomeArtista, listaMusicasCopia[cont].nomeMusica);
    }
}

musicaAtual(musicas listaMusicas[]){ 

}

int main () {
    musicas listaMusicas[500];
    int posicaoMusica = 0;
    int esc;
    char nomeMusica[100];
    int resp = 0;

    iniciarLista(listaMusicas, &posicaoMusica);
    reescreverLista(listaMusicas, posicaoMusica);

    do{
        system("clear");
        printf("==================== MENU ====================");
        printf("\n[1] Exibir playlist por ordem de cadastro\n");
        printf("[2] Exibir playlist ordenada pelo nome das músicas\n");
        printf("[3] Inserir nova música\n");
        printf("[4] Remover música\n");
        printf("[5] Buscar música\n");
        printf("[6] Próxima música\n");
        printf("[7] Música anterior\n");
        printf("==================== **** ====================");
        printf("\nO que deseja fazer? ");
        scanf("%d", &esc);

        musicaAtual(listaMusicas);

        switch(esc) {
            case 1:
                exibirPlaylistCadastro(listaMusicas, posicaoMusica);
            break;

            case 2:
                exibirPlaylistOrdenadaMusica(listaMusicas, posicaoMusica);
            break;

            case 3:
                limparCaractere();
                inserirMusica(listaMusicas, &posicaoMusica);
                reescreverLista(listaMusicas, posicaoMusica);
            break;

            case 4:
                limparCaractere();
                printf("Digite o nome da música que você deseja remover: ");
                fgets(nomeMusica, sizeof(nomeMusica), stdin);
                nomeMusica[strcspn(nomeMusica, "\n")] = '\0';

                removerMusica(listaMusicas, &posicaoMusica, nomeMusica);
            break;

            case 5:
                limparCaractere();
                printf("Digite o nome da música: ");
                fgets(nomeMusica, sizeof(nomeMusica), stdin);
                nomeMusica[strcspn(nomeMusica, "\n")] = '\0';

                buscarMusica(listaMusicas, posicaoMusica, nomeMusica);
                break;
            break;

            case 6:
                
            break;

            case 7:
                
            break;

            default:
                printf("Obrigado por utilizar nosso programa.");
            break;
        }

        printf("\nDeseja realizar mais uma interação? SIM [0] / NÃO [1] ");
        scanf("%d", &resp);

    } while (resp != 1);

    printf("\nnome artista: %s", listaMusicas[4].nomeArtista);
    printf("\nnome música: %s", listaMusicas[4].nomeMusica);
    printf("\n endereço anterior: %p", listaMusicas[4].anteriorMusica);
    printf("\n endereço proxima: %p", listaMusicas[4].proximaMusica);
    printf("\nendereco anterior: %p", &listaMusicas[3]);
    printf("\n endereco proximo: %p", &listaMusicas[5]);
    printf("\n contador final: %d", posicaoMusica);

    return 0;
}