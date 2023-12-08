#include "ModuloEmSerie.h"
#include "Sinal.h"

#include <stdexcept>
#include <list>

ModuloEmSerie::ModuloEmSerie() : Modulo(), saida(nullptr)
{
}

ModuloEmSerie::~ModuloEmSerie()
{
}

Sinal *ModuloEmSerie::processar(Sinal *sinalIN)
{
    if (circuitos->empty())
        throw new logic_error("Não há circuitosSISO para processar o sinal de entrada");
    for (list<CircuitoSISO *>::iterator i = this->getCircuitos()->begin(); i != this->getCircuitos()->end(); i++)
    {
        if (i == this->getCircuitos()->begin())
            saida = (*i)->processar(sinalIN);
        else
            saida = (*i)->processar(saida);
    }

    return saida;
}
