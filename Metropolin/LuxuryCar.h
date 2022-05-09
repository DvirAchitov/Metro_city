//
// Created by Dvir on 04/01/2022.
//

#ifndef HW3_LUXURYCAR_H
#define HW3_LUXURYCAR_H

#include "Car.h"
class LuxuryCar: virtual public Car{
public:
    LuxuryCar():Car(){type=3;name='L';};
    LuxuryCar(unsigned int CarNum,int s):Car(CarNum,s){type=3;name='L';};
    virtual void setSection(int sect){crosNum=sect;}
    virtual int getType(){return type;}
    virtual char getName(){return name;}
};



#endif //HW3_LUXURYCAR_H
