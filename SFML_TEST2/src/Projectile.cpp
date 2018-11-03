#include "Projectile.h"

Projectile::Projectile()
{
    RECT.setSize(sf::Vector2f(32,32));
    RECT.setFillColor(sf::Color::Green);
    RECT.setPosition(0, 0);
    SPRITE.setTextureRect(sf::IntRect(0,0,32,32));
}

//esta wea es para la direccion de la bala...
void Projectile::Update()
{
    if(direction == 1) //up
    {
        RECT.move(0, -movementSpeed);
        SPRITE.setTextureRect(sf::IntRect(counterAnimation * 28, 3 * 32, 29, 32));

    }
    if(direction == 2) //down
    {
        RECT.move(0, movementSpeed);
        SPRITE.setTextureRect(sf::IntRect(counterAnimation * 28, 0, 29, 32));
    }
    if(direction == 3) //left
    {
        RECT.move(-movementSpeed, 0);
        SPRITE.setTextureRect(sf::IntRect(counterAnimation * 28, 1 * 32, 29, 32));
    }
    if(direction == 4) //right
    {
        RECT.move(movementSpeed, 0);
        SPRITE.setTextureRect(sf::IntRect(counterAnimation * 28, 2 * 32, 29, 32));
    }
    counterLifetime++;
    if(counterLifetime >= Lifetime){

        Destroy = true;
    }
    counterAnimation++;
    if(counterAnimation >= 2){

        counterAnimation = 0;
    }

    SPRITE.setPosition(RECT.getPosition());


}
Projectile::~Projectile()
{
    //dtor
}
