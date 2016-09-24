#ifndef GRAFO_H
#define GRAFO_H
#include <climits>
#include <iostream>

using namespace std;

class Grafo
{
    public:
        static const int tamanio = 10;
        int numeros[tamanio];
        int adyacencias[tamanio][tamanio];
        int caminos[tamanio];
        int pesos[tamanio][tamanio];
        Grafo();
        void llenarNumeros();
        void establecerAdyacencias();
        void establecerPesos();
        void establecerCaminos();
        int getPosition(int num);
        void agregarArista(int num1, int num2);
        void agregarPeso(int num1, int num2, int peso);
        void distanciaMinima(int num);
        void relajar(int caminos[], int k, int p);
        void printPesos();
        virtual ~Grafo();

    protected:

    private:
};

#endif // GRAFO_H
