// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define main signed main
// #define elif else if
// #define fix_(x) setprecision(x)<<fixed
// #define TIME (1.0*clock())/CLOCKS_PER_SEC
// template <class T>
// class Node{
//     private:
//         T element;
//         Node *next;
//     public:
//         Node(T e=T(), Node *n=NULL){
//             element = e;
//             next = n;
//         }
//         T& getElement(){
//             return element;
//         }
//         Node<T>*& getNext(){
//             return next;
//         }
//         void setElement(T e){
//             element = e;
//         }
//         void setNext(Node<T> *n){
//             next = n;
//         }
// };
// template <class T>
// class List{
//     private:
//         Node<T> *head;
//         Node<T> *tail;
//         int length;
//     public:
//         List(): head(NULL), tail(NULL), length(0){}
//         //bộ lặp
//         class iterator{
//             private:
//                 Node<T> *node;
//             public:
//                 iterator ()
//         };

//         //adnashdkajdkasjdkajdajdlajdladladklwadawd
//         int size(){
//             return length;
//         }
//         bool empty(){
//             return length == 0;
//         }
//         T& front(){
//             return *head.getElenment();
//         }
//         T& back(){
//             return *tail.getElement();
//         }
//         void push_front(T e){
//             head = new Node<T>(e, head);
//             if(length ==1) tail = head;
//             length++;
//         }
//         void push_back(T e){
//             if (length ==0) push_front(e);
//             else{
//                 tail -> setNext(new Node<T>(e,NULL));
//                 tail = tail -> getNext();
//                 length++;
//             }
//         }
//         void pop_front(){
//             if(length==0) return;
//             if (length==1) head =tail = NULL;
//             else{
//                 head = head->getNext();
//             }
//             length--;
//         }
//         void pop_back(){
//             if(length == 0) return;
//             if (length==1) head =tail = NULL;
//             else{
//                 Node<T> *p = head;
//                 while (p->getNext() != tail)
//                 {
//                     p = p->getNext();
//                 }
//                 p->setNext(NULL);
//                 tail = p;
//             }
//             length--;
//         }
// };
// main(){
//     cin.tie(0)->sync_with_stdio(0);
//     List<int> a;
    
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
const long long MOD=2'000'000'000'000'000'001;
unsigned long long pow_mod(int x, int exp){
    if(exp == 0) return 1;
    unsigned long long tmp = pow_mod(x,exp/2)%MOD;
    unsigned long long res = tmp*tmp%MOD;
    if(exp&1) res = res*x%MOD;
    return res;
}
main(){
    int i=64;
   
        cout<<pow_mod(2,i-1)<<" "<<((unsigned long long)1<<(i-1))%MOD<<endl;
    
}