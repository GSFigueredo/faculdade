#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

typedef struct produto{
    int codigo; 
    char descricao[60];
    int quantidade;
    float valor;
    struct produto *prox;
} produto;

produto* iniciarLista(){
    return NULL;
}

produto* novoProduto() {
    produto *novoProd = (produto*)malloc(sizeof(produto));

    if(novoProd == NULL) {
        printf("Não há memória suficiente...");
        exit(EXIT_FAILURE);
    } 

    novoProd -> prox = NULL;

    return novoProd;
}

produto* cadastrarProduto(produto *aux) {
    produto *novoProd = novoProduto();

    printf("\nDigite o código do produto: ");
    scanf("%d", &novoProd->codigo);
    while (getchar() != '\n');

    printf("Digite a descrição do produto: ");
    fgets(novoProd->descricao, sizeof(novoProd->descricao), stdin);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &novoProd->quantidade);
    while (getchar() != '\n');

    printf("Digite o valor do produto: ");
    scanf("%f", &novoProd->valor);
    while (getchar() != '\n');

    novoProd->prox = NULL;


    if(aux == NULL) {
        aux = novoProd;
    } else {
        produto *atual = aux; 

        while(atual->prox != NULL) {
            atual = atual->prox;
        }

        atual->prox = novoProd;
    }

    return aux;
}

void mostrarProdutos(produto *aux) {
    produto *atual = aux; 

    if(atual == NULL) {
        printf("Não há ninguém na lista");
        return; 
    } else {
        while(atual != NULL) {
                printf("----------------------------------");
                printf("\n");
                printf("Código: %d", atual->codigo);
                printf("\n");
                printf("Descrição: %s", atual->descricao);
                printf("Quantidade: %d", atual->quantidade);
                printf("\n");
                printf("Valor: %.2f", atual->valor);
                printf("\n");
                printf("----------------------------------");

            atual = atual->prox;
        }
    }

}

produto* buscarProduto(produto *aux, int codigo) {
    produto *atual = aux;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            printf("----------------------------------\n");
            printf("Código: %d\n", atual->codigo);
            printf("Descrição: %s", atual->descricao);
            printf("Quantidade: %d\n", atual->quantidade);
            printf("Valor: %.2f\n", atual->valor);
            printf("----------------------------------\n");
            return atual;
        }
        atual = atual->prox;
    }

    printf("Produto não encontrado\n");
    return NULL;
}

produto* excluirProduto(produto *aux, int codigo) {
    produto *anterior = NULL;
    produto *atual = aux;

    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->codigo == codigo) {
        if (anterior != NULL) {
            // Excluir depois do primeiro
            anterior->prox = atual->prox;
        } else {
            // Excluir o primeiro elemento
            aux = atual->prox;
        }

        free(atual);
        printf("Produto excluído com sucesso\n");
    } else {
        printf("Produto não encontrado\n");
    }

    return aux; 
}


int main() {

    int opcao, codigo; 
    produto *aux =  iniciarLista(); 

    do{ 

        printf("\n1 - Cadastrar novo produto");
        printf("\n2 - Mostrar todos os produtos");
        printf("\n3 - Buscar produto");
        printf("\n4 - Excluir produto");
        printf("\n5 - Iniciar lista vazia");
        printf("\n0 - Sair");
        printf("\n");

        scanf("%d", &opcao); 

        switch(opcao) {
            case 1: 
                aux = cadastrarProduto(aux);
            break;

            case 2: 
                mostrarProdutos(aux);
            break;

            case 3: 
                printf("Digite o código que deseja buscar:");
                scanf("%d", &codigo);

                buscarProduto(aux, codigo);
            break;

            case 4: 
                printf("Digite o código que deseja excluir:");
                scanf("%d", &codigo);

                aux = excluirProduto(aux, codigo);
            break;
        }

    }while (opcao != 0);

    return 0;
}