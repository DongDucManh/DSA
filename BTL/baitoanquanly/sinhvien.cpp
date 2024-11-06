#ifndef SINHVIEN_CPP
#define SINHVIEN_CPP
#include <bits/stdc++.h>
using namespace std;
#define elif else if
#define fix_(x) setprecision(x)<<fixed
class Sinhvien{
    private:
        string name;
        string birth;
        string msv;
        int sex;//1 la nam, 0 la nu
        string lop;
    public:
        Sinhvien(string name,string msv, string birth, int sex, string lop ){
            this->name = name;
            this->birth = birth;
            this->msv = msv;
            this->lop = lop;
            this->sex = sex;
        }
        //getter va setter
        void setName(string name){
            this->name = name;
        }
        void setBirth(string birth){
            this->birth = birth;
        }
        void setMsv(string msv){
            this->msv = msv;
        }
        void setLop(string lop){
            this->lop = lop;
        }
        void setSex(int sex){
            this->sex = sex;
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
        string getBirth(){
            return this->birth;
        }
        string getMsv(){
            return this->msv;
        }
        string getLop(){
            return this->lop;
        }
        int getSex(){
            return sex;
        }
        //-------------------------------------
        Sinhvien(){
            this->name = "";
            this->birth = "";
            this->msv = "";
            this->lop = "";
            this->sex = -1;
        }

        friend istream& operator>>(istream &is, Sinhvien &sv){
            cout<<"Nhap ten: ";
            is.ignore();
            getline(is,sv.name);
            cout<<"Nhap msv: ";
            is>>sv.msv;
            cout<<"Nhap ngay sinh: ";
            is.ignore();
            getline(is,sv.birth);
            cout<<"Nhap gioi tinh(1 la nam, 0 la nu): ";
            is>>sv.sex;
            cout<<"Nhap lop: ";
            is.ignore();
            getline(is,sv.lop);
            return is;
        }
        friend ostream& operator<<(ostream &os, Sinhvien &sv){
            os<<"Name: "<<sv.name<<endl;
            os<<"Msv: "<<sv.msv<<endl;
            os<<"Birth: "<<sv.birth<<endl;
            os<<"Gioi tinh: "<<sv.sex<<endl;
            os<<"Lop: "<<sv.lop<<endl;
            return os;
        }
        bool operator<(Sinhvien &sv){
            return this->name < sv.name;
        }
        void show(){
            cout<< left <<setw(10)<<"Ho ten: "<<this->name<<endl;
            cout<< left <<setw(10)<<"Ma sinh vien: "<<this->msv<<endl;
            cout<< left <<setw(10)<<"Ngay sinh: "<<this->birth<<endl;
            cout<< left <<setw(10)<<"Gioi tinh: "<<this->sex<<endl;
            cout<< left <<setw(10)<<"Lop: "<<this->lop<<endl;
        }
};
#endif