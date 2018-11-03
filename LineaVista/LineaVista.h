#ifndef LINEAVISTA_H
#define LINEAVISTA_H

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string>
#include "Cola.h"

struct coordenada {
    int x = 0;
    int y = 0;
};

using namespace std;

class LineaVista {
private:
    coordenada destino;
    coordenada origen;

    Cola<pair<int, int>> *ruta = new Cola<pair<int, int >>;

public:
    Cola<pair<int, int >> lineaVista(int x, int y, int xd, int yd, int matix[15][27]);

private:

    void rodearObstaculo(coordenada *origen, coordenada destino, int matrix[15][27]);
    void buscarRuta(coordenada *ruta1, coordenada destino1, int matrix[15][27]);
    void buscarRuta(coordenada destino, coordenada origen, int matrix[15][27]);

};
bool operator==(coordenada a, coordenada b);

#endif // LINEAVISTA_H
