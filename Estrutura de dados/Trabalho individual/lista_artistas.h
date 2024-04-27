#ifndef LISTA_ARTISTAS_H
#define LISTA_ARTISTAS_H

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

void limparCaractere ();
void iniciarLista(artistas listaArtistas[], int *posicaoArtista);
void inserirArtista (artistas listaArtistas[], int *posicaoArtista);
int ordenarAlfabeticamente(const void *a, const void *b);
void limparString(char *str);
void reescreverLista(artistas listaArtistas[], int quantidadeArtistas);
void removerArtista(artistas listaArtistas[], int *posicaoArtista, char nomeArtista[100]);
void editarArtista(artistas listaArtistas[], int c, char tipoEdicao[100]);
void tipoEdicao(artistas listaArtistas[], int *posicaoArtista, char nomeArtista[200]);
void buscarAlbum(artistas listaArtistas[], int quanArtistas, char nomeAlbum[200]);
void buscarBinario(artistas listaArtistas[], int inicio, int fim, char nomeArtista[]);

#endif
