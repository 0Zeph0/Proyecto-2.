#include "LineaVista.h"



/**
 * Metodo para buscar rutas por Linea-Vista
 * @param x posicion de origen en x
 * @param y posicion de origen en y
 * @param xd  posicion de destino en x
 * @param yd  posicion de destino en y
 * @param X  --- Cola para devolver la ruta
 * @param Y ---//
 * @param matrix Matriz donde se hace la busquedad de la ruta
 */
Cola<pair<int, int>> LineaVista::lineaVista(int x, int y, int xd, int yd, int matrix[15][27]) {
    origen.x = x;
    origen.y = y;
    destino.x = xd;
    destino.y = yd;


    buscarRuta(destino, origen, matrix);

    return *this->ruta;

};

void LineaVista::rodearObstaculo(coordenada *origen, coordenada destino, int matrix[15][27]) {
    if (matrix[origen->x + 1][origen->y] == 0 && origen->x < destino.x) {
        while (matrix[origen->x + 1][origen->y] == 0) {
            this->ruta->push(make_pair(origen->x, origen->y+1));
            /*
            rutaX.push(origen->x);
            rutaY.push(origen->y + 1);
            */
            origen->y += 1;
        }
        this->ruta->push(make_pair(origen->x+1, origen->y));
        /*
        rutaX.push(origen->x + 1);
        rutaY.push(origen->y);
        */
        origen->x += 1;
    }
    if (matrix[origen->x - 1][origen->y] == 0 && origen->x > destino.x) {
        while (matrix[origen->x - 1][origen->y] == 0) {
            this->ruta->push(make_pair(origen->x, origen->y+1));
            /*
            rutaX.push(origen->x);
            rutaY.push(origen->y + 1);
            */
            origen->y += 1;
        }
        this->ruta->push(make_pair(origen->x-1, origen->y));
        /*
        rutaX.push(origen->x - 1);
        rutaY.push(origen->y);
        */
        origen->x -= 1;
    }
    if (matrix[origen->x][origen->y + 1] == 0 && origen->y < destino.y) {
        while (matrix[origen->x][origen->y + 1] == 0) {
            this->ruta->push(make_pair(origen->x+1, origen->y));
            /*
            rutaX.push(origen->x + 1);
            rutaY.push(origen->y);
            */
            origen->x += 1;
        }
        this->ruta->push(make_pair(origen->x, origen->y+1));
        /*
        rutaX.push(origen->x);
        rutaY.push(origen->y + 1);
        */
        origen->y += 1;
    }
    if (matrix[origen->x][origen->y - 1] == 0 && origen->y > destino.y) {
        while (matrix[origen->x][origen->y - 1] == 0) {
            this->ruta->push(make_pair(origen->x+1, origen->y));
            /*
            rutaX.push(origen->x + 1);
            rutaY.push(origen->y);
            */
            origen->x += 1;
        }
        this->ruta->push(make_pair(origen->x, origen->y-1));
        /*
        rutaX.push(origen->x);
        rutaY.push(origen->y - 1);
        */
        origen->y -= 1;
    }
};

void LineaVista::buscarRuta(coordenada *ruta1, coordenada destino1, int matrix[15][27]) {
    if (ruta1->x > destino1.x && matrix[ruta1->x - 1][ruta1->y] != 0) {
        this->ruta->push(make_pair(ruta1->x-1, ruta1->y));
        /*
        rutaX.push(ruta1->x - 1);
        rutaY.push(ruta1->y);
        */
        ruta1->x -= 1;
    }
    if (ruta1->x < destino1.x && matrix[ruta1->x + 1][ruta1->y] != 0) {
        this->ruta->push(make_pair(ruta1->x+1, ruta1->y));
        /*
        rutaX.push(ruta1->x + 1);
        rutaY.push(ruta1->y);
        */
        ruta1->x += 1;
    }
    if (ruta1->y > destino1.y && matrix[ruta1->x][ruta1->y - 1] != 0) {
        this->ruta->push(make_pair(ruta1->x, ruta1->y-1));
        /*
        rutaX.push(ruta1->x);
        rutaY.push(ruta1->y - 1);
        */
        ruta1->y -= 1;
    }
    if (ruta1->y < destino1.y && matrix[ruta1->x][ruta1->y + 1] != 0) {
        this->ruta->push(make_pair(ruta1->x, ruta1->y+1));
        /*
        rutaX.push(ruta1->x);
        rutaY.push(ruta1->y + 1);
        */
        ruta1->y += 1;
    }
    if (ruta1->x > destino1.x && ruta1->y > destino1.y && matrix[ruta1->x - 1][ruta1->y - 1] != 0) {
        this->ruta->push(make_pair(ruta1->x-1, ruta1->y-1));
        /*
        rutaX.push(ruta1->x - 1);
        rutaY.push(ruta1->y - 1);
        */
        ruta1->x -= 1;
        ruta1->y -= 1;
    }
    if (ruta1->x > destino1.x && ruta1->y < destino1.y && matrix[ruta1->x - 1][ruta1->y + 1] != 0) {
        this->ruta->push(make_pair(ruta1->x-1, ruta1->y+1));
        /*
         rutaX.push(ruta1->x - 1);
        rutaY.push(ruta1->y + 1);
        */
        ruta1->x -= 1;
        ruta1->y += 1;
    }
    if (ruta1->x < destino1.x && ruta1->y > destino1.y && matrix[ruta1->x - 1][ruta1->y - 1] != 0) {
        this->ruta->push(make_pair(ruta1->x+1, ruta1->y-1));
        /*
        rutaX.push(ruta1->x + 1);
        rutaY.push(ruta1->y - 1);
        */
        ruta1->x += 1;
        ruta1->y -= 1;
    }
    if (ruta1->x < destino1.x && ruta1->y < destino1.y && matrix[ruta1->x + 1][ruta1->y + 1] != 0) {
        this->ruta->push(make_pair(ruta1->x>+1, ruta1->y+1));
        /*
        rutaX.push(ruta1->x + 1);
        rutaY.push(ruta1->y + 1);
        */
        ruta1->x += 1;
        ruta1->y += 1;
    } else {
        rodearObstaculo(ruta1, destino1, matrix);
    }
};
void LineaVista::buscarRuta(coordenada destino, coordenada origen, int matrix[15][27]) {
    coordenada *XYtemp = new coordenada;
    XYtemp->x = origen.x;
    XYtemp->y = origen.y;
    while (!(destino == *XYtemp)) {
        buscarRuta(XYtemp, destino, matrix);
    }
   // while (rutaX.size() > 0 && rutaY.size() >0 ) {
     //   cout << rutaX.pop() << " "<< rutaY.pop() << endl;
     ///}
    delete (XYtemp);

};

bool operator==(coordenada a, coordenada b) {
    if (a.x == b.x && a.y == b.y) {
        return true;
    } else {
        return false;
    }
};
