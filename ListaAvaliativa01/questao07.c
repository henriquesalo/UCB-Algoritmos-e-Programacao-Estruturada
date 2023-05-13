#include <stdio.h>

int main() {
    int n, atual = 0, anterior1 = 1, anterior2 = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("O termo de ordem zero da sequencia de Fibonacci e: %d\n", atual);
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        atual = anterior1 + anterior2;
        anterior2 = anterior1;
        anterior1 = atual;
    }

    printf("O termo de ordem %d da sequencia de Fibonacci e: %d\n", n, atual);

    return 0;
}