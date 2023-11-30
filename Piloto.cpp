#include "Piloto.h"

Piloto::Piloto(double ganho) : ganho(ganho), amplificador(new Amplificador(ganho)), integrador(new Integrador())
{
}

Piloto::~Piloto()
{
    // delete nos objetos criados no construtor
    delete amplificador;
    delete integrador;
}

Sinal *Piloto::processar(Sinal *sinalIN)
{
    return integrador->processar(amplificador->processar(sinalIN));
}