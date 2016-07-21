#include "MiArreglo.h"

MiArreglo::MiArreglo(int tam)
{
    arreglo[tam];
    llenar();
}

void MiArreglo::insertar(int pos, int num)
{
    arreglo[pos] = num;
}

void MiArreglo::imprimir()
{
    for(int n = 0; n < 10; n++){
        cout<<arreglo[n]<<endl;
    }
}

void MiArreglo::eliminar(int pos)
{
    arreglo[pos] = 0;
}

bool MiArreglo::buscar(int num)
{
    for(int n = 0; n < 10; n++){
        if(arreglo[n] == num){
            return true;
        }
    }
    return false;
}

void MiArreglo::llenar()
{
     for(int n = 0; n < 10; n++){
        arreglo[n] = 0;
    }
}

int MiArreglo::ordenar(int tamanio)
{
    int i, j, temp;

    for(i = 0; i < tamanio; i++)
    {
        for( j = 0; j < tamanio-1; j++)
        {
            if(arreglo[j] > arreglo[j+1])
            {
                temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            }
        }
    }
    return 0;
}


MiArreglo::~MiArreglo()
{
    //dtor
}
