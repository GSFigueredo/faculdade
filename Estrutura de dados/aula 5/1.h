#ifndef FILMES_H
#define FILMES_H

typedef struct Filme Filme;

struct Filme *criaLista(int numAlunos);

void listarFilme(ListarFilmes *filmes);

void adicionarFilme(listarFilmes **filmes, Filme filme);

void removerFilme(Filme **Filme, int idFilme);

void buscarFilme(struct Filme *lista, int id);

#endif