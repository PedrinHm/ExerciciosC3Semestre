#include <stdio.h>

int main()
{

  int n1, resultado;

  printf("Digite o raio de uma esfera para obter o seu volume: ");
  scanf("%d", &n1);

  n1 = calcularCubo(n1);

  resultado = calcularVolume(n1);

  printf("Resultado: %d", resultado);
}

int calcularCubo(int raio)
{
  int cuboRaio;

  cuboRaio = raio * raio * raio;

  return (cuboRaio);
}

int calcularVolume(int raio)
{
  int volume;

  volume = (raio * 4 * 3.14) / 3;

  return (volume);
}
