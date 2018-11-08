#ifndef SOLDADO_H
#define SOLDADO_H
#include <iostream>
#include <utility>
#include "Pila.h"
#include "Cola.h"




class Soldado
{

    public:
     //typedef pair <int, int> Pair;

    pair <int,int> Pair;
    Soldado(int x, int y);
    Soldado();
    void setIJ(int i, int j, int matriz[10][15]);
    void dibujarSoldado();
    void seguirRuta();
    Pair escogerPunto(int matriz[10][15], int xd, int yd);
    Pair atacar(int matriz [10][15]);



    private:
    int vida = 7;
    int xd, yd, tempX, tempY;
    bool llegue = false, flagAttack = false;
int freAtaque = 0;
};

#endif // SOLDADO_H
