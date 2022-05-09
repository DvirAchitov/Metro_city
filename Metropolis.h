//
// Created by Dvir on 14/12/2021.
//

#ifndef HW3_METROPOLIS_H
#define HW3_METROPOLIS_H
#include "Cross.h"
#include "Road.h"

class Metropolis {
    struct Cars{
        Car* key;
        Cars *next;
        Cars(Car* key , Cars* next);
    };
    struct Crosses{
        Cross* key;
        Crosses* next;
        Crosses(Cross* key, Crosses* next);
    };
    struct Roads{
        Road* key;
        Roads* next;
        Roads(Road* key, Roads* next);
    };
private:
    int crosNum;
    int carsNum;
    int roadCounter;
    Cars* totCList;
    Crosses* crsList;
    Roads* rList;
public:
    Metropolis (double** graph, unsigned int size);
    Metropolis(){carsNum=0;crosNum=0;roadCounter=0;totCList=NULL;crsList=NULL;rList=NULL;}
    void Move(int k , double toxic);
    void addRoad(int from,int to,int t);
    double getToxicityRoad(int from,int to);
    Cross* getCross(int cur);
    void printToxicity(int size);
    void printCars(int size);
    void setCar(int CarNum, int pos,char t);
    void setCross(const Cross& i);
    void setRoad(double len, int from, int to, int c);
    void setCars(string st,int section);
    ~Metropolis(){delete rList;delete crsList;delete totCList;}
};

#endif //HW3_METROPOLIS_H
