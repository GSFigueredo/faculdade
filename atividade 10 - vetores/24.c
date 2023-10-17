#include <stdio.h>

int main() {
    int numero_aluno;
    float altura, altura_maxima = 0, altura_minima = 3.0;
    int aluno_maximo, aluno_minimo;
    
    for (int i = 1; i <= 10; i++) {
        printf("Informe o número do aluno %d: ", i);
        scanf("%d", &numero_aluno);
        printf("Informe a altura do aluno %d (em metros): ", i);
        scanf("%f", &altura);
        
        if (altura > altura_maxima) {
            altura_maxima = altura;
            aluno_maximo = numero_aluno;
        }
        
        if (altura < altura_minima) {
            altura_minima = altura;
            aluno_minimo = numero_aluno;
        }
    }
    
    printf("Aluno mais alto:\n");
    printf("Número do aluno: %d\n", aluno_maximo);
    printf("Altura: %.2f metros\n", altura_maxima);
    
    printf("Aluno mais baixo:\n");
    printf("Número do aluno: %d\n", aluno_minimo);
    printf("Altura: %.2f metros\n", altura_minima);
    
    return 0;
}
