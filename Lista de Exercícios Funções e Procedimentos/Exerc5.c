#include <stdio.h>

int classificacao(int idadeNadador)
{
  if (idadeNadador < 5)
  {
    printf("O nadador não pertence a nenhuma categoria.");
  }
  else if (idadeNadador <= 7)
  {
    printf("O nadador pertence a categoria INFANTIL A");
  }
  else if (idadeNadador <= 10)
  {
    printf("O nadador pertence a categoria INFANTIL B");
  }
  else if (idadeNadador <= 13)
  {
    printf("O nadador pertence a categoria JUVENIL A");
  }
  else if (idadeNadador <= 17)
  {
    printf("O nadador pertence a categoria JUVENIL B");
  }
  else
  {
    printf("O nadador pertence a categoria Adulto");
  }
}

void main()
{

  int idade;

  printf("Digite a idade do nadador: ");
  scanf("%d", &idade);

  classificacao(idade);
}