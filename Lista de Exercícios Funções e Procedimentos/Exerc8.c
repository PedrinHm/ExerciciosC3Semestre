#include <stdio.h>

float mediaAritmetica(float acum, float cont)
{

  float mediaA = acum / (cont - 1);

  return (mediaA);
}
void main()
{
  float valor, media;
  int acumulador = 0, contador = 0;
  do
  {
    printf("Digite um valor: ");
    scanf("%f", &valor);
    contador = contador + 1;
    acumulador = acumulador + valor;
  } while (valor != 0);

  media = mediaAritmetica(acumulador, contador);

  printf("A media é %.2f", media);
}