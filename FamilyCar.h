//
// Created by Dvir on 04/01/2022.
//

#ifndef HW3_FAMILYCAR_H
#define HW3_FAMILYCAR_H

#include "Car.h"
class FamilyCar: public Car{
public:
    FamilyCar(unsigned int CarNum,int s):Car(CarNum,s){type=2;name='F';};
    virtual void setSection(int sect){crosNum=sect;};
    virtual int getType(){return type;}
    virtual char getName(){return name;}
};



#endif //HW3_FAMILYCAR_H
