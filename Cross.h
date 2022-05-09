//
// Created by Dvir on 14/12/2021.
//

#ifndef HW3_CROSS_H
#define HW3_CROSS_H

#include "Car.h"
#include <iostream>
#include <algorithm>

using namespace std;

class Cross {
    struct Cars{
        Car* key;
        Cars *next;
        Cars(Car* key , Cars* next);
    };

public:
    struct Neightbors{
        Cross* key;
        Neightbors* next;
        Neightbors(Cross* key, Neightbors* next);
    };
    int countNeighbors;
    int id;
    int carCount;
    Cars* carList;
    Neightbors* neighList;
    Cross(){id=0;carCount=0;countNeighbors=0;}
    Cross(int id,Cars *car, Neightbors *neigh);
    explicit Cross(int i);
    void insertNeighbor(int x);
    int getId() const{return id;}
    int getNeightbor(int i)const;
    int getNumOfNeighbros() const{return countNeighbors;}
    void removeCar(unsigned int car);
    void insertCar(unsigned int car, int x,char n);
    string printCars() const;
    ~Cross(){delete carList;delete neighList;}
};


#endif //HW3_CROSS_H
