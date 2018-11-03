#ifndef DIJKSTRA_H
#define DIJKSTRA_H


#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define ColumnasMapa 25
#define FilasMapa 50

const double INF = 99999.0;
const double DIAGONAL = 1.42412;

using namespace std;

struct Vertice{
    double distancia;
    int posicionX;
    int posicionY;
    bool visitado;
};

class Dijkstra {
private:
    vector<Vertice> verticesMapa[FilasMapa*ColumnasMapa];
    vector<Vertice> verticesPendientes[FilasMapa*ColumnasMapa];
    vector<Vertice> ruta[1];
    int contador = 0;

    bool definirCentro(int x,int y);

    void EvaluarVecinos(int posicionX, int posicionY, double peso);

    Vertice RetornaVecinoMenor(int posicionX, int posicionY, double peso);


public:
    Dijkstra(int mapa[FilasMapa][ColumnasMapa]);

    Dijkstra(){}

    void DefinirPesos(int x, int y);

    int DefinirRutaOptima(int x, int y);

    Vertice obtenerSiguienteVertice();

};


#endif // DIJKSTRA_H
