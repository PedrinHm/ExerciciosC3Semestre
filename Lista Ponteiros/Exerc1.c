#include <stdio.h>
#include <stdlib.h>

void main()
{
  int inteiro = 10;
  float real = 15.5;
  char caractere = 'a';

  int *pontinteiro;
  float *pontreal;
  char *pontcaractere;

  pontinteiro = &inteiro;
  pontreal = &real;
  pontcaractere = &caractere;

  printf("\n%d %.2f %c\n%p %p %p\n", inteiro, real, caractere, pontinteiro, pontreal, pontcaractere);

  *pontinteiro = 15;
  *pontreal = 17.4;
  *pontcaractere = 'z';

  printf("\n%d %.2f %c\n%p %p %p", inteiro, real, caractere, pontinteiro, pontreal, pontcaractere);
}