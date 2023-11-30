#ifndef PILOTO_H
#define PILOTO_H

#include "Amplificador.h"
#include "Integrador.h"

class Piloto
{
private:
  double ganho;
  Amplificador *amplificador;
  Integrador *integrador;

public:
  Piloto(double ganho);
  virtual ~Piloto();
  Sinal *processar(Sinal *sinalIN);
};

#endif