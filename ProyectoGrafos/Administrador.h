#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>

#include "Utility.h"
#include "Puntos.h"
#include "Rutas.h"

using namespace std;

class Administrador
{
    public:
        Puntos* puntos[15];
        Rutas* ruta = new Rutas;
        Utility* utility;
        bool llenar = false;
        Administrador();
        void ventanaPrincipal();
        void dibujarPuntos(sf::Texture texture[], sf::Sprite sprite[]);
        void crearRuta();
        void ventanaConsultarCaminos();
        void imprimeCaminos();
        void dibujarAristas(char* nombre_punto1, char* nombre_punto2);
        void drawLineas();
        virtual ~Administrador();

    protected:

    private:
};

#endif // ADMINISTRADOR_H
