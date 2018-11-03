#include <iostream>
#include "Individuo.h"
#include <stdlib.h>
#include <time.h>
#include <limits>
#include "Poblacion.h"

using namespace std;


int main()
{
    /*
    Individuo mierda1 = Individuo();
    Individuo mierda2 = Individuo();
    cout << "hp: "<< mierda1.getHP() << " atk: "<< mierda1.getATK() << endl;
    cout << "hp: "<< mierda2.getHP() << " atk: "<< mierda2.getATK();*/

    /*
    Individuo mierda[3];
    mierda[0] =  Individuo();
    mierda[0].iniciarGEN();
    mierda[1] =  Individuo();
    mierda[1].iniciarGEN();
    mierda[2] =  Individuo();
    mierda[2].iniciarGEN();
    cout << " HP: " << mierda[0].getHP() << " " << " ATK: " << mierda[0].getATK() << endl;
    cout << " HP: " << mierda[1].getHP() << " " << " ATK: " << mierda[1].getATK() << endl;
    cout << " HP: " << mierda[2].getHP() << " " << " ATK: " << mierda[2].getATK() << endl;*/
    /*
    for(int i = 0; i<3; i++){
        mierda[i] = new Individuo();
    }
    for(int j = 0; j < 3; j++){
        cout << "hp: " << mierda[j]->getHP() << " atk: " << mierda[j]->getATK() << endl;
    }*/


    /*Individuo* Zeph = new Individuo();
    Zeph->CalcFitness();
    cout << "Fitness: " << Zeph->getFitness();
    cout << endl;
    for(int j = 0; j < 4; j++){

        cout << Zeph->getGenes()[j] << endl;;
    }
    cout << "HP: "<< Zeph->getHP() << endl;
    cout << "ATK: "<< Zeph->getATK() << endl;
    cout << "AGI: "<< Zeph->getAGI() << endl;
    cout << "MATK: "<< Zeph->getMATK() << endl;*/

    srand(time(NULL));
    int n = 7;
    Poblacion* TEC = new Poblacion(n);
    TEC->CalcTotalFit();
    //cout << "Generacion: "  << TEC->getGeneracion() << " "<< "Fitness: " << TEC->getBestFitIND() << endl;
    for(int i = 0; i < n; i++){
        cout << TEC->getBUFFER()[i].getFitness()<< endl;

        //cout << " HP: "<< TEC->getBUFFER()[i]->getHP() << " ATK: "<< TEC->getBUFFER()[i]->getATK()<<" AGI: "<<TEC->getBUFFER()[i]->getAGI()<< " MATK: " <<TEC->getBUFFER()[i]->getMATK()<<endl;

    }
    cout << " " << endl;
    cout << " Fitnes 1: " << TEC->getBestFIT() << " indice: " << TEC->getBestFitINDEX() << endl;
    cout << " Fitnes 2: " << TEC->getSecoFIT() << " Indice: " << TEC->getSecoFitINDEX() << endl;
    cout << "El mas mierda està en: " << TEC->getLowFitINDEX();
    cout <<" " << endl;
    TEC->Selection();
    TEC->CrossOver();
    cout << " " << endl;
    TEC->Mutation();
    TEC->addNewOffSpring();
    TEC->CalcTotalFit();
    cout << " " << endl;
    cout << "Aqui se separa la generacion"<< endl;
    for (int j = 0; j < n; j++){

        //cout << " HP: "<< TEC->getBUFFER()[j]->getHP() << " ATK: "<< TEC->getBUFFER()[j]->getATK()<<" AGI: "<<TEC->getBUFFER()[j]->getAGI()<< " MATK: " <<TEC->getBUFFER()[j]->getMATK()<<endl;
        cout << TEC->getBUFFER()[j].getFitness() <<endl;


    }
    cout << "ajio ajio: " << TEC->getBestFIT();




    return 0;
}
