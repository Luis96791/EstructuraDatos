#include <iostream>
#include <SFML/Graphics.hpp>
#include "Administrador.h"
#include "Rutas.h"

using namespace std;

int main()
{
    Administrador* admin = new Administrador;

    admin->ventanaPrincipal();
    return 0;
}
