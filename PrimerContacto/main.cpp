#include <iostream>

using namespace std;

int main()
{
    int x = 25;
//    cout << &x << endl;
    //sacando el espacio de memoria al cual se asigno la variable

//    int t = 5;
    int *p, *q;

//    p = &t; //se asigna a 'p' la direccion de 't'
    q = p; //se asigna a 'q' la direccion almacenada en 'p' (la misma de 't')


    int t = 5; //asignando un valor a la variable
//    cout<<&t<<endl; //sacamos la direccion en memoria

    p = &t; //con el ampersand asignamos la direccion en memoria de 't' a 'p'
    cout<<*p<<endl;//otra manera de obtener la direccion en memoria de 't'

    return 0;
}
