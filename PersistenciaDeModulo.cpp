#include "PersistenciaDeModulo.h"
#include "PersistenciaDeModulo.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"
#include "Amplificador.h"
#include "Derivador.h"
#include "Integrador.h"

#include <fstream>

void salvarEmArquivoRecurssivo(Modulo *mod, ofstream &arquivo) // funcao auxiliar para salvar em arquivo
{
    // sera utilizado o cast dinamico para saber qual o tipo do modulo ou circuito
    if (dynamic_cast<ModuloEmSerie *>(mod))
        arquivo << "S" << '\n';

    else if (dynamic_cast<ModuloEmParalelo *>(mod))
        arquivo << "P" << '\n';

    else if (dynamic_cast<ModuloRealimentado *>(mod))
        arquivo << "R" << '\n';

    for (list<CircuitoSISO *>::iterator i = (mod->getCircuitos())->begin(); i != (mod->getCircuitos())->end(); i++)
    {
        if (dynamic_cast<Integrador *>(*i))
            arquivo << "I" << '\n';

        else if (dynamic_cast<Derivador *>(*i))
            arquivo << "D" << '\n';

        else if (dynamic_cast<Amplificador *>(*i))
            arquivo << "A " << dynamic_cast<Amplificador *>(*i)->getGanho() << '\n';

        else if (dynamic_cast<Modulo *>(*i))
            salvarEmArquivoRecurssivo(dynamic_cast<Modulo *>(*i), arquivo);
    }
    arquivo << "f" << '\n'; // marca o fim da recursao
}

Modulo *lerDeArquivoRecurssivo(ifstream &arquivo) // funcao auxiliar para ler de arquivo
{
    Modulo *mod = nullptr;
    string tipo;
    double ganho;

    arquivo >> tipo;
    if (tipo == "S")
        mod = new ModuloEmSerie();
    else if (tipo == "P")
        mod = new ModuloEmParalelo();
    else if (tipo == "R")
        mod = new ModuloRealimentado();

    arquivo >> tipo;
    while (arquivo)
    {
        if (tipo == "I")
            mod->adicionar(new Integrador());

        else if (tipo == "D")
            mod->adicionar(new Derivador());

        else if (tipo == "A")
        {
            arquivo >> ganho;
            mod->adicionar(new Amplificador(ganho));
        }

        else if (tipo == "S" || tipo == "P" || tipo == "R") // se for um modulo
        {
            arquivo.unget();                                 // retorna o tipo para o arquivo para que a funcao lerDeArquivoRecurssivo possa ler novamente
            mod->adicionar(lerDeArquivoRecurssivo(arquivo)); // le o modulo de forma recurssiva e adiciona na lista
        }
        else if (tipo == "f")
            return mod; // marca o fim da recursao

        arquivo >> tipo;
    }
    throw new logic_error("formatacao incorreta do arquivo"); // se o arquivo nao termina com "f"
}

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo) : nomeDoArquivo(nomeDoArquivo)
{ // construtor recebe o nome do arquivo
}

PersistenciaDeModulo::~PersistenciaDeModulo()
{ // destrutor nao faz nada de especial
}

void PersistenciaDeModulo::salvarEmArquivo(Modulo *mod)
{
    ofstream arquivo;
    arquivo.open(nomeDoArquivo);
    salvarEmArquivoRecurssivo(mod, arquivo);
    arquivo.close();
}

Modulo *PersistenciaDeModulo::lerDeArquivo()
{
    ifstream arquivo;
    arquivo.open(nomeDoArquivo);
    if (arquivo.fail()) // se o arquivo nao existe
        throw new invalid_argument("arquivo nao encontrado");
    Modulo *mod = lerDeArquivoRecurssivo(arquivo);
    if (!arquivo.eof()) // se o arquivo nao termina com "f"
        throw new logic_error("formatacao incorreta do arquivo");
    arquivo.close();
    return mod;
}
