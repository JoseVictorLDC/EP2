#ifndef MODULOEMPARALELO_H
#define MODULOEMPARALELO_H

#include "Modulo.h"
#include "Sinal.h"

class ModuloEmParalelo : public Modulo // herança da classe Modulo
{
private:
    Sinal *saida;

public:
    ModuloEmParalelo();
    virtual ~ModuloEmParalelo();
    Sinal *processar(Sinal *sinalIN); // redifinição do método processar da superclasse
};

#endif
