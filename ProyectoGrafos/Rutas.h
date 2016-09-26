#ifndef RUTAS_H
#define RUTAS_H
#include <iostream>
#include <stack>

#include "Utility.h"

using namespace std;

class Rutas
{
    public:
        Utility* utility;

        static const int _size = 15;
        char* puntos[_size];
        char* caminoDirecto[5];
        bool adyacencieas[_size][_size];
        bool caminos[_size][_size];
        int pesos[_size][_size];
        int distancias[_size][_size];
        Rutas();
        void llenarPuntos();
        void setAdyacencias();
        void setCaminos();
        void setPesos();
        void nuevaAdyacencia(char* nombre_punto1, char* nombre_punto2);
        void nuevoCamino(char* nombre_punto1, char* nombre_punto2);
        void agregarPeso(char* nombre_punto1, char* nombre_punto2, int peso);
        void eliminarCamino(char* nombre_punto1, char* nombre_punto2);
        void eliminarPeso(char* nombre_punto1, char* nombre_punto2);
        bool consultarCamino(char* nombre_punto1, char* nombre_punto2);
        int obtenerPosicion(char* nombre_punto);
        char* obtenerPunto(int posicion);
        void rutasPosibles();
        bool existeCamino(char* nombre_punto1, char* nombre_punto2);
        void obtenerCaminosDirectos(char* nombre_punto1);
        int caminoMinimo(char* nombre_punto1, char* nombre_punto2);
        void reestablecerCaminosDirectos();
        virtual ~Rutas();

    protected:

    private:
};

#endif // RUTAS_H
