#include "TextDisplay.h"

TextDisplay::TextDisplay()
{
    TEXT.setColor(sf::Color::Red);
    TEXT.setCharacterSize(50);
    TEXT.setPosition(300, 300);
    TEXT.setString(myString);
}



void TextDisplay::UpDate()
{

    TEXT.move(0, -movementSpeed);
    counter++;
    if(counter >= lifeTime)
    {
        Destroy = true;
    }

}
TextDisplay::~TextDisplay()
{
    //dtor
}
