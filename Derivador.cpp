#include "Derivador.h"

Derivador::Derivador() : sequencia(nullptr)
{
}

Derivador::~Derivador()
{
  // delete em sequencia alocado dinamicamente no processar
  delete[] sequencia;
}

Sinal *Derivador::processar(Sinal *sinalIN)
{
  sequencia = new double[sinalIN->getComprimento()];
  sequencia[0] = (sinalIN->getSequencia())[0];
  for (int i = 1; i < sinalIN->getComprimento(); i++)
  {
    sequencia[i] = (sinalIN->getSequencia())[i] - (sinalIN->getSequencia())[i - 1];
  }
  return new Sinal(sequencia, sinalIN->getComprimento());
}