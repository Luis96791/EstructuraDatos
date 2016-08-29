#include "TablaHash.h"

TablaHash::TablaHash()
{
    for(int i = 0; i < tamanio; i++)
    {
        hashTable[i] = new Item("vacio","vacio");
//        hashTable[i]->nombre = "vacio";
//        hashTable[i]->modelo = "vacio";
        hashTable[i]->siguiente = NULL;
    }
}

int TablaHash::Hash(char* llave)
{
    int hash = 0;
    int index = 0;

    while(llave[index] != '\0')
    {
        hash = hash +(int)llave[index];
        index++;
    }

    index = hash % tamanio;

    return index;
}

void TablaHash::agregarItem(char* nombre, char* modelo)
{
    int index = Hash(nombre);

    if(hashTable[index]->nombre == "vacio")
    {
        hashTable[index]->nombre = nombre;
        hashTable[index]->modelo = modelo;
    }
    else{
        Item* temp = hashTable[index];
        Item* nuevo = new Item(nombre,modelo);
        nuevo->nombre = nombre;
        nuevo->modelo = modelo;
        nuevo->siguiente = NULL;

        while(temp->siguiente != NULL)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

int TablaHash::numeroDeItemsPorIndex(int index)
{
    int contador = 0;

    if(hashTable[index]->nombre == "vacio")
    {
        return contador;
    }
    else{
        contador++;
        Item* temp = hashTable[index];

        while(temp->siguiente != NULL)
        {
            contador++;
            temp = temp->siguiente;
        }
    }
    return contador;
}

void TablaHash::imprimirTabla()
{
    int n_item;

    for(int c = 0; c < tamanio; c++)
    {
        n_item = numeroDeItemsPorIndex(c);
        cout<<"------------------"<<endl;
        cout<<hashTable[c]->nombre<<endl;
        cout<<hashTable[c]->modelo<<endl;
        cout<<"Numero de Item's: "<<n_item<<endl;
    }
}

void TablaHash::imprimirItemsPorIndex(int index)
{
    Item* temp = hashTable[index];

    if(temp->nombre == "vacio")
    {
        cout<<"Index: "<<index<<" esta vacio."<<endl;
    }
    else{
        cout<<"index: "<<index<<endl;
        while(temp != NULL)
        {
            cout<<"----------------"<<endl;
            cout<<temp->nombre<<endl;
            cout<<temp->modelo<<endl;
            temp = temp->siguiente;
        }
    }
}

Item* TablaHash::buscarItem(char* nombre)
{
    int index = Hash(nombre);

    Item* temp = hashTable[index];

    while(temp != NULL)
    {
        if(temp->nombre == nombre)
        {
            return temp;
        }
        temp = temp->siguiente;
    }
    return NULL;
}

void TablaHash::eliminarItem(char* nombre)
{
    int index = Hash(nombre);

    Item* temp;

    if(hashTable[index]->nombre == "vacio")
    {
        cout<<"No se encontro en esta lista"<<endl;
        return;
    }

    if(*hashTable[index]->nombre == *nombre && hashTable[index]->siguiente == NULL)
    {
        hashTable[index]->nombre = "vacio";
        hashTable[index]->modelo = "vacio";
        return;
    }

    if(*hashTable[index]->nombre == *nombre)
    {
        hashTable[index] = hashTable[index]->siguiente;
        return;
    }

    temp = hashTable[index];

    while(temp != NULL)
    {
        if(*temp->siguiente->nombre == *nombre)
        {
            *temp->siguiente = *temp->siguiente->siguiente;
            return;
        }
        temp = temp->siguiente;
    }
}

TablaHash::~TablaHash()
{
    //dtor
}
