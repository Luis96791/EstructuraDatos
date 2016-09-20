#include <iostream>
#include "TablasHash.h"

using namespace std;

int main()
{
    TablasHash* tablaHash = new TablasHash;

    cout<<tablaHash->hashing(357812991881)<<endl;
    return 0;
}
