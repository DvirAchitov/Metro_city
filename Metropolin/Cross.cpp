
#include "Cross.h"
#include "FamilyCar.h"
#include "LuxuryCar.h"
#include "SportsCar.h"
#include "Maserati.h"

using namespace std;

Cross::Cross(int i, Cars *car,Neightbors *neigh){
    id=i;
    carCount=0;
    countNeighbors=0;
    carList=NULL;
    neighList=NULL;
    while(car!=NULL) {
        insertCar(car->key->getId(), car->key->getId(),car->key->getName());
        car = car->next;
    }
    while(neigh!=NULL) {
        insertNeighbor(neigh->key->getId());
        neigh=neigh->next;
    }
}
Cross::Cross(int i){
    id=i;
    carCount=0;
    countNeighbors=0;
    carList=NULL;
    neighList=NULL;
}
int Cross::getNeightbor(int i)const {
    Neightbors* temp=neighList;
    i=i-1;
    while(i>0) {
        temp = temp->next;
        i=i-1;
    }
    return temp->key->getId();
}
void Cross::insertNeighbor(int x) {
    Cross* s1=new Cross(x);
    neighList=new Neightbors(s1,neighList);
    countNeighbors++;
}
void Cross::removeCar(unsigned int i) {
    if (!carList)
        return;
    Cars* temp = carList;
    if (temp->key->getId()== i) {
        carList = carList->next;
        delete temp;
        carCount=carCount-1;
        return;
    }
    while (temp->next && temp->next->key->getId() != i) {
        temp = temp->next;
    }
    if (temp->next) {
        Cars* del = temp->next;
        temp->next = del->next;
        delete del;
        carCount=carCount-1;
    }
}

void Cross::insertCar(unsigned int i, int x,char n) {
    Car *c1=NULL;
    if(n=='F')
        c1=new FamilyCar(i,x);
    else if(n=='L')
        c1=new LuxuryCar(i,x);
    else if(n=='S')
        c1=new SportsCar(i,x);
    else
        c1= new Maserati(i, x);
    carList=new Cars(c1,carList);
    carCount++;
}

string Cross::printCars()const {
    Cars *c=carList;
    string st="";
    while(c!=NULL){
        if(c->key->getId()!=10)
            st+=(c->key->getId())+'0';
        else
            st+="01";
        st+=c->key->getName();
        st+=" ";
        c=c->next;
    }
    std::reverse(st.begin(), st.end());
    return st;
}

Cross::Cars::Cars(Car *x, Cars *p) {
    key=x;
    next=p;

}

Cross::Neightbors::Neightbors(Cross* x, Cross::Neightbors *p) {
    key=x;
    next=p;
}