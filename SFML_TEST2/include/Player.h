#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Animation.h"


class Player
{
    public:
        Player(sf::Texture* TEXTURE, sf::Vector2u ImageCount, float SwitchTime, float speed);
        virtual ~Player();
        void Update(float DeltaTime);
        void Draw(sf::RenderWindow& Window);

    protected:

    private:
    sf::RectangleShape Body;
    Animation ANIMATION;
    unsigned int row;
    float speed;
    bool FaceRight;
};

#endif // PLAYER_H
