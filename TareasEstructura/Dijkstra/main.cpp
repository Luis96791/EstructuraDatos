#include <iostream>
#include "Grafo.h"

using namespace std;

int main()
{
    Grafo* grafo = new Grafo;

    grafo->llenarNumeros();
    grafo->establecerAdyacencias();
    grafo->establecerPesos();

    grafo->printPesos();
    return 0;
}
