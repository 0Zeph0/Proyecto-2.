#ifndef KRUSCAL_H
#define KRUSCAL_H
#include <iostream>
#include<utility>


#include <vector>
#include "Pila.h"
#include "Graph.h"
#include "ListaSimple.h"

using namespace std;

struct EdgePath {
    EdgePath() {
    }

    EdgePath(int row, int column, int prevRow, int prevColumn, int weight) {
        this->row = row;
        this->column = column;
        this->prevRow = prevRow;
        this->prevColumn = prevColumn;
        this->weight = weight;
    }

    EdgePath(int row, int column)
    {
        this->row = row;
        this->column = column;
    }
int row, column, prevRow, prevColumn, weight;

};

class Kruskal {
private:
    ListaSimple<EdgePath> makeEdges(Graph graph, int currentRow, int currentColumn);

    EdgePath findePrevEdge(int row, int column, ListaSimple <EdgePath> edges);

    bool isVisited(int row, int column, ListaSimple<EdgePath> visited);

public:

    Pila <pair <int, int> > kruskalAlgorithm(int currentRow, int currentColumn, int destRow, int destColumn, Graph graph);

};

#endif // KRUSCAL_H
