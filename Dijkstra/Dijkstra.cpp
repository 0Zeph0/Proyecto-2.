#include "Dijkstra.h"
bool Dijkstra::definirCentro(int x,int y){
    cout<<"Definiendo centro"<<endl;
    int xAux;
    int yAux;
    for(int i = 0; i<verticesPendientes->size(); i++) {
        yAux = (verticesPendientes->operator[](i)).posicionY;
        xAux = (verticesPendientes->operator[](i)).posicionX;
        if(xAux == x && yAux == y){
            (verticesPendientes->operator[](i)).distancia = 0.0;
            cout<<"Centro definido"<<endl;
            return true;
        }
    }
    cout<<"No se puede definir centro en esa posición"<<endl;
    return false;
}

void Dijkstra::EvaluarVecinos(int posicionX, int posicionY, double peso){
    double dist = INF;
    for(int y = posicionY-1; y <= posicionY+1; y++){
        for(int x = posicionX-1; x <= posicionX+1; x++){
            if(y < 0 || x < 0 || y > FilasMapa-1 || x > ColumnasMapa-1){
            }else if(x == posicionX && y == posicionY){
            }else{
                Vertice aux{};

                for(int i = 0; i<verticesPendientes->size(); i++) {
                    aux = verticesPendientes->operator[](i);
                    if (aux.posicionX == x && aux.posicionY == y) {
                        if(aux.distancia == INF){
                            if(x != posicionX && y != posicionY){
                                //dist = DIAGONAL;
                            }else{
                                dist = 1.0;
                                (verticesPendientes->operator[](i)).distancia = peso + dist;
                            }
                        }
                    }
                }
            }
        }
    }
}


Vertice Dijkstra::RetornaVecinoMenor(int posicionX, int posicionY, double peso){
    double dist = peso;
    Vertice verticeAux1{};
    Vertice verticeAux2{};
    verticeAux1.distancia = peso;
    verticeAux1.posicionX = posicionX;
    verticeAux1.posicionY = posicionY;
    for(int y = posicionY-1; y <= posicionY+1; y++){
        for(int x = posicionX-1; x <= posicionX+1; x++){
            if(y < 0 || x < 0 || y > FilasMapa-1 || x > ColumnasMapa-1){
            }else if(x == posicionX && y == posicionY){
            }else{
                for(int i = 0; i<verticesPendientes->size(); i++) {
                    verticeAux2 = verticesPendientes->operator[](i);
                    if (verticeAux2.posicionX == x && verticeAux2.posicionY == y) {
                        if(verticeAux2.distancia < dist){
                            if(!(x != posicionX && y != posicionY)) {
                                dist = verticeAux2.distancia;
                                verticeAux1 = verticeAux2;
                            }
                        }
                    }
                }
            }
        }
    }
    return verticeAux1;
}


Dijkstra::Dijkstra(int mapa[FilasMapa][ColumnasMapa]){
    for (int y = 0; y < FilasMapa; y++){
        for (int x = 0; x < ColumnasMapa; x++){
            if(mapa[y][x] == 0) {
                Vertice vertice{};
                vertice.distancia = INF;
                vertice.posicionX = x;
                vertice.posicionY = y;
                vertice.visitado = false;
                verticesMapa->push_back(vertice);
            }
        }
    }
}

void Dijkstra::DefinirPesos(int x, int y){
    if(y<FilasMapa && x<ColumnasMapa){
        verticesPendientes->clear();
        for(int i = 0; i<verticesMapa->size(); i++) {
            verticesPendientes->push_back(verticesMapa->operator[](i));
        }
        if(definirCentro(x,y)) {
            Vertice aux{};
            for(int i = 0; i < 55; i++) {
                for (int i = 0; i < verticesPendientes->size(); i++) {
                    aux = verticesPendientes->operator[](i);
                    if (aux.distancia != INF) {
                        EvaluarVecinos(aux.posicionX, aux.posicionY, aux.distancia);
                        (verticesPendientes->operator[](i)).visitado = true;
                    }
                }
            }
        }
    }
}

int Dijkstra::DefinirRutaOptima(int x, int y) {
    if (y < FilasMapa && x < ColumnasMapa) {
        int xAux;
        int yAux;
        Vertice verticeActual = {};
        Vertice verticeAux{};
        verticeActual.distancia = INF;
        ruta->clear();
        contador = 0;

        for (int i = 0; i < verticesPendientes->size(); i++) {
            verticeAux = verticesPendientes->operator[](i);
            yAux = verticeAux.posicionY;
            xAux = verticeAux.posicionX;
            if (xAux == x && yAux == y) {
                verticeActual = verticeAux;
                break;
            }
        }

        if (verticeActual.distancia == INF) {
            cout << "Fuera de rango" << endl;
            return 0;
        } else if (verticeActual.distancia == 0.0) {
            ruta->push_back(verticeActual);
        } else {
            ruta->push_back(verticeActual);
            bool flag = true;
            cout<<"Dentro del while"<<endl;
            while (flag) {
                verticeActual = RetornaVecinoMenor(verticeActual.posicionX,
                                                   verticeActual.posicionY, verticeActual.distancia);
                cout<<verticeActual.distancia<<endl;
                if (verticeActual.distancia == 0.0) {
                    ruta->push_back(verticeActual);
                    flag = false;
                } else {
                    ruta->push_back(verticeActual);
                }
            }
            cout<<"Fuera del while"<<endl;
        }

        cout << "{" << endl;
        for (int i = 0; i < ruta->size(); i++) {
            cout << "(Vertice" << i << ": X = " << (ruta->operator[](i)).posicionX << "," << "Y = "
                 << (ruta->operator[](i)).posicionY << ", Peso = " << (ruta->operator[](i)).distancia << "),"
                 << endl;
        }
        cout << "}" << endl;
        return 1;
    }
    return 0;
}

Vertice Dijkstra::obtenerSiguienteVertice(){
    Vertice aux{};
    aux.posicionX = -1;
    aux.posicionY = -1;

    if (contador < 150) {
        if(contador < ruta->size()) {
            aux = ruta->operator[](contador);
        }
        contador++;
    }

    return aux;
}
