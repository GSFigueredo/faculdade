#ifndef LISTA_ARTISTAS_H
#define LISTA_ARTISTAS_H

typedef struct artistas artistas;

void iniciarLista(artistas listaArtistas[], int *posicaoArtista);
void inserirArtista(artistas listaArtistas[], int *posicaoArtista); // Corrigido para corresponder à definição
void limparCaractere();
void removerArtista(artistas listaArtistas[], int *posicaoArtista, char nomeArtista[100]);
void tipoEdicao(artistas listaArtistas[], int *posicaoArtista, char nomeArtista[100]);
void editarArtista(artistas listaArtistas[], int *posicaoArtista, char tipoEdicao[100]); // Corrigido para corresponder à definição

#endif
