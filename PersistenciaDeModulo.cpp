#include "PersistenciaDeModulo.h"
#include "Modulo.h"
#include "CircuitoSISO.h"
#include "Amplificador.h"
#include "Integrador.h"
#include "Derivador.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo) {
    this->nomeDoArquivo = nomeDoArquivo;
}

PersistenciaDeModulo::~PersistenciaDeModulo() {
}

void PersistenciaDeModulo::salvarEmArquivo(Modulo* mod) {
    ofstream ostream;
    ostream.open(nomeDoArquivo, ios_base::app);
    

    for(list<CircuitoSISO*>::iterator i = (mod->getCircuitos())->begin(); i != (mod->getCircuitos())->end(); i++) {
        ostream << testeDeClasse(*i) << endl;
    }

    ostream << "f" << endl;

    ostream.close();

}

Modulo* PersistenciaDeModulo::lerDeArquivo() {
    ifstream istream;
    string X;
    istream.open(nomeDoArquivo, ios_base::in);

    if(istream.fail()) {
        throw invalid_argument("Erro de leitura");
    }
    while (istream) {
        istream >> X;
        cout << X << endl;
    }

    if (!istream.eof()) {
        throw logic_error("Arquivo em formatação inesperada");
    }
    istream.close(); 
}

string testeDeClasse(CircuitoSISO *Circuito) {
    ModuloEmSerie moduloSerie;
    ModuloEmParalelo moduloParalelo;
    ModuloRealimentado moduloRealimentado;
    Amplificador amplificador(0);
    Integrador integrador;
    Derivador derivador;

    if (CircuitoSISO *Circuito = dynamic_cast<ModuloEmSerie*>(moduloSerie) == true) {
        return "S";
    }
    if (CircuitoSISO *Circuito = dynamic_cast<ModuloEmParalelo*>(moduloParalelo) == true) {
        return "P";
    }
    if (CircuitoSISO *Circuito = dynamic_cast<ModuloRealimentado*>(moduloRealimentado) == true) {
        return "R";
    }
    if (CircuitoSISO *Circuito = dynamic_cast<Amplificador*>(amplificador) == true) {
        return "A" << Circuito->getGanho();
    }
    if (CircuitoSISO *Circuito = dynamic_cast<Integrador*>(integrador) == true) {
        return "I";
    }
    if (CircuitoSISO *Circuito = dynamic_cast<Derivador*>(derivador) == true) {
        return "D";
    }
}
