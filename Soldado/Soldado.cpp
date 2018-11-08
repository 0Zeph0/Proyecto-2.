
#include "Soldado.h"
#include "LineaVista.h"
#include "AStarPathFinding.h"
#include <utility>
#include <iostream>

/**
 * Construtuor con parametros
 * @param x posicion horizontal donde se dibujara el soldado la primera vez
 * @param y posicion vertical donde se dibujara el soldado la primera vez
 */

typedef pair<int, int> Pair;
Soldado::Soldado(int x , int y) {

    this->tempX = x;
    this->tempY = y;
    xd = tempX;
    yd = tempY;
    //Sprite::dibujaPersonaje(192, 644, image, 3);
}
/**
 * Constructor
 */
Soldado::Soldado() {}

/**
 * Insertar posiciones a cada soldado
 * @param i
 * @param j
 * @param matriz
 */
void Soldado::setIJ(int i, int j, int matriz[10][15]) {

    //calcular Ruta
    Pair posff = escogerPunto(matriz,i,j);
    AstarPathfinding AStar = AstarPathfinding();
    ruta2 = AStar.busquedaAStar(matriz, make_pair(yd/70, xd/90), posff);
    Application::matriz[posff.first][posff.second] = 4;
}
/**
 * Toma la ruta punto a punto dada por el algoritmo de busquedad
 */
void Soldado::seguirRuta(){
    if(ruta2.getLenght() > 0) {
        if (this->llegue) {
            Pair coorTemp = ruta2.pop();
            xd = coorTemp.second * 90;
            yd = coorTemp.first * 70;
            this->llegue = false;
        }
    }
}

/**
 * Escoge un punto libre los mas cercano al punto seleccionado por el jugador
 * @param matriz
 * @param id  Punto de destino
 * @param jd Punto de destino
 * @return Punto escogido
 */
Pair Soldado::escogerPunto(int matriz[10][15], int id, int jd) {
    if(matriz[id][jd] == 1){
        return make_pair(id,jd);
    }
    int a=3, b=3;
    while(true){
        cout<<"0"<< endl;
        id -=1;
        jd -=1;
        try {
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j) {
                    if ((id + i) < 0) {
                        cout<<"1"<< endl;
                        id = 0;
                    }
                    if ((id + i )> 9) {
                        cout<<"2"<< endl;
                        id -= abs((i + 1));
                    }
                    if ((jd + j) < 0) {
                        cout<<"3"<< endl;
                        jd = 0;
                    }
                    if ((jd + j) > 14) {
                        cout<<"4"<< endl;
                        jd = abs(jd - (j + 1));
                    }
                    if (matriz[abs(id + i)][abs(jd + j)] == 1) {
                        return make_pair(id + i, jd + j);
                    }
                }
            }
        }
        catch(...) { }
        a++,b++;
    }
}
/**
 * Realiza el efecto caminar de punto a punto dados por el algoritmo de busqueda
 */
void Soldado::dibujarSoldado() {
    seguirRuta();
    //image = al_load_bitmap("../img/soldier.png");

    if(tempX == xd && tempY == yd){
        this->llegue = true;
        if(flagAttack){
            //image = al_load_bitmap("../img/enemy.png");
        }
    }
    else if(xd > tempX && yd > tempY){
        tempX += 5;
        tempY += 5;
    }
    else if(xd < tempX && yd < tempY){
        tempX -= 5;
        tempY -= 5;
    }
    else if(xd > tempX && yd < tempY){
        tempX += 5;
        tempY -= 5;
    }
    else if(xd < tempX && yd > tempY){
        tempX -= 5;
        tempY += 5;
    }
    else if(xd > tempX){
        tempX += 5;
    }
    else if(xd < tempX){
        tempX -= 5;
    }
    else if(yd > tempY){
        tempY += 5;
    }
    else if(yd < tempY){
        tempY -= 5;
    }

    Application::matriz[yd/70][xd/90] = 3;
}
/**
 * Revida si es posible atacar a un enemgio dentro del rango
 * @param matriz
 * @return Posicion a la que ataco
 */
pair<int, int> Soldado::atacar(int matriz[10][15]) {
    if (this->freAtaque > 20 && this->freAtaque > 10){
        this->freAtaque = 0;
    }
    this->freAtaque++;
    if(this->freAtaque < 10) {
        int i = (yd / 70) - 1, j = (xd / 90) - 1;
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                if (matriz[abs(i + k)][abs(j + l)] == 2) {
                    flagAttack = true;
                    return make_pair(abs(i + k), abs(j + l));
                }
            }
        }
    }
    flagAttack = false;
    return make_pair(-1,-1);
}

