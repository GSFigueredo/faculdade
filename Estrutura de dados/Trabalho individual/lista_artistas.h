#ifndef LISTA_ARTISTAS_H
#define LISTA_ARTISTAS_H

typedef struct artistas{
    char nome[50];
    char tipoMusc[50];
    char naturalidade[50];
    char listaAlbuns[200][50];
    int quantidadeAlbuns;
} artistas;

void limparCaractere ();
void iniciarLista(artistas listaArtistas[], int *posicaoArtista);
void inserirArtista (artistas listaArtistas[], int *posicaoArtista);
void removerArtista(artistas listaArtistas[], int *posicaoArtista, char nomeArtista[100]);
void editarArtista(artistas listaArtistas[], int c, char tipoEdicao[100]);
void tipoEdicao(artistas listaArtistas[], int *posicaoArtista, char nomeArtista[200]);

#endif
