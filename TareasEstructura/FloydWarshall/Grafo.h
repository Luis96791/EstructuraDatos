#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <climits>
#include <stack>

using namespace std;

class Grafo
{
    public:
        static const int tamanio = 10;
        int numeros[10] = {20,33,54,22,90,67,78,96,12,48};
        bool adyacencias[tamanio][tamanio];
        int pesos[tamanio][tamanio];
        Grafo();
        void establecerAdyacencias();
        void establecerPesos();
        bool crearAdyacencia(int num1, int num2);
        void agregarPesos(int num1, int num2, int peso);
        void eliminarAdyacencia(int num1, int num2);
        bool existeCamino(int num1, int num2);
        int caminoMinimo(int num1, int num2);
        bool isConexo();
        bool isCompleto();
        int getPosicion(int num);
        void imprimirAdyacencias();
        void imprimirPesos();
        virtual ~Grafo();

    protected:

    private:
};

#endif // GRAFO_H
