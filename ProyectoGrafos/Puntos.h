#ifndef PUNTOS_H
#define PUNTOS_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Puntos
{
    public:
        sf::Texture texture;
        sf::Sprite sprite;
        char* nombre_punto;
        Puntos();
        virtual ~Puntos();

    protected:

    private:
};

#endif // PUNTOS_H
