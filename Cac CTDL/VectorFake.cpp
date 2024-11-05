#ifndef VectorFake
#define VectorFake
#include <iostream>
using namespace std;
//#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
#define TIME (1.0*clock())/CLOCKS_PER_SEC
template<class T>
class Vector{
	private:
		T* elements;
		int Size;
		int space;
	public:
		Vector(){
			Size = 0;
			space = 0;
		}
		Vector (int n){
			Size = n;
			space = n;
			elements = new T[n];
			for (int i=0;i<n;i++) elements[i] = T();
		}
		Vector (int n, T value){
			Size = n;
			space = n;
			elements = new T[n];
			for (int i=0;i<n;i++) elements[i] = value;
		}
        int size(){
            return this->Size;
        }
		class iterator{
			private:
				T* curr;
			public:
				iterator (T* p = NULL){
					curr =p;
				}
				iterator& operator++(int){
					curr++;//dich con tro sang nho tiep theo
					return *this;
				}
                iterator& operator--(int){
                    curr = curr -1;
                    return *this;
                }
                iterator operator+ (int i){
                    return curr + i ;
                }
                iterator operator - (int i){
                    return curr - i;
                }

                int operator - (iterator a){//Loi do truyen tham chieu, khong truyen tham tri. Sua lai thanh truyen tham tri
                    return curr - a.curr;
                }
				iterator& operator=(iterator it){
					curr = it.curr;
					return *this;
				}
				bool operator==(iterator it){
					return curr == it.curr;
				}
				bool operator!=(iterator it){
					return !(it == (*this));
				}
				T operator*(){//khong co tham so dau sao dung truoc, dai dien cho con tro, hoac gia tri con tro
					return *curr;
				}
		};
		iterator begin(){
			return iterator(elements);
		}
		iterator end(){
			return iterator(elements + Size);
		}
        iterator rbegin(){
            return iterator(elements + Size -1);
        }
        iterator rend(){
            return elements -1;
        }
		void resever(int n){
			if (n <= space) return;
			T* temp = new T[n];
			for (int i=0; i<Size ;i++) temp[i] = elements[i];
			if (elements != NULL) delete[] elements;
			elements = temp;
			space = n;
		}
		void push_back(T value){
			if (Size == space ) {
				if (space==0) resever(1);
				else
				resever(space*2 );
				elements[Size] = value;
				Size++;
			}
			else{
				elements[Size] = value;
				Size++;
			}
		}
		void pop_back(){
			if (Size == 0) return;
			Size--;
		}
        T& operator[](int i){
            return elements[i];
        }
		~Vector(){
		}
		void insert(iterator it, T val){
			int x = it - begin();
            if(Size == space){
                resever(space*2);//làm thay đổi địa chỉ của elements ban đầu, dẫn đến lỗi
            }
			for (int i = Size; i>x ; i--){
					elements[i] = elements[i-1];
				}
			elements[x] = val; 
			Size++;
        }

		//dinh nghia =
		Vector& operator=(Vector a){
			Size = a.Size;
			space = a.space;
			elements = new T[space];
			for (int i=0;i<Size;i++) elements[i] = a.elements[i];
			return *this;
		}
};
main(){
	Vector <int>a;
	a.push_back(3);
	Vector<int>b;
	b = a;
	cout<<b.size();
}
#endif
