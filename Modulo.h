#ifndef MODULO_H
#define MODULO_H

#include "CircuitoSISO.h"
#include <list>

class Modulo : public CircuitoSISO // herança da classe CircuitoSISO
{
private:
    list<CircuitoSISO *> *circuitos;

public:
    Modulo();
    virtual ~Modulo();
    virtual void adicionar(CircuitoSISO *circ);
    virtual list<CircuitoSISO *> *getCircuitos();
    void imprimir();
};

#endif
