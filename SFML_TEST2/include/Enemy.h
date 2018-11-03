#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include "Random.h"

class Enemy : public Entity
{
    public:
        Enemy();
        virtual ~Enemy();
        void UpDate();
        void UpDateMovement();

    public:
        int X;
        int Y;
        int ATK = 2;
        int HP = 50;
        int ChangeTime = 1;
        int Direction = 0; /// 1=up, 2=down, 3=left, 4=right.
        int counterWalking = 0;
        int counter = 0;
        int movementLength = 20;
        bool Vivo = true;

    protected:

    private:
};

#endif // ENEMY_H
