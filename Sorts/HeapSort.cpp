#include "HeapSort.h"

HeapSort::HeapSort()
{
    //ctor
}

void HeapSort::insertar(int n, int x)
{
    nodos[n] = new Nodo(x);

    while(nodos[(n-1)/2] < nodos[n])
    {
        int auxiliar = nodos[(n-1)/2]->numero;
        nodos[(n-1)/2] = nodos[n];
        nodos[n]->numero = auxiliar;
        n = (n-1)/2;
    }
}

int HeapSort::eliminar(int n)
{
    int x = nodos[0]->numero;
    nodos[0] = nodos[n--];

    int elemento_movido = 0;
    int hijo_elemento_movido = 1;

    while(hijo_elemento_movido < elemento_movido)
    {
        if(hijo_elemento_movido+1 < n && nodos[hijo_elemento_movido+1]->numero > nodos[hijo_elemento_movido]->numero)
        {
            hijo_elemento_movido++;
        }

        if(nodos[elemento_movido]->numero < nodos[hijo_elemento_movido]->numero)
        {
            int aux = nodos[elemento_movido]->numero;
            nodos[elemento_movido]->numero = nodos[hijo_elemento_movido]->numero;
            nodos[hijo_elemento_movido]->numero = aux;
            elemento_movido = hijo_elemento_movido;
            hijo_elemento_movido = 2*elemento_movido+1;
        }
        else{
            hijo_elemento_movido = n;
        }
    }
    return x;
}

void HeapSort::heapSort(int n)
{
    for(int s = 0; s < n; s++)
    {
        insertar(s, nodos[s]->numero);
    }

    for(int x = n; x > 0; x--)
    {
        nodos[x-1]->numero = eliminar(x);
    }
}

HeapSort::~HeapSort()
{
    //dtor
}
