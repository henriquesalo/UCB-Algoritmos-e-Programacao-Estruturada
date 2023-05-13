#include <stdio.h>

int main() {
    int opcao;
    float valor, total = 0.0;
    int quantidade;
    char continuar;

    do {
    	printf("|==================|\n");
    	printf("|MERCADO DO SALOMAO|\n");
    	printf("|==================|\n\n");
        printf("Escolha uma fruta:\n");
        printf("1 => ABACAXI – 5,00 a unidade\n");
        printf("2 => MACA – 1,00 a unidade\n");
        printf("3 => PERA – 4,00 a unidade\n\n");

        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                valor = 5.0;
                printf("ABACAXI selecionado\n");
                break;
            case 2:
                valor = 1.0;
                printf("MACA selecionada\n");
                break;
            case 3:
                valor = 4.0;
                printf("PERA selecionada\n");
                break;
            default:
                printf("Opcao inválida!\n");
                continue;
        }

        printf("Digite a quantidade desejada: ");
        scanf("%d", &quantidade);

        total += valor * quantidade;

        printf("Deseja escolher mais frutas? (s/n) ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("O valor total da compra e R$ %.2f\n", total);

    return 0;
}