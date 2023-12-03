#include <iostream>

#include "Circuito.h"

using namespace std;

int Circuito::IDgeral = 0;

Circuito::Circuito() {
    this->IDespecifico = Circuito::IDgeral + 1;
    Circuito::IDgeral ++;
}

Circuito::~Circuito() {
}

int Circuito::getID() {
    return IDespecifico;
}

void Circuito::imprimir() {
    cout << "Circuito com ID " << getID() << endl;
}

int Circuito::getUltimoID() {
    return Circuito::IDgeral;
}