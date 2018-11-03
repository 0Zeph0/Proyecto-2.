#include "Soldier.h"

Soldier::Soldier(float X, float Y)
{
    this->X = X;
    this->Y = Y;
    RECT.setSize(sf::Vector2f(32,48));
    RECT.setFillColor(sf::Color::Blue);
    RECT.setPosition(X, Y);
    SPRITE.setTextureRect(sf::IntRect(0, 48 * 2, 32, 48));

}


void Soldier::UpDate(){

    SPRITE.setPosition(RECT.getPosition());
}

void Soldier::UpDateMovement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

        RECT.move(0, -movementSpeed);
        SPRITE.setTextureRect(sf::IntRect(counterWalking * 32, 48 * 3, 32, 48));
        direction = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

        RECT.move(0, movementSpeed);
        SPRITE.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 48));
        direction = 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){

        RECT.move(-movementSpeed, 0);
        SPRITE.setTextureRect(sf::IntRect(counterWalking * 32, 48 * 1, 32, 48));
        direction = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

        RECT.move(movementSpeed, 0);
        SPRITE.setTextureRect(sf::IntRect(counterWalking * 32, 48 * 2, 32, 48));
        direction = 4;
    }
    counterWalking++;
    if(counterWalking == 3){

        counterWalking = 0;
    }
}

float Soldier::getPosX(){

    return X;
}
float Soldier::getPosY(){

    return Y;
}

void Soldier::setATK(int ataque){

    this->ATK = ataque;
}

void Soldier::setHP(int vida){

    this->HP = vida;
}

void Soldier::MouseClick(float Xini, float Yini, float goalX, float goalY){

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(Xini < goalX){
        RECT.move(0.1,0);
        SPRITE.setTextureRect(sf::IntRect(0 * 32, 48 * 2, 32, 48));
        Xini = Xini + 500;
        }


    }
}






Soldier::~Soldier()
{
    //dtor
}
