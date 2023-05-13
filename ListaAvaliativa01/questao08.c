#include <stdio.h>

int main() {
    int numero, maior = -1000000, menor = 1000000;

    printf("Digite um numero inteiro (digite um negativo para encerrar): ");
    scanf("%d", &numero);

    while (numero >= 0) {
        if (numero > maior) {
            maior = numero;
        }

        if (numero < menor) {
            menor = numero;
        }

        printf("Digite um numero inteiro (negativo para encerrar): ");
        scanf("%d", &numero);
    }

    printf("O maior numero digitado foi: %d\n", maior);
    printf("O menor numero digitado foi: %d\n", menor);

    return 0;
}