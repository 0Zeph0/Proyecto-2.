//
// Created by JonathanGarcia on 3/11/18.
//

#ifndef ALGORITMOS_GRAPH_H
#define ALGORITMOS_GRAPH_H

#include "ListaSimple.h"


struct Vertex {
    Vertex() ;
    Vertex(int row, int column, int weight) {
        this->weight = weight;
        this->row = row;
        this->column = column;
        edge = new  ListaSimple<Vertex>();
    }

    int row, column, weight = 0;
    ListaSimple<Vertex> *edge;

};

ListaSimple<int> listaS;
class Graph {
/**private:
     ListaSimple<int> listaS;
     ListaSimple<Vertex> vertexs;
     ListaSimple<listaS> adjMatrix;
     int number = 0;
*/
public:

     ListaSimple<Vertex> vertexs;
     ListaSimple<ListaSimple<int>> adjMatrix;
     int number = 0;


    bool addVertex(int row, int column);

    bool addEdge(int row, int column, int adyRow, int adyColumn);

    int findByCoord(int row, int column);

    Vertex getVertex(int row, int column);

    void printGraph();

    const ListaSimple<Vertex> &getVertexs() const;

    int getNumber() const;

};

#endif //ALGORITMOS_GRAPH_H
