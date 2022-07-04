#include <stdio.h>

int quantDivisor(int numero, int div)
{

  int result, acum = 0;

  if (numero % div == 0)
  {
    while (numero % div == 0)
    {
      result = numero / div;
      numero = result;
      acum++;
    }
    return (acum);
  }
  else
  {
    return (-1);
  }
}

void main()
{

  int num, divisor;

  printf("Digite um numero: ");
  scanf("%d", &num);

  printf("Digite um numero: ");
  scanf("%d", &divisor);

  int result = quantDivisor(num, divisor);

  printf("A quantia de divisoes e: %d", result);

  getchar();
}