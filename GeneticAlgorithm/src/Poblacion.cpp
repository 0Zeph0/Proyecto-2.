#include "Poblacion.h"
#include <limits>
#include "Individuo.h"
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;

Poblacion::Poblacion(int size)
{
    this->TamanioPoblacion = size;

    this->BestFIT = 0;
    this->SecoFIT = 0;
    this->BufferDeIndividuos = new Individuo[TamanioPoblacion];

    this->Generacion = 0;
    //this->Padre = new Individuo();
    //this->Madre = new Individuo();
    for(int i = 0; i < TamanioPoblacion; i++){
        //int* index
        BufferDeIndividuos[i] = Individuo();
    }
}


///Mètodos///

//retorna el individuo mas pichudo de la poblacion->->->
Individuo Poblacion::getBestFitIND(){

    int maxFIT = numeric_limits<int>::min();
    int MaxFIT_Index = 0;
    for(int k = 0; k < TamanioPoblacion; k++){

        if(maxFIT <= BufferDeIndividuos[k].getFitness()){

            maxFIT = BufferDeIndividuos[k].getFitness();

            MaxFIT_Index = k;
        }
    }
    BestFIT = BufferDeIndividuos[MaxFIT_Index].getFitness();
    return BufferDeIndividuos[MaxFIT_Index];
}
//retorno el indice con el mae mas pichudo
int Poblacion::getBestFitINDEX(){

    int maxFIT = numeric_limits<int>::min();
    int MaxFIT_Index = 0;
    for(int k = 0; k < TamanioPoblacion; k++){

        if(maxFIT <= BufferDeIndividuos[k].getFitness()){

            maxFIT = BufferDeIndividuos[k].getFitness();

            MaxFIT_Index = k;
        }
    }
    return MaxFIT_Index;
}
//retorno el fit del mejor(revisar)
int Poblacion::getBestFIT(){

    return BestFIT;

}

//retorno el numero de generacion->->
int Poblacion::getGeneracion(){

    return Generacion;
}
//obtengo el individuo con el segundo mejor fitness->
Individuo Poblacion::getSecBestFitIND(){

    int indexMax1 = 0;
    int indexMax2 = 0;
    for(int j = 0; j < TamanioPoblacion; j++){

        if(BufferDeIndividuos[j].getFitness() > BufferDeIndividuos[indexMax1].getFitness()){

            indexMax2 = indexMax1;
            indexMax1 = j;
        }
        else if( BufferDeIndividuos[j].getFitness() > BufferDeIndividuos[indexMax2].getFitness() ){

            indexMax2 = j;
        }
    }
    SecoFIT = BufferDeIndividuos[indexMax2].getFitness();
    return BufferDeIndividuos[indexMax2];
}

int Poblacion::getSecoFitINDEX(){

    int indexMax1 = 0;
    int indexMax2 = 0;
    for(int j = 0; j < TamanioPoblacion; j++){

        if(BufferDeIndividuos[j].getFitness() > BufferDeIndividuos[indexMax1].getFitness()){

            indexMax2 = indexMax1;
            indexMax1 = j;
        }
        else if( BufferDeIndividuos[j].getFitness() > BufferDeIndividuos[indexMax2].getFitness() ){

            indexMax2 = j;
        }
    }
    return indexMax2;
}

//retorna el indice donde esta el individuo con menor fitness...
int Poblacion::getLowFitINDEX(){

    int MinFIT = numeric_limits<int>::max();
    int MinFIT_Index = 0;
    for(int k = 0; k < TamanioPoblacion; k++){

        if(MinFIT >= BufferDeIndividuos[k].getFitness()){

            MinFIT = BufferDeIndividuos[k].getFitness();
            MinFIT_Index = k;
        }
    }
    return MinFIT_Index;
}

//aqui el calculo el fitness a cada mae de la poblacion...
void Poblacion::CalcTotalFit(){

    for(int x = 0; x < TamanioPoblacion; x++){

        BufferDeIndividuos[x].CalcFitness();
    }
    getBestFitIND();
}

void Poblacion::Selection(){
    //cout << "0" << endl;
    //selecciono el mejor perro
    this->FirstIND = Individuo(getBestFitIND());
    //this.FirstIND = getBestFitIND();
    cout <<" El mas pichudo: " << FirstIND.getFitness() << endl;

    //selecciono el segundo mejor
    this->SeconIND = Individuo(getSecBestFitIND());
    cout << " El otro pichudo: " << SeconIND.getFitness() <<  endl;
}

//metodo para hacer el cruce entre individuos...
void Poblacion::CrossOver(){
    //cout <<"a" << endl ;
    int crossOverPoint;
    //srand(time(NULL));
    crossOverPoint = 1 + rand()%(4 - 1);
    cout << " Primer mono: " << endl;
    cout << " HP: " << FirstIND.getGenes()[0] << " ATK: " << FirstIND.getGenes()[1] << " AGI: " << FirstIND.getGenes()[2] << " MATK: " << FirstIND.getGenes()[3] << endl;
    cout << " Segundo mono: " << endl;
    cout << " HP: " << SeconIND.getGenes()[0] << " ATK: " << SeconIND.getGenes()[1] << " AGI: " << SeconIND.getGenes()[2] << " MATK: " << SeconIND.getGenes()[3] << endl;
    for(int i = 0; i < crossOverPoint; i++){

        int TempValue = FirstIND.getGenes()[i];
        FirstIND.getGenes()[i] = SeconIND.getGenes()[i];
        SeconIND.getGenes()[i] = TempValue;
    }
    cout << "Punto de culeo: " << crossOverPoint << endl;
    cout << "despues de la culiada: " << endl;
    cout << " Primer mono: " << endl;
    cout << " HP: " << FirstIND.getGenes()[0] << " ATK: " << FirstIND.getGenes()[1] << " AGI: " << FirstIND.getGenes()[2] << " MATK: " << FirstIND.getGenes()[3] << endl;
    cout << " Segundo mono: " << endl;
    cout << " HP: " << SeconIND.getGenes()[0] << " ATK: " << SeconIND.getGenes()[1] << " AGI: " << SeconIND.getGenes()[2] << " MATK: " << SeconIND.getGenes()[3] << endl;

}

//mutacion vacilona
void Poblacion::Mutation(){

    //int MutationPoint;
    //int RDM1;
    //int RDM2;

    //MutationPoint = rand()%(4);
   // RDM1 = 10 + rand()%(51 - 10);
    //RDM2 = 10 + rand()%(51 - 10);

    //intercambio de genes entre los cromosomas...
    int low = 0;
    for(int j = 0; j < 4; j++){

        if(FirstIND.getGenes()[low] >  FirstIND.getGenes()[j]){

                low = j;
            }
    }
    cout << "indice culo: " << low << endl;
    cout << "el mas mierda del primero: " << FirstIND.getGenes()[low] << endl;
    if(FirstIND.getGenes()[low] < 25){

        FirstIND.setGenes(low, 45);
    }

    else{FirstIND.setGenes(low, 35);}

    cout << " Primer mono: " << endl;
    cout << " HP: " << FirstIND.getGenes()[0] << " ATK: " << FirstIND.getGenes()[1] << " AGI: " << FirstIND.getGenes()[2] << " MATK: " << FirstIND.getGenes()[3] << endl;



    for(int j = 0; j < 4; j++){

        if(SeconIND.getGenes()[low] > SeconIND.getGenes()[j]){

                low = j;
            }
    }
    cout << "el otro indice culo: " << low << endl;
    cout << " el mas mierda del segundo: " << SeconIND.getGenes()[low] << endl;
    if(SeconIND.getGenes()[low] < 25){

        SeconIND.setGenes(low, 45);
    }

    else{SeconIND.setGenes(low, 35);}

    cout << " Segundo mono: " << endl;
    cout << " HP: " << SeconIND.getGenes()[0] << " ATK: " << SeconIND.getGenes()[1] << " AGI: " << SeconIND.getGenes()[2] << " MATK: " << SeconIND.getGenes()[3] << endl;



    /*

    if(FirstIND.getGenes()[MutationPoint] == RDM1){

        //aqui hago un flip raro ahi, que baja la probabilidad de mutar...
        FirstIND.setGenes(MutationPoint,RDM2);
    }
    MutationPoint = rand()%(4);
    if(SeconIND.getGenes()[MutationPoint] == RDM1){

        //aqui con el segundo individuo..
        SeconIND.setGenes(MutationPoint,RDM2);
    }*/

}
//retorno el mas pichudo de los nuevos creados...
Individuo Poblacion::getBestOffSpring(){

    if(FirstIND.getFitness() > SeconIND.getFitness()){

        return FirstIND;
    }
    return SeconIND;
}

void Poblacion::addNewOffSpring(){

    //hacemos un update del nuevo fitness despues de la mutacion...
    FirstIND.CalcFitness();
    cout << " Primer mono: " << endl;
    cout << " HP: " << FirstIND.getGenes()[0] << " ATK: " << FirstIND.getGenes()[1] << " AGI: " << FirstIND.getGenes()[2] << " MATK: " << FirstIND.getGenes()[3] << endl;
    SeconIND.CalcFitness();
    cout << " Segundo mono: " << endl;
    cout << " HP: " << SeconIND.getGenes()[0] << " ATK: " << SeconIND.getGenes()[1] << " AGI: " << SeconIND.getGenes()[2] << " MATK: " << SeconIND.getGenes()[3] << endl;

    //obtengo el index del mas malo...
    int ElMasMalo = getLowFitINDEX();
    cout << " El mas mierda està en: " << ElMasMalo;

    //aqui me fumo al debil y pongo al mas pichudo.
    BufferDeIndividuos[ElMasMalo] = getBestOffSpring();
    Generacion++;
}

//retorno el fit del segundo mas pichudo...
int Poblacion::getSecoFIT(){

    return BufferDeIndividuos[getSecoFitINDEX()].getFitness();
}
Individuo* Poblacion::getBUFFER(){

    return BufferDeIndividuos;
}



Poblacion::~Poblacion()
{
    //dtor
}
