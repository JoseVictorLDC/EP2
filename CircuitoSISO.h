#ifndef CIRCUITOSISO_H
#define CIRCUITOSISO_H

#include "CircuitoSISO.h"
#include "Circuito.h"
#include "Sinal.h"

class CircuitoSISO : public Circuito 
{
private:

public:
    CircuitoSISO();
    virtual ~CircuitoSISO();
    virtual Sinal* processar(Sinal* sinalIN) = 0; // abstrato

};

#endif