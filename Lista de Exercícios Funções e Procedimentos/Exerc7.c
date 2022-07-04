#include <stdio.h>
#include <stdbool.h>

int verifSeTriang(int ladoT1, int ladoT2, int ladoT3)
{
  bool verOuFal;
  if ((ladoT1 + ladoT2 > ladoT3) && (ladoT1 + ladoT3 > ladoT2) && (ladoT3 + ladoT2 > ladoT1))
  {
    verOuFal = true;
  }
  else
  {
    verOuFal = false;
  }
  return (verOuFal);
}

int verifTipoTriang(int ladoT1, int ladoT2, int ladoT3)
{
  int opcao;
  if ((ladoT1 == ladoT2) && (ladoT2 == ladoT3))
  {
    opcao = 1;
  }
  else if ((ladoT1 != ladoT2) && (ladoT2 != ladoT3) && (ladoT1 != ladoT3))
  {
    opcao = 2;
  }
  else
  {
    opcao = 3;
  }

  return (opcao);
}

void main()
{
  bool verificacao;
  int lado1, lado2, lado3, result;

  printf("Digite um numero: ");
  scanf("%d", &lado1);
  printf("Digite um numero: ");
  scanf("%d", &lado2);
  printf("Digite um numero: ");
  scanf("%d", &lado3);

  verificacao = verifSeTriang(lado1, lado2, lado3);

  if (verificacao == true)
  {
    result = verifTipoTriang(lado1, lado2, lado3);

    switch (result)
    {
    case 1:
      printf("Os lados formam um triangulo equilatero. ");
      break;
    case 2:
      printf("Os lados formam um triangulo escaleno. ");
      break;
    default:
      printf("Os lados formam um triangulo isosceles. ");
      break;
    }
  }
  else
  {
    printf("Os lados nao formam um triangulo.");
  }
}