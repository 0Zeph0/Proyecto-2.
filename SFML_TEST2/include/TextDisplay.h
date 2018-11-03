#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "Entity.h"
#include <string>
using namespace std;
#include <iostream>

class TextDisplay : public Entity
{
    public:
        TextDisplay();
        virtual ~TextDisplay();
        void UpDate();
    public:
        string myString = "Ajio";
        float movementSpeed = 3;
        int counter = 0;
        bool Destroy = false;
        int lifeTime = 40;


    protected:

    private:
};

#endif // TEXTDISPLAY_H
