#include "Modulo.h"
#include "CircuitoSISO.h"

#include <iostream>
#include <list>
using namespace std;

Modulo::Modulo() : CircuitoSISO()
{
    this->circuitos = new list<CircuitoSISO *>();
}

Modulo::~Modulo()
{
    delete circuitos;
}

void Modulo::adicionar(CircuitoSISO *circ)
{
    circuitos->push_back(circ);
}

list<CircuitoSISO *> *Modulo::getCircuitos()
{
    return circuitos;
}

void Modulo::imprimir()
{
    cout << "Modulo com ID " << IDespecifico << " e :" << endl;

    for (list<CircuitoSISO *>::iterator i = circuitos->begin(); i != circuitos->end(); i++)
    {
        (*i)->imprimir();
    }
    cout << "--" << endl; 
}
