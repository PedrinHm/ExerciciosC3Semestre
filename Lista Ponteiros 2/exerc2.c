#include <stdio.h>
#include <stdlib.h>

void main()
{

  int quantAlunos = 0, i = 0, j = 0;
  int **alunos;

  printf("Digite a quantia de alunos da turma: ");
  // quantAlunos = 5;
  scanf("%d", &quantAlunos);
  
  alunos = malloc(quantAlunos * sizeof(int *));

  for (int i = 0; i < quantAlunos; i++)
  {
    alunos[i] = malloc(2 * sizeof(int));
  }

  for (i = 0; i < quantAlunos; i++)
  {

    j = 0;
    printf("\nDigite a matricula do aluno: \n");
    // alunos[i][j] = rand() % 100;
    scanf("%d", &alunos[i][j]);
    printf("\nDigite a média do aluno %d:\n", alunos[i][j]);
    // alunos[i][j + 1] = rand() % 100;
    scanf("%d", &alunos[i][j + 1]);
  }

  for (i = 0; i < quantAlunos; i++)
  {
    printf("\nMédia do aluno %d: %d\n", alunos[i][j], alunos[i][1 + j]);
  }
}
