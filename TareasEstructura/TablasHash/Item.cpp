#include "Item.h"

Item::Item(int id, char* nombre)
{
    this->id = id;
    this->nombre = nombre;
}

Item::~Item()
{
    //dtor
}
