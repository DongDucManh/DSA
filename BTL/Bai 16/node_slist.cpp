#ifndef NODE
#define NODE
#include <bits/stdc++.h>
using namespace std;
#define main signed main
#define elif else if
template <class T>
class node{
    private:
        T elem;
        node* next;
    public:
        node(T val = T(), node* nt = NULL){
            elem = val;
            next = nt;
        }
        void setElem(T elem){
            this->elem = elem;
        }
        void setNext(node *next){
            this->next = next;
        }
        T& getElem(){
            return elem;
        }
        node<T>*& getNext(){
            return next;
        }
};
#endif