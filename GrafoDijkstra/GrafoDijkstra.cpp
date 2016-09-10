#include "GrafoDijkstra.h"

GrafoDijkstra::GrafoDijkstra()
{
    //ctor
}

void GrafoDijkstra::inicializarDijkstra()
{
    for(int c = 0; c < TAM; c++)
    {
        visitado[c] = false;
        elementos[c] = 0;

        for(int j = 0; j < TAM; j++)
        {
            matriz[c][j] = INT_MAX;
        }
    }
    distancia[0] = matriz[0][0];
    visitado[0] = true;
    distancia[0] = 0;

    for(int n = 0; n < TAM; n++)
    {
        minimo = INT_MAX;
        for(int c = 0; c < 10; c++)
        {
            if(minimo > distancia[c] && !visitado)
            {
                minimo = distancia[c];
                sig = c;
            }
        }
        visitado[sig] = true;

        for(int s = 0; s < TAM; s++)
        {
            if(!visitado[s])
            {
                if(minimo+matriz[sig][s] < distancia[s])
                {
                    distancia[s] = minimo+matriz[sig][s];
                    elementos[s] = sig;
                }
            }
        }
    }
}

GrafoDijkstra::~GrafoDijkstra()
{
    //dtor
}
