#include <iostream>
#include "HeapSort.h"
#include "Nodo.h"

using namespace std;

//  Metodo Burbuja Descendente con int's

void bubbleSortDescendente(int arreglo[], int array_size)
{
    int i, j, temp;

    for(i = array_size-1; i >= 0; i--)
    {
        for(j = 1; j <= i; j++)
        {
            if(arreglo[j-1] > arreglo[j])
            {
                temp = arreglo[j-1];
                arreglo[j-1] = arreglo[j];
                arreglo[j] = temp;
            }
        }
        cout<<arreglo[i]<<endl;
    }
}

//  Metodo Burbuja Ascendente con int's

void bubbleSortAscendente(int arreglo[], int array_size)
{
    int i, j, temp;

    for(i = 0; i < array_size; i++)
    {
        for( j = 0; j < array_size-1; j++)
        {
            if(arreglo[j] > arreglo[j+1])
            {
                temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            }
        }
        cout<<arreglo[i]<<endl;
    }
}

int length(int array_size)
{
    return array_size;
}

void selectionSort(int arreglo[], int array_size)
{
    int i = 0, j, minimo, temporal;

    for( ; i < array_size-1; i++)
    {
        minimo = i;
        for( j = i+1; j < array_size; j++)
        {
            if(arreglo[j] < arreglo[minimo])
            {
                minimo = j;
            }
        }
        temporal = arreglo[i];
        arreglo[i] = arreglo[minimo];
        arreglo[minimo] = temporal;
    }

    for(int c = 0; c < array_size; c++)
    {
        cout<<arreglo[c]<<endl;
    }
}

void insertionSort(int arreglo[], int array_size)
{
    int a = 0, b = 0, temporal;

    while(a < array_size)
    {
        temporal = arreglo[a];
        b = a-1;
        while(b >= 0 && arreglo[b] > temporal)
        {
            arreglo[b+1] = arreglo[b];
            b--;
        }
        arreglo[b+1] = temporal;
        a++;
    }

    for(int s = 0; s < array_size; s++)
    {
        cout<<arreglo[s]<<endl;
    }
}

//      ------- FUNCIONES PARA EL HEAPSORT ------

void insertar(int* arreglo, int _size, int numero)
{
    arreglo[_size] = numero;

    while(arreglo[(_size-1)/2] < arreglo[_size])
    {
        int auxiliar = arreglo[(_size-1)/2];
        arreglo[(_size-1)/2] = arreglo[_size];
        arreglo[_size] = auxiliar;
        _size = (_size-1)/2;
    }
}

int eliminar(int* arreglo, int _size)
{
    int x = arreglo[0];
    arreglo[0] = arreglo[_size--];

    int elemento_movido = 0;
    int hijo_elemento_movido = 1;

    while(hijo_elemento_movido < elemento_movido)
    {
        if(hijo_elemento_movido+1 < _size && arreglo[hijo_elemento_movido+1] > arreglo[hijo_elemento_movido])
        {
            hijo_elemento_movido++;
        }

        if(arreglo[elemento_movido] < arreglo[hijo_elemento_movido])
        {
            int aux = arreglo[elemento_movido];
            arreglo[elemento_movido] = arreglo[hijo_elemento_movido];
            arreglo[hijo_elemento_movido] = aux;
            elemento_movido = hijo_elemento_movido;
            hijo_elemento_movido = 2*elemento_movido+1;
        }
        else{
            hijo_elemento_movido = _size;
        }
    }
    return x;
}

void heapSort(int* arreglo, int _size)
{
    int* copia_arreglo = new int[_size];

    for(int s = 0; s < _size; s++)
    {
        insertar(copia_arreglo, s, arreglo[s]);
    }

    for(int x = _size; x > 0; x--)
    {
        arreglo[x-1] = eliminar(arreglo, x);
    }
}

//      ------- FUNCIONES PARA EL HEAPSORT ------

int main()
{
//    int bubble[] = {0,30,70,28,14,105,15,33,57,16,98};
//    int size = (sizeof(bubble)/sizeof(bubble[0]));
//
    return 0;
}
