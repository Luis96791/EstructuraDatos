#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "Nodo.h"
#include <iostream>

using namespace std;

class HeapSort
{
    public:
        Nodo* nodos[10];
        HeapSort();
        void insertar(int n, int x);
        int eliminar(int n);
        void heapSort(int n);
        virtual ~HeapSort();

    protected:

    private:
};

#endif // HEAPSORT_H
