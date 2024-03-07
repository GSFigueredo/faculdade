#include <stdio.h>
#include <time.h>

void calcularIdade(int diaNasc, int mesNasc, int anoNasc) {

    time_t t = time(NULL);
    struct tm hoje = *localtime(&t);

    int idadeAnos = hoje.tm_year + 1900 - anoNasc;
    int idadeMeses = hoje.tm_mon + 1 - mesNasc;
    int idadeDias = hoje.tm_mday - diaNasc;

    if (idadeDias < 0) {
        idadeMeses--;
        idadeDias += 30;
    }

    if (idadeMeses < 0) {
        idadeAnos--;
        idadeMeses += 12;
    }

    printf("Idade: %d anos, %d meses, %d dias\n", idadeAnos, idadeMeses, idadeDias);
}

int main() {

    int diaNascimento, mesNascimento, anoNascimento;

    printf("Digite a data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &diaNascimento, &mesNascimento, &anoNascimento);

    calcularIdade(diaNascimento, mesNascimento, anoNascimento);

    return 0;
}