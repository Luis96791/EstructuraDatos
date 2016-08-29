#include "Item.h"

Item::Item(char* nombre, char* modelo)
{
    this->nombre = nombre;
    this->modelo = modelo;
}

Item::~Item()
{
    //dtor
}
