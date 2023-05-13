#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDANTES 20
#define MAX_DISCIPLINAS 3
#define MAX_NOTAS 4

struct Disciplina
{
    char nome[50];
    int carga_horaria;
    float notas[MAX_NOTAS];
};

struct Estudante
{
    char nome[50];
    int matricula;
    int idade;
    struct Disciplina disciplinas[MAX_DISCIPLINAS];
};

int main()
{
    struct Estudante estudantes[MAX_ESTUDANTES];
    int i, j, k;
    int num_estudantes = 0;

    while (num_estudantes < MAX_ESTUDANTES)
    {
        printf("Digite o nome do estudante (ou 'fim' para encerrar): ");
        scanf("%s", estudantes[num_estudantes].nome);

        if (strcmp(estudantes[num_estudantes].nome, "fim") == 0)
        {
            break;
        }

        printf("Digite a matricula do estudante: ");
        scanf("%d", &estudantes[num_estudantes].matricula);

        printf("Digite a idade do estudante: ");
        scanf("%d", &estudantes[num_estudantes].idade);

        for (i = 0; i < MAX_DISCIPLINAS; i++)
        {
            printf("Digite o nome da disciplina %d: ", i + 1);
            scanf("%s", estudantes[num_estudantes].disciplinas[i].nome);

            printf("Digite a carga horaria da disciplina %d: ", i + 1);
            scanf("%d", &estudantes[num_estudantes].disciplinas[i].carga_horaria);

            for (j = 0; j < MAX_NOTAS; j++)
            {
                printf("Digite a nota %d da disciplina %d: ", j + 1, i + 1);
                scanf("%f", &estudantes[num_estudantes].disciplinas[i].notas[j]);
            }
        }

        num_estudantes++;
    }

    printf("\n\nDados dos estudantes cadastrados:\n");
    for (i = 0; i < num_estudantes; i++)
    {
        printf("\nEstudante %d\n", i + 1);
        printf("Nome: %s\n", estudantes[i].nome);
        printf("Matricula: %d\n", estudantes[i].matricula);
        printf("Idade: %d\n", estudantes[i].idade);

        float media_geral = 0.0;
        int total_notas = 0;

        for (j = 0; j < MAX_DISCIPLINAS; j++)
        {
            printf("Disciplina %d\n", j + 1);
            printf("Nome: %s\n", estudantes[i].disciplinas[j].nome);
            printf("Carga horaria: %d\n", estudantes[i].disciplinas[j].carga_horaria);

            float media_disciplina = 0.0;
            for (k = 0; k < MAX_NOTAS; k++)
            {
                media_disciplina += estudantes[i].disciplinas[j].notas[k];
            }
            media_disciplina /= MAX_NOTAS;

            printf("Media da disciplina: %.2f\n", media_disciplina);

            media_geral += media_disciplina;
            total_notas += MAX_NOTAS;
        }

        media_geral /= total_notas;

        printf("Media geral: %.2f\n", media_geral);
    }

    float maior_media = 0.0;
    printf("\n\nEstudante(s) com a maior media:\n");
    for (i = 0; i < num_estudantes; i++)
    {
        float media_estudante = 0.0;
        int total_notas = 0;

        for (j = 0; j < MAX_DISCIPLINAS; j++)
        {
            for (k = 0; k < MAX_NOTAS; k++)
            {
                media_estudante += estudantes[i].disciplinas[j].notas[k];
            }
            total_notas += MAX_NOTAS;
        }

        media_estudante /= total_notas;

        if (media_estudante > maior_media)
        {
            maior_media = media_estudante;
            printf("%s\n", estudantes[i].nome);
        }
    }

    return 0;
}