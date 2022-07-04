#include <stdio.h>

int calcularAnos(int anosN)
{
  anosN = anosN * 365;

  return (anosN);
}

int calcularMeses(int mesN)
{
  mesN = mesN * 30;

  return (mesN);
}

int main()
{
  int anos, meses, dias, resultado;

  printf("Digite a quantidade de anos vividos: ");
  scanf("%d", &anos);

  printf("Digite a quantidade de meses vividos: ");
  scanf("%d", &meses);

  printf("Digite a quantidade de dias vividos: ");
  scanf("%d", &dias);

  int nAnos = calcularAnos(anos);

  int nMeses = calcularMeses(meses);

  resultado = dias + nAnos + nMeses;

  printf("Resultado: %d", resultado);
}
