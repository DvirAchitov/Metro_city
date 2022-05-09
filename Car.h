//
// Created by Dvir on 14/12/2021.
//

#ifndef HW3_CAR_H
#define HW3_CAR_H
#include <iostream>
#include <cstdlib>
using namespace std;

class Car {
protected:
    int crosNum;
    int type;
    char name;
private:
    unsigned int id;
public:
    Car(){name=' ';type=0;crosNum=0;id=0;};
    Car(unsigned int n , int x){id=n;crosNum=x;type=0;name=' ';}
    virtual int getType()const{return type;}
    virtual char getName()const{return name;}
    virtual unsigned int getId()const{return id;};
    virtual int getCrosNum()const{return crosNum;};
    virtual void setSection(int x)=0;


};


#endif //HW3_CAR_H
