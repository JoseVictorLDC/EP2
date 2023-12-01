#include "Derivador.h"
#include "ModuloRealimentado.h"
#include "Integrador.h"
#include <cmath>

double *obterSequencia(double *sequencia);
void processarOpcao1();
void processarOpcao2();

void menu()
{
  int opcao;
  cout << "\tSimulink em C++" << endl
       << "Qual simulacao voce gostaria de fazer?" << endl
       << "1) Piloto Automatico" << endl
       << "2) Sua propria sequencia de operacoes" << endl
       << "Escolha: ";
  cin >> opcao;

  if (opcao == 1)
    processarOpcao1();
  
  else if (opcao == 2)
    processarOpcao2();
}

double *obterSequencia(double *sequencia)
{
  int opcao;
  cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?" << endl
       << "1) 5+3*cos(n*pi/8)" << endl
       << "2) constante" << endl
       << "3) rampa" << endl
       << "Escolha: ";
  cin >> opcao;
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
    cout << "Qual o valor dessa constante?" << endl
         << "C = ";
    cin >> C;
    for (int i = 0; i < 60; i++)
    {
      sequencia[i] = C;
    }
  }
  else if (opcao == 3)
  {
    double a;
    cout << "Qual a inclinacao dessa rampa?" << endl
         << "a = ";
    cin >> a;
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
  double ganho;

  cout << "Qual o ganho do acelerador?" << endl
       << "g = ";
  cin >> ganho;
  ModuloRealimentado *modulo = new ModuloRealimentado();
  // impressao && processar do sinal
  (modulo->processar(sinal))->imprimir("Velocidade do Carro");

  // delete nos objetos criados
  delete modulo;
  delete sinal;
  delete[] sequencia;
}

void processarOpcao2()
{
  // inicializando o sinal
  double *sequencia = new double[60];
  Sinal *sinal = new Sinal(obterSequencia(sequencia), 60);
  // inicializando os operadores necessarios
  Amplificador *amplificador = new Amplificador(-1); // amplificador foi inicializado com ganho = -1 e utilizaremos o setGanho()
  Somador *somador = new Somador();
  Derivador *derivador = new Derivador();
  Integrador *integrador = new Integrador();

  int loop = 1, opcao;
  while (loop == 1)
  {
    cout << "Qual operacao voce gostaria de fazer?" << endl
         << "1) Amplificar" << endl
         << "2) Somar" << endl
         << "3) Derivar" << endl
         << "4) Integrar" << endl
         << "Escolha: ";
    cin >> opcao;
    // opcao para cada caso acima
    if (opcao == 1)
    {
      double ganho;
      cout << "Qual o ganho dessa amplificacao?" << endl
           << "g = ";
      cin >> ganho;
      amplificador->setGanho(ganho);
      
      sinal = (amplificador)->processar(sinal);
    }
    else if (opcao == 2)
    {
      cout << "Informe mais um sinal para ser somado." << endl;
      double *sequenciaAux = new double[60];
      Sinal *sinalAux = new Sinal(obterSequencia(sequenciaAux), 60);
      sinal = (somador)->processar(sinal, sinalAux);
      delete[] sequenciaAux;
      delete sinalAux;
    }
    else if (opcao == 3)
    {
      sinal = (derivador)->processar(sinal);
    }
    else if (opcao == 4)
    {
      sinal = (integrador)->processar(sinal);
    }

    cout << "O que voce quer fazer agora?" << endl
         << "1) Realizar mais uma operacao no resultado" << endl
         << "2) Imprimir o resultado para terminar" << endl
         << "Escolha: ";
    // Aqui podemos quebrar o loop
    cin >> loop;
  }
  // impressao do sinal processado
  sinal->imprimir("Resultado Final");
  // delete nos objetos criados com "new"
  delete[] sequencia;
  delete sinal;
  delete amplificador;
  delete somador;
  delete derivador;
  delete integrador;
}
