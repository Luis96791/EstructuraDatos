#include "Grafo.h"

Grafo::Grafo()
{
    //ctor
}

void Grafo::establecerAdyacencias()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            adyacencias[f][c] = false;
        }
    }
}

void Grafo::establecerPesos()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            pesos[f][c] = 0;
        }
    }
}

int Grafo::getPosicion(int num)
{
    for(int s = 0; s < tamanio; s++)
    {
        if(numeros[s] == num)
        {
            return s;
        }
    }
    return -1;
}

bool Grafo::crearAdyacencia(int num1, int num2)
{
    if(!adyacencias[getPosicion(num1)][getPosicion(num2)]
       || !adyacencias[getPosicion(num2)][getPosicion(num1)])
    {
        adyacencias[getPosicion(num1)][getPosicion(num2)] = true;
        adyacencias[getPosicion(num2)][getPosicion(num1)] = true;
        return true;
    }
    return false;
}

void Grafo::eliminarAdyacencia(int num1, int num2)
{
    adyacencias[getPosicion(num1)][getPosicion(num2)] = false;
    adyacencias[getPosicion(num2)][getPosicion(num1)] = false;
}

bool Grafo::existeCamino(int num1, int num2)
{
    bool verticesVisitados[10] = {0,0,0,0,0,0,0,0,0,0};
    verticesVisitados[getPosicion(num1)] = true;
    stack<int> siguiente;
    siguiente.push(getPosicion(num1));

    while(!siguiente.empty())
    {
        int temp = siguiente.top();
        siguiente.pop();

        for(int s = 0; s < tamanio; s++)
        {
            if(!verticesVisitados[s] && adyacencias[temp][s])
            {
                verticesVisitados[s] = true;
                siguiente.push(s);
            }
        }
    }
    return verticesVisitados[getPosicion(num2)];
}

void Grafo::agregarPesos(int num1, int num2, int peso)
{
    pesos[getPosicion(num1)][getPosicion(num2)] = peso;
    pesos[getPosicion(num2)][getPosicion(num1)] = peso;
}

int Grafo::caminoMinimo(int num1, int num2)
{
    int temporal[tamanio][tamanio];

    for(int s = 0; s < tamanio; s++)
    {
        for(int x = 0; x < tamanio; x++)
        {
            temporal[s][x] = pesos[s][x];
        }
    }

    for(int n = 0; n < tamanio; n++)
    {
        for(int m = 0; m < tamanio; m++)
        {
            for(int s = 0; s < tamanio; s++)
            {
                if(temporal[m][n]+temporal[n][s] < temporal[m][s])
                {
                    temporal[m][s] = temporal[m][n] + temporal[n][s];
                }
            }
        }
    }
    return temporal[getPosicion(num1)][getPosicion(num2)];
}

bool Grafo::isConexo()
{
    int puntos = 0;

    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            if(adyacencias[f][c])
            {
                puntos++;
            }
        }
        if(puntos >= 1)
        {
            puntos = 0;
        }
        else{
            return false;
        }
    }
    return true;
}

bool Grafo::isCompleto()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            if(!adyacencias[f][c])
            {
                return false;
            }
        }
    }
    return true;
}

void Grafo::imprimirAdyacencias()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            cout<<adyacencias[f][c]<<" ";
        }
        cout<<endl<<endl;
    }
}



void Grafo::imprimirPesos()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            cout<<pesos[f][c]<<" ";
        }
        cout<<endl<<endl;
    }
}

Grafo::~Grafo()
{
   delete adyacencias;
}
