#include <stdio.h>

int main() {
   int numeros[10], i, soma = 0;
   float media;

   for (i = 0; i < 10; i++) {
      printf("Digite um numero inteiro: ");
      scanf("%d", &numeros[i]);
      soma += numeros[i];
   }

   media = (float) soma / 10;

   printf("A media dos numeros e de: %.2f", media);

   return 0;
}