#include "Sinal.h"
#include "Grafico.h"

#include <iostream>

Sinal::Sinal(double *sequencia, int comprimento) : sequencia(sequencia), comprimento(comprimento), sequenciaAux(new double[comprimento])
{
    for (int i = 0; i < comprimento; i++)
    {
        sequenciaAux[i] = sequencia[i];
    }
}

Sinal::Sinal(double constante, int comprimento) : comprimento(comprimento) {
    for (int i = 0; i < comprimento; i++) {
        sequencia[i] = constante;
    }
    this->sequencia = sequencia;
}

Sinal::~Sinal()
{
    // delete sequenciaAux alocado dinamicamente no cosntrutor
    delete[] sequenciaAux;
}

double *Sinal::getSequencia()
{
    return sequencia;
}

int Sinal::getComprimento()
{
    return comprimento;
}

void Sinal::imprimir(string nomeDoSinal)
{
    Grafico *grafico = new Grafico(nomeDoSinal, sequencia, comprimento);
    grafico->plot();
    delete grafico;
}

void Sinal::imprimir() {
    for (int i = 0; i < comprimento; i++) {
        cout << i << "- " << (getSequencia())[i] << endl;
    }
    cout << "--";
} 

void Sinal::imprimir(int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << i << "- " << (getSequencia())[i] << endl;
    }
    cout << "--";
}