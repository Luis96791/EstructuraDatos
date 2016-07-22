#include <iostream>

using namespace std;

int miArreglo[10];

int tamanio(){
    return (sizeof(miArreglo)/sizeof(int));
}

void llenar(){
    for(int c = 0; c < tamanio(); c++){
        miArreglo[c] = 0;
    }
}

void imprimir(){
    for(int n = 0; n < tamanio(); n++){
        cout<<miArreglo[n]<<endl;
    }
}

void insertar(int pos, int num){
    miArreglo[pos] = num;
}

//aprendiendo un nuevo tipo de busqueda :)

bool busqueda(int num){
    int inicio = 0;
    int fin = tamanio();
    int centro;

    while(inicio <= fin){
        centro = ((inicio+fin)/2);
        if(miArreglo[centro]==num){
            return true;
        }else if(miArreglo[centro]>num){
            fin = centro;
            centro = (inicio + fin)/2;
        }else if(miArreglo[centro]<num){
            inicio = centro;
            centro = (inicio + fin)/2;
        }
        if(centro == 0){
            return false;
        }
    }
}

bool eliminar(int num)
{
    for(int c  = 0; c < tamanio(); c++){
        if(miArreglo[c]== num){
            miArreglo[c] = 0;
            return true;
        }
    }
    return false;
}

ordenar(int tamanio)
{
    int i, j, temp;

    for(i = 0; i < tamanio; i++)
    {
        for( j = 0; j < tamanio-1; j++)
        {
            if(miArreglo[j] > miArreglo[j+1])
            {
                temp = miArreglo[j];
                miArreglo[j] = miArreglo[j+1];
                miArreglo[j+1] = temp;
            }
        }
    }
    return 0;
}

int main()
{
    llenar();

    insertar(0,80);
    insertar(2,20);
    insertar(4,70);
    insertar(5,66);
    insertar(8,75);

    imprimir();
    cout<<"--"<<endl;

    //-----------------------------

    if(busqueda(0)){
        cout<<"Existe"<<endl;
    }else{
        cout<<"No Existe"<<endl;
    }

    if(eliminar(80)){
        cout<<"Eliminado"<<endl;
    }
    ordenar(tamanio());
    imprimir();
    return 0;
}
