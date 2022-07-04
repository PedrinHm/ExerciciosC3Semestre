#include <stdio.h>
#include <stdlib.h>
void main()
{

  char nome[10];
  int nProvas;
  float media;
  int *tamanho;

  printf("\nDigite o nome do aluno.\nNome: ");
  scanf("%s", &nome);

  printf("\nQuantas provas %s fez?", nome);
  scanf("%d", &nProvas);

  tamanho = malloc(nProvas * sizeof(int));

  for (int i = 0; i < nProvas; i++)
  {
    printf("Digite a nota da prova de :\n");
    scanf("%d", &tamanho[i]);
  }

  for (int j = 0; j < nProvas; j++)
  {
    media = media + tamanho[j];
  }
  media = media / nProvas;

  printf("\nMédia : %.2f", media);
}
