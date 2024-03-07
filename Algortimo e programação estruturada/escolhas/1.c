#include <stdio.h>
#include <math.h>

int main(){
    int ddd;

    printf("--------------- Digite seu DDD ---------------");

    printf("\n");
    printf("Brasília [61]");
    printf("\n");
    printf("Salvador [71]");
    printf("\n");
    printf("São Paulo [11]");
    printf("\n");
    printf("Rio de Janeiro  [21]");
    printf("\n");
    printf("Juiz de Fora [32]");
    printf("\n");
    printf("Campinas [19]");
    printf("\n");
    printf("Vitória [27]");
    printf("\n");
    printf("Belo horizonte [31]");
    printf("\n");

    scanf("%d", &ddd);

    switch (ddd)
    {
    case 61:
        printf("Morador em Brasília...");
        break;
    case 71:
         printf("Morador em Salvador...");
        break;
    case 11:
         printf("Morador em São Paulo...");
        break;
    case 21:
         printf("Morador no Rio de Janeiro...");
        break;
    case 32:
         printf("Morador em Juiz de Fora...");
        break;
    case 19:
         printf("Morador em Campinas...");
        break;
    case 27:
         printf("Morador em Vitória...");
        break;
    case 31:
         printf("Morador em Belo horizonte...");
        break;
    default:
        printf("Morador em outra cidade do Brasil / Fora do Brasil...");
    }

    return 0;
}
