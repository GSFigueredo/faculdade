#include <stdio.h>
#include <math.h>
#include <string.h>

//protótipos das funções//
void comoPagar(float gastos, int esc);
void mostrarDados(float gastos, int parcelas, float juros);
void parcelarValor(float gastos);
void pagamentoParcelas(float gastos);
//protótipos das funções//

void pagarValor(float gastos) {

    int esc;

    printf("Opções de pagamento:");
    printf("\n A vista com 10 porcento de desconto [1]");
    printf("\n Em duas vezes (preço da etiqueta) [2]");
    printf("\n De 3 até 10x com 3 porcento de juros ao mês sobre o valor de cada prestação (compras acima de R$100) [3]");

    printf("\nQual a forma de pagamento? [1/2/3] ");
    scanf("%d", &esc);

    comoPagar(gastos, esc);
}

void comoPagar(float gastos, int esc) {

    if(esc == 1) {
        float result = (gastos*10)/100;

        gastos = gastos - result;
        mostrarDados(gastos, 0, 0);
    } else if (esc == 2) {
        float gastosP = gastos/2;
        mostrarDados(gastos, 2, gastosP);
    } else if(esc == 3){
        parcelarValor(gastos);
    }
}

void parcelarValor(float gastos) {
    if( gastos < 100) {

        int esc;

        system("clear");

        printf("Opção de parcelamento somente para compras com valor superior a R$100");
        printf("\n");
        printf("Deseja escolher outra forma de pagamento? sim[1] / não[2]");
        scanf("%d", &esc);

        if(esc == 1) {
            pagarValor(gastos);
        } else {
            printf("Finalizando pedido");
        }
    } else {
        pagamentoParcelas(gastos);
    }
}

void pagamentoParcelas(float gastos){ 

    int prest;

    printf("Quer parcelar em quantas vezes? [3x até 10x] com 3%% de juros a.m: ");
    scanf("%d", &prest);

    float gastosM = gastos/prest;
    float juros = (gastosM*3)/100;
    gastos = (gastosM + juros)*prest;

    mostrarDados(gastos, prest, juros);
    
}

void mostrarDados(float gastos, int parcelas, float juros) {
    if(parcelas == 0) {
        printf("Foi pago um total de %.2f à vista", gastos);
    } else if(parcelas == 2) {
        printf("Foi pago um total de %.2f em duas parcelas de %.2f", gastos, juros);
    } else {
        printf("Foi pago um total de %.2f em %d parcelas, com R$%.2f de juros a.m", gastos, parcelas, juros);
    }
}

int main() {

    float gastos;

    printf("Qual foi o total de gastos em nossa loja? ");
    scanf("%f", &gastos);

    pagarValor(gastos);

    return 0;
}