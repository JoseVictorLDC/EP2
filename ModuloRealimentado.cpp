#include "ModuloRealimentado.h"

ModuloRealimentado ::ModuloRealimentado() : inversor(new Amplificador(-1)), somador(new Somador()), saida(nullptr)
{
  ModuloEmSerie *moduloSerie = new ModuloEmSerie();
}

ModuloRealimentado ::~ModuloRealimentado()
{
  // delete nos objetos criados no construtor
  delete saida;
  delete moduloSerie;
  delete inversor;
  delete somador;
}

Sinal *ModuloRealimentado::processar(Sinal *sinalIN)
{
  double *sequenciaSaidaInvertida = new double[sinalIN->getComprimento()];
  // objetos que serao utilizados nas interacoes
  Sinal *saidaInvertida = nullptr;

  for (int i = 0; i < sinalIN->getComprimento(); i++)
  {
    // Sequencia de operacoes dadas no enunciado
    if (i == 0)
      sequenciaSaidaInvertida[i] = 0;
    else // i > 0
    {
      sequenciaSaidaInvertida[i] = ((inversor->processar(saida))->getSequencia())[i - 1];
      delete saida;
    }
    // criar a saida invertida com a sua sequencia
    saidaInvertida = new Sinal(sequenciaSaidaInvertida, i + 1);
    // processar uma nova saida
    saida = moduloSerie->processar(somador->processar(sinalIN, saidaInvertida));
    // destruir o objeto criado na interacao
    delete saidaInvertida;
  }
  // destriur o vetor alocado dinamicamente
  delete[] sequenciaSaidaInvertida;

  return saida;
}
