#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {


    float gastos;
    int esc;

    printf("Qual foi o total de gastos em nossa loja?");
    scanf("%f", &gastos);

    printf("Opções de pagamento:");
    printf("\n A vista com 10 porcento de desconto [1]");
    printf("\n Em duas vezes (preço da etiqueta) [2]");
    printf("\n De 3 até 10x com 3 porcento de juros ao mês sobre o valor de cada prestação (compras acima de R$100) [3]");

    printf("Qual a forma de pagamento? [1/2/3]");
    scanf("%d", &esc);

    if(esc == 1) {
        float result = (gastos*10)/100;

        gastos = gastos - result;
    } else if (esc = 2) {
        gastos = gastos/2;
    } else {
        if(gastos < 100) {
            printf("Só é possível parcelar acima de R$100");
        } else {
            
        }
    }

    return 0;
}