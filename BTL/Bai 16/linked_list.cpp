#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP
#include <bits/stdc++.h>
#include "node_slist.cpp"
using namespace std;
#define elif else if
template <class T>
class linked_list{
    private:
        node<T>* head;
        node<T>* trail;
        int len;
    public:
        linked_list():head(NULL), trail(NULL), len(T()){}
        class iterator{
            private:
                node<T>* curr;
            public:
                iterator(node<T>* p): curr(p){}
                node<T>* getCurr(){
                    return curr;
                }
                bool operator!=( iterator b){
                    return curr == b.getCurr();
                }
                iterator operator++(int){
                    node<T>* tmp = curr;
                    curr = curr->getNext();
                    return tmp;
                }
                iterator operator++(){
                    curr = curr->getNext();
                    return curr;
                }
                T& operator*()
                {
                    return this->getCurr();
                }
        };
        iterator begin(){
            return head;
        }
        iterator end(){
            return NULL;
        }
        int size(){
            return len;
        }
        bool empty(){
            return len == 0;
        }
        T& front(){
            return head->getValid();
        }
        T& back(){
            return trail->getValid();
        }
        void push_front(T val){
            head = new node<T>(val, head);
            if(len == 1) trail = head;
            len++;
        }
        void push_back(T val){
            if(len == 0) head = trail = new node<T>(val);
            else{
                trail->setNext(new node<T>(val));
                trail = trail->getNext();
            }
            len++;
        }
        void pop_front(){
            if(len == 0) return;
            node<T>* tmp = head;
            head = head->getNext();
            delete tmp;
            len--;
        }
        void pop_back(){
            if(len == 0) return;
            if(len == 1){
                delete head;
                head = trail = NULL;
            }
            else{
                node<T>* tmp = head;
                while(tmp->getNext() != trail) tmp = tmp->getNext();
                delete trail;
                trail = tmp;
                trail->setNext(NULL);
            }
            len--;
        }

};
#endif