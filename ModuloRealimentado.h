#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Piloto.h"
#include "Somador.h"

class ModuloRealimentado
{
private:
    double ganho;
    Piloto *piloto;
    Amplificador *inversor;
    Somador *somador;
    Sinal *saida;

public:
    ModuloRealimentado(double ganho);
    ~ModuloRealimentado();
    Sinal *processar(Sinal *sinalIN);
};

#endif