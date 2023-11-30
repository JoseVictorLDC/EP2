#ifndef MODULO_H
#define MODULO_H

#include "CircuitoSISO.h"
#include <list>

class Modulo
{
private:

public:
    Modulo();
    virtual ~Modulo();
    void adicionar(CircuitoSISO* circ);
    list<CircuitoSISO*>* getCircuitos();

};

#endif