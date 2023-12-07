#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Veiculo {
    char proprietario[50];
    char combustivel[20];
    char modelo[50];
    char cor[20];
    char chassi[20];
    int ano;
    char placa[10];
    struct Veiculo* proximo;
} Veiculo;

Veiculo* inicializarLista() {
    return NULL;
}

Veiculo* adicionarVeiculo(Veiculo* lista) {
    Veiculo* novoVeiculo = (Veiculo*)malloc(sizeof(Veiculo));

    printf("Proprietario: ");
    scanf("%s", novoVeiculo->proprietario);
    printf("Combustivel (alcool/diesel/gasolina): ");
    scanf("%s", novoVeiculo->combustivel);
    printf("Modelo: ");
    scanf("%s", novoVeiculo->modelo);
    printf("Cor: ");
    scanf("%s", novoVeiculo->cor);
    printf("Chassi: ");
    scanf("%s", novoVeiculo->chassi);
    printf("Ano: ");
    scanf("%d", &novoVeiculo->ano);
    printf("Placa: ");
    scanf("%s", novoVeiculo->placa);

    novoVeiculo->proximo = lista;

    return novoVeiculo;
}

void listarProprietariosDiesel2010(Veiculo* lista) {
    printf("\nProprietarios de carros do ano de 2010 ou posterior movidos a diesel:\n");
    while (lista != NULL) {
        if (lista->ano >= 2010 && strcmp(lista->combustivel, "diesel") == 0) {
            printf("%s\n", lista->proprietario);
        }
        lista = lista->proximo;
    }
}

void listarPlacasJ(Veiculo* lista) {
    printf("\nPlacas que comecam com J e terminam com 0, 2, 4 ou 7, com respectivos proprietarios:\n");
    while (lista != NULL) {
        if (lista->placa[0] == 'J' && (lista->placa[6] == '0' || lista->placa[6] == '2' || lista->placa[6] == '4' || lista->placa[6] == '7')) {
            printf("Placa: %s - Proprietario: %s\n", lista->placa, lista->proprietario);
        }
        lista = lista->proximo;
    }
}

void listarModeloCor(Veiculo* lista) {
    printf("\nModelo e cor de veiculos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numericos fornece um numero par:\n");
    while (lista != NULL) {
        if ((lista->placa[1] == 'A' || lista->placa[1] == 'E' || lista->placa[1] == 'I' || lista->placa[1] == 'O' || lista->placa[1] == 'U') &&
            ((lista->placa[2] - '0') + (lista->placa[3] - '0') + (lista->placa[4] - '0') + (lista->placa[5] - '0')) % 2 == 0) {
            printf("Modelo: %s - Cor: %s\n", lista->modelo, lista->cor);
        }
        lista = lista->proximo;
    }
}

Veiculo* trocarProprietario(Veiculo* lista, char* novoProprietario, char* chassi) {
    Veiculo* atual = lista;

    while (atual != NULL) {
        if (strcmp(atual->chassi, chassi) == 0) {
            int temZero = 0;
            for (int i = 0; i < strlen(atual->placa); i++) {
                if (atual->placa[i] == '0') {
                    temZero = 1;
                    break;
                }
            }

            if (!temZero) {
                strcpy(atual->proprietario, novoProprietario);
                printf("\nProprietario trocado com sucesso.\n");
                return lista;
            } else {
                printf("\nO carro possui um digito zero na placa. Troca de proprietario nao permitida.\n");
                return lista;
            }
        }
        atual = atual->proximo;
    }

    printf("\nVeiculo com chassi %s nao encontrado.\n", chassi);
    return lista;
}

void liberarLista(Veiculo* lista) {
    Veiculo* atual = lista;
    while (atual != NULL) {
        Veiculo* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    Veiculo* lista = inicializarLista();
    int opcao;
    char novoProprietario[50], chassi[20];

    printf("=============================================\n");
    printf("   Sistema de Controle de Veiculos\n");
    printf("=============================================\n");

    do {
        printf("\nMenu:\n");
        printf("1 - Adicionar Veiculo\n");
        printf("2 - Listar Proprietarios Diesel 2010\n");
        printf("3 - Listar Placas J\n");
        printf("4 - Listar Modelo e Cor\n");
        printf("5 - Trocar Proprietario\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                lista = adicionarVeiculo(lista);
                break;
            case 2:
                listarProprietariosDiesel2010(lista);
                break;
            case 3:
                listarPlacasJ(lista);
                break;
            case 4:
                listarModeloCor(lista);
                break;
            case 5:
                printf("\nDigite o novo proprietario: ");
                scanf("%s", novoProprietario);
                printf("Digite o chassi do veiculo: ");
                scanf("%s", chassi);
                lista = trocarProprietario(lista, novoProprietario, chassi);
                break;
            case 0:
                liberarLista(lista);
                printf("\nPrograma encerrado. Obrigado por usar o Sistema de Controle de Veiculos!\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}