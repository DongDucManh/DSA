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
        slist():head(NULL), trail(NULL), len(0){}
        slist(T n){
            len = n;
            head = new node<T>();
            node<T>* tmp = head;
            for(int i = 1; i < n; i++){
                tmp->setNext(new node<T>());
                tmp = tmp->getNext();
            }
            trail = tmp;
        }
        class iterator{
            private:
                node<T>* curr;
            public:
                iterator(node<T>* p): curr(p){}
                iterator(): curr(NULL){}
                iterator (const iterator& it){
                    curr = it.curr;
                }
                iterator& operator=(const iterator& it){
                    curr = it.curr;
                    return *this;
                }
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
        void insert(int pos, T val){
            if (pos < 0 || pos > len) return;
            if (len==0) {
                push_back(val);
                return;
            }
            if (pos == 0) {
                push_front(val);
                return;
            }
            if (pos == len) {
                push_back(val);
                return;
            }
            node<T>* tmp = head;
            for (int i = 0; i < pos-1; i++)
            {
                tmp = tmp->getNext();
            }
            tmp->setNext(new node<T>(val, tmp->getNext()));
            len++;
        }
        void erase(int pos){
            if (pos < 0 || pos >= len) return;
            if (len == 0) return;
            if (len == 1){
                pop_back();
                return;
            }
            if (pos == 0){
                pop_front();
                return;
            }
            node<T>* tmp = head;
            for (int i = 0; i < pos-1; i++)
            {
                tmp = tmp->getNext();
            }
            node<T>* tmp2 = tmp->getNext();
            tmp->setNext(tmp2->getNext());
            delete tmp2;
            len--;
        }

};
#endif