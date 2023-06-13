#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50
#define UF_SIZE 3

typedef struct {
    char marca[50];
    char site[100];
    char telefone[20];
    char uf[UF_SIZE];
} Fabricante;

typedef struct {
    char descricao[100];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    Fabricante fabricante;
} Produto;

Fabricante fabricantes[MAX_FABRICANTES];
int numFabricantes = 0;

Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;

#include <stdlib.h>

void cadastrarFabricante();
void cadastrarProduto();
void listarTodasMarcas();
void listarTodosProdutos();
void listarProdutosEstado();
void listarProdutosMarca();
void listarEstadoProdutoMaisCaro();
void listarFabricanteProdutoMaisBarato();
void listarProdutosOrdemCrescenteValor();
void listarProdutosOrdemCrescenteLucro();
void listarProdutosOrdemCrescentePercentualLucro();
void limpartela();


int main() {
    int opcao;

    do {
        printf("\n-Xx-----Bem Vindo Ao Menu-----xX-");
        printf("\n\nDigite..\n\n");
        printf("[1] Para Cadastrar Fabricante\n");
        printf("[2] Para Cadastrar Produto\n");
        printf("[3] Para Listar todas as marcas\n");
        printf("[4] Para Listar todos os produtos\n");
        printf("[5] Para Listar os produtos de um determinado estado\n");
        printf("[6] Para Listar os produtos de uma determinada marca\n");
        printf("[7] Para Apresentar o(s) estado(s) onde esta registrado o produto mais caro\n");
        printf("[8] Para Apresentar o(s) fabricante(s) onde esta registrado o produto mais barato\n");
        printf("[9] Para Listar todos os produtos em ordem crescente de valor\n");
        printf("[10] Para Listar todos os produtos em ordem crescente de maior lucro\n");
        printf("[11] Para Listar todos os produtos em ordem crescente de maior percentual de lucro\n");
        printf("[12] Para sair do programa\n");

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarFabricante();
                break;
            case 2:
                cadastrarProduto();
                break;
            case 3:
                listarTodasMarcas();
                break;
            case 4:
                listarTodosProdutos();
                break;
            case 5:
                listarProdutosEstado();
                break;
            case 6:
                listarProdutosMarca();
                break;
            case 7:
                listarEstadoProdutoMaisCaro();
                break;
            case 8:
                listarFabricanteProdutoMaisBarato();
                break;
            case 9:
                listarProdutosOrdemCrescenteValor();
                break;
            case 10:
                listarProdutosOrdemCrescenteLucro();
                break;
            case 11:
                listarProdutosOrdemCrescentePercentualLucro();
                break;
            case 12:
                printf("\nPrograma encerrado.\n");
                break;
            default:
                printf("Opcao invalida. Digite novamente.\n");
        }
    } while (opcao != 12);

    return 0;
}

void limpartela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void cadastrarFabricante() {
    if (numFabricantes == MAX_FABRICANTES) {
        printf("Limite maximo de fabricantes atingido.\n");
        return;
    }
    
    limpartela();
    printf("\n=== Cadastro de Fabricante ===\n");

    printf("Marca: ");
    fgets(fabricantes[numFabricantes].marca, sizeof(fabricantes[numFabricantes].marca), stdin);
    fabricantes[numFabricantes].marca[strcspn(fabricantes[numFabricantes].marca, "\n")] = '\0';

    printf("Site: ");
    fgets(fabricantes[numFabricantes].site, sizeof(fabricantes[numFabricantes].site), stdin);
    fabricantes[numFabricantes].site[strcspn(fabricantes[numFabricantes].site, "\n")] = '\0';

    printf("Telefone: ");
    fgets(fabricantes[numFabricantes].telefone, sizeof(fabricantes[numFabricantes].telefone), stdin);
    fabricantes[numFabricantes].telefone[strcspn(fabricantes[numFabricantes].telefone, "\n")] = '\0';

    printf("UF: ");
    fgets(fabricantes[numFabricantes].uf, sizeof(fabricantes[numFabricantes].uf), stdin);
    fabricantes[numFabricantes].uf[strcspn(fabricantes[numFabricantes].uf, "\n")] = '\0';

    numFabricantes++;
    limpartela();
    printf("Fabricante cadastrado com sucesso.\n");

}

void cadastrarProduto() {
    if (numProdutos == MAX_PRODUTOS) {
        printf("Limite maximo de produtos atingido.\n");
        return;
    }
    printf("=== Cadastro de Produto ===\n");

    printf("Descricao: ");
    fgets(produtos[numProdutos].descricao, sizeof(produtos[numProdutos].descricao), stdin);
    produtos[numProdutos].descricao[strcspn(produtos[numProdutos].descricao, "\n")] = '\0';

    printf("Peso: ");
    scanf("%f", &produtos[numProdutos].peso);
    getchar();

    printf("Valor de Compra: ");
    scanf("%f", &produtos[numProdutos].valorCompra);
    getchar();

    printf("Valor de Venda: ");
    scanf("%f", &produtos[numProdutos].valorVenda);
    getchar();

    produtos[numProdutos].valorLucro = produtos[numProdutos].valorVenda - produtos[numProdutos].valorCompra;
    produtos[numProdutos].percentualLucro = (produtos[numProdutos].valorLucro / produtos[numProdutos].valorCompra) * 100;

    printf("Marca do Fabricante: ");
    fgets(produtos[numProdutos].fabricante.marca, sizeof(produtos[numProdutos].fabricante.marca), stdin);
    produtos[numProdutos].fabricante.marca[strcspn(produtos[numProdutos].fabricante.marca, "\n")] = '\0';

    printf("UF do Fabricante: ");
    fgets(produtos[numProdutos].fabricante.uf, sizeof(produtos[numProdutos].fabricante.uf), stdin);
    produtos[numProdutos].fabricante.uf[strcspn(produtos[numProdutos].fabricante.uf, "\n")] = '\0';

    numProdutos++;
    printf("Produto cadastrado com sucesso.\n");
}

void listarTodasMarcas() {
	limpartela();
    printf("=== Lista de Marcas ===\n");
    for (int i = 0; i < numFabricantes; i++) {
        printf("%s\n", fabricantes[i].marca);
    }
}

void listarTodosProdutos() {
	limpartela();
    printf("=== Lista de Produtos ===\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: R$ %.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: R$ %.2f\n", produtos[i].valorVenda);
        printf("Valor do Lucro: R$ %.2f\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Marca do Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("UF do Fabricante: %s\n\n", produtos[i].fabricante.uf);
    }
}

void listarProdutosEstado() {
	limpartela();
    char estado[UF_SIZE];

    printf("Digite o estado: ");
    fgets(estado, sizeof(estado), stdin);
    estado[strcspn(estado, "\n")] = '\0';

    printf("=== Lista de Produtos do Estado %s ===\n", estado);
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante.uf, estado) == 0) {
            printf("Descricao: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de Compra: R$ %.2f\n", produtos[i].valorCompra);
            printf("Valor de Venda: R$ %.2f\n", produtos[i].valorVenda);
            printf("Valor do Lucro: R$ %.2f\n", produtos[i].valorLucro);
            printf("Percentual do Lucro: %.2f%%\n", produtos[i].percentualLucro);
            printf("Marca do Fabricante: %s\n", produtos[i].fabricante.marca);
            printf("UF do Fabricante: %s\n\n", produtos[i].fabricante.uf);
        }
    }
}

void listarProdutosMarca() {
	limpartela();;
    char marca[50];

    printf("Digite a marca: ");
    fgets(marca, sizeof(marca), stdin);
    marca[strcspn(marca, "\n")] = '\0';

    printf("=== Lista de Produtos da Marca %s ===\n", marca);
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante.marca, marca) == 0) {
            printf("Descricao: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de Compra: R$ %.2f\n", produtos[i].valorCompra);
            printf("Valor de Venda: R$ %.2f\n", produtos[i].valorVenda);
            printf("Valor do Lucro: R$ %.2f\n", produtos[i].valorLucro);
            printf("Percentual do Lucro: %.2f%%\n", produtos[i].percentualLucro);
            printf("Marca do Fabricante: %s\n", produtos[i].fabricante.marca);
            printf("UF do Fabricante: %s\n\n", produtos[i].fabricante.uf);
        }
    }
}

void listarEstadoProdutoMaisCaro() {
	limpartela();
    float maiorValor = 0;
    char estadoMaisCaro[UF_SIZE];

    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda > maiorValor) {
            maiorValor = produtos[i].valorVenda;
            strcpy(estadoMaisCaro, produtos[i].fabricante.uf);
        }
    }

    printf("=== Estado(s) onde esta registrado o produto mais caro ===\n");
    printf("%s\n", estadoMaisCaro);
}

void listarFabricanteProdutoMaisBarato() {
	limpartela();
    float menorValor = produtos[0].valorVenda;

    for (int i = 1; i < numProdutos; i++) {
        if (produtos[i].valorVenda < menorValor) {
            menorValor = produtos[i].valorVenda;
        }
    }

    printf("=== Fabricante(s) onde esta registrado o produto mais barato ===\n");
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda == menorValor) {
            printf("Marca: %s\n", produtos[i].fabricante.marca);
        }
    }
}

void listarProdutosOrdemCrescenteValor() {
	limpartela();
    Produto temp;

    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorVenda > produtos[j + 1].valorVenda) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("=== Lista de Produtos em Ordem Crescente de Valor ===\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: R$ %.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: R$ %.2f\n", produtos[i].valorVenda);
        printf("Valor do Lucro: R$ %.2f\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Marca do Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("UF do Fabricante: %s\n\n", produtos[i].fabricante.uf);
    }
}

void listarProdutosOrdemCrescenteLucro() {
	limpartela();
    Produto temp;

    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorLucro > produtos[j + 1].valorLucro) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("=== Lista de Produtos em Ordem Crescente de Maior Lucro ===\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: R$ %.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: R$ %.2f\n", produtos[i].valorVenda);
        printf("Valor do Lucro: R$ %.2f\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Marca do Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("UF do Fabricante: %s\n\n", produtos[i].fabricante.uf);
    }
}

void listarProdutosOrdemCrescentePercentualLucro() {
	limpartela();
    Produto temp;

    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].percentualLucro > produtos[j + 1].percentualLucro) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("=== Lista de Produtos em Ordem Crescente de Maior Percentual de Lucro ===\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de Compra: R$ %.2f\n", produtos[i].valorCompra);
        printf("Valor de Venda: R$ %.2f\n", produtos[i].valorVenda);
        printf("Valor do Lucro: R$ %.2f\n", produtos[i].valorLucro);
        printf("Percentual do Lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Marca do Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("UF do Fabricante: %s\n\n", produtos[i].fabricante.uf);
    }
}
