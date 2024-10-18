#ifndef SINHVIEN_CPP
#define SINHVIEN_CPP
#include <bits/stdc++.h>
using namespace std;
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
        string getOnlyName(){
            string tmp="";
            for (int i = name.size()-1; i >= 0; i--){
                if (name[i] == ' ') break;
                tmp = name[i] + tmp;
            }
            return tmp;
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
        Sinhvien(){
            this->name = "";
            this->age = 0;
            this->msv = "";
            this->lop = "";
        }
        void inputfile(string f){
            ifstream filein(f);
            if(filein.fail()){
                cout<<"Khong the mo file"<<endl;
                return;
            }
            while(!filein.eof()){
                getline(filein,name);
                filein>>age;
                filein.ignore();
                getline(filein,msv);
                getline(filein,lop);
                Sinhvien sv(name,age,msv,lop);
            }
            filein.close();
        }
        friend istream& operator>>(istream &is, Sinhvien &sv){
            cout<<"Nhap ten: ";
            is.ignore();
            getline(is,sv.name);
            cout<<"Nhap tuoi: ";
            is>>sv.age;
            cout<<"Nhap msv: ";
            is>>sv.msv;
            cout<<"Nhap lop: ";
            is.ignore();
            getline(is,sv.lop);
            return is;
        }
        friend ostream& operator<<(ostream &os, Sinhvien &sv){
            os<<"Name: "<<sv.name<<endl;
            os<<"Age: "<<sv.age<<endl;
            os<<"Msv: "<<sv.msv<<endl;
            os<<"Lop: "<<sv.lop<<endl;
            return os;
        }
        bool operator==(Sinhvien &sv){
            return this->name == sv.name && this->age == sv.age && this->msv == sv.msv && this->lop == sv.lop;
        }
        bool operator<(Sinhvien &sv){
            return this->name < sv.name;
        }
        void show(){
            cout<< left <<setw(10)<<"Name: "<<this->name<<endl;
            cout<< left <<setw(10)<<"Age: "<<this->age<<endl;
            cout<< left <<setw(10)<<"Msv: "<<this->msv<<endl;
            cout<< left <<setw(10)<<"Lop: "<<this->lop<<endl;
        }
};
#endif