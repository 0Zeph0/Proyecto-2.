#include "Random.h"

int generateRandom(int Max){

    int randomnumber = rand();
    float random = (randomnumber % Max) + 1;
    int myRandom = random;
    return myRandom;
}


int generateRandomZero(int Max){

    int randomnumber = rand();
    float random = (randomnumber % Max);
    int myRandom = random;
    return myRandom;

}
bool generateRandomBOOL(){

    int randomnumber = rand();
    float random = (randomnumber % 2) + 1;
    int myRandom = random;
    if(myRandom == 1){

        return true;
    }
    else{return false;}
}
