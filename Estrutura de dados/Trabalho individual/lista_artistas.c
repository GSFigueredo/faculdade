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

int ordenarAlfabeticamente(const void *a, const void *b) {
    const artistas *artistaA = (const artistas *)a;
    const artistas *artistaB = (const artistas *)b;
    return strcmp(artistaA->nome, artistaB->nome);
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

void reescreverLista(artistas listaArtistas[], int quantidadeArtistas) {

    qsort(listaArtistas, quantidadeArtistas, sizeof(artistas), ordenarAlfabeticamente);

    FILE *arquivo = fopen("artistas.txt", "w");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    fseek(arquivo, 0, SEEK_SET);

    for(int cont = 0; cont < quantidadeArtistas; cont++) {

        limparString(listaArtistas[cont].nome);
        limparString(listaArtistas[cont].tipoMusc);
        limparString(listaArtistas[cont].naturalidade);
        for (int quanAlbuns = 0; quanAlbuns < listaArtistas[cont].quantidadeAlbuns; quanAlbuns++) {
            limparString(listaArtistas[cont].listaAlbuns[quanAlbuns]);
        }

        fprintf(arquivo, "%s\n", listaArtistas[cont].nome);
        fprintf(arquivo, "%s\n", listaArtistas[cont].tipoMusc);
        fprintf(arquivo, "%s\n", listaArtistas[cont].naturalidade);
        for(int quanAlbuns = 0; quanAlbuns < listaArtistas[cont].quantidadeAlbuns; quanAlbuns++) {
            fprintf(arquivo, "%s\n", listaArtistas[cont].listaAlbuns[quanAlbuns]);
        }

        if(cont == quantidadeArtistas -1) {
            fprintf(arquivo, "%s", "==========");
        }
        else {
            fprintf(arquivo, "%s\n", "==========");
        }
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
        printf("Digite os albuns do artista, album %d: ", quantidadeAlbuns+1);
        fgets(listaArtistas[*posicaoArtista].listaAlbuns[quantidadeAlbuns], sizeof(listaArtistas[*posicaoArtista].listaAlbuns[quantidadeAlbuns]), stdin);
        listaArtistas[*posicaoArtista].listaAlbuns[quantidadeAlbuns][strcspn(listaArtistas[*posicaoArtista].listaAlbuns[quantidadeAlbuns], "\n")] = '\0';
        fprintf(arquivo, "%s\n", listaArtistas[*posicaoArtista].listaAlbuns[quantidadeAlbuns]);

        quantidadeAlbuns++;
        listaArtistas[*posicaoArtista].quantidadeAlbuns = quantidadeAlbuns;

        printf("\n[0] Digitar novo album |");
        printf(" [1] Encerrar: ");
        scanf("\n%d", &esc);
        limparCaractere();
    } while (esc != 1);

    fprintf(arquivo, "%s", "==========");

    fclose(arquivo);

    (*posicaoArtista)++;
}

void removerArtista(artistas listaArtistas[], int *posicaoArtista, char nomeArtista[100]) {
    int indice = -1;

    for(int c = 0; c < *posicaoArtista; c++) {
        if(strcmp(nomeArtista, listaArtistas[c].nome) == 0) {
            indice = c;
            break;
        }
    }

    if (indice != -1) {
        for (int i = indice; i < *posicaoArtista - 1; i++) {
            listaArtistas[i] = listaArtistas[i + 1];
        }
        (*posicaoArtista)--;

        reescreverLista(listaArtistas, *posicaoArtista);
        
        printf("Artista removido com sucesso.\n");
    } else {
        printf("Artista não encontrado.\n");
    }
}

void editarArtista(artistas listaArtistas[], int c, char tipoEdicao[100]) {

    FILE *arquivo = fopen("artistas.txt", "r+");
    long posicaoI = 0, posicaoF = 0;
    char linhaTxt[300];
    int quantidadeAlbuns = 0;
    int esc = 1;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(EXIT_FAILURE);
    }

    while (fgets(linhaTxt, sizeof(linhaTxt), arquivo) != NULL) {
        if (strstr(linhaTxt, listaArtistas[c].nome) != NULL) {
            posicaoI = ftell(arquivo) - strlen(linhaTxt);
            limparCaractere();

            if(strcmp(tipoEdicao, "editarNome") == 0) { 
                printf("Novo nome: ");
                fgets(listaArtistas[c].nome, sizeof(listaArtistas[c].nome), stdin);
                listaArtistas[c].nome[strcspn(listaArtistas[c].nome, "\n")] = '\0';
            } 
            
            if(strcmp(tipoEdicao, "editarTipoMusc") == 0) { 
                printf("Novo tipo musical: ");
                fgets(listaArtistas[c].tipoMusc, sizeof(listaArtistas[c].tipoMusc), stdin);
                listaArtistas[c].tipoMusc[strcspn(listaArtistas[c].tipoMusc, "\n")] = '\0';
            } 
            
            if(strcmp(tipoEdicao, "editarNaturalidade") == 0) { 
                printf("Nova naturalidade: ");
                fgets(listaArtistas[c].naturalidade, sizeof(listaArtistas[c].naturalidade), stdin);
                listaArtistas[c].naturalidade[strcspn(listaArtistas[c].naturalidade, "\n")] = '\0';
            } 
            
            if(strcmp(tipoEdicao, "editarAlbuns") == 0) { 
               do {
                    printf("Digite os albuns do artista, album %d: ", quantidadeAlbuns+1);
                    fgets(listaArtistas[c].listaAlbuns[quantidadeAlbuns], sizeof(listaArtistas[c].listaAlbuns[quantidadeAlbuns]), stdin);
                    listaArtistas[c].listaAlbuns[quantidadeAlbuns][strcspn(listaArtistas[c].listaAlbuns[quantidadeAlbuns], "\n")] = '\0';

                    quantidadeAlbuns++;
                    listaArtistas[c].quantidadeAlbuns = quantidadeAlbuns;

                    printf("\n[0] Digitar novo album |");
                    printf(" [1] Encerrar: ");
                    scanf("\n%d", &esc);
                    limparCaractere();
                } while (esc != 1);
            }
            break;
        }
    }

    fseek(arquivo, posicaoI, SEEK_SET);
    while (fgets(linhaTxt, sizeof(linhaTxt), arquivo) != NULL) {
        if (strstr(linhaTxt, "==========") != NULL) {
            posicaoF = ftell(arquivo); 
            break;
        }
    }

    fseek(arquivo, posicaoI, SEEK_SET);

    while (ftell(arquivo) < posicaoF) {
        fprintf(arquivo, " "); 
    }

    fseek(arquivo, posicaoI, SEEK_SET);

    fprintf(arquivo, "%s\n", listaArtistas[c].nome);
    fprintf(arquivo, "%s\n", listaArtistas[c].tipoMusc);
    fprintf(arquivo, "%s\n", listaArtistas[c].naturalidade);

    for (int i = 0; i < listaArtistas[c].quantidadeAlbuns; i++) {
        fprintf(arquivo, "%s\n", listaArtistas[c].listaAlbuns[i]);
    }
    fprintf(arquivo, "%s", "==========");

    fclose(arquivo);
    
}

void tipoEdicao(artistas listaArtistas[], int *posicaoArtista, char nomeArtista[200]) {

    int nenhum;
    
    for(int c = 0; c <= *posicaoArtista-1; c++) { 
        if(strcmp(nomeArtista, listaArtistas[c].nome) == 0) { 
            int esc;
            nenhum = 0;

            printf("\n==================== EDIÇÃO ====================");
            printf("\n[1] Nome\n");
            printf("[2] Tipo musical\n");
            printf("[3] Naturalidade\n");
            printf("[4] Albuns\n");
            printf("==================== ****** ====================");
            printf("\nQual informação você deseja editar? ");
            scanf("%d", &esc);

            switch(esc) {
                case 1:
                    editarArtista(listaArtistas, c, "editarNome");
                break;    

                case 2:
                    editarArtista(listaArtistas, c, "editarTipoMusc");
                break;

                case 3:
                    editarArtista(listaArtistas, c, "editarNaturalidade");
                break;

                case 4:
                   editarArtista(listaArtistas, c, "editarAlbuns");
                break;
            }
        }  else {
            nenhum = 1;
        }
    }

    if(nenhum != 0) {
        printf("Nenhum artista encontrado...");
    }
}

void buscarAlbum(artistas listaArtistas[], int quanArtistas, char nomeAlbum[200]) {

    int encontro = 0;

    for(int cont = 0; cont < quanArtistas; cont++) {
        for(int contAlbuns = 0; contAlbuns < listaArtistas[cont].quantidadeAlbuns; contAlbuns++) {
            if(strcmp(nomeAlbum, listaArtistas[cont].listaAlbuns[contAlbuns]) == 0){
                printf("\nAlbum %s encontrado com sucesso, ele pertence ao artista: %s", listaArtistas[cont].listaAlbuns[contAlbuns], listaArtistas[cont].nome);
                encontro = 1;
            }
        }
    }

    if(encontro == 0) {
        printf("\nNenhum album foi encontrado.");
    }
}

void buscarBinario(artistas listaArtistas[], int inicio, int fim, char nomeArtista[]) {
    int encontrado = 0;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        int comparacao = strcmp(listaArtistas[meio].nome, nomeArtista);

        if (comparacao == 0) {
            printf("Artista %s encontrado com sucesso.\n", listaArtistas[meio].nome);
            encontrado = 1;
            break;
        }

        if (comparacao > 0) {
            fim = meio - 1;
        } else { 
            inicio = meio + 1;
        }
    }

    if (!encontrado) {
        printf("Artista não encontrado.\n");
    }
}


int main () {
    artistas listaArtistas[200];
    int posicaoArtista = 0;
    int esc;
    char nomeArtista[100];
    char nomeAlbum[100];
    int resp = 0;

    iniciarLista(listaArtistas, &posicaoArtista);
    reescreverLista(listaArtistas, posicaoArtista);

    do{
        printf("==================== MENU ====================");
        printf("\n[1] Inserir novo artista\n");
        printf("[2] Remover artista\n");
        printf("[3] Editar artista\n");
        printf("[4] Buscar artista (Binária)\n");
        printf("[5] Buscar álbum\n");
        printf("==================== **** ====================");
        printf("\nO que deseja fazer? ");
        scanf("%d", &esc);

        switch(esc) {
            case 1:
                inserirArtista(listaArtistas, &posicaoArtista);
                break;

            case 2:
                limparCaractere();
                printf("Digite o nome do artista que você deseja excluir: ");
                fgets(nomeArtista, sizeof(nomeArtista), stdin);
                nomeArtista[strcspn(nomeArtista, "\n")] = '\0';

                removerArtista(listaArtistas, &posicaoArtista, nomeArtista);
                break;

            case 3:
                limparCaractere();
                printf("Digite o nome do artista que você deseja editar: ");
                fgets(nomeArtista, sizeof(nomeArtista), stdin);
                nomeArtista[strcspn(nomeArtista, "\n")] = '\0';

                tipoEdicao(listaArtistas, &posicaoArtista, nomeArtista);
                break;

            case 4:
                limparCaractere();
                printf("Digite o nome do artista que você deseja buscar: ");
                fgets(nomeArtista, sizeof(nomeArtista), stdin);
                nomeArtista[strcspn(nomeArtista, "\n")] = '\0';

                buscarBinario(listaArtistas, 0, posicaoArtista - 1, nomeArtista);
                break;

            case 5:
                limparCaractere();
                printf("Digite o nome do album: ");
                fgets(nomeAlbum, sizeof(nomeAlbum), stdin);
                nomeAlbum[strcspn(nomeAlbum, "\n")] = '\0';

                buscarAlbum(listaArtistas, posicaoArtista, nomeAlbum);
                break;

            default:
                printf("Obrigado por utilizar nosso programa.");
                break;
        }

        qsort(listaArtistas, posicaoArtista, sizeof(artistas), ordenarAlfabeticamente);

        printf("\nDeseja realizar mais uma interação? SIM [0] / NÃO [1] ");
        scanf("%d", &resp);

    } while (resp != 1);

    return 0;
}