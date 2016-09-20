#include "TablasHash.h"

TablasHash::TablasHash()
{
    for(int x = 0; x < tamanio; x++)
    {
        tabla[x] = new Item(-1, NULL);
        tabla[x]->siguiente = NULL;
    }
}

int TablasHash::hashing(int id)
{
    int index = 0;

    /**
        Tomado del libro: Estructura de Datos y Algoritmos de Aho, Hopcroft and Ullman
        Seccion 4.8 página 131

        Funcíon: h(n) = [n^2/C] % B

        En este caso n sería el id el cual se eleva al cuadrado y se divide en este caso
        decidí dividirlo entre el doble del tamaño (en la definición dice que C puede ser
        un numero al azar) al resultado de estas dos operaciones se le saca el residuo
        con esta estrategia se evita que el residuo sea siempre el ultimo numero de la serie
        cuando el divisor sea potencia de 10.
        Esta función busca que el hashing sea mas aleatorio.

        Desventaja: con numeros bastante grandres el proceso de compilacion es mas lento y a veces
        lanza numeros negativos.
    **/

    index = ((id*id)/(tamanio*2)) % tamanio;

//    para que siempre sea positivo

    if(index <= -1)
    {
        index = index*-1;
    }
//    siempre sera el ultimo de la serie
//    index = id % tamanio;

    return index;
}

void TablasHash::agregar(int id, char* nombre)
{
    int index = hashing(id);

    if(tabla[index]->id == -1)
    {
        tabla[index]->id = id;
        tabla[index]->nombre = nombre;
    }
    else{
        Item* temp = tabla[index];
        Item* nuevo = new Item(id,nombre);
        nuevo->siguiente = NULL;

        while(temp->siguiente != NULL)
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
        delete temp;
        delete nuevo;
    }
}

int TablasHash::celdasDisponibles()
{
    int contador = tamanio;

    for(int c = 0; c < tamanio; c++)
    {
        if(tabla[c]->id != -1)
        {
            contador--;
        }
    }
    return contador;
}

void TablasHash::duplicarCapacidad()
{
    if(celdasDisponibles() != 0){return;}

    Item* temporal[tamanio];

    for(int c = 0; c < tamanio; c++)
    {
        temporal[c] = new Item(tabla[c]->id, tabla[c]->nombre);
    }
    tabla[tamanio*2];

    for(int n = 0; n < tamanio; n++)
    {
        tabla[n] = new Item(temporal[n]->id, temporal[n]->nombre);
    }
    tamanio = tamanio*2;

    delete temporal;
}

Item* TablasHash::buscar(int id)
{
    int index = hashing(id);

    Item* temp = tabla[index];

    while(temp != NULL)
    {
        if(temp->id == id)
        {
            return temp;
        }
        temp = temp->siguiente;
    }
    return NULL;
}

void TablasHash::eliminar(int id)
{
    int index = hashing(id);

    Item* temp;

    if(tabla[index]->id == -1)
    {
        cout<<id<<" No Existe"<<endl;
        return;
    }

    if(tabla[index]->id == id && tabla[index]->siguiente == NULL)
    {
        tabla[index]->id = -1;
        tabla[index]->nombre = NULL;
        return;
    }

    if(tabla[index]->id == id)
    {
        tabla[index] = tabla[index]->siguiente;
        return;
    }

    temp = tabla[index];

    while(temp != NULL)
    {
        if(temp->siguiente->id == id)
        {
            *temp->siguiente = *temp->siguiente->siguiente;
            return;
        }
        temp = temp->siguiente;
    }
}

TablasHash::~TablasHash()
{
    delete tabla;
}
