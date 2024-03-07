#include <stdio.h>
#include <math.h>

int main()
{

    float salario;
    float reajuste, bonus;
    int serv;
    int cont = 0;

    printf("Qual o salário do funcionário?");
    scanf("%f", &salario);

    printf("Qual o tempo de serviço do funcionário?");
    scanf("%d", &serv);

    serv *= 12;

    if (salario <= 500 && serv < 12)
    {
        reajuste = (salario * 25) / 100;
        bonus = 0;
        salario = salario + bonus + reajuste;

        cont = 1;
    }

    if ((salario > 500 && salario <= 1000) && (serv >= 12 && serv <= 36))
    {
        reajuste = (salario * 20) / 100;
        bonus = 100;
        salario = salario + reajuste + bonus;

        cont = 1;
    }

    if ((salario > 1000 && salario <= 1500) && (serv >= 48 && serv <= 72))
    {
        reajuste = (salario * 15) / 100;
        bonus = 200;
        salario = salario + reajuste + bonus;

        cont = 1;
    }

    if ((salario > 1500 && salario <= 2000) && (serv >= 84 && serv <= 120))
    {
        reajuste = (salario * 10) / 100;
        bonus = 300;
        salario = salario + reajuste + bonus;

        cont = 1;
    }

    if ((salario > 2000) && (serv > 120))
    {
        reajuste = 0;
        bonus = 500;
        salario = salario + reajuste + bonus;

        cont = 1;
    }

    system("clear");

    if (cont == 0)
    {
        printf("Funcionário não está apto ao aumento salarial");
    } else if(cont == 1){
        printf("Reajuste de: %.2f", reajuste);
        printf("\n");
        printf("Bonus de: %.2f", bonus);
        printf("\n");
        printf("Salário final: %.2f", salario);
    }
}