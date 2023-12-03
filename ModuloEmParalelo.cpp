#include "ModuloEmParalelo.h"
#include "Somador.h"
#include <stdexcept>

ModuloEmParalelo::ModuloEmParalelo() : Modulo(), saida(nullptr)
{
}

ModuloEmParalelo::~ModuloEmParalelo()
{

}

Sinal *ModuloEmParalelo::processar(Sinal *sinalIN)
{
    if (circuitos->empty())
        throw new logic_error("Não há circuitosSISO para processar o sinal de entrada");

    Somador *somador = new Somador();

    for (list<CircuitoSISO *>::iterator i = circuitos->begin(); i != circuitos->end(); i++)
    {
        if (i == circuitos->begin())
            saida = (*i)->processar(sinalIN);
        else
            saida = somador->processar((*i)->processar(sinalIN), saida);
    }

    delete somador;
    return saida;
}
