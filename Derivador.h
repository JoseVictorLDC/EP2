#ifndef DERIVADOR_H
#define DERIVADOR_H

#include "Sinal.h"
#include "CircuitoSISO.h"

class Derivador : public CircuitoSISO
{
private:
    double *sequencia;

public:
    Derivador();
    virtual ~Derivador();
    Sinal *processar(Sinal *sinalIN);
};

#endif