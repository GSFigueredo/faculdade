#include <stdio.h> 
#include <math.h>
#include <string.h>

void retirarFilmes(int filmes) {

    if(filmes%15 == 0) {
        filmes = filmes/15;

        printf("Você tem direito a pegar %d filmes de graça", filmes);
    }

}

int main () {

    int filmes;

    printf("Quantos filmes você deseja retirar?");
    scanf("%d", &filmes);

    retirarFilmes(filmes);

    return 0;
}