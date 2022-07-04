#include <stdio.h>
#include <stdlib.h>

void main()
{

  int linhas, colunas, i, j;
  double **tamanhoA, **tamanhoB, **tamanhoC;
  double soma;

  printf("Digite as medidas das matrizes: \nnúmero de linhas: ");
  scanf("%d", &linhas);
  printf("\nNumero de colunas: ");
  scanf("%d", &colunas);
  tamanhoA = malloc(linhas * sizeof(double *));
  tamanhoB = malloc(linhas * sizeof(double *));

  for (int i = 0; i < linhas; i++)
  {
    tamanhoA[i] = malloc(colunas * sizeof(double));
    tamanhoB[i] = malloc(colunas * sizeof(double));
  }

  printf("\nMatriz A\n");

  for (int i = 0; i < linhas; i++)
  {
    for (int j = 0; j < colunas; j++)
    {
      printf("Digite o valor em: ");
      scanf("%lf", &tamanhoA[i][j]);
      // tamanhoA[i][j] = rand() % 100;
    }
  }
  printf("\nMatriz B\n");
  for (i = 0; i < linhas; i++)
  {
    for (j = 0; j < colunas; j++)
    {
      printf("Digite o valor em %d %d: ", i, j);
      scanf("%lf", &tamanhoB[i][j]);
      // tamanhoB[i][j] = rand() % 100;
    }
  }

  for (i = 0; i < linhas; i++)
  {
    printf("\n");
    for (j = 0; j < colunas; j++)
    {
      soma = tamanhoA[i][j] + tamanhoB[i][j];
      printf("%.2f ", soma);
    }
  }
}