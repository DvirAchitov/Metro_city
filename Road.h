//
// Created by Dvir on 14/12/2021.
//

#ifndef HW3_ROAD_H
#define HW3_ROAD_H
#include <iostream>
using namespace std;

class Road {
private:
    int from;
    int to;
    double len,tox,totalTox;
public:
    Road(double le , int frm , int t , double c){len=le;from=frm;to=t;tox=c;totalTox=0;}
    Road& operator++();
    Road operator++(int);
    int getFrom() const{return from;}
    int getTo()const{return to;}
    void setTox(double c){tox=c;}
    double getToxicity()const{return totalTox;}
};


#endif //HW3_ROAD_H
