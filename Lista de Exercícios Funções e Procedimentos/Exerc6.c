#include <stdio.h>
#include <stdbool.h>

bool posOuNeg(int numPosOuNeg)
{

  bool result;
  if (numPosOuNeg < 0)
  {
    result = false;
    return (result);
  }
  else if (numPosOuNeg > 0)
  {
    result = true;
    return (result);
  }
  else
  {
    printf("O numero zero e neutro.");
  }
}

void main()
{

  int num;
  bool resposta;

  printf("Digite um numero: ");
  scanf("%d", &num);

  resposta = posOuNeg(num);

  if (resposta == true)
  {
    printf("O numero e positivo.");
  }
  else
  {
    printf("O numero e negativo.");
  }
}