#include <iostream>
#include "MiArreglo.h"

using namespace std;

MiArreglo* miArreglo = new MiArreglo(10);

int main()
{
    miArreglo->insertar(2,10);
    miArreglo->insertar(4,20);
    miArreglo->insertar(6,30);
    miArreglo->imprimir();
    cout<<"---"<<endl;
    miArreglo->ordenar(10);
    miArreglo->eliminar(7);
    miArreglo->imprimir();
    cout<<"---"<<endl;
    cout<<miArreglo->buscar(350)<<endl;
    return 0;
}
