#include <stdio.h>
#include <math.h>

int main()
{

    float a, b, c;
    float delta;

    float x1, x2;

    printf("Digite o valor de a, b e c (respectivamente)");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0)
    {
        printf("A variável 'a' deve ser diferente de 0");
    }
    else
    {
        delta = (b * b) - 4 * a * c;

        if (delta < 0)
        {
            printf("Não existem raizes reais para essa equação...");
        }
        else if (delta == 0)
        {

            x1 = ( (-b + sqrt(delta))/ (2 * a) );

            printf("Existe apenas uma raíz: %.2f", x1);
        }
        else if (delta > 0)
        {
            x1 = ( (-b + sqrt(delta)) / (2 * a) );

            x2 = ( (-b - sqrt(delta)) / (2 * a) );

            printf("Existem duas raízes, x': %.2f e x'': %.2f", x1, x2);
        }
    }

    return 0;
}