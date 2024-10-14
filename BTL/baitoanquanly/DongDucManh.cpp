// quan ly sinh vien o ktx
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
class Sinhvien{
    private:
        string name;
        int age;
        string msv;
        string lop;
    public:
        Sinhvien(string name, int age, string msv, string lop){
            this->name = name;
            this->age = age;
            this->msv = msv;
            this->lop = lop;
        }
        //getter va setter
        void setName(string name){
            this->name = name;
        }
        void setAge(int age){
            this->age = age;
        }
        void setMsv(string msv){
            this->msv = msv;
        }
        void setLop(string lop){
            this->lop = lop;
        }
        string getName(){
            return this->name;
        }
        int getAge(){
            return this->age;
        }
        string getMsv(){
            return this->msv;
        }
        string getLop(){
            return this->lop;
        }
        //-------------------------------------


        void show(){
            cout<<"Name: "<<this->name<<endl;
            cout<<"Age: "<<this->age<<endl;
            cout<<"Msv: "<<this->msv<<endl;
            cout<<"Lop: "<<this->lop<<endl;
        }
};
class phong{//quan ly phong o ktx
    private:
        string toanha;
        string name;
        int songuoi;
        list<Sinhvien> sv;
    public:
        phong(string toanha, string name, int songuoi){
            this->toanha = toanha;
            this->name = name;
            this->songuoi = songuoi;
        }
        void setToanha(string toanha){
            this->toanha = toanha;
        }
        void setName(string name){
            this->name = name;
        }
        void setSonguoi(int songuoi){
            this->songuoi = songuoi;
        }
        string getToanha(){
            return this->toanha;
        }
        string getName(){
            return this->name;
        }
        int getSonguoi(){
            return this->songuoi;
        }
        void addSv(Sinhvien sv){
            this->sv.push_back(sv);
        }
        void show(){
            cout<<"Toa nha: "<<this->toanha<<endl;
            cout<<"Ten phong: "<<this->name<<endl;
            cout<<"So nguoi: "<<this->songuoi<<endl;
            cout<<"Danh sach sinh vien: "<<endl;
            for(auto i: this->sv){
                i.show();
            }
        }
        void insertSv(Sinhvien sv, int pos){
            auto it = this->sv.begin();
            advance(it, pos);
            this->sv.insert(it, sv);
        }
        void pushbackSv(Sinhvien sv){
            this->sv.push_back(sv);
        }
        void popbackSv(){
            this->sv.pop_back();
        }
        void eraseSv(int pos){
            auto it = this->sv.begin();
            advance(it, pos);
            this->sv.erase(it);
        }
};
main(){
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}