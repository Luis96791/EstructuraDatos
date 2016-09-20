#ifndef TABLASHASH_H
#define TABLASHASH_H
#include <iostream>
#include "Item.h"

using namespace std;

class TablasHash
{
    public:
        Item* tabla[10];
        int tamanio = (sizeof(tabla)/sizeof(tabla[0]));
        TablasHash();
        int hashing(int id);
        void agregar(int id, char* nombre);
        Item* buscar(int id);
        void eliminar(int id);
        void duplicarCapacidad();
        int celdasDisponibles();
        virtual ~TablasHash();

    protected:

    private:
};

#endif // TABLASHASH_H
