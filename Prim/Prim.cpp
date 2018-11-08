

#include <cmath>
#include <iostream>
#include "Prim.h"

/**
 *
 * Algoritmo de busqueda Prim, devuelve la ruta más corta mediante un arbol de mínima expresión
 * @param currentRow Posición actual del objeto en la fila
 * @param currentColumn Posición actual del objeto en la columna
 * @param destRow Posición destino en la fila
 * @param destColumn Posición destino en la columna
 * @param graph Grafo de la matriz del mapa
 * @return Pila<pain>
 */


Pila<pair <int, int>> Prim::primAlgorithm(int currentRow, int currentColumn, int destRow, int destColumn, Graph graph) {

    if (graph.getVertex(destRow, destColumn).row == -1 && graph.getVertex(destRow, destColumn).column == -1) {
        return {};
    }
    this->graph = graph;
    ListaSimple<Vertex> queue;
    Vertex current = this->graph.getVertex(currentRow, currentColumn);
    Vertex temp;
    visited.add(current);
    queue.add(current);
    ListaSimple<Path> prev;
    prev.add(Path{current.row, current.column, -1, -1});
    while (!queue.isEmpty()) {
        current = *queue.getData(0);
        queue.deleteNode(0);
        if (current.row == destRow && current.column == destColumn) {
            break;
        }
        for (int i = 0; i < current.edge->getLength(); i++) {
            temp = *current.edge->getData(i);
            if (!isVisited(temp)) {
                visited.add(temp);
                temp.weight = current.weight + 1;
                queue.add(temp);
                prev.add(Path{temp.row, temp.column, current.row, current.column});
            }
        }
    }

    return queueGenerator(currentRow, currentColumn, destRow, destColumn, prev);
}

/**
 * Verifica que el vértice se exista en la lista de los visitados
 * @param vertex vertice a evaluar
 * @return bool
 */
bool Prim::isVisited(Vertex vertex) {
    for (int i = 0; i < visited.getLength(); i++) {
        if (visited.getData(i)->column == vertex.column && visited.getData(i)->row == vertex.row) {
            return true;
        }
    }
    return false;
}

/**
 * Genera la cola de salida en una Pila
 * @param row fila Actual del objeto
 * @param column columna actual del objeto
 * @param destRow fila destino del objeto
 * @param destColumn columna destino del objeto
 * @param cola Lista que contiene la ruta
 * @return Pila<pair>
 */

 Prim::queueGenerator(int row, int column, int destRow, int destColumn, ListaSimple<Path> cola){
    Pila<pair <int, int>> pila;
    Path tempPath;
    for (int i = 0; i < cola.getLength(); i++)
    {
        if (cola.getData(i)->row == destRow && cola.getData(i)->column == destColumn) {
            tempPath = * cola.getData(i);
        }
    }

    while (true) {
        if (tempPath.row == row && tempPath.column == column) {
            cout << "Encontrado" << endl;
            break;
        }
        pila.push(make_pair(tempPath.row, tempPath.column));
        tempPath = findPrevPath(tempPath.prevRow, tempPath.prevColumn, cola);

    }
    return pila;

}

/**
 * Busca el previo del path
 * @param prevRow fila previa
 * @param prevColumn columna previa
 * @param path Lista con la ruta
 * @return Path
 */
Path Prim::findPrevPath(int prevRow, int prevColumn, ListaSimple<Path> path) {
    Path temp;
    for (int i = 0; i < path.getLength(); i++) {
        temp = *path.getData(i);
        if (temp.row == prevRow && temp.column == prevColumn) {
            return temp;
        }
    }

}

