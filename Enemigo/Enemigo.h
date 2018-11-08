
#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <utility>
#include "Cola.h"
#include "Pila.h"
#include "AStarPathFinding.h"



class Enemigo
{
    public:
    Enemigo(){};
    Enemigo(int x, int y);
    int getPosX() const;
    void setEnemy( );// tiramos enemigo
    int getPosY() const;
   pair<int, int> revisaAtaque(int matriz[10][15]);

    bool atacando = false;



    private:
    int posX;
    int posY;
    int cont = 0;
    int vida = 7;
    int defensa = 5;
    int ataque = 5;
    int rango = 1;
};

#endif // ENEMIGO_H
