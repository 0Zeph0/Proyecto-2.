#include "AStarPathFinding.h"
#include "SimpleList.h"

#include "Extructuras/Pila.h"

//Revisa si una celda dada es valida o no

bool AStarPathFinding::esValido(int fila, int columna) {
    return (fila>=0) && (fila< FILA) &&
           (columna >= 0) && (columna < COLUMNA);
}


bool AStarPathFinding::estaDesbloqueda(int grid[][COLUMNA], int fila, int columna) {
    return grid[fila][columna] == 1;
}

bool AStarPathFinding::esDestino(int fila, int columna, Pair destino) {
    return (fila == destino.first && columna == destino.second);
}

double AStarPathFinding::calcularValorH(int fila, int columna, Pair destino) {
    return ((double)sqrt((fila-destino.first)*(fila-destino.first) + (columna-destino.second) * (columna-destino.second)));
}


void AStarPathFinding::trazarCamino(celda detallesCelda[][COLUMNA], Pair destino) {
    printf("\n La ruta es: ");
    int fila = destino.first;
    int columna = destino.second;

    Pila<Pair> Path;

    while (!(detallesCelda[fila][columna].parent_i == fila
             && detallesCelda[fila][columna].parent_j == columna)){
        Path.push(make_pair(fila, columna));
        int temp_fila = detallesCelda[fila][columna].parent_i;
        int temp_columna = detallesCelda[fila][columna].parent_j;
        fila = temp_fila;
        columna = temp_columna;
    }


Path.push(make_pair(fila, columna));

    while (Path.getLenght() != 0){
        pair<int, int> p = Path.pop();
        cout<<"-> ("<<p.first<<", "<<p.second<<") ";
    }
}




void AStarPathFinding::busquedaAStar(int grid[][COLUMNA], Pair inicio, Pair destino) {

    //Si el inicio está fuera de rango
    if(!esValido(inicio.first, inicio.second)){
        printf("Inicio inválido");
        return;
    }

    //Si el destino está fuera de rango
    if(!esValido(destino.first, destino.second)){
        printf("Destino inválido");
        return;
    }

    //Si el inicio o el destino estan bloqueados
    if(!estaDesbloqueda(grid, inicio.first, inicio.second) ||
       !estaDesbloqueda(grid, destino.first, destino.second))
    {
        printf("Destino o inicio están bloqueados");
        return;
    }

    //Si el destino es igual al inicio
    if(esDestino(inicio.first, inicio.second, destino)){
        printf("Ya se encuentra en el destino");
        return;
    }

    bool closedList[FILA][COLUMNA];
    memset(closedList, false, sizeof(closedList));

    celda detallesCelda[FILA][COLUMNA];

    for(int i = 0; i < FILA; i++){
        for(int j=0; j<COLUMNA; j++){
            detallesCelda[i][j].f = FLT_MAX;
            detallesCelda[i][j].g = FLT_MAX;
            detallesCelda[i][j].h = FLT_MAX;
            detallesCelda[i][j].parent_i = -1;
            detallesCelda[i][j].parent_j = -1;
        }
    }

    int i = inicio.first;
    int j = inicio.second;
    detallesCelda[i][j].f = 0.0;
    detallesCelda[i][j].g = 0.0;
    detallesCelda[i][j].h = 0.0;
    detallesCelda[i][j].parent_i = i;
    detallesCelda[i][j].parent_j = j;



SimpleList <pPair> openList;



   openList.add(make_pair(0.0, make_pair(i,j)));)
    bool foundDest = false;

    while (!openList.isEmpty()){

        pPair p = openList.getData(0);

        openList.deleteNode(0);

        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

        double gNew, hNew, fNew;

        //REVISA LOS NODOS ADYACENTES//

        //-----------------  NORTE  ----------------------------
        if(esValido(i - 1, j)){
            if(esDestino(i-1, j, destino)){
                detallesCelda[i-1][j].parent_i = i;
                detallesCelda[i-1][j].parent_j = j;
                printf("Se encontró el destino\n");
                trazarCamino(detallesCelda, destino);
                foundDest = true;
                return;
            }
            else if(!closedList[i - 1][j] && estaDesbloqueda(grid, i-1, j)){
                gNew = detallesCelda[i][j].g + 1.0;
                hNew = calcularValorH(i-1, j, destino);
                fNew = gNew + hNew;

                if(detallesCelda[i-1][j].f == FLT_MAX || detallesCelda[i-1][j].f > fNew){
                    openList.add(make_pair(fNew, make_pair(i-1, j)));
                    detallesCelda[i-1][j].f = fNew;
                    detallesCelda[i-1][j].g = gNew;
                    detallesCelda[i-1][j].h = hNew;
                    detallesCelda[i-1][j].parent_i = i;
                    detallesCelda[i-1][j].parent_j = j;
                }
            }
        }

        //-------------------  SUR  -----------------
        if (esValido(i + 1, j))
        {
            if (esDestino(i + 1, j, destino))
            {
                detallesCelda[i+1][j].parent_i = i;
                detallesCelda[i+1][j].parent_j = j;
                printf("Se encontró el destino\n");
                trazarCamino(detallesCelda, destino);
                foundDest = true;
                return;
            }

            else if (!closedList[i + 1][j] &&
                     estaDesbloqueda(grid, i+1, j))
            {
                gNew = detallesCelda[i][j].g + 1.0;
                hNew = calcularValorH(i+1, j, destino);
                fNew = gNew + hNew;
                if (detallesCelda[i+1][j].f == FLT_MAX || detallesCelda[i+1][j].f > fNew)
                {
                    openList.add( make_pair (fNew, make_pair (i+1, j)));
                    detallesCelda[i+1][j].f = fNew;
                    detallesCelda[i+1][j].g = gNew;
                    detallesCelda[i+1][j].h = hNew;
                    detallesCelda[i+1][j].parent_i = i;
                    detallesCelda[i+1][j].parent_j = j;
                }
            }
        }

        //--------------  ESTE  ---------------------------
        if (esValido(i, j + 1))
        {
            if (esDestino(i, j + 1, destino))
            {
                detallesCelda[i][j+1].parent_i = i;
                detallesCelda[i][j+1].parent_j = j;
                printf("Se encontró el destino\n");
                trazarCamino(detallesCelda, destino);
                foundDest = true;
                return;
            }
            else if (!closedList[i][j + 1] &&
                     estaDesbloqueda (grid, i, j+1))
            {
                gNew = detallesCelda[i][j].g + 1.0;
                hNew = calcularValorH (i, j+1, destino);
                fNew = gNew + hNew;

                if (detallesCelda[i][j+1].f == FLT_MAX ||
                    detallesCelda[i][j+1].f > fNew)
                {
                    openList.add( make_pair(fNew,
                                            make_pair (i, j+1)));

                    detallesCelda[i][j+1].f = fNew;
                    detallesCelda[i][j+1].g = gNew;
                    detallesCelda[i][j+1].h = hNew;
                    detallesCelda[i][j+1].parent_i = i;
                    detallesCelda[i][j+1].parent_j = j;
                }
            }
        }

        //----------------  OESTE  ------------------
        if (esValido(i, j - 1))
        {
            if (esDestino(i, j - 1, destino))
            {
                detallesCelda[i][j-1].parent_i = i;
                detallesCelda[i][j-1].parent_j = j;
                printf("Se encontró el destino\n");
                trazarCamino(detallesCelda, destino);
                foundDest = true;
                return;
            }
            else if (!closedList[i][j - 1] &&
                     estaDesbloqueda(grid, i, j-1))
            {
                gNew = detallesCelda[i][j].g + 1.0;
                hNew = calcularValorH(i, j-1, destino);
                fNew = gNew + hNew;
                if (detallesCelda[i][j-1].f == FLT_MAX ||
                    detallesCelda[i][j-1].f > fNew)
                {
                    openList.add( make_pair (fNew, make_pair (i, j-1)));
                    detallesCelda[i][j-1].f = fNew;
                    detallesCelda[i][j-1].g = gNew;
                    detallesCelda[i][j-1].h = hNew;
                    detallesCelda[i][j-1].parent_i = i;
                    detallesCelda[i][j-1].parent_j = j;
                }
            }
        }
        //----------- Noreste ------------
        if (esValido(i - 1, j + 1))
        {
            if (esDestino(i-1, j+1, destino))
            {
                detallesCelda[i-1][j+1].parent_i = i;
                detallesCelda[i-1][j+1].parent_j = j;
                printf("Se encontró el destino\n");
                trazarCamino (detallesCelda, destino);
                foundDest = true;
                return;
            }

            else if (!closedList[i - 1][j + 1] && estaDesbloqueda(grid, i-1, j+1))
            {
                gNew = detallesCelda[i][j].g + 1.414;
                hNew = calcularValorH(i-1, j+1, destino);
                fNew = gNew + hNew;

                if (detallesCelda[i-1][j+1].f == FLT_MAX || detallesCelda[i-1][j+1].f > fNew)
                {
                    openList.add( make_pair (fNew, make_pair(i-1, j+1)));
                    detallesCelda[i-1][j+1].f = fNew;
                    detallesCelda[i-1][j+1].g = gNew;
                    detallesCelda[i-1][j+1].h = hNew;
                    detallesCelda[i-1][j+1].parent_i = i;
                    detallesCelda[i-1][j+1].parent_j = j;
                }
            }
        }

        //----------- Noroeste ------------


        if (esValido (i - 1, j - 1))
        {
            if (esDestino (i - 1, j - 1, destino))
            {
                detallesCelda[i-1][j-1].parent_i = i;
                detallesCelda[i-1][j-1].parent_j = j;
                printf("Se encontró el destino\n");
                trazarCamino (detallesCelda, destino);
                foundDest = true;
                return;
            }
            else if (!closedList[i-1][j-1] && estaDesbloqueda(grid, i-1, j-1))
            {
                gNew = detallesCelda[i][j].g + 1.414;
                hNew = calcularValorH(i-1, j-1, destino);
                fNew = gNew + hNew;
                if (detallesCelda[i-1][j-1].f == FLT_MAX || detallesCelda[i-1][j-1].f > fNew)
                {
                    openList.add( make_pair (fNew, make_pair (i-1, j-1)));
                    detallesCelda[i-1][j-1].f = fNew;
                    detallesCelda[i-1][j-1].g = gNew;
                    detallesCelda[i-1][j-1].h = hNew;
                    detallesCelda[i-1][j-1].parent_i = i;
                    detallesCelda[i-1][j-1].parent_j = j;
                }
            }
        }

        //----------- SurEste ------------

        if (esValido(i + 1, j + 1))
        {
            if (esDestino(i + 1, j + 1, destino))
            {
                detallesCelda[i+1][j+1].parent_i = i;
                detallesCelda[i+1][j+1].parent_j = j;
                printf("Se encontró el destino\n");
                trazarCamino (detallesCelda, destino);
                foundDest = true;
                return;
            }
            else if (!closedList[i + 1][j + 1] && estaDesbloqueda(grid, i+1, j+1))
            {
                gNew = detallesCelda[i][j].g + 1.414;
                hNew = calcularValorH(i+1, j+1, destino);
                fNew = gNew + hNew;

                if (detallesCelda[i+1][j+1].f == FLT_MAX ||
                    detallesCelda[i+1][j+1].f > fNew)
                {
                    openList.add(make_pair(fNew, make_pair (i+1, j+1)));
                    detallesCelda[i+1][j+1].f = fNew;
                    detallesCelda[i+1][j+1].g = gNew;
                    detallesCelda[i+1][j+1].h = hNew;
                    detallesCelda[i+1][j+1].parent_i = i;
                    detallesCelda[i+1][j+1].parent_j = j;
                }
            }
        }

        //----------- SurOeste ------------

        if (esValido (i + 1, j - 1)) {

            if (esDestino(i + 1, j - 1, destino)) {
                detallesCelda[i + 1][j - 1].parent_i = i;
                detallesCelda[i + 1][j - 1].parent_j = j;
                printf("Se encontró el destino\n");
                trazarCamino(detallesCelda, destino);
                foundDest = true;
                return;
            } else if (!closedList[i + 1][j - 1] &&
                       estaDesbloqueda(grid, i + 1, j - 1)) {
                gNew = detallesCelda[i][j].g + 1.414;
                hNew = calcularValorH(i + 1, j - 1, destino);
                fNew = gNew + hNew;

                if (detallesCelda[i + 1][j - 1].f == FLT_MAX ||
                    detallesCelda[i + 1][j - 1].f > fNew) {
                    openList.add(make_pair(fNew,
                                           make_pair(i + 1, j - 1)));

                    detallesCelda[i + 1][j - 1].f = fNew;
                    detallesCelda[i + 1][j - 1].g = gNew;
                    detallesCelda[i + 1][j - 1].h = hNew;
                    detallesCelda[i + 1][j - 1].parent_i = i;
                    detallesCelda[i + 1][j - 1].parent_j = j;
                }
            }
        }
    }

    if(foundDest == false){
        printf("Error al encontrar el destino\n");
        return;
    }
}
