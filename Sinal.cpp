#include "Sinal.h"
#include "Grafico.h"

Sinal::Sinal(double *sequencia, int comprimento) : sequencia(sequencia), comprimento(comprimento), sequenciaAux(new double[comprimento])
{
    for (int i = 0; i < comprimento; i++)
    {
        sequenciaAux[i] = sequencia[i];
    }
}

Sinal::~Sinal()
{
    // delete sequenciaAux alocado dinamicamente no cosntrutor
    delete[] sequenciaAux;
}

double *Sinal::getSequencia()
{
    return sequencia;
}

int Sinal::getComprimento()
{
    return comprimento;
}

void Sinal::imprimir(string nomeDoSinal)
{
    Grafico *grafico = new Grafico(nomeDoSinal, sequencia, comprimento);
    grafico->plot();
    delete grafico;
}