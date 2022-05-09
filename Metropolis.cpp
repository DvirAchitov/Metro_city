//
// Created by Dvir on 14/12/2021.
//

#include "Metropolis.h"
#include "FamilyCar.h"
#include "LuxuryCar.h"
#include "SportsCar.h"
#include "Maserati.h"
#include <sstream>
#include <stdlib.h>

Metropolis::Metropolis(double **graph, unsigned int size){
    carsNum=0;crosNum=0;
    roadCounter=0;
    Cross *s;
    crsList=NULL;
    rList=NULL;
    totCList=NULL;
    for (unsigned int i = 0; i < size; i++) {
        s=new Cross(i+1);
        for (unsigned int j = 0; j < size; j++) {
            if (graph[j][i] != 0) {
                s->insertNeighbor(j+1);
                setRoad(graph[j][i], i+1, j+1, 0);
            }
        }
        setCross(*s);
    }
}

void Metropolis::printToxicity(int size) {
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++) {
            if (j+1== size)
                cout << getToxicityRoad(i, j);
            else
                cout << getToxicityRoad(i, j)<<" ";
        }
        cout<<endl;
    }
}
void Metropolis::setCars(string str,int x) {
    str=str.substr(2);
    if(str.empty())
        return ;
    stringstream s(str);
     string car;
    while (!(s.eof())){
        s>>car;
        setCar(atoi(car.substr(1).c_str()),x,car[0]);
        getCross(x)->insertCar(atoi(car.substr(1).c_str()),x,car[0]);
    }
}
void Metropolis::printCars(int size) {
    string st;
    for(int i=1;i<size+1;i++)
    {
        cout<<i<<":";
        st=getCross(i)->printCars();
        cout<<st;
        cout<<endl;
    }
}
void Metropolis::setRoad(double len,int from,int to,int c) {
    Road* r1=new Road(len,from,to,c);
    rList=new Roads(r1,rList);
    roadCounter++;
}
void Metropolis::addRoad(int from, int to,int t) {
    Roads *temp=rList;
    while(temp!=NULL){
        if(temp->key->getFrom()==from&&temp->key->getTo()==to) {
            (*(temp->key)).setTox(t);
            (*(temp->key))++;

        }
        temp=temp->next;
    }
}
void Metropolis::setCross(const Cross& i) {
    Cross* s1;
    s1=new Cross(i.id,i.carList,i.neighList);
    crsList=new Crosses(s1,crsList);
    crosNum++;
}

Metropolis::Cars::Cars(Car *d, Metropolis::Cars *n) {
    key=d;
    next=n;
}
Metropolis::Crosses::Crosses(Cross* d, Metropolis::Crosses *n) {
    key=d;
    next=n;
}
Metropolis::Roads::Roads(Road* d, Metropolis::Roads *n) {
    key=d;
    next=n;
}
void Metropolis::setCar(int i, int x,char t) {
    Car *c1=NULL;
    if(t=='F')
        c1=new FamilyCar(i,x);
    else if(t=='L')
        c1=new LuxuryCar(i,x);
    else if(t=='S')
        c1=new SportsCar(i,x);
    else
        c1= new Maserati(i, x);
    totCList=new Cars(c1,totCList);
    carsNum++;
}

double Metropolis::getToxicityRoad(int from, int to) {
    Roads *r=rList;
    while(r!=NULL){
        if(r->key->getTo()==to&&r->key->getFrom()==from)
            return r->key->getToxicity();
        r=r->next;
    }
    return 0;
}


void Metropolis::Move(int K , double toxic) {
    Cars *temp = totCList;
    Crosses *p=crsList;
    Crosses *s=crsList;
    Roads *ro=rList;
    int to;
    int r;
    while(ro!=NULL) {
        ro->key->setTox(toxic);
        ro=ro->next;
    }
    for(int i=0;i<K;i++) {
        while (temp != NULL) {
            while (p->key->getId() != temp->key->getCrosNum()){p = p->next;}
            r = rand() % ((p->key->getNumOfNeighbros() - 0) + 1) + 0;
            if (r != 0) {
                p->key->removeCar(temp->key->getId());
                to = p->key->getNeightbor(r);
                while (s->key->getId() != to)
                    s = s->next;
                s->key->insertCar(temp->key->getId(), s->key->getId(),temp->key->getName());
                addRoad(temp->key->getCrosNum(), s->key->getId(),temp->key->getType());
                temp->key->setSection(s->key->getId());
            }
            temp = temp->next;
            s = crsList;
            p = crsList;
        }
        temp=totCList;
    }
}
Cross * Metropolis::getCross(int x)  {
    Crosses *temp=crsList;
    while(temp!=NULL){
        if(temp->key->getId()==x) {
            return temp->key;
        }
        temp=temp->next;
    }
    return NULL;
}
