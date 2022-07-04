#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>

// Variaveis globais

int quantidadeJogadores, quantidadePremios, linha, coluna, intervalo, tamanho;
int verificadorDeConfiguracaoCartela = 0, posicaoJogador = 1;
char texto_str[20];
FILE *ArquivoJogador;
FILE *ArquivoPremio;
FILE *ArquivoResultado;
FILE *ArquivoHistorico;

// Structs
typedef struct
{
  char *nome;
  char *numeroTelefone;
  char *cpf;
  int cartela[10][10];
  int quantidadeDeAcertos;
  int colocacao;
  int bingo;
} Jogador;

Jogador jogador[100];
Jogador cadastrarJogadores(int i);
Jogador gerarCartela(Jogador jogador);
void ExibirCartela(Jogador jogador);
char *entradaNumeroTelJogador();
char *entradaCPFJogador();
char *entradaNomeJogador(int numJogador);
void inserirQuantidadeJogadores();
void definirColocacaoJogador();
void configurarCartela();

typedef struct
{
  char *nomePremio;
  float valorAssociado;
  int posicaoPremio;
} Premio;

Premio premio[100];
Premio cadastrarPremio(int i, int quantidadePremios);
void gerarArquivoPremio(int quantidadeDePremios, int i, Premio premio);
float inserirValorDoPremio();
char *inserirNomeDoPremio(int numPremio);
void inserirQuantidadeDePremios(int qtdJogadores);

void definirArquivoResultado(int pedrasSorteadas[]);
void gerarArquivoDoJogador(int quantidadeDeJogadores, int i, Jogador jogador);
void gerarArquivoPremio(int quantidadeDePremios, int i, Premio premio);
void ExibirMenuArquivos();
void selecionarExibicaoArquivos(int escolhaMenuArquivo);
void ExibirArquivoJogadores();
void ExibirArquivoPremios();
void ExibirArquivoResultado();
void ExibirArquivoHistorico();
void exibirGanhador(int i);

void VerificarConfiguracoes();

void horaDeBingar();
void verificarGanhador(int i);
int sorteioPedra(int numPedra, int *pedrasSorteadas);
void realizarSorteio(int numPedra, int pedra, int pedrasSorteadas[]);
Jogador verificadorDePedraMarcada(Jogador jogador, int pedra);

int main()
{

  int escolhaMenu;
  setlocale(LC_ALL, "portuguese");
  system("cls");

menu:

  printf("\n\n  _________________________MENU_____________________________\n");
  printf(" | 1. Configurar cartela.                                   |\n");
  printf(" | 2. Cadastrar participantes.                              |\n");
  printf(" | 3. Cadastrar premios.                                    |\n");
  printf(" | 4. Iniciar BINGO.                                        |\n");
  printf(" | 5. Arquivos                                              |\n");
  printf(" | 0. Encerrar programa.                                    |\n");
  printf(" |__________________________________________________________|\n\n");

  printf("Escolha: ");
  scanf("%d", &escolhaMenu);

  switch (escolhaMenu)
  {
  case 1:
  {
    system("cls");
    configurarCartela();
    break;
  }
  case 2:
  {
    system("cls");
    if (verificadorDeConfiguracaoCartela == 1)
    {

      inserirQuantidadeJogadores();

      for (int i = 0; i < quantidadeJogadores; i++)
      {
        system("cls");
        jogador[i] = cadastrarJogadores(i);
        fflush(stdin);
        gerarArquivoDoJogador(quantidadeJogadores, i, jogador[i]);
      }
    }
    else
    {
      system("cls");
      printf("Impossivel cadastrar participantes antes de definir as configurações das cartelas.");
    }
    break;
  }
  case 3:
  {
    system("cls");
    inserirQuantidadeDePremios(quantidadeJogadores);

    for (int i = 0; i < quantidadePremios; i++)
    {
      premio[i] = cadastrarPremio(i, quantidadePremios);
    }
    break;
  }
  case 4:
  {
    VerificarConfiguracoes();
    system("cls");

    break;
  }
  case 5:
  {
    ExibirMenuArquivos();
  }
  case 0:
  {
    system("cls");
    printf("\nPrograma encerrado.");
    break;
  }
  default:
  {
    system("cls");
    printf("Codigo inexistente");
    break;
  }
  }

  if (escolhaMenu != 0)
  {
    goto menu;
  }

  return 0;
}

// Secao jogadores

void inserirQuantidadeJogadores()
{
  printf("Definir quantidade de jogadores.");
  do
  {
    printf("Insira a quantidade de jogadores: ");
    scanf("%d", &quantidadeJogadores);
  } while (quantidadeJogadores < 1);
}

// modificada
char *entradaNomeJogador(int numJogador)
{
  int condNome = 0;
  char *nome = (char *)malloc(sizeof *nome * 100);

  do
  {
    printf("\nDigite o nome do %do jogador: ", numJogador + 1);
    fgets(nome, 100, stdin);

    for (int i = 0; i < strlen(nome); i++)
    {
      if ((nome[i] >= 'a' && nome[i] <= 'z') || (nome[i] >= 'A' && nome[i] <= 'Z'))
      {
        condNome = 1;
      }
      else if (isspace(nome[i]))
      {
        condNome = 1;
      }
      else
      {
        condNome = 0;
        break;
      }
    }
    if (condNome == 1)
    {
      printf("\nNome validado!");
    }
    else
    {
      printf("\nNome invalido! Insira apenas letras!");
    }
  } while (condNome != 1);

  return nome;
}

char *entradaCPFJogador()
{
  char *cpf = (char *)malloc(sizeof *cpf * 12);
  int icpf[12];
  int contador, somatorio = 0, primeiroDigito, resultPrimeiroDigito, resultSegundoDigito, segundoDigito, condCPF = 0;

  do
  {
    printf("\nInsira o CPF do Jogador: ");
    fgets(cpf, 12, stdin);
    // Conversao de array de char para um array de int.
    for (int i = 0; i < 11; i++)
    {
      icpf[i] = cpf[i] - 48;
    }

    somatorio = 0;

    // Validação primeiro digito.
    for (int i = 0; i < 9; i++)
    {
      somatorio += icpf[i] * (10 - i);
    }

    resultPrimeiroDigito = somatorio % 11;

    if (resultPrimeiroDigito < 2)
    {
      primeiroDigito = 0;
    }
    else
    {
      primeiroDigito = 11 - resultPrimeiroDigito;
    }

    // Validação segundo digito.
    somatorio = 0;

    for (int i = 0; i < 10; i++)
    {
      somatorio += icpf[i] * (11 - i);
    }

    resultSegundoDigito = somatorio % 11;
    if (resultSegundoDigito < 2)
    {
      segundoDigito = 0;
    }
    else
    {
      segundoDigito = 11 - resultSegundoDigito;
    }

    // RESULTADOS DA VALIDACAO.
    if ((primeiroDigito == icpf[9]) && (segundoDigito == icpf[10]))
    {
      printf("\nCPF inserido VALIDADO.\n");
      condCPF = 1;
    }
    else
    {
      printf("CPF inserido INVALIDO\n");
      condCPF = 0;
    }
  } while (condCPF != 1);

  return cpf;
}

char *entradaNumeroTelJogador()
{
  int condNumTel = 0;
  char *numTel = (char *)malloc(sizeof *numTel * 100);
  ;

  do
  {
    printf("\nDigite o numero de telefone do jogador: ");
    fgets(numTel, 12, stdin);

    for (int i = 0; i < strlen(numTel); i++)
    {
      if ((numTel[i] >= '0') && (numTel[i] <= '9'))
      {
        condNumTel = 1;
      }
      else
      {
        printf("\n\nEntrada de dados invalida: Insira apenas numeros!\n\n");
        condNumTel = 0;
      }
    }
  } while (condNumTel != 1);

  return numTel;
}

Jogador cadastrarJogadores(int i)
{
  Jogador jogador;
  jogador.quantidadeDeAcertos = 0;
  jogador.colocacao = 0;
  system("cls");
  printf("Cadastrar participante.\n");
  fflush(stdin);
  jogador.nome = entradaNomeJogador(i);
  fflush(stdin);
  jogador.numeroTelefone = entradaNumeroTelJogador();
  fflush(stdin);
  jogador.cpf = entradaCPFJogador();

  jogador = gerarCartela(jogador);

  return jogador;
}

// Secao Premios

void inserirQuantidadeDePremios(int qtdJogadores)
{
  system("cls");
  printf("\nCadastrar prêmios.\n");
  if (qtdJogadores <= 0)
  {
    printf("Cadastre o numero de jogadores primeiro.");
  }
  else
  {
    do
    {
      printf("Digite a quantidade de premios que serão cadastrados: ");
      scanf("%d", &quantidadePremios);

      if (quantidadePremios > qtdJogadores)
      {
        printf("\nNumero maior que a quantidade de participantes. \n");
      }
      else if (quantidadePremios < 1)
      {
        printf("\nNumero de premios menor que o permitido. Cadastre pelo menos 1!");
      }
    } while (quantidadePremios > qtdJogadores || quantidadePremios < 1);
  }
}

char *inserirNomeDoPremio(int numPremio)
{
  char *nomePremio = (char *)malloc(sizeof *nomePremio * 100);

  printf("\nDigite o nome do premio do %d° colocado: ", numPremio + 1);
  fgets(nomePremio, 100, stdin);

  return nomePremio;
}

float inserirValorDoPremio()
{
  float valor;

  printf("\nDigite o valor do premio: ");
  scanf("%f", &valor);

  while (valor < 1)
  {
    if (valor < 1)
    {
      system("cls");
      printf("\nValor do premio menor que o permitido!\nDigite novamente o valor do premio: ");
      scanf("%f", &valor);
    }
  }

  return valor;
}

Premio cadastrarPremio(int i, int quantidadePremios)
{
  Premio premio;
  fflush(stdin);
  premio.nomePremio = inserirNomeDoPremio(i);
  fflush(stdin);
  premio.posicaoPremio = i;
  premio.valorAssociado = inserirValorDoPremio();
  gerarArquivoPremio(quantidadePremios, i, premio);

  return premio;
}

// Seção Cartela

// modificada2.0
void configurarCartela()
{
  printf("\nConfigurar cartela.\n");
  do
  {
    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linha);

    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &coluna);

    if (linha > 10 || coluna > 10)
    {
      printf("\nTamanho invalido! Digite novamente");
    }
  } while (linha < 0 || coluna < 0);

  int auxTamanho = linha * coluna;

  printf("\nInsira o numero limite dos numeros a serem gerados: ");
  scanf("%d", &intervalo);
  if (auxTamanho >= intervalo)
  {
    printf("\nIntervalo menor ou igual o tamanho da cartela. \nDigite um valor maior.");
  }
  else
  {
    verificadorDeConfiguracaoCartela = 1;
  }
}

Jogador gerarCartela(Jogador jogador)
{
  tamanho = linha * coluna;
  int *numerosUsados = (int *)malloc(tamanho * sizeof(int));
  int contadorNumerosUsados, ultimoNumeroUsado;

  contadorNumerosUsados = 0;
  for (int j = 0; j < linha; j++)
  {
    for (int k = 0; k < coluna; k++)
    {
      ultimoNumeroUsado = contadorNumerosUsados;
      jogador.cartela[j][k] = 1 + rand() % intervalo;
      numerosUsados[contadorNumerosUsados] = jogador.cartela[j][k];
      for (int l = 0; l < ultimoNumeroUsado; l++)
      {
        if (jogador.cartela[j][k] == numerosUsados[l])
        {
          k--;
          contadorNumerosUsados--;
          break;
        }
      }
      contadorNumerosUsados++;
    }
  }
  ExibirCartela(jogador);
  return jogador;
}

void ExibirCartela(Jogador jogador)
{
  printf("\nCartela do jogador %s : \n", jogador.nome);
  for (int j = 0; j < linha; j++)
  {
    for (int k = 0; k < coluna; k++)
    {
      printf(" %d ", jogador.cartela[j][k]);
    }
    printf("\n");
  }
}

// Secao Bingo

void horaDeBingar()
{
  int numPedra = 0, pedra, pedrasSorteadas[intervalo];

  ArquivoHistorico = fopen("arquivoHistorico.txt", "w");
  ArquivoResultado = fopen("arquivoResultado.txt", "w");

  realizarSorteio(numPedra, pedra, pedrasSorteadas);

  definirColocacaoJogador();

  definirArquivoResultado(pedrasSorteadas);

  fclose(ArquivoHistorico);
  fclose(ArquivoResultado);
}

void VerificarConfiguracoes()
{
  if (quantidadeJogadores != 0 && quantidadePremios != 0)
  {
    system("cls");
    printf("\n\n  _________________________BINGO_____________________________\n");
    printf(" |                       Tudo pronto!                       |\n");
    printf(" |                                                          |\n");
    printf(" |                                                          |\n");
    printf(" |                     Hora do bingo!                       |\n");
    printf(" |                                                          |\n");
    printf(" |                                                          |\n");
    printf(" |__________________________________________________________|\n\n");
    system("pause");
    system("cls");
    horaDeBingar();
    ExibirArquivoResultado();
    system("pause");
  }
  else
  {
    system("cls");
    printf("Termine as configurações iniciais antes de começar o bingo!\n");
    system("pause");
  }
}

// modificada
void verificarGanhador(int i)
{
  if (jogador[i].colocacao == 0 && jogador[i].quantidadeDeAcertos == tamanho)
  {
    printf("\n\n__________________________________________________________\n");
    jogador[i].colocacao = posicaoJogador;
    exibirGanhador(i);
  }
}
// modificada
void exibirGanhador(int i)
{
  printf("\n\n        O jogador %s ganhou! \n", jogador[i].nome);
  printf("\nPremio: %s.", premio[posicaoJogador - 1].nomePremio);
  printf("Colocação: %d", posicaoJogador);
  posicaoJogador++;
  printf(" ");
  printf("\n  _______0__o_o__o_0_0_o_o___0__________");
  printf("\n  ______0___o__o__o0_0__o_o___0_________");
  printf("\n  _____0___o__o_o__0_0__o___o__0________");
  printf("\n  ____0_o___o___o__0_0___o___o__0_______");
  printf("\n  ____00o0000o00o0o0_0o00o00oo0oo0______");
  printf("\n  ___000o0o00000o000_000o00o0o000o0_____");
  printf("\n  ___00000o000o000o0_000o000o00000o0____");
  printf("\n  ___0o00oo00o0o00o0__0000o0o0o00000____");
  printf("\n  ___0o0o00000o00o0___000o0o0o0o0o00____");
  printf("\n  ____0o0o0000o0o0_____0000o00o00o0_____");
  printf("\n  _____0000o0000________ 00o000o000_____");
  printf("\n  ______0000000___________0000000_______");
  printf("\n  ________00__________________00________");
  printf("\n  _______00____________________00_______");
  printf("\n  ______00_____FELICIDADES!_____00______");
  printf("\n  _____00________________________00_____");
  printf("\n  ____00__________________________00____");
  printf("\n  _000000________________________000000_");
  printf("\n  ______________________________________\n");
}

void definirColocacaoJogador()
{
  while (posicaoJogador <= quantidadeJogadores)
  {
    int maiorQtdeAcertos = 0;
    int jogadorMaiorQtdeAcertos = 0;
    for (int i = 0; i < quantidadeJogadores; i++)
    {
      if (jogador[i].colocacao == 0 && jogador[i].quantidadeDeAcertos > maiorQtdeAcertos)
      {
        maiorQtdeAcertos = jogador[i].quantidadeDeAcertos;
        jogadorMaiorQtdeAcertos = i;
      }
    }
    jogador[jogadorMaiorQtdeAcertos].colocacao = posicaoJogador;
    posicaoJogador++;
  }
}

void realizarSorteio(int numPedra, int pedra, int pedrasSorteadas[])
{
  while (posicaoJogador <= quantidadePremios)
  {
    pedra = sorteioPedra(numPedra, pedrasSorteadas);
    pedrasSorteadas[numPedra] = pedra;
    numPedra++;

    for (int i = 0; i < quantidadeJogadores; i++)
    {
      jogador[i] = verificadorDePedraMarcada(jogador[i], pedra);
    }

    for (int i = 0; i < quantidadeJogadores; i++)
    {
      verificarGanhador(i);
    }
    system("pause");
    system("cls");
  }
}

int sorteioPedra(int numPedra, int *pedrasSorteadas)
{
  int resultado;
  int novo = 0;
  srand(time(NULL));

  do
  {
    resultado = 1 + rand() % intervalo;
    novo = 0;
    for (int i = 0; i < numPedra; i++)
      if (pedrasSorteadas[i] == resultado)
      {
        novo = 1;
      }
  } while (novo != 0);
  printf("\nA pedra sorteada foi: %d\n", resultado);
  fprintf(ArquivoHistorico, "\nA pedra sorteada foi: %d\n", resultado);
  return resultado;
}

Jogador verificadorDePedraMarcada(Jogador jogador, int pedra)
{
  for (int j = 0; j < linha; j++)
  {
    for (int k = 0; k < coluna; k++)
    {
      if (jogador.cartela[j][k] == pedra)
      {
        printf("O jogador %s marcou esse número!\n", jogador.nome);
        jogador.quantidadeDeAcertos++;
        fprintf(ArquivoHistorico, " O jogador %s marcou esse número!\n", jogador.nome);
        break;
      }
    }
  }

  return jogador;
}

// ARQUIVOS

void gerarArquivoPremio(int quantidadeDePremios, int i, Premio premio)
{
  char premios[quantidadeDePremios];
  sprintf(premios, "premio-%02d.txt", i + 1);
  ArquivoPremio = fopen(premios, "w");
  if (ArquivoPremio == NULL)
  {
    printf("ERRO: Arquivo já existente!");
    fclose(ArquivoPremio);
  }
  else
  {
    fprintf(ArquivoPremio, "Nome: %sValor: %.2f\nColocação: %d ", premio.nomePremio, premio.valorAssociado, premio.posicaoPremio);
    fclose(ArquivoPremio);
  }
}

void gerarArquivoDoJogador(int quantidadeDeJogadores, int i, Jogador jogador)
{
  char jogadores[quantidadeDeJogadores];
  sprintf(jogadores, "Jogadores-%02d.txt", i + 1);
  ArquivoJogador = fopen(jogadores, "w");
  if (ArquivoJogador == NULL)
  {
    system("cls");
    printf("ERRO: Arquivo já existente!");
    fclose(ArquivoJogador);
  }
  else
  {
    fprintf(ArquivoJogador, "Nome: %sNumero de Celular: %s\nCPF: %s\nCartela: \n", jogador.nome, jogador.numeroTelefone, jogador.cpf);
    for (int j = 0; j < linha; j++)
    {
      for (int k = 0; k < coluna; k++)
      {
        fprintf(ArquivoJogador, " %d", jogador.cartela[j][k]);
      }
      fprintf(ArquivoJogador, "\n");
    }
    fclose(ArquivoJogador);
  }
}

void definirArquivoResultado(int pedrasSorteadas[])
{
  for (int i = quantidadeJogadores; i >= 1; i--)
  {
    for (int j = quantidadeJogadores; j >= 0; j--)
    {
      if (jogador[j].colocacao == i)
      {
        if (premio[i - 1].nomePremio != NULL)
        {
          fprintf(ArquivoResultado, "\n----------GANHADOR----------\n");
          fprintf(ArquivoResultado, "\nJogador: %s \nColocação: %d \nPremio: %s \nCartela:\n", jogador[j].nome, jogador[j].colocacao, premio[i - 1].nomePremio);
        }
        else
        {
          fprintf(ArquivoResultado, "\nJogador: %s \nColocação: %d \nCartela:\n", jogador[j].nome, jogador[j].colocacao);
        }

        for (int k = 0; k < linha; k++)
        {
          for (int l = 0; l < coluna; l++)
          {
            fprintf(ArquivoResultado, " %d", jogador[j].cartela[k][l]);
          }
          fprintf(ArquivoResultado, "\n");
        }
        fprintf(ArquivoResultado, "\n");

        int temp = 1;
        fprintf(ArquivoResultado, "\nNúmeros faltantes: \n");

        for (int k = 0; k < linha; k++)
        {
          for (int l = 0; l < coluna; l++)
          {
            for (int m = 0; m < intervalo; m++)
            {
              if (jogador[j].cartela[k][l] == pedrasSorteadas[m])
              {
                temp = 1;
                break;
              }
              else
              {
                temp = 0;
              }
            }
            if (temp == 0)
            {
              fprintf(ArquivoResultado, "\n %d ", jogador[j].cartela[k][l]);
            }
          }
        }
      }
    }
  }
}

// modificada
void ExibirArquivoHistorico()
{
  ArquivoHistorico = fopen("arquivoHistorico.txt", "r");
  while (fgets(texto_str, 20, ArquivoHistorico) != NULL)
    printf("%s", texto_str);
  fclose(ArquivoHistorico);
  printf("\n\n__________________________________________________________\n");
  system("pause");
  system("cls");
}

// modificada
void ExibirArquivoResultado()
{
  ArquivoResultado = fopen("arquivoResultado.txt", "r");
  while (fgets(texto_str, 20, ArquivoResultado) != NULL)
    printf("%s", texto_str);
  fclose(ArquivoResultado);
  printf("\n\n__________________________________________________________\n");
}

// modificada
void ExibirArquivoPremios()
{
  char premios[quantidadePremios];
  for (int i = 0; i < quantidadePremios; i++)
  {
    sprintf(premios, "premio-%02d.txt", i + 1);
    ArquivoPremio = fopen(premios, "r");
    while (fgets(texto_str, 20, ArquivoPremio) != NULL)
      printf("%s", texto_str);
    fclose(ArquivoPremio);
    printf("\n\n__________________________________________________________\n");
    system("cls");
  }
}

void ExibirArquivoJogadores()
{
  char jogadores[quantidadeJogadores];
  for (int i = 0; i < quantidadeJogadores; i++)
  {
    sprintf(jogadores, "Jogadores-%02d.txt", i + 1);
    ArquivoJogador = fopen(jogadores, "r");
    while (fgets(texto_str, 20, ArquivoJogador) != NULL)
      printf("%s", texto_str);
    fclose(ArquivoJogador);
    system("pause");
  }
}

void selecionarExibicaoArquivos(int escolhaMenuArquivo)
{
  switch (escolhaMenuArquivo)
  {
  case 1:
  {
    ExibirArquivoJogadores();
    break;
  }
  case 2:
  {
    ExibirArquivoPremios();
    break;
  }
  case 3:
  {
    ExibirArquivoHistorico();
    break;
  }
  case 4:
  {

    ExibirArquivoResultado();
    break;
  }
  case 0:
  {
    break;
  }
  }
}

void ExibirMenuArquivos()
{
  int escolhaMenuArquivo;
  do
  {

    printf("\n\n  _________________________MENU_____________________________\n");
    printf(" | 1. Exibir arquivos de jogadores.                         |\n");
    printf(" | 2. Exibir arquivos de premios.                           |\n");
    printf(" | 3. Exibir historico                                      |\n");
    printf(" | 4. Exibir ranking                                        |\n");
    printf(" |                                                          |\n");
    printf(" | 0. retornar a tela inicial                               |\n");
    printf(" |__________________________________________________________|\n\n");
    scanf("%d", &escolhaMenuArquivo);
    system("cls");
    selecionarExibicaoArquivos(escolhaMenuArquivo);

  } while (escolhaMenuArquivo != 0);
}