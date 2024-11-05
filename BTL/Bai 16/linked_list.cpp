#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP
#include <bits/stdc++.h>
#include "node_slist.cpp"
using namespace std;
#define elif else if
template <class T>
class slist{
    private:
        node<T>* head;
        node<T>* trail;
        int len;
    public:
        slist():head(NULL), trail(NULL), len(T()){}
        slist(T val):head(new node<T>(val)), trail(head), len(1){}
        class iterator{
            private:
                node<T>* curr;
            public:
                iterator(node<T>* p): curr(p){}
                bool operator==( iterator b){
                    return curr == b.curr;
                }
                bool operator!=( iterator b){
                    return curr != b.curr;
                }
                iterator operator++(int){
                    node<T>* tmp = curr;
                    curr = curr->getNext();
                    return tmp;
                }
                iterator operator++(){
                    return curr->getNext();
                }
                T& operator*()
                {
                    return curr->getElem();
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
        T front(){
            return head->getValid();
        }
        T back(){
            return trail->getValid();
        }
        void push_front(T val){
            head = new node<T>(val, head);
            len++;
            if(len == 1) trail = head;
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
        void insert(iterator pos, T val){
            if(pos == NULL) return;
            if(pos == head){
                push_front(val);
                return;
            }
            node<T>* tmp = head;
            while(tmp->getNext() != pos.curr) tmp = tmp->getNext();
            tmp->setNext(new node<T>(val, pos.curr));
            len++;
        }
        void erase(iterator pos){
            if(pos == NULL) return;
            if(pos == head){
                pop_front();
                return;
            }
            node<T>* tmp = head;
            while(tmp->getNext() != pos.curr) tmp = tmp->getNext();
            tmp->setNext(pos.curr->getNext());
            delete pos.curr;
            len--;
        }

};
#endif