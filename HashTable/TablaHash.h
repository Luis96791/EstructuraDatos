#ifndef TABLAHASH_H
#define TABLAHASH_H
#include "Item.h"
#include <iostream>

using namespace std;

class TablaHash
{
     private:
        static const int tamanio = 10;
        Item* hashTable[tamanio];

    public:

        TablaHash();
        int Hash(char* llave);
        void agregarItem(char* nombre, char* modelo);
        int numeroDeItemsPorIndex(int index);
        void imprimirTabla();
        void imprimirItemsPorIndex(int index);
        Item* buscarItem(char* nombre);
        void eliminarItem(char* nombre);
        virtual ~TablaHash();

    protected:
};

#endif // TABLAHASH_H
