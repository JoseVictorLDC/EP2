#ifndef MODULOEMSERIE_H
#define MODULOEMSERIE_H

#include "Modulo.h"

class ModuloEmSerie : public Modulo // herança da classe Modulo
{
private:
    Sinal *saida;

public:
    ModuloEmSerie();
    virtual ~ModuloEmSerie();
    Sinal *processar(Sinal *sinalIN); // redifinição do método processar da superclasse
};

#endif
