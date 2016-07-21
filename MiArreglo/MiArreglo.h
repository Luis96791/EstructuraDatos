#ifndef MIARREGLO_H
#define MIARREGLO_H
#include <iostream>

using namespace std;

class MiArreglo
{
    public:
        int arreglo[];
        MiArreglo(int tam);
        void insertar(int pos, int num);
        void imprimir();
        void eliminar(int pos);
        bool buscar(int num);
        void llenar();
        int ordenar(int tamanio);
        virtual ~MiArreglo();

    protected:

    private:
};

#endif // MIARREGLO_H
