#ifndef INTEGRADOR_H
#define INTEGRADOR_H

#include "Sinal.h"

class Integrador
{
private:
    double *sequencia;

public:
    Integrador();
    virtual ~Integrador();
    Sinal *processar(Sinal *sinalIN);
};

#endif