#include <iostream>

using namespace std;

int main()
{
    int x = 25;
    cout << &x << endl;
    //sacando el espacio de memoria al cual se asigno la variable

    int t = 5;
    int *p, *q;

    p = &t; //se asigna a 'p' la direccion de 't'
    q = p; //se asigna a 'q' la direccion almacenada en 'p' (la mismade 't')

    cout<<p<<endl;
    cout<<q<<endl;
    cout<<t<<endl;

    return 0;
}
