#include "Modulo.h"

Modulo::Modulo() {
    this->listaCircuitos = new list<CircuitoSISO*>();
}

Modulo::~Modulo() {
    for (list<CircuitoSISO*>::iterator i = listaCircuitos->begin(); i != listaCircuitos->end(); i++) {
    delete (*i);
    }
    delete listaCircuitos;
}

void Modulo::adicionar(CircuitoSISO* circ) {
    listaCircuitos->push_back(circ);
}

list<CircuitoSISO*>* Modulo::getCircuitos() {
    return listaCircuitos;
}

void Modulo::imprimir() {
    cout << "Modulo com ID " << getID() << " e:" << endl;
    for (list<CircuitoSISO*>::iterator i = listaCircuitos->begin(); i != listaCircuitos->end(); i++) {
    cout << "Circuito com ID " << getID() << endl;
    }
    cout << "--" << endl;
} 