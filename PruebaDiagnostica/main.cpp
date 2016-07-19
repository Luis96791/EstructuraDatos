#include <iostream>

using namespace std;

//Ejercicio 1

//void ordenarArreglo(int arreglo[]){
//    int tamanio = 10, temporal;
//    int ordenado[tamanio];
//    for(int i = 0;i < tamanio; i++){
//        for(int j = 0; j < tamanio-1; j++){
//            if(ordenado > arreglo[j+1]){
//                temporal = ordenado;
//                arreglo=ordenado[i+1];
//                ordenado[j+1] = temporal;
//            }
//        }
//    }
//}

//Ejercicio 2

bool busquedaIterativa(int arreglo[], int num){
    int tamanio = 10;
    arreglo[tamanio];

    for(int c = 0; c < tamanio; c++){
        if(num == arreglo[c]){
            return true;
        }
    }
    return false;
}

//Ejercicio 3

bool busquedaRecursiva(int arreglo[], int num, int acumular){
    int tamanio = 10;
    arreglo[tamanio];

    if(acumular < tamanio){
        if(arreglo[acumular]==num){
            return true;
        }
        return busquedaRecursiva(arreglo,num, acumular+1);
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

int inicializar(int a){
    a = 100;
    return a;
}

//Ejercicio 6

int subFn(int n1, int n2){

}

int llamarSubFn(int* ptr, int n1, int n2){
    *ptr = subFn(n1, n2);
    return *ptr;
}


int main()
{
    simularCiclo(1,0,10);
    cout << inicializar(2) << endl;
    return 0;
}
