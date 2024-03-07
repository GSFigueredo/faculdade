#include <stdio.h> 
#include <math.h>
#include <string.h>

void retirarFilmes(int filmes[500]) {

        int gratis[500];

        for(int c = 0; c < 500; c++) {
          gratis[c] = filmes[c]/15;
        }

        for(int c = 0; c < 500; c++) {
            printf("Cliente %d pode pegar %d filmes de graça", filmes[c], gratis[c]);
            printf("\n");
        }

}

int main () {

    int filmes[500];

    for(int c = 0; c < 500; c++) {
        filmes[c] = rand() % 100 +1;
    }

    retirarFilmes(filmes);

    return 0;
}