#include <stdio.h>

int main() {
    int vetor[100];
    int num = 1;

    for (int i = 0; i < 100; ) {
        if (num % 7 != 0 && num % 10 != 7) {
            vetor[i] = num;
            i++;
        }
        num++;
    }

    for (int i = 0; i < 100; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}
