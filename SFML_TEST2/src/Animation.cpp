#include "Animation.h"

Animation::Animation(sf::Texture* TEXTURE, sf::Vector2u ImageCount, float SwitchTime)
{
    this->ImageCount = ImageCount;
    this->SwitchTime = SwitchTime;
    TotalTime = 0.0f;
    CurrentImage.x = 0;

    uvRect.width = int(TEXTURE->getSize().x / float(ImageCount.x));
    uvRect.height = int(TEXTURE->getSize().y / float(ImageCount.y));
}

void Animation::UpDate(int row, float DeltaTime, bool FaceRight){

    CurrentImage.y = row;
    TotalTime += DeltaTime;

    if(TotalTime >= SwitchTime){

        TotalTime -= SwitchTime;
        CurrentImage.x++;

        if(CurrentImage.x >= ImageCount.x){

            CurrentImage.x = 0;
        }
    }

    uvRect.top  = CurrentImage.y * uvRect.height;

    if(FaceRight){

        uvRect.left = CurrentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }
    else{

        uvRect.left = (CurrentImage.x+1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}

Animation::~Animation()
{
    //dtor
}
