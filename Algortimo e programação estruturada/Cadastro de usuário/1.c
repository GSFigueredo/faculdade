#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Usuario {
    int id;
    char nome[100];
    char email[100];
    char sexo[15];
    char endereco[100];
    double altura;
    int vacina;
};

int gerarId() {
    return rand() % 10000 + 1;
}

void adicionarUsuario(struct Usuario usuarios[], int *totalUsuarios) {
    if (*totalUsuarios < 1000) {
        struct Usuario novoUsuario;
        novoUsuario.id = gerarId();

        printf("Digite o nome completo: ");
        scanf(" %[^\n]s", novoUsuario.nome);

        printf("Digite o email: ");
        scanf(" %s", novoUsuario.email);

        if (strchr(novoUsuario.email, '@') == NULL) {
            printf("Email inválido. O email deve conter o caractere '@'.\n");
            return;
        }

        printf("Digite o sexo (Feminino, Masculino ou Indiferente): ");
        scanf(" %s", novoUsuario.sexo);

        if (strcmp(novoUsuario.sexo, "Feminino") != 0 &&
            strcmp(novoUsuario.sexo, "Masculino") != 0 &&
            strcmp(novoUsuario.sexo, "Indiferente") != 0) {
            printf("Sexo inválido. Escolha entre Feminino, Masculino ou Indiferente.\n");
            return;
        }

        printf("Digite o endereço: ");
        scanf(" %[^\n]s", novoUsuario.endereco);

        printf("Digite a altura (entre 1 e 2 metros): ");
        scanf("%lf", &novoUsuario.altura);

        if (novoUsuario.altura < 1.0 || novoUsuario.altura > 2.0) {
            printf("Altura inválida. A altura deve estar entre 1 e 2 metros.\n");
            return;
        }

        printf("O usuário foi vacinado? (1 para sim, 0 para não): ");
        scanf("%d", &novoUsuario.vacina);

        usuarios[*totalUsuarios] = novoUsuario;
        (*totalUsuarios)++;

        printf("Usuário adicionado com sucesso!\n");
    } else {
        printf("Limite de usuários atingido. Não é possível adicionar mais usuários.\n");
    }
}

void editarUsuario(struct Usuario usuarios[], int totalUsuarios) {
    int idEditar;

    printf("Digite o ID do usuário a ser editado: ");
    scanf("%d", &idEditar);

    for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].id == idEditar) {
            printf("Digite o novo nome completo: ");
            scanf(" %[^\n]s", usuarios[i].nome);

            printf("Digite o novo email: ");
            scanf(" %s", usuarios[i].email);

            if (strchr(usuarios[i].email, '@') == NULL) {
                printf("Email inválido. O email deve conter o caractere '@'.\n");
                return;
            }

            printf("Digite o novo sexo (Feminino, Masculino ou Indiferente): ");
            scanf(" %s", usuarios[i].sexo);

            if (strcmp(usuarios[i].sexo, "Feminino") != 0 &&
                strcmp(usuarios[i].sexo, "Masculino") != 0 &&
                strcmp(usuarios[i].sexo, "Indiferente") != 0) {
                printf("Sexo inválido. Escolha entre Feminino, Masculino ou Indiferente.\n");
                return;
            }

            printf("Digite o novo endereço: ");
            scanf(" %[^\n]s", usuarios[i].endereco);

            printf("Digite a nova altura (entre 1 e 2 metros): ");
            scanf("%lf", &usuarios[i].altura);

            if (usuarios[i].altura < 1.0 || usuarios[i].altura > 2.0) {
                printf("Altura inválida. A altura deve estar entre 1 e 2 metros.\n");
                return;
            }

            printf("O usuário foi vacinado? (1 para sim, 0 para não): ");
            scanf("%d", &usuarios[i].vacina);

            printf("Usuário editado com sucesso!\n");
            return;
        }
    }

    printf("Usuário não encontrado com o ID fornecido.\n");
}

void excluirUsuario(struct Usuario usuarios[], int *totalUsuarios) {
    int idExcluir;

    printf("Digite o ID do usuário a ser excluído: ");
    scanf("%d", &idExcluir);

    for (int i = 0; i < *totalUsuarios; i++) {
        if (usuarios[i].id == idExcluir) {
            for (int j = i; j < *totalUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }

            (*totalUsuarios)--;
            printf("Usuário excluído com sucesso!\n");
            return;
        }
    }

    printf("Usuário não encontrado com o ID fornecido.\n");
}

void buscarUsuarioPorEmail(struct Usuario usuarios[], int totalUsuarios) {
    char emailBuscar[100];

    printf("Digite o email do usuário a ser buscado: ");
    scanf(" %s", emailBuscar);

    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].email, emailBuscar) == 0) {
            printf("Usuário encontrado:\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacinado: %s\n", usuarios[i].vacina ? "Sim" : "Não");
            return;
        }
    }

    printf("Usuário não encontrado com o email fornecido.\n");
}

int main() {
    struct Usuario usuarios[1000];
    int totalUsuarios = 0;
    char opcao;

    srand(time(NULL));

    do {
        printf("\nEscolha uma opção:\n");
        printf("1 - Adicionar Usuário\n");
        printf("2 - Editar Usuário\n");
        printf("3 - Excluir Usuário\n");
        printf("4 - Buscar Usuário por Email\n");
        printf("5 - Imprimir Todos os Usuários\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionarUsuario(usuarios, &totalUsuarios);
                break;
            case '2':
                editarUsuario(usuarios, totalUsuarios);
                break;
            case '3':
                excluirUsuario(usuarios, &totalUsuarios);
                break;
            case '4':
                buscarUsuarioPorEmail(usuarios, totalUsuarios);
                break;
            case '5':
                for (int i = 0; i < totalUsuarios; i++) {
                    printf("\nUsuário %d:\n", i + 1);
                    printf("ID: %d\n", usuarios[i].id);
                    printf("Nome: %s\n", usuarios[i].nome);
                    printf("Email: %s\n", usuarios[i].email);
                    printf("Sexo: %s\n", usuarios[i].sexo);
                    printf("Endereço: %s\n", usuarios[i].endereco);
                    printf("Altura: %.2lf\n", usuarios[i].altura);
                    printf("Vacinado: %s\n", usuarios[i].vacina ? "Sim" : "Não");
                }
                break;
            case '0':
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != '0');

    return 0;
}
