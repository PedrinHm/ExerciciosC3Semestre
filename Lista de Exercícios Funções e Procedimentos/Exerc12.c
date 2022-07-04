#include <stdio.h>
#include <stdbool.h>

int sePrimo(int numero)
{
  bool validacao;
  int acum = 0;
  for (int i = numero; i > 0; i--)
  {
    if (numero % i == 0)
    {
      acum++;
    }
  }
  if (acum == 2)
  {
    validacao = true;
  }
  else
  {
    validacao = false;
  }

  return (validacao);
}
void main()
{

  int num;

  printf("Digite um numero: ");
  scanf("%d", &num);

  bool result = sePrimo(num);

  if (result == true)
  {
    printf("O número %d e primo.", num);
  }
  else
  {
    printf("O numero %d nao e primo.", num);
  }
}