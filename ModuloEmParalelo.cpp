#include "ModuloEmParalelo.h"
#include "Somador.h"
#include "Sinal.h"

#include <stdexcept>
#include <list>

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

    for (list<CircuitoSISO *>::iterator i = this->getCircuitos()->begin(); i != this->getCircuitos()->end(); i++)
    {
        if (i == this->getCircuitos()->begin())
            saida = (*i)->processar(sinalIN);
        else
            saida = somador->processar((*i)->processar(sinalIN), saida);
    }

    delete somador;
    return saida;
}
