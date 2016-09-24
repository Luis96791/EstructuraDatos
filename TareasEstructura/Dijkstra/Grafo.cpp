#include "Grafo.h"

Grafo::Grafo()
{
    //ctor
}

void Grafo::llenarNumeros()
{
    numeros[0] = 34;
    numeros[1] = 48;
    numeros[2] = 98;
    numeros[3] = 56;
    numeros[4] = 16;
    numeros[5] = 31;
    numeros[6] = 68;
    numeros[7] = 10;
    numeros[8] = 3;
    numeros[9] = 88;
}

void Grafo::establecerAdyacencias()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            adyacencias[f][c] = INT_MAX;
        }
    }
}

void Grafo::establecerPesos()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            pesos[f][c] = INT_MAX;
        }
    }
}

void Grafo::establecerCaminos()
{
    for(int c = 0; c < tamanio; c++)
    {
        caminos[c] = INT_MAX;
    }
}

int Grafo::getPosition(int num)
{
    for(int t = 0; t < tamanio; t++)
    {
        if(numeros[t] == num)
        {
            return t;
        }
    }
    return -1;
}

void Grafo::agregarArista(int num1, int num2)
{
    adyacencias[getPosition(num1)][getPosition(num2)] = true;
    adyacencias[getPosition(num2)][getPosition(num1)] = true;
}

void Grafo::agregarPeso(int num1, int num2, int peso)
{
    pesos[getPosition(num1)][getPosition(num2)] = peso;
    pesos[getPosition(num2)][getPosition(num1)] = peso;
}

//Dijkstra
void Grafo::distanciaMinima(int num)
{
    int Pminimo, Vminimo;
    bool visitados[tamanio] = {false};

    visitados[num] = true;

    for(int s = 0; s < tamanio; s++)
    {
        Pminimo = 1;
        Vminimo = INT_MAX;

        for(int j = 0; j < tamanio; j++)
        {
            if(Vminimo > caminos[j])
            {
                Vminimo = caminos[j];
                Pminimo = j;
            }
        }
    }
    visitados[Pminimo] = true;

    for(int k = 0; k < tamanio; k++)
    {
        relajar(caminos, k, Pminimo);
    }
}

void Grafo::relajar(int caminos[], int k, int p)
{
    if(caminos[k] > (caminos[p]+adyacencias[p][k]))
    {
        caminos[k] = caminos[p]+adyacencias[p][k];
    }
}

void Grafo::printPesos()
{
    for(int f = 0; f < tamanio; f++)
    {
        for(int c = 0; c < tamanio; c++)
        {
            if(pesos[f][c] == INT_MAX)
            {
                cout<<"I ";
            }
            else{
                cout<<pesos[f][c]<<" ";
            }
        }
        cout<<endl<<endl;
    }
}

Grafo::~Grafo()
{
    //dtor
}
