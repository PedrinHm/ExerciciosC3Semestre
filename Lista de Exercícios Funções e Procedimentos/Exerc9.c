#include <stdio.h>

int elevarAoQuad(int x, int z)
{
  int resultado = x;
  for (int i = 1; i < z; i++)
  {
    resultado = resultado * x;
  }

  return (resultado);
}
void main()
{

  int num1, num2;

  printf("Digite um numero: ");
  scanf("%d", &num1);
  printf("Digite um número: ");
  scanf("%d", &num2);

  int result = elevarAoQuad(num1, num2);

  printf("O numero %d elevado a %d é igual a %d", num1, num2, result);
}