//
// Created by Dvir on 04/01/2022.
//

#ifndef HW3_MASERATI_H
#define HW3_MASERATI_H

#include "SportsCar.h"
#include "LuxuryCar.h"
class Maserati:  public LuxuryCar, public SportsCar{
public:
    Maserati():Car(){type=4;name='M';};
    Maserati(unsigned int CarNum,int s):Car(CarNum,s){type=4;name='M';};
    virtual void setSection(int sect){crosNum=sect;}
    virtual int getType(){return type;}
    virtual char getName(){return name;}
};



#endif //HW3_MASERATI_H
