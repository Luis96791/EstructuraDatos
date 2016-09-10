#ifndef GRAFODIJKSTRA_H
#define GRAFODIJKSTRA_H
#include <iostream>
#include <climits>

using namespace std;

class GrafoDijkstra
{
    public:
        static const int TAM = 10;
        int minimo = INT_MAX, sig = 0;
        int elementos[TAM];
        int matriz[TAM][TAM];
        int distancia[TAM];
        bool visitado[TAM];
        GrafoDijkstra();
        void inicializarDijkstra();
        void dijkstra(int inicio);
        virtual ~GrafoDijkstra();

    protected:

    private:
};

#endif // GRAFODIJKSTRA_H
