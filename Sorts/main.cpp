#include <iostream>

using namespace std;

//  Metodo Burbuja Descendente con int's

int bubbleSortDescendente(int arreglo[], int array_size)
{
    int i, j, temp;

    for(i = array_size-1; i >= 0; i--)
    {
        for(j = 1; j <= i; j++)
        {
            if(arreglo[j-1] > arreglo[j])
            {
                temp = arreglo[j-1];
                arreglo[j-1] = arreglo[j];
                arreglo[j] = temp;
            }
        }
        cout<<arreglo[i]<<endl;
    }
    return 0;
}

//  Metodo Burbuja Ascendente con int's

int bubbleSortAscendente(int arreglo[], int array_size)
{
    int i, j, temp;

    for(i = 0; i < array_size; i++)
    {
        for( j = 0; j < array_size-1; j++)
        {
            if(arreglo[j] > arreglo[j+1])
            {
                temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            }
        }
        cout<<arreglo[i]<<endl;
    }
    return 0;
}

int main()
{
    int bubble[] = {30,70,28,14,15,33,57,16,98};
    cout<<"BubbleSort Descendente"<<endl;
    bubbleSortDescendente(bubble, 9);
    cout<<"BubbleSort Ascendente"<<endl;
    bubbleSortAscendente(bubble, 9);
    return 0;
}
