#include <stdio.h>

int main()
{

    FILE *arq = fopen("teste.txt", "r");
    int caractere;

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    printf("Conteúdo do arquivo:\n");
    while (1) {
        caractere = fgetc(arq);

        if(feof(arq)) {
            break;
        }

        printf("%c", caractere);
    }

    fclose(arq);

    return 0;
}