#ifndef UTILITY_H
#define UTILITY_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Utility
{
    public:
        Utility();
        bool clickSprite(sf::Sprite sprite, sf::Vector2f mouse);
        bool compareTo(char* cadena1, char* cadena2);
        string toString(int num);
        virtual ~Utility();

    protected:

    private:
};

#endif // UTILITY_H
