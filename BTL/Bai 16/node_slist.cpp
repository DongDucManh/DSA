#ifndef NODE
#define NODE
#include <bits/stdc++.h>
using namespace std;
#define main signed main
#define elif else if
template <class T>
class node{
    private:
        T valid;
        node* next;
    public:
        node(T val = T(), node* nt = NULL){
            valid = val;
            next = nt;
        }
        void setValid(T valid){
            this->valid = valid;
        }
        void setNext(node *next){
            this->next = next;
        }
        T getValid(){
            return valid;
        }
        node<T>*& getNext(){
            return next;
        }
};
#endif