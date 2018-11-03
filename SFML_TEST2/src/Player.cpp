#include "Player.h"

Player::Player(sf::Texture* TEXTURE, sf::Vector2u ImageCount, float SwitchTime, float speed) : ANIMATION(TEXTURE, ImageCount, SwitchTime)
{
    this->speed = speed;
    row = 0;
    FaceRight = true;

    Body.setSize(sf::Vector2f(25.0f, 36.0f));
    Body.setPosition(0.0f, 550.0f);
    Body.setTexture(TEXTURE);
}

void Player::Update(float DeltaTime){

    sf::Vector2f movement(0.0f, 0.0f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= speed * DeltaTime;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += speed * DeltaTime;

    if(movement.x == 0.0f){

        row = 2;
    }
    else{

        row - 1;
            if( movement.x > 0.0f)
                FaceRight = true;
            else
                FaceRight = false;

    }
    ANIMATION.UpDate(row, DeltaTime, FaceRight);
    Body.setTextureRect(ANIMATION.uvRect);
    Body.move(movement);
}

void Player::Draw(sf::RenderWindow& Window){

    Window.draw(Body);
}

Player::~Player()
{
    //dtor
}
