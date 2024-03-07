#include <stdio.h>
#include <string.h>
#include <math.h>

struct users {
    char nome[30];
    char cpf[18];
    int idade; 
    float salario;
};

int main() {

    struct users p1; 

    printf("Digite seu nome: ");
    fgets(p1.nome, sizeof(p1.nome), stdin);

    printf("Digite seu cpf: ");
    fgets(p1.cpf, sizeof(p1.cpf), stdin);

    printf("Digite sua idade: ");
    scanf("%d", &p1.idade);

    printf("Digite seu salário: ");
    scanf("%f", &p1.salario);

    system("clear");

    printf("Nome: %s", p1.nome);
    printf("\n");
    printf("CPF: %s", p1.cpf);
    printf("\n");
    printf("Idade: %d", p1.idade);
    printf("\n");
    printf("Salário: %.2f", p1.salario);


    return 0;
}