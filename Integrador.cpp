#include "Integrador.h"
#include "Sinal.h"

Integrador::Integrador() : sequencia(nullptr)
{
}

Integrador::~Integrador()
{
    // delete em sequencia alocado dinamicamente no processar
    delete[] sequencia;
}

Sinal *Integrador::processar(Sinal *sinalIN)
{
    sequencia = new double[sinalIN->getComprimento()];
    sequencia[0] = (sinalIN->getSequencia())[0];
    for (int i = 1; i < sinalIN->getComprimento(); i++)
    {
        sequencia[i] = (sinalIN->getSequencia())[i] + sequencia[i - 1];
    }
    return new Sinal(sequencia, sinalIN->getComprimento());
}