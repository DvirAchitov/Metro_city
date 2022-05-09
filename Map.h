//
// Created by Dvir on 03/01/2022.
//

#ifndef HW4_MAP_H
#define HW4_MAP_H
#include <iostream>
using namespace std;
template<class T,class V>
struct dict{
    T key;
    V value;
    dict<T,V> *next;

};
template<class T , class V>
class Map {
private:
    dict<T,V> *head;
    dict<T,V> *temp ;
    int count;
public:
    Map(){count=0;head=NULL;temp=NULL;}
    void insert(T k , V v);
    dict<T,V> search(T k)const;
    void del(T k);
    void clear();
    int size(){return count;}
    void print();
    int size()const{return count;}

};

template<class T, class V>
void Map<T, V>::insert(T k, V v) {
    if(!head) {
        head = new dict<T, V>;
        head->key = k;
        head->value = v;
        head->next = NULL;
        count++;
    }

    else {
        temp = new dict<T,V>;
        temp->key = k;
        temp->value=v;
        temp->next = NULL;
        dict<T,V> *list = head;
        while(list->next){
            if(list->key > k ){
                temp->next = list;
                head = temp;
                count++;
                return ;
            }
            else if(list->key==k){
                list->value=v;
                return;
            }
            else if(list->key < k && list->next->key > k){
                temp->next=list->next;
                list->next=temp;
                count++;
                return ;
            }
            else
            {
                list=list->next;
            }
        }
        list->next = temp;
        count++;
        return;
    }
}

template<class T, class V>
void Map<T, V>::print() {
    dict<T,V> *list = head;
    while(list!=NULL){
        cout<<list->key<<" "<<list->value<<endl;
        list=list->next;
    }


}

template<class T, class V>
dict<T, V> Map<T, V>::search(T k) const {
    dict<T,V> *list = head;
    while(list){
        if(list->key==k)
            return list;
        list=list->next;
    }
    return NULL;
}

template<class T, class V>
void Map<T, V>::del(T k) {
    dict<T,V> *list = head;
    dict<T,V> *rem = NULL;
    if(list->key==k){
        rem = list;
        head = list->next;
        delete rem;
        count--;
        return;
    }
    while(list->next){
        if(list->next->key==k) {
            rem = list->next;
            list->next = list->next->next;
            delete rem;
            count--;
            return ;
        }
        list=list->next;
    }
}

template<class T, class V>
void Map<T, V>::clear() {
    while(head){
        del(head->key);
    }
}


#endif //HW4_MAP_H
