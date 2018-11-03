#ifndef POBLACION_H
#define POBLACION_H
#include <cstddef>
#include <limits>
#include "Individuo.h"
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;


class Poblacion
{
    public:
        Poblacion(int size);
        virtual ~Poblacion();
        Individuo getBestFitIND();
        Individuo getSecBestFitIND();
        int getGeneracion();
        int getLowFitINDEX();//aqui obtengo el indice de la lista de poblacion que contiene el cromosoma con peor fitnes...
        void CalcTotalFit();
        void Selection();
        void CrossOver(); //metodo para hacer el intercambio de genes...
        void Mutation(); //con este se hace la mutacion...
        Individuo getBestOffSpring(); //de los nuevos creados despues de la mutacion, selecciono el mas poderoso...
        void addNewOffSpring();//Este mae agrega el mas poderoso a la poblacion y se fuma al mas debil...
        int getBestFIT(); //retorno variable BestFIT que es la que me guarda el mae mas pichudo
        int getSecoFIT(); //retorno variable SecoFIT que es la que me guarda el segundo mae mas pichudo.
        int getBestFitINDEX();//aqui obtengo el indice de la lista de poblacion que contiene el cromosoma con el mejor fitness...
        int getSecoFitINDEX();//aqui obtengo el indice de la lista de poblacion que tiene el cromosoma con el segundo mejor fitness..
        Individuo* getBUFFER(); //retorno la lista.


    protected:

    private:
        int TamanioPoblacion; //este valor varia dependiendo de la dificultad que se escoga( EZ = +5; MED = +10; HD = +15)
        Individuo* BufferDeIndividuos; //aqui van los cromosomas(individuos)
        int BestFIT;
        int SecoFIT;
        Individuo FirstIND;
        Individuo SeconIND;
        int Generacion;
        //estos maes solo me sirven para extraer por valor el dato de los individuos y despues asignarlos a los punteros First y Secon...
        //Individuo Cascaron1;
        //Individuo Cascaron2;

        //int BufferLength;

};

#endif // POBLACION_H
