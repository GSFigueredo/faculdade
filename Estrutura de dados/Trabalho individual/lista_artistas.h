#ifndef LISTA_ARTISTAS_H
#define LISTA_ARTISTAS_H

typedef struct artistas;

void iniciarLista(artistas listaArtistas[], int *posicaoArtista);
void inserirArtista(int posicaoArtista);
void limparCaractere ();
void removerArtista(artistas listaArtistas[], int *posicaoArtista, char nomeArtista[100]);
void editarArtista(artistas listaArtistas[], int *posicaoArtista, char nomeArtista[100]);

#endif
