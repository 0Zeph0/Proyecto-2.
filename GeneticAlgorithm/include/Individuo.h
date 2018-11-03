#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;


class Individuo
{
    public:
        Individuo();
        Individuo(const Individuo &ajio);
        virtual ~Individuo();
        void CalcFitness();
        int* getGenes()const;
        void setGenes(int pos, int newGEN);
        int getHP();
        int getATK();
        int getAGI();
        int getMATK();
        int getFitness()const;
        int getLength();

    protected:

    private:

        int GenesLength;
        int* Genes;
        int Fitness;
        //int TotalGenes;

};

#endif // INDIVIDUO_H
