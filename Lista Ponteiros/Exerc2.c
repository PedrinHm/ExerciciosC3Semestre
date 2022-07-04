#include <stdio.h>
#include <stdlib.h>

float troca(float *a, float *b)
{
  float aux;

  aux = *a;
  *a = *b;
  *b = aux;
}
void main()
{

  float valor1, valor2;
  float *pontV1, *pontV2;

  printf("Leia dois valores: \nvalor1: ");
  scanf("%f", &valor1);
  printf("\nValor 2: ");
  scanf("%f", &valor2);

  pontV1 = &valor1;
  pontV2 = &valor2;

  printf("\nAntes da troca: \n%.2f %.2f", valor1, valor2);

  troca(pontV1, pontV2);

  printf("\nDepois da troca: \n%.2f %.2f", valor1, valor2);
}