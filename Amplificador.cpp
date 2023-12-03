#include "Amplificador.h"

Amplificador::Amplificador(double ganho) : ganho(ganho), sequencia(nullptr)
{
}

Amplificador::~Amplificador()
{
    // delete em sequencia alocado dinamicamente no processar
    delete[] sequencia;
}

void Amplificador::setGanho(double ganho)
{
    this->ganho = ganho;
}

double Amplificador::getGanho()
{
    return ganho;
}

Sinal *Amplificador::processar(Sinal *sinalIN)
{
    sequencia = new double[sinalIN->getComprimento()];
    for (int i = 0; i < sinalIN->getComprimento(); i++)
    {
        sequencia[i] = (sinalIN->getSequencia())[i] * ganho;
    }
    return new Sinal(sequencia, sinalIN->getComprimento());
}