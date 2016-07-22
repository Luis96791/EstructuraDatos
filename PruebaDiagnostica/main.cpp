#include <iostream>

using namespace std;

//Ejercicio 1

int ordenar(int arreglo[], int array_size)
{
    int t, r, a;

    for(t = 0; t < array_size; t++)
    {
        for( r = 0; r < array_size-1; r++)
        {
            if(arreglo[r] > arreglo[r+1])
            {
                a = arreglo[r];
                arreglo[r] = arreglo[r+1];
                arreglo[r+1] = a;
            }
        }
    }
    return 0;
}

//Ejercicio 2

bool busquedaIterativa(int arreglo[], int num, int tamanio){

    for(int c = 0; c < tamanio; c++){
        if(num == arreglo[c]){
            return true;
        }
    }
    return false;
}

//Ejercicio 3

bool busquedaRecursiva(int arreglo[], int num, int acumular, int tamanio){

    if(acumular < tamanio){
        if(arreglo[acumular]==num){
            return true;
        }
        return busquedaRecursiva(arreglo,num, acumular+1, tamanio);
    }
    return false;
}

//Ejercicio 4

int simularCiclo(int inicio, int incremento, int fin)
{
    if(inicio >= 0)
    {
        if(incremento <= fin){
            cout<<incremento<<endl;
            return simularCiclo(inicio, incremento+1,fin);
        }
    }
    return 0;
}

//Ejercicio 5

int inicializar(int* a){
    int n = 100;
    a = &n;
    return *a;
}

//Ejercicio 6

int subFn(int n1, int n2){
    n1 = 2;
    n2 = 4;
    return n1, n2;
}

int llamarSubFn(int (*ptr) (int, int), int n1, int n2){

}


int main()
{
    int (*fptr)(int,int);
    fptr = subFn;
    llamarSubFn(fptr,4,5);
    cout<<fptr(2,1)<<endl;
    int num = 5;
    simularCiclo(1,1,10);
    cout << inicializar(&num) << endl;
    return 0;
}
