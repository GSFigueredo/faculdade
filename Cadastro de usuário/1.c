#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
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

int idDinamico(int x);
void cadastrar(users usuario[], int id);
int verificarGenero(char x[30]);

int idDinamico(int x){

    int id = x + 1;
    return id;
}

void cadastrar(users usuario[], int id){
    
    int testeG;
    usuario[id].id = id;

    printf("Nome completo: ");
    fgets(usuario[id].nome, sizeof(usuario[id].nome), stdin);

    printf("Email: ");
    fgets(usuario[id].email, sizeof(usuario[id].email), stdin);

    do{

        printf("Gênero: ");
        fgets(usuario[id].sexo, sizeof(usuario[id].sexo), stdin);

        usuario[id].sexo[strcspn(usuario[id].sexo, "\n")] = '\0';

        testeG = verificarGenero(usuario[id].sexo);

        if(testeG == 0) {
            printf("Gênero fora do padrão, favor digitar novamente...");
            printf("\n");
        }   
    } while(testeG != 1);

    printf("Endereço: ");
    fgets(usuario[id].endereco, sizeof(usuario[id].endereco), stdin);

    printf("Altura: ");
    scanf("%lf", &usuario[id].altura);

    getchar();

    printf("Vacinado? sim[1] / não[0] ");
    scanf("%d", &usuario[id].vacina);

    getchar();
}


int verificarGenero(char x[30]) {

    if (strcmp(x, "masculino") == 0 || strcmp(x, "feminino") == 0 || strcmp(x, "indiferente") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(){

    int id = 0;
    users usuario[1000];

    for (int c = 0; c < 3; c++){
          
        id = idDinamico(id);  
        system("clear");
        printf("------------------------- Novo registro -------------------------");
        printf("\n");

        cadastrar(usuario, id);
    }
    return 0;
}