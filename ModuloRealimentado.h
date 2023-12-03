#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "ModuloEmSerie.h"

class ModuloRealimentado : public Modulo // herança da classe Modulo
{
private:
    ModuloEmSerie *moduloEmSerie;
    Sinal *saida;

public:
    ModuloRealimentado();
    virtual ~ModuloRealimentado();
    Sinal *processar(Sinal *sinalIN);     // redifinição do método processar da superclasse
    void adicionar(CircuitoSISO *circ);   // redifinição do método adicionar da superclasse
    list<CircuitoSISO *> *getCircuitos(); // redifinição do método getCircuitos da superclasse
};

#endif
