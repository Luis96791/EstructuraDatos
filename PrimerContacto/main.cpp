#include <iostream>

using namespace std;

int multiplicar(int n1, int n2){
    return n1*n2;
}

int main()
{
    int (*funcion)(int,int);
    funcion = &multiplicar;
    cout<<(*funcion)(3,3)<<endl;
    return 0;
}
