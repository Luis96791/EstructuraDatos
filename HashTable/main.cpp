#include <iostream>
#include <stdio.h>
#include "TablaHash.h"
#include "Item.h"

using namespace std;

int main()
{
    char index[10];
    TablaHash* tablaHash = new TablaHash;
    Item* item = new Item("","");

    tablaHash->agregarItem("Carlos","Samsung S3");
    tablaHash->agregarItem("Jose","Samsung S4");
    tablaHash->agregarItem("Luis","Samsung S5");
    tablaHash->agregarItem("Alfredo","Samsung S6");
    tablaHash->agregarItem("Maria","Samsung S6E");
    tablaHash->agregarItem("Damaris","Samsung S3");
    tablaHash->agregarItem("Sofia","Samsung S4");
    tablaHash->agregarItem("Antonieta","Samsung S5");
    tablaHash->agregarItem("Marlon","Samsung S6");
    tablaHash->agregarItem("Sergio","Samsung S6E");


//    tablaHash->imprimirTabla();
//
//    item = tablaHash->buscarItem("Sergio");
//
//    cout<<"Nombre: "<<item->nombre<<endl;
//    cout<<"Modelo: "<<item->modelo<<endl;
//
//
//    while(true)
//    {
//        cout<<"A eliminar: ";
//        cin>>index;
//        char* index1 = index;
//        tablaHash->eliminarItem(index1);
//        tablaHash->imprimirTabla();
//
//    }

    return 0;
}
