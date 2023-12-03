#include "PersistenciaDeModulo.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"
#include "Amplificador.h"
#include "Derivador.h"
#include "Integrador.h"

#include <fstream>
#include <stdexcept>
#include <cmath>
#include <iostream>
using namespace std;

double *obterSequencia(double *sequencia);
void processarOpcao1();
void processarOpcao2();
void salvarArquivo(Modulo *modulo);
void aquisicaoDeOperacao(CircuitoSISO *circuito, Modulo *modulo);
void impressao(Modulo *modulo, Sinal *sinal);
void aquisicaoEimpressao(CircuitoSISO *circuito, Modulo *modulo, Sinal *sinal);

void menu()
{
  int opcao;
  cout << "\tSimulink em C++" << '\n'
       << "Qual simulacao voce gostaria de fazer?" << '\n'
       << "1) Circuito advindo de arquivo" << '\n'
       << "2) Sua propria sequencia de operacoes" << '\n'
       << "Escolha: ";
  cin >> opcao;
  cout << '\n';

  if (opcao == 1)
    processarOpcao1();

  else if (opcao == 2)
    processarOpcao2();
}

double *obterSequencia(double *sequencia)
{
  int opcao;
  cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao" << '\n'
       << "1) 5+3*cos(n*pi/8)" << '\n'
       << "2) constante" << '\n'
       << "3) rampa" << '\n'
       << "Escolha: ";
  cin >> opcao;
  cout << '\n';
  if (opcao == 1)
  {
    for (int i = 0; i < 60; i++)
    {
      sequencia[i] = 5 + 3 * cos(i * M_PI / 8);
    }
  }
  else if (opcao == 2)
  {
    double C;
    cout << "Qual o valor dessa constante?" << '\n'
         << "C = ";
    cin >> C;
    cout << '\n';
    for (int i = 0; i < 60; i++)
    {
      sequencia[i] = C;
    }
  }
  else if (opcao == 3)
  {
    double a;
    cout << "Qual a inclinacao dessa rampa?" << '\n'
         << "a = ";
    cin >> a;
    cout << '\n';
    for (int i = 0; i < 60; i++)
    {
      sequencia[i] = i * a;
    }
  }
  return sequencia;
}

void processarOpcao1()
{
  // criacao dos objetos necessarios//
  double *sequencia = new double[60];
  Sinal *sinal = new Sinal(obterSequencia(sequencia), 60);
  Modulo *modulo = nullptr;

  string nomeDoarquivo;
  cout << "Qual o nome do arquivo a ser lido?" << '\n'
       << "Nome: ";
  cin >> nomeDoarquivo;
  cout << '\n';

  try
  {
    PersistenciaDeModulo *persistencia = new PersistenciaDeModulo(nomeDoarquivo);
    modulo = persistencia->lerDeArquivo();
    impressao(modulo, sinal);
    delete persistencia;
  }
  catch (logic_error *e)
  {
    cout << e->what() << '\n';
    delete e;
  }

  // delete nos objetos criados
  if (modulo != nullptr)
    delete modulo;
  delete sinal;
  delete[] sequencia;
}


void processarOpcao2()
{
  double *sequencia = new double[60];
  Sinal *sinal = new Sinal(obterSequencia(sequencia), 60);
  Modulo *modulo = nullptr;
  CircuitoSISO *circuito = nullptr;

  cout << "Qual estrutura de operações voce deseja ter como base" << '\n'
       << "1) Operacoes em serie nao realimentadas" << '\n'
       << "2) Operacoes em paralelo nao realimentadas" << '\n'
       << "3) Operacoes em serie realimentadas" << '\n'
       << "Escolha: ";
  int opcao;
  cin >> opcao;
  cout << '\n';

  if (opcao == 1)
    modulo = new ModuloEmSerie();

  else if (opcao == 2)
    modulo = new ModuloEmParalelo();

  else if (opcao == 3)
    modulo = new ModuloRealimentado();

  aquisicaoEimpressao(circuito, modulo, sinal);

  // delete nos objetos criados com "new"
  if (modulo != nullptr)
    delete modulo;
  if (circuito != nullptr)
    delete circuito;
  delete sinal;
  delete[] sequencia;
}

void salvarArquivo(Modulo *modulo)
{
  cout << "Voce gostaria de salvar o resultado em um arquivo?" << '\n'
       << "1) Sim" << '\n'
       << "2) Nao" << '\n'
       << "Escolha: ";
  int opcao;
  cin >> opcao;
  cout << '\n';
  if (opcao == 1)
  {
    string nomeDoArquivo;
    cout << "Qual o nome do arquivo a ser escrito?" << '\n'
         << "Nome: ";
    cin >> nomeDoArquivo;
    cout << '\n';
    PersistenciaDeModulo *persistencia = new PersistenciaDeModulo(nomeDoArquivo);
    persistencia->salvarEmArquivo(modulo);
    delete persistencia;
  }
}

void aquisicaoDeOperacao(CircuitoSISO *circuito, Modulo *modulo)
{
  int opcao;
  int loop = 1;
  while (loop == 1)
  {
    cout << "Qual operacao voce gostaria de fazer?" << '\n'
         << "1) Amplificar" << '\n'
         << "2) Derivar" << '\n'
         << "3) Integrar" << '\n'
         << "Escolha: ";
    cin >> opcao;
    cout << '\n';
    // opcao para cada caso acima
    if (opcao == 1)
    {
      double ganho;
      cout << "Qual o ganho dessa amplificacao?" << '\n'
           << "g = ";
      cin >> ganho;
      cout << '\n';
      circuito = new Amplificador(ganho);
      modulo->adicionar(circuito);
    }
    else if (opcao == 2)
    {
      circuito = new Derivador();
      modulo->adicionar(circuito);
    }

    else if (opcao == 3)
    {
      circuito = new Integrador();
      modulo->adicionar(circuito);
    }

    cout << "O que voce quer fazer agora?" << '\n'
         << "1) Realizar mais uma operacao no resultado" << '\n'
         << "2) Imprimir o resultado" << '\n'
         << "Escolha: ";
    // Aqui podemos quebrar o loop
    cin >> loop;
    cout << '\n';
  }
}

void impressao(Modulo *modulo, Sinal *sinal)
{
  Sinal *saida = nullptr;
  try
  {
    saida = modulo->processar(sinal);
    saida->imprimir("Resultado Final");
    cout << '\n';
    salvarArquivo(modulo);
    delete saida;
  }
  catch (logic_error *e)
  {
    cout << e->what() << '\n';
    delete e;
  }
}

void aquisicaoEimpressao(CircuitoSISO *circuito, Modulo *modulo, Sinal *sinal)
{
  aquisicaoDeOperacao(circuito, modulo);
  impressao(modulo, sinal);
}

