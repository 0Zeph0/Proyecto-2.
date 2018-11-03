#include "Enemy.h"

Enemy::Enemy()
{
    //X = 500 + rand()%(1001 - 500);
    //Y = 350 + rand()%(701 - 350);
    RECT.setSize(sf::Vector2f(32,48));
    RECT.setFillColor(sf::Color::Blue);
    RECT.setPosition(500, 600);
    SPRITE.setTextureRect(sf::IntRect(0, 0 * 2, 32, 48));
}

void Enemy::UpDate(){

    SPRITE.setPosition(RECT.getPosition());
}



void Enemy::UpDateMovement()
{
    if (Direction == 1){ ///up

        //RECT.move(0, -movementSpeed);
        SPRITE.setTextureRect(sf::IntRect(0, 48 * 3, 32, 48));
        Direction = 1;
    }
    else if (Direction == 2){ ///down

        //RECT.move(0, movementSpeed);
        SPRITE.setTextureRect(sf::IntRect(0, 0, 32, 48));
        Direction = 2;
    }
    else if (Direction == 3){ ///left

        //RECT.move(-movementSpeed, 0);
        SPRITE.setTextureRect(sf::IntRect(0, 48 * 1, 32, 48));
        Direction = 3;
    }
    else if (Direction == 4){ ///right

        //RECT.move(movementSpeed, 0);
        SPRITE.setTextureRect(sf::IntRect(0, 48 * 2, 32, 48));
        Direction = 4;
    }

    else {}


    counterWalking++;
    if(counterWalking == 1){

        counterWalking = 0;
    }
    counter++;
    if(counter >= movementLength){

        Direction = generateRandom(10);
        counter = 0;
    }
}

Enemy::~Enemy()
{
    //dtor
}
