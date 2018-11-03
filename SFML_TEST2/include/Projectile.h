#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Entity.h"


class Projectile : public Entity
{
    public:
        Projectile();
        virtual ~Projectile();
        void Update();
    public:
        int movementSpeed = 10;
        int ATK = 5;
        int direction = 0;
        bool Destroy = false;
        int counterLifetime = 0;
        int Lifetime = 60; //tiempo o distancia de vida de las balas...
        int counterAnimation = 0;

    protected:

    private:
};

#endif // PROJECTILE_H
