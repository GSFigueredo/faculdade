#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int ultimaPosLivre = 0;

struct Aluno
{
    int idade;
    char nome[50];
    float nota;
};


struct Aluno *criaLista(int numAlunos){
    //alocando dinamicamente
    struct Aluno *alunos = (struct Aluno*) malloc(numAlunos*sizeof(Aluno));
    return alunos;
}



void adicionarAluno(struct Aluno **lista, struct Aluno aluno)
{
    strcpy((*lista)[ultimaPosLivre].nome, aluno.nome);
    (*lista)[ultimaPosLivre].idade = aluno.idade;
    (*lista)[ultimaPosLivre].nota = aluno.nota;

    ultimaPosLivre++;
}

void listarAluno(struct Aluno *lista){
    for(int i = 0; i<ultimaPosLivre;i++){
        printf("Aluno: %d\n", i + 1);
        printf("Nome: %s\n", lista[i].nome );
        printf("Idade: %d\n", lista[i].idade);
        printf("Float: %.2f\n", lista[i].nota);
        printf("\n");
    }
}
int main(){
    struct Aluno *alunos;
    alunos = criaLista(10);

    struct Aluno aluno1,aluno2,aluno3;

    strcpy(aluno1.nome, "joao");
    aluno1.idade = 19;
    aluno1.nota = 8.5;

    strcpy(aluno2.nome, "carlos");
    aluno2.idade = 18;
    aluno2.nota = 7;

    strcpy(aluno3.nome, "robsû");
    aluno3.idade = 21;
    aluno3.nota = 9;
    
    adicionarAluno(&alunos,aluno1);
    adicionarAluno(&alunos,aluno2);
    adicionarAluno(&alunos,aluno3);

    //adicionarAluno(alunos,);
    listarAluno(alunos);
    return 0;
}