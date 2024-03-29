#ifndef PERSISTENCIADEMODULO_H
#define PERSISTENCIADEMODULO_H

#include "Modulo.h"

#include <string>
using namespace std;

class PersistenciaDeModulo
{
private:
    string nomeDoArquivo;

public:
    PersistenciaDeModulo(string nomeDoArquivo);
    virtual ~PersistenciaDeModulo();
    void salvarEmArquivo(Modulo* mod);
    Modulo* lerDeArquivo();
};

#endif