#ifndef CIRCUITO_H
#define CIRCUITO_H

#include "Circuito.h"

class Circuito
{
protected:
    static int IDgeral;
    int IDespecifico;

public:
    Circuito();
    virtual ~Circuito() = 0;
    int getID();
    virtual void imprimir();
    static int getUltimoID();
};

#endif