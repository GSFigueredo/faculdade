#include <stdio.h>
#include <math.h>
#include <string.h>

float validarQuantidade(int x){
    if (x <= 50){
        return 1;
    } else if (x > 50 && x <= 80){
        return 0.50;
    } else if (x > 80){
        return 0.75;
    }
}

float calcularSalario(int pecas, float acres){
    
    float salario = 600;
    
    if(acres == 1) {
        return salario;
    } else {
        float comissao = pecas*acres;
        salario += comissao;

        return salario;
    }
}

void mostrarFinal (float salario[200], int id) {
    for (int c = 0; c < id; c++) {
        printf("Salario do funcionário %d é igual a: %.2f", c, salario[c]);
        printf("\n");
    }
}

int main(){

    int pecas[200];
    int id = -1; 
    float x[200];
    int resp = 0;
    float salario[200];

    do {
    id++;
    printf("Quantas peças foram produzidas? ");
    scanf("%d", &pecas[id]);

    getchar();

    x[id] = validarQuantidade(pecas[id]);

    salario[id] = calcularSalario(pecas[id], x[id]);

    printf("PRÓXIMO FUNCIONÁRIO [1] / ENCERRAR [0] ");
    scanf("%d", &resp);
} while (resp == 1);

    mostrarFinal(salario, id);

    return 0;
}