#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int idDinamico(int x);
void cadastrar();
int verificarGenero(char x[30]);

typedef struct
{
    int id;
    char nome[50];
    char email[100];
    char sexo[30];
    char endereco[350];
    double altura;
    int vacina;
} users;

int idDinamico(int x){

    int id = x + 1;
    return id;
}

void cadastrar(){
    int id = 0;  
    id = idDinamico(id);   
    int testeG;

for (int c = 0; c < 2; c++){

    users usuario[c];
    usuario[c].id = id;

    printf("Nome completo: ");
    fgets(usuario[c].nome, sizeof(usuario[c].nome), stdin);

    printf("\nEmail: ");
    fgets(usuario[c].email, sizeof(usuario[c].email), stdin);
    getchar();

    do{

        printf("\nGênero: ");
            fgets(usuario[c].sexo, sizeof(usuario[c].sexo), stdin);

            testeG = verificarGenero(usuario[c].sexo);

            printf("teste %d", testeG);

            if(testeG == 0) {
                printf("Gênero fora do padrão, favor digitar novamente...");
            }   
        } while(testeG == 0);

    printf("\nEndereço: ");
    fgets(usuario[c].endereco, sizeof(usuario[c].endereco), stdin);

    printf("\nAltura: ");
    scanf("%lf", &usuario[c].altura);

    getchar();

    printf("\nVacinado? sim[1] / não[0]");
    scanf("%d", &usuario[c].vacina);

    getchar();
}
}

int verificarGenero(char x[30]) {

    if (strcmp(x, "masculino") == 0 || strcmp(x, "feminino") == 0 || strcmp(x, "indiferente") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(){

    for (int c = 0; c < 2; c++){
        printf("Novo registro:");
        printf("\n");

        cadastrar();

    }
    return 0;
}