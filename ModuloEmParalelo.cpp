#include "ModuloEmSerie.h"
#include "Somador.h"

#include <list>
#include <stdexcept>
using namespace std;

ModuloEmSerie::ModuloEmSerie() {
}

ModuloEmSerie::~ModuloEmSerie() {
}

Sinal* ModuloEmSerie::processar(Sinal* sinalIN) {
    Sinal *saidaAux = sinalIN;
    Sinal *sinalSomado = sinalIN;
    Somador *somador = new Somador();

    if (getCircuitos()->empty()) {
        throw new logic_error ("Nenhum CircuitoSISO");
    }
    for (list<CircuitoSISO*>::iterator i = (getCircuitos())->begin(); i != (getCircuitos())->end(); i++) {
        saidaAux = (*i)->processar(saidaAux);
        sinalSomado = somador->processar(sinalSomado, saidaAux);
    }
    return saidaAux;


}