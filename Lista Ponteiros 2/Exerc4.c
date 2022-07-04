#include <stdio.h>
#include <stdlib.h>

int *interseccao(int *x1, int *x2, int n1, int n2, int *x3, int n3)
{
  int qnt = 0;

  for (int i = 0; i < n1; i++)
  {
    printf("\n");
    for (int j = 0; j < n2; j++)
    {
      if (x1[i] == x2[j])
      {
        qnt += 1;
      }
    }
  }

  x3 = (malloc(qnt * sizeof(int)));
  int i = 0;
  for (int j = 0; j < n1; j++)
  {
    for (int k = 0; k < n2; k++)
    {
      if (x1[j] == x2[k])
      {
        x3[i] = x1[j];
        i++;
        n3++;
      }
    }
  }

  return x3;
}

void main()
{

  int *x1, *x2, *qtd, *x3;
  int n1, n2, n3, i = 0, j;

  n1 = 5;
  n2 = 5;

  x1 = malloc(n1 * sizeof(int));
  x2 = malloc(n2 * sizeof(int));

  x1[0] = 1;
  x1[1] = 2;
  x1[2] = 3;
  x1[3] = 6;
  x1[4] = 7;

  x2[0] = 1;
  x2[1] = 3;
  x2[2] = 4;
  x2[3] = 6;
  x2[4] = 8;

  x3 = interseccao(x1, x2, n1, n2, x3, n3);

  printf("vetor x3:\n| ");
  for (j = 0; j < n3; j++)
  {
    printf(" %d |", x3[i]);
  }
}
