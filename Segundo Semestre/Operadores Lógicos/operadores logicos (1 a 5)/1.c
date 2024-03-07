#include <stdio.h>
#include <math.h>

int main()
{

    float n1;

    printf("Digite um valor inteiro:");
    scanf("%f", &n1);

    getchar();

    if (n1 < 0)
    {
        n1 *= n1;

        printf("%f", n1);
    }
    else if (n1 >= 0)
    {
        n1 = sqrt(n1);

        printf("%f", n1);
    }

    return 0;
}