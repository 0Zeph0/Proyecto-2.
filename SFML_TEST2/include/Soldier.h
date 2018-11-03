#ifndef SOLDIER_H
#define SOLDIER_H
#include "Entity.h"


class Soldier : public Entity
{
    public:
        Soldier(float X, float Y);
        virtual ~Soldier();

        void UpDate();
        void UpDateMovement();
        void MouseClick(float Xini, float Yini, float goalX, float goalY);
        float getPosX();
        float getPosY();
        void setHP(int vida);
        void setATK(int ataque);
    public:
        float movementSpeed = 1.5;
        int ATK = 5;
        int HP = 20;
        int counterWalking = 0;
        float X = 0.0f;
        float Y = 0.0f;
        int direction = 0; /// 1 = up, 2 = down, 3 = left, 4 = right

    protected:

    private:

};

#endif // SOLDIER_H
