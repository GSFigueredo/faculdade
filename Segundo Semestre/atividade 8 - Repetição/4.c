#include <stdio.h>
#include <math.h>

int main()
{

    int n1;

    printf("Digite um valor:");
    scanf("%d", &n1);

    for (int c = 1; c <= n1; c++){
        if (n1 % c == 0){
            printf("%d", c);
            printf(" ");
        }
    }

    return 0;
}