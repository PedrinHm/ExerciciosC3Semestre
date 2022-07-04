#include <stdio.h>

int somatorio(int numero)
{

  int acum = numero;
  for (int i = 0; i < numero; i++)
  {

    acum = acum + i;
  }

  return (acum);
}
void main()
{

  int num;

  printf("Digite um numero: ");
  scanf("%d", &num);

  int result = somatorio(num);

  printf("O somatorio desse numero e: %d", result);
}