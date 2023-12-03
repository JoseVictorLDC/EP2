#ifndef MODULO_H
#define MODULO_H

#include "CircuitoSISO.h"
#include <list>

class Modulo : public CircuitoSISO
{
private:
    list<CircuitoSISO*>* listaCircuitos;

public:
    Modulo();
    virtual ~Modulo() = 0;
    void adicionar(CircuitoSISO* circ);
    list<CircuitoSISO*>* getCircuitos();
    void imprimir();

};

#endif