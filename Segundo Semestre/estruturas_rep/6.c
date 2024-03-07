#include <stdio.h>
#include <math.h>

int main(){
    int fruta;
    //float preco;
    float valor;
    int quan = 0;
    int comp = 0;

    do{

    quan++;

    printf("Escolha uma fruta:");

    printf("\n");

    printf("Abacaxi [R$5,00] [1]");
    printf("\n");

    printf("Maça [R$1,00] [2]");
    printf("\n");

    printf("Pera [R$4,00] [3]");
    printf("\n");

    scanf("%d", &fruta);

    switch (fruta)
    {
    case 1:
        valor = 5;
        break;
    case 2:
         valor = 1;
        break;
    case 3:
         valor = 4;
        break;
    }

    valor += valor;

    printf("Quer fazer mais um pedido? [1 - sim / 2 - não]");
    scanf("%d", &comp);

} while (comp == 1);

    printf("Total da compra: %.2f", valor);

    return 0;
}
