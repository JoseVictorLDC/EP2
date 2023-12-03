#include "ModuloRealimentado.h"
#include "Somador.h"
#include "Amplificador.h"
#include "Sinal.h"

#include <list>

ModuloRealimentado ::ModuloRealimentado() : moduloEmSerie(new ModuloEmSerie()), saida(nullptr)
{
}

ModuloRealimentado ::~ModuloRealimentado()
{
  // delete nos objetos criados no construtor
  delete moduloEmSerie;
}

Sinal *ModuloRealimentado::processar(Sinal *sinalIN)
{
  // objetos que serao utilizados nas interacoes
  Amplificador *inversor = new Amplificador(-1);
  Somador *somador = new Somador();

  Sinal *saidaInvertida = nullptr;
  Sinal *diferenca = nullptr;

  double *sequenciaSaidaInvertida = new double[sinalIN->getComprimento()];
  const double vInicial = 0;

  sequenciaSaidaInvertida[0] = vInicial;
  diferenca = new Sinal(sinalIN->getSequencia(), 1);
  saida = moduloEmSerie->processar(diferenca);
  delete diferenca;

  for (int i = 1; i < sinalIN->getComprimento(); i++)
  {
    // Sequencia de operacoes dadas no enunciado
    sequenciaSaidaInvertida[i] = ((inversor->processar(saida))->getSequencia())[i - 1];
    // criar a saida invertida com a sua sequencia
    saidaInvertida = new Sinal(sequenciaSaidaInvertida, i + 1);
    diferenca = somador->processar(sinalIN, saidaInvertida);
    delete saida;
    // processar uma nova saida
    saida = moduloEmSerie->processar(diferenca);
    // destruir o objeto criado na interacao
    delete saidaInvertida;
    delete diferenca;
  }
  // destriur o vetor alocado dinamicamente
  delete[] sequenciaSaidaInvertida;
  delete inversor;
  delete somador;

  return saida;
}

void ModuloRealimentado::adicionar(CircuitoSISO *circ)
{
  moduloEmSerie->adicionar(circ);
}

list<CircuitoSISO *> *ModuloRealimentado::getCircuitos()
{
  return moduloEmSerie->getCircuitos();
}
