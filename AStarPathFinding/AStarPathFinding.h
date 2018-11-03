#ifndef ASTARPATHFINDING_H
#define ASTARPATHFINDING_H
#include<iostream>
#include<bits/stdc++.h>

#define FILA 5
#define COLUMNA 5
using namespace std;


 typedef pair<int, int> Pair;

typedef pair<double, pair<int, int> > pPair;

struct celda{
    int parent_i, parent_j;
    double f, g, h;
};
class AStarPathFinding
{
    public:
            AStarPathFinding();
            virtual ~AStarPathFinding();

            bool esValido(int fila, int columna);
            bool estaDesbloqueda(int grid[][COLUMNA], int fila, int columna);
            bool esDestino(int fila, int columna, Pair destino);
            double calcularValorH(int fila, int columna, Pair destino);
            void trazarCamino(celda detallesCelda[][COLUMNA], Pair destino);
            void busquedaAStar(int grid[][COLUMNA], Pair inicio, Pair destino);

};

#endif // ASTARPATHFINDING_H
