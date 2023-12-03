#include "Somador.h"
#include "Sinal.h"

Somador::Somador() : sequencia(nullptr)
{
}

Somador::~Somador()
{
    // delete em sequencia alocado dinamicamente no processar
    delete[] sequencia;
}

Sinal *Somador::processar(Sinal *sinalIN1, Sinal *sinalIN2)
{

    if (sinalIN1->getComprimento() >= sinalIN2->getComprimento())
    {
        sequencia = new double[sinalIN2->getComprimento()];
        for (int i = 0; i < sinalIN2->getComprimento(); i++)
        {
            sequencia[i] = sinalIN1->getSequencia()[i] + sinalIN2->getSequencia()[i];
        }
        return new Sinal(sequencia, sinalIN2->getComprimento());
    }

    sequencia = new double[sinalIN1->getComprimento()];
    for (int i = 0; i < sinalIN1->getComprimento(); i++)
    {
        sequencia[i] = sinalIN1->getSequencia()[i] + sinalIN2->getSequencia()[i];
    }
    return new Sinal(sequencia, sinalIN1->getComprimento());
}