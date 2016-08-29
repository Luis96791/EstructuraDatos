#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;

//Usuario Samsung, modelo telefono

class Item
{
    public:
        char* nombre;
        char* modelo;
        Item* siguiente = NULL;
        Item(char* nombre, char* modelo);
        virtual ~Item();

    protected:

    private:
};

#endif // ITEM_H
