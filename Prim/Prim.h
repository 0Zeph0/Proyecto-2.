#ifndef PRIM_H
#define PRIM_H
#include <vector>
#include <climits>
#include "ListaSimple.h"
#include "Graph.h"
#include "Pila.h"
#include<bits/stdc++.h>
using namespace std;


struct Path {
    Path() {

    }

    Path(int row, int column, int prevRow, int prevColumn) {
        this->row = row;
        this->column = column;
        this->prevRow = prevRow;
        this->prevColumn = prevColumn;
    }

    int row, column, prevRow, prevColumn;
};

class Prim {
private:
    Graph graph;
    ListaSimple<Vertex> visited;



    Pila<pair<int, int>> queueGenerator(int row, int column, int destRow, int destColumn, ListaSimple<Path> cola);

    bool isVisited(Vertex vertex);

    Path findPrevPath(int prevRow, int prevColumn, ListaSimple<Path> path);

public:
//    Pila<pair<int, int>> queueGenerator(int row, int column, int destRow, int destColumn, ListaSimple<Path> cola);

    Pila<pair<int, int>> primAlgorithm(int currentRow, int currentColumn, int destRow, int destColumn, Graph graph);
};

#endif // PRIM_H
