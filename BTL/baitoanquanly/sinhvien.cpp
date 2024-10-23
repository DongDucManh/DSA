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
        double diem;
        string lop;
    public:
        Sinhvien(string name, string ngayinh, string msv, string lop, float diem){
            this->name = name;
            this->birth = birth;
            this->msv = msv;
            this->lop = lop;
            this->diem = diem;
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
        void setDiem(double diem){
            this->diem = diem;
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
        double getDiem(){
            return this->diem;
        }
        //-------------------------------------
        Sinhvien(){
            this->name = "";
            this->birth = "";
            this->msv = "";
            this->lop = "";
            this->diem = 0;
        }
        void inputfile(string f){
            ifstream filein(f);
            if(filein.fail()){
                cout<<"Khong the mo file"<<endl;
                return;
            }
            while(!filein.eof()){
                getline(filein,name);
                filein>>birth;
                filein.ignore();
                getline(filein,msv);
                getline(filein,lop);
                Sinhvien sv(name,birth,msv,lop,diem);
            }
            filein.close();
        }
        friend istream& operator>>(istream &is, Sinhvien &sv){
            cout<<"Nhap ten: ";
            is.ignore();
            getline(is,sv.name);
            cout<<"Nhap ngay sinh: ";
            is.ignore();
            getline(is,sv.birth);
            cout<<"Nhap msv: ";
            is>>sv.msv;
            cout<<"Nhap lop: ";
            is.ignore();
            getline(is,sv.lop);
            cout<<"Nhap diem: ";
            is>>sv.diem;
            return is;
        }
        friend ostream& operator<<(ostream &os, Sinhvien &sv){
            os<<"Name: "<<sv.name<<endl;
            os<<"Birth: "<<sv.birth<<endl;
            os<<"Msv: "<<sv.msv<<endl;
            os<<"Lop: "<<sv.lop<<endl;
            os<<"Diem: "<<sv.diem<<endl;
            return os;
        }
        bool operator==(Sinhvien &sv){
            return this->name == sv.name && this->birth == sv.birth && this->msv == sv.msv && this->lop == sv.lop;
        }
        bool operator<(Sinhvien &sv){
            return this->name < sv.name;
        }
        void show(){
            cout<< left <<setw(10)<<"Name: "<<this->name<<endl;
            cout<< left <<setw(10)<<"Birth: "<<this->birth<<endl;
            cout<< left <<setw(10)<<"Msv: "<<this->msv<<endl;
            cout<< left <<setw(10)<<"Lop: "<<this->lop<<endl;
            cout<< left <<setw(10)<<"Diem: "<<fix_(2)<<this->diem<<endl;
        }
};
#endif