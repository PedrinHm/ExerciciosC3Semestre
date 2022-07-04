#include <stdio.h>

float bhaskara(float a, float b, float raizDelta)
{

  if (raizDelta < 0)
  {
    printf("Sem raizes reais.");
  }
  else
  {
    float resultadoX1 = ((b * -1) + raizDelta) / (2 * a);

    float resultadoX2 = ((b * -1) - raizDelta) / (2 * a);

    printf("X1 = %f \nX2 = %f", resultadoX1, resultadoX2);
  }
}

float raizDelta(float aDelta, float bDelta, float cDelta)
{
  bDelta = bDelta * bDelta;

  float delta = bDelta - (4 * aDelta * cDelta);

  if (delta < 0)
  {

    return (delta);
  }
  else
  {
    delta = sqrt(delta);

    return (delta);
  }
}

int main()
{

  float valorA, valorB, valorC, result;

  printf("Digite o Valor A: ");
  scanf("%f", &valorA);

  printf("Digite o Valor B: ");
  scanf("%f", &valorB);

  printf("Digite o Valor C: ");
  scanf("%f", &valorC);

  float Delta = raizDelta(valorA, valorB, valorC);

  result = bhaskara(valorA, valorB, Delta);
}