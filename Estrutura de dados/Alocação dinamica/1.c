#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct noFilme {
    char nome[50];
    int anoLancamento;
    char diretor[50];
    struct noFilme *proxFilme;
} noFilme;

void iniciarLista(noFilme **head, noFilme *filme) {
    *head = filme; 
    filme->proxFilme = NULL;
}

void adicionarFilme(noFilme **head, noFilme *filme) { 
    if (*head == NULL) {
        iniciarLista(head, filme);
    } else {
        filme->proxFilme = *head;
        *head = filme; 
    }
}

void listarFilmes(noFilme *head) {
    noFilme *aux = head;
    if (head != NULL) {
        while (aux != NULL) {

            printf("\n---------------");
            printf("\nNome do filme: %s", aux->nome);
            printf("\nAno lançamento: %d", aux->anoLancamento);
            printf("\nDiretor: %s", aux->diretor);

            aux = aux->proxFilme;
        }
    }
}

int main() {
    noFilme *head = NULL;

    noFilme filme1;

    strcpy(filme1.nome, "Senhor dos aneis");
    filme1.anoLancamento = 2002;
    strcpy(filme1.diretor, "Peter Jackson");
    filme1.proxFilme = NULL;
    adicionarFilme(&head, &filme1); 

    noFilme filme2;

    strcpy(filme2.nome, "O Poderoso Chefão");
    filme2.anoLancamento = 1972;
    strcpy(filme2.diretor, "Francis Ford Coppola");
    filme2.proxFilme = NULL;
    adicionarFilme(&head, &filme2); 

    listarFilmes(head);

    return 0;
}