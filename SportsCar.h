//
// Created by Dvir on 04/01/2022.
//

#ifndef HW3_SPORTSCAR_H
#define HW3_SPORTSCAR_H

#include "Car.h"

class SportsCar: virtual public Car{
public:
    SportsCar():Car(){type=4;name='S';};
    SportsCar(unsigned int CarNum,int s):Car(CarNum,s){type=4;name='S';};
    virtual void setSection(int sect){crosNum=sect;}
    virtual int getType(){return type;}
    virtual char getName(){return name;}
};



#endif //HW3_SPORTSCAR_H
