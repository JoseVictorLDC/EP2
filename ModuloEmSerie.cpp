#include "ModuloEmSerie.h"

#include <stdexcept>

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
    for (list<CircuitoSISO *>::iterator i = circuitos->begin(); i != circuitos->end(); i++)
    {
        if (i == circuitos->begin())
            saida = (*i)->processar(sinalIN);
        else
            saida = (*i)->processar(saida);
    }

    return saida;
}
