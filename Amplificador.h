#ifndef AMPLIFICADOR_H
#define AMPLIFICADOR_H

#include "Sinal.h"
#include "CircuitoSISO.h"

class Amplificador : public CircuitoSISO
{
private:
  double ganho;
  double *sequencia;

public:
  Amplificador(double ganho);
  virtual ~Amplificador();
  void setGanho(double ganho);
  double getGanho();
  Sinal *processar(Sinal *sinalIN);
};

#endif