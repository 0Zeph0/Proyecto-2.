#include "Individuo.h"
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;

Individuo::Individuo()
{
    this->Fitness = 0;
    this->GenesLength = 18;
    //this->TotalGenes = 12;
    this->Genes = new int[GenesLength];
    //int RDM;
    //srand(time(NULL));
    for(int i = 0; i < GenesLength; i++){ //genero valores random a cada gen del individuo.

        Genes[i] = 10 + rand()%(51 -10);
    }
    Fitness = 0;
}

Individuo::Individuo(const Individuo &ajio){

    this->Fitness = ajio.getFitness();
    this->GenesLength = 18;
    this->Genes = ajio.getGenes();
}


/*Metodo para calcular el Fitness*/
void Individuo::CalcFitness()
{

    Fitness=0;


    for(int i = 0; i < GenesLength; i++){

        if(Genes[i] == 45 || Genes[i] == 35 || Genes[i] == 40){


            Fitness++;
        }

    }

}

void Individuo::setGenes(int pos, int newGEN){

    Genes[pos] = newGEN;
}
///Getters

int* Individuo::getGenes()const{

    return Genes;
}

int Individuo::getHP(){ //Obtengo el HP del individuo.

    return Genes[0];
}

int Individuo::getATK(){

    return Genes[1];
}

int Individuo::getAGI(){

    return Genes[2];
}

int Individuo::getMATK(){

    return Genes[3];
}

int Individuo::getFitness()const{

    return Fitness;
}

int Individuo::getLength(){

    return GenesLength;
}
Individuo::~Individuo()
{
    //dtor
}
