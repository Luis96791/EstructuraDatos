#include <iostream>
#include "Grafo.h"

using namespace std;

int main()
{
    Grafo* grafo = new Grafo;

    grafo->establecerAdyacencias();
    grafo->establecerPesos();

    grafo->crearAdyacencia(20,48);
    grafo->agregarPesos(20,48,20);
    grafo->crearAdyacencia(33,22);
    grafo->agregarPesos(33,22,15);
    grafo->crearAdyacencia(33,67);
    grafo->agregarPesos(33,67,10);
    grafo->crearAdyacencia(54,33);
    grafo->agregarPesos(54,33,5);
    grafo->crearAdyacencia(54,90);
    grafo->agregarPesos(54,90,25);
    cout<<grafo->existeCamino(20,48)<<endl;
    grafo->~Grafo();
    return 0;
}
