//
// Created by dvir on 14/12/2021.
//

#ifndef HW3_Reader_H
#define HW3_Reader_H
#include "string"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Metropolis.h"
using namespace std;

class Reader {
public:
    Reader(){size=0;};
double** getMat(const char* s);
int getSize() const{return size;}
private :
    int size;
};


#endif //HW3_Reader_H
