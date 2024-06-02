#ifndef LISTA_MUSICAS_H
#define LISTA_MUSICAS_H

typedef struct musicas{
    char nomeArtista[100];
    char nomeMusica[100];
    int idMusica;
    struct musicas *anteriorMusica;
    struct musicas *proximaMusica;
} musicas;

void limparCaractere ();
void iniciarLista(musicas listaMusicas[], int *posicaoMusica);
void limparString(char *str);
void reescreverLista(musicas listaMusicas[], int quantidadeMusicas);
void exibirPlaylistCadastro (musicas listaMusicas[], int quantidadeMusicas);
void inserirMusica(musicas listaMusicas[], int *posicaoMusica);
void removerMusica(musicas listaMusicas[], int *posicaoMusica, char nomeMusica[100]);
void buscarMusica(musicas listaMusicas[], int quanMusicas, char nomeMusica[200]);
int compararMusicas(const void *a, const void *b);
void exibirPlaylistOrdenadaMusica(musicas listaMusicas[], int quantidadeMusicas);
void proximaMusica(musicas **musicaAtual);
void musicaAnterior(musicas **musicaAtual);
int main ();

#endif