#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Queue{
	int Size,space,f,l;
	T* elem;
	public:
		Queue(){
			Size = space = f = l =0;
			elem = NULL;
		}
		~Queue(){
			if (elem != NULL) delete[] elem;
		}
		Queue<T>& operator=(Queue<T>& a){
			Size = a.Size;
			space = a.space;
			f = a.f;
			l = a.l;
			T* tmp = new T[space];
			for (int i=0;i<size;i++){
				tmp[i] = a.elem[i];
			}
			if (elem != NULL) delete[] elem;
			elem = tmp;
			return *this;
		}
		Queue(Queue<T>& A){
			*this = A;
		}
		bool empty(){
			return Size==0;
		}
		int size(){
			return size;
		}
		T& front(){
			return elem[f];
		}
		T& back(){
			if (l==0) return elem[space-1];
			return elem[l-1];
		}
		void push(T val){
			if (Size == space){
				space = space == 0 ? 1 : space*2;
				T* tmp = new T[space];
				for(int i = 0, j = f; i<Size; i++, j = (j+1)%Size){
					tmp[i] = elem[j];
				}
				if (elem != NULL) delete[] elem;
				elem = tmp;
				f = 0;
				l = Size;
			}
			elem[l] = val;
			l = (l+1)%space;
			Size++;
		}
		void pop(){
			if (Size == 0) return;
			f = (f+1)%space;
			Size--;
		}
		
};
main(){
	Queue<int> q;
	q.push(1);
	q.push(2);
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
}