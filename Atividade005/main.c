#include <stdio.h>
#include <string.h>

void configurar_referencia(char nome_completo[]) {
    char* token;
    char* ultimo_nome;
    char iniciais[20] = "";

    // Obtém o último nome
    token = strtok(nome_completo, " ");
    while (token != NULL) {
        ultimo_nome = token;
        token = strtok(NULL, " ");
    }

    // Obtém as iniciais dos outros nomes
    token = strtok(nome_completo, " ");
    while (token != NULL) {
        if (token != ultimo_nome) {
            iniciais[strlen(iniciais)] = toupper(token[0]);
            iniciais[strlen(iniciais)] = '.';
            iniciais[strlen(iniciais)] = ' ';
        }
        token = strtok(NULL, " ");
    }
    iniciais[strlen(iniciais) - 1] = '\0';

    // Imprime a referência formatada
    printf("%s ", strupr(ultimo_nome));
    printf("%s\n", iniciais);
}

int main() {
    char nome_completo[50];

    printf("Digite um nome completo: ");
    fgets(nome_completo, 50, stdin);

    configurar_referencia(nome_completo);

    return 0;
}