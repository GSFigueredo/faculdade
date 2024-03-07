#include <stdio.h>

int main()
{

    int idade, serv;

    printf("Qual a idade do colaborador?");
    scanf("%d", &idade);

    printf("Qual o tempo de serviço do colaborador?");
    scanf("%d", &serv);

    if((idade >= 65 || serv>=30) || (idade>= 60 && serv>=25)) {
        printf("Aposentadoria permitida...");
    } else {
        printf("Aposentadoria não permitida...");
    }

}