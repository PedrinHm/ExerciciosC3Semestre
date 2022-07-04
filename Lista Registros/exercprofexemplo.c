#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct
{
  char nome[50];
  int idade;
} Pessoa;

int main(void)
{
  setlocale(LC_ALL, "");

  // PONTEIRO PARA O ARQUIVO
  FILE *pont_arq;
  Pessoa p;
  int opcao;

  do
  {
    printf("-------MENU-------\n");
    printf("1 - Cadastrar Pessoa.\n");
    printf("2 - Ler Arquivo.\n");
    printf("0 - Sair.\n");
    printf("Informe a opção: ");
    scanf("%d", &opcao);

    if (opcao == 0)
      break;

    if (opcao == 1)
    {
      fflush(stdin);
      printf("Digite o nome da pessoa: ");
      gets(p.nome);
      printf("Digite a idade da pessoa: ");
      scanf("%d", &p.idade);

      // ABRINDO O ARQUIVO
      pont_arq = fopen("arquivo.txt", "a");
      if (pont_arq != NULL)
      {
        printf("\n O arquivo foi aberto com sucesso!\n");
        // SALVANDO DADOS NO ARQUIVO
        fprintf(pont_arq, "Nome = %s.\nIdade = %d.\n", p.nome, p.idade);
        // FECHANDO O ARQUIVO
        fclose(pont_arq);
        printf("...Dados armazenados com sucesso!\n\n");
        system("pause");
        system("cls");
      }
      else
      {
        printf("\nERRO! O arquivo não foi aberto!\n");
      }
    }
    else if (opcao == 2)
    {
      // ABRINDO O ARQUIVO -(Modo Leitura)
      pont_arq = fopen("arquivo.txt", "r");
      if (pont_arq != NULL)
      {
        printf("\n..:: Dados do arquivo::..\n\n");
        char texto_str[100];
        int i = 1;

        while (fgets(texto_str, 100, pont_arq) != NULL)
        {
          printf(" %d| %s", i, texto_str);
          i++;
        }
        printf("\n");
        fclose(pont_arq);
        system("pause");
        system("cls");
      }
      else
      {
        printf("\nERRO! O arquivo não foi encontrado!\n\n");
        system("pause");
        system("cls");
      }
    }

  } while (1);
}