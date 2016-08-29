#include <iostream>

using namespace std;

void llenarTablero(char arreglo[4][4])
{
    for(int n = 0; n < 4; n++)
    {
        for(int s = 0; s < 4; s++)
        {
            arreglo[n][s] = '_';
        }
    }
}

void imprimir(char arreglo[4][4])
{
    for(int n = 0; n < 4; n++)
    {
        for(int s = 0; s < 4; s++)
        {
            cout<<arreglo[n][s]<<" ";
        }
        cout<<'\n';
    }
}

void ingresarReina(char arreglo[4][4], int x, int y)
{
    arreglo[x-1][y-1] = 'R';
}

int bloqueoHorizontal(char arreglo[4][4])
{

}

int main()
{
    int posX, posY;
    char tablero[4][4];
    llenarTablero(tablero);
    imprimir(tablero);
    cout<<"Pos en X: ";
    cin>>posX;
    cout<<"Pos en Y: ";
    cin>>posY;
    ingresarReina(tablero,posX,posY);
    imprimir(tablero);
    return 0;
}
