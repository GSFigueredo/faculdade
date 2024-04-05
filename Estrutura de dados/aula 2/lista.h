#ifndef ALUNOS_H
#define ALUNOS_H

typedef struct Aluno Aluno;

struct Aluno *criaLista(int numAlunos);

void listarAlunos(Aluno *lista);

void adicionarAluno(Aluno **lista, Aluno aluno);

void removerAluno(Aluno **lista, int matricula);

void buscarAlunos(struct Aluno *lista, int id);

#endif