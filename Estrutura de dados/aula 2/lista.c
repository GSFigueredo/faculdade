#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"

// Variáveis

    int cont = 0;

// Fim variáveis


struct Aluno{
    char nome[50];
    int idade;
    char curso[50];
    float nota;
} aluno;

struct Aluno *criarLista(int numAlunos){

    struct Aluno *alunos = (struct Aluno*)malloc(numAlunos * sizeof(aluno));

    return alunos;
}

void adicionarAlunos(struct Aluno **lista, struct Aluno aluno) {

    strcpy(lista[cont]->nome, aluno.nome);
    lista[cont]->idade = aluno.idade;
    lista[cont]->nota = aluno.nota;

    cont++;

}

void listarAlunos (Aluno *lista) {
    for(int i = 0; i < cont; i++) {
        printf("Aluno: %s", lista[i].nome);
        printf("\nIdade: %d", lista[i].idade);
        printf("\nCurso: %s", lista[i].curso);
        printf("\nNota: %.2f", lista[i].nota);
    }
}

int main(){

    struct Aluno *alunos;

    alunos =  criarLista(10);

    struct Aluno aluno1, aluno2;

    strcpy(aluno1.nome, "Gabriel");
    aluno1.idade = 18;
    strcpy(aluno1.curso, "CCC");
    aluno1.nota = 10;

    adicionarAlunos(&alunos, aluno1);

    strcpy(aluno2.nome, "Joao");
    aluno2.idade = 19;
    strcpy(aluno2.curso, "CCC");
    aluno2.nota = 8;

    adicionarAlunos(&alunos, aluno2);

    listarAlunos(alunos);

    return 0;
}