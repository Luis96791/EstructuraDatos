#include "Utility.h"

Utility::Utility()
{
    //ctor
}

bool Utility::clickSprite(sf::Sprite sprite, sf::Vector2f mouse)
{
    sf::FloatRect bounds = sprite.getGlobalBounds();

    if(bounds.contains(mouse))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            return true;
        }
    }
    return false;
}

bool Utility::compareTo(char* cadena1, char* cadena2)
{
    int cont = 0;
    while(cadena2[cont] != NULL)
    {
        if(cadena1[cont] == cadena2[cont])
        {
            cont++;
        }
        else{
            return false;
        }
    }
    return true;
}

Utility::~Utility()
{
    //dtor
}
