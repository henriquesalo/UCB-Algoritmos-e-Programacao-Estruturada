#include <stdio.h>

int main() {
    float media, menor_media = 10;
    int reprovados = 0, aprovados = 0, cont = 1;

    printf("Henrique Rodrigues Salomão\n");
    printf("Quantidade de  alunos aprovados e reprovados");

    while (cont <= 25) {
        printf("Digite a media do aluno %d: ", cont);
        scanf("%f", &media);

        if (media < 0 || media > 10) {
            printf("Media invalida. Insira um valor entre 0 e 10.\n");
            continue;
        }

        if (media < menor_media) {
            menor_media = media;
        }

        if (media >= 6.9) {
            aprovados++;
        } else {
            reprovados++;
        }

        cont++;
    }

    printf("\nQuantidade de alunos aprovados: %d\n", aprovados);
    printf("Quantidade de alunos reprovados: %d\n", reprovados);
    printf("Menor media informada: %.2f\n", menor_media);

    return 0;
}