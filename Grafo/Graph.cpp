//
// Created by JonathanGarcia on 3/11/18.
//

#include <iostream>
#include "Graph.h"

/**
 * Se añade el vertice al grafo
 * @param row Fila de la matriz
 * @param column Columna de la matriz
 * @return bool
 */
bool Graph::addVertex(int row, int column) {
    for (int i = 0; i < vertexs.getLength(); i++) {
        if (vertexs.getData(i)->column == column && vertexs.getData(i)->row == row) {
            return false;
        }
    }
    this->vertexs.add(Vertex(row, column, 0));
    number++;
    return true;
}

/**
 * Añade una arista (conexión) entre dos vértices
 * @param row fila del vértice uno
 * @param column columna del vertice uno
 * @param adyRow fila del vertice adyacente
 * @param adyColumn columna del vertice adyacente
 * @return bool
 */
bool Graph::addEdge(int row, int column, int adyRow, int adyColumn) {
    Vertex temp;
    Vertex adyTemp;
    for (int i = 0; i < this->vertexs.getLength(); i++) {
        temp = *vertexs.getData(i);
        if (temp.row == row && temp.column == column) {
            for (int j = 0; j < temp.edge->getLength(); j++) {
                adyTemp = *temp.edge->getData(j);
                if (adyTemp.column == adyColumn && adyTemp.row == adyRow) {
                    return false;
                }
            }
        }
    }
    adyTemp = this->getVertex(adyRow, adyColumn);
    temp = this->getVertex(row, column);

    temp.edge->add(adyTemp);
    return true;
}

/**
 * Obtiene el vértice
 * @param row
 * @param column
 * @return
 */
Vertex Graph::getVertex(int row, int column) {
    Vertex temp;
    for (int i = 0; i < vertexs.getLength(); i++) {
        temp = *vertexs.getData(i);
        if (temp.row == row && temp.column == column) {
            return temp;
        }
    }
    return Vertex{-1,-1,0};
}

void Graph::printGraph() {
    Vertex temp;
    Vertex temp2;
    for (int i = 0; i < vertexs.getLength(); i++) {
        temp = *vertexs.getData(i);
        std::cout << "El vertice (" << temp.row << ", " << temp.column << ")" << std::endl;
        for (int j = 0; j < temp.edge->getLength(); j++) {
            temp2 = *temp.edge->getData(j);
            std::cout << "(" << temp2.row << ", " << temp2.column << ") -> ";
        }
        std::cout << std::endl;
    }
}

const ListaSimple <Vertex> &Graph::getVertexs() const {
    return vertexs;
}

int Graph::getNumber() const {
    return number;
}

int Graph::findByCoord(int row, int column) {
    for (int i = 0; i < vertexs.getLength(); i++) {
        Vertex temp = *vertexs.getData(i);
        if (row == temp.row && column == temp.column){
            return i;
        }
    }
    return 0;
}
