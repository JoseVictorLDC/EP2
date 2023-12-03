#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Amplificador.h"
#include "Somador.h"
#include "Modulo.h"
#include "ModuloEmSerie.h"

class ModuloRealimentado : public Modulo
{
private:
    ModuloEmSerie *moduloSerie;
    Amplificador *inversor;
    Somador *somador;
    Sinal *saida;

public:
    ModuloRealimentado();
    ~ModuloRealimentado();
    Sinal *processar(Sinal *sinalIN);
};

#endif