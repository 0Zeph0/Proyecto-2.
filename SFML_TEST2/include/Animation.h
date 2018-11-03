#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>


class Animation
{
    public:
        Animation(sf::Texture* TEXTURE, sf::Vector2u ImageCount, float SwitchTime);
        virtual ~Animation();
        void UpDate(int row, float DeltaTime, bool FaceRight);

        sf::IntRect uvRect;

    protected:

    private:

        sf::Vector2u ImageCount;
        sf::Vector2u CurrentImage;

        float TotalTime;
        float SwitchTime;
};

#endif // ANIMATION_H
