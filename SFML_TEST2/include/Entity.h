#ifndef ENTITY_H
#define ENTITY_H
#include "stdio.h"
#include <SFML/Graphics.hpp>



class Entity
{
    public:
        Entity();
        virtual ~Entity();
        sf::RectangleShape RECT;
        sf::Sprite SPRITE;
        sf::Text TEXT;


    protected:

    private:
};

#endif // ENTITY_H
