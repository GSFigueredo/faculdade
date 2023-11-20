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
void editarUsuario(users usuario[], int id, int id2);
void imprimirUsuarios(users usuario[], int id);

int idDinamico(int x){

    int id = x + 1;
    return id;
}

int verificarGenero(char x[30]) {

    if (strcmp(x, "masculino") == 0 || strcmp(x, "feminino") == 0 || strcmp(x, "indiferente") == 0) {
        return 1;
    } else {
        return 0;
    }
}

void cadastrar(users usuario[], int id){
    
    int testeG;
    usuario[id].id = id;

    system("clear");
    printf("------------------------- Novo registro -------------------------");
    printf("\n");

    printf("Nome completo: ");
    fgets(usuario[id].nome, sizeof(usuario[id].nome), stdin);

    getchar();

    printf("Email: ");
    fgets(usuario[id].email, sizeof(usuario[id].email), stdin);

    while (getchar() != '\n');

    do{
        printf("Gênero: ");
        fgets(usuario[id].sexo, sizeof(usuario[id].sexo), stdin);

        while (getchar() != '\n');

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

    while (getchar() != '\n');

    printf("Vacinado? sim[1] / não[0] ");
    scanf("%d", &usuario[id].vacina);

    getchar();
}

void editarUsuario(users usuario[], int id, int id2) {
    for(int c = 0; c < id; c++) {
        if(usuario[c].id == id2) {
            int esc; 
            char novoNome[50];

            printf("O que você deseja editar?");    
            printf("\n");
            printf("Nome [1]");
            printf("\n");
            printf("Email [2]");
            printf("\n");
            printf("Sexo [3]");
            printf("\n");
            printf("Endereço [4]");
            printf("\n");

            scanf("%d", &esc);

            switch (esc)
            {
            case 1:
                printf("Qual o novo nome?");
                fgets(novoNome, sizeof(novoNome), stdin);

                while (getchar() != '\n');

                strcpy(usuario[c].nome, novoNome);
                break;
            
            default:
                break;
            }
        }
    }
}

void imprimirUsuarios(users usuario[], int id) {
    for(int c = 1; c < id+1; c++) {
        printf("---------------------------------------");
        printf("\n");
        printf("Nome: %s", usuario[c].nome);
        printf("\n");
        printf("Email: %s", usuario[c].email);
        printf("\n");
        printf("Sexo: %s", usuario[c].sexo);
        printf("\n");
        printf("Endereço: %s", usuario[c].endereco);
        printf("\n");
        printf("Altura: %.2f", usuario[c].altura);
        printf("\n");
        printf("---------------------------------------");
    }
}

int main(){

    int id = 0;
    int resp;
    int esc;
    users usuario[1000];

do {

    int id2;

    printf("O que você deseja fazer?");
    printf("\n");

    printf("Cadastrar usuário [1]");
    printf("\n");
    printf("Editar usuário [2]");
    printf("\n");
    printf("Excluir usuário [3]");
    printf("\n");
    printf("Buscar usuário [4]");
    printf("\n");
    printf("Checar usuários [5]");
    printf("\n");

    scanf("%d", &esc);

    switch (esc)
    {
    case 1:
        id = idDinamico(id);  
        cadastrar(usuario, id);
        break;
    case 2:
        printf("Qual o id?");
        scanf("%d", &id2);

        editarUsuario(usuario, id, id2);
    break;

    case 5:
         imprimirUsuarios(usuario, id);
    break;
    }

    system("clear");

    printf("Deseja realizar uma nova interação? SIM [1] / NÃO [0]");
    scanf("%d", &resp);

    } while (resp != 0);
    return 0;
}