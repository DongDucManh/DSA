#ifndef PhongKTX_CPP
#define PhongKTX_CPP
#include <bits/stdc++.h>
#include "Sinhvien.cpp"
using namespace std;
#define elif else if
int cmp(Sinhvien a, Sinhvien b){
    return a.getOnlyName() < b.getOnlyName();
}
class Phong{
    private:
        string name;
        string id;
        int soLuongSinhVien;
        list<Sinhvien> sv;
    public:
        Phong(string name, string id, int soLuongSinhVien, list<Sinhvien> sv){
            this->name = name;
            this->id = id;
            this->soLuongSinhVien = soLuongSinhVien;
            this->sv = sv;
        }
        //getter va setter
        // void setName(string name){
        //     this->name = name;
        // }
        // void setId(string id){
        //     this->id = id;
        // }
        void setSoLuongSinhVien(int soLuongSinhVien){
            this->soLuongSinhVien = soLuongSinhVien;
        }
        // void setSv(list<Sinhvien> sv){
        //     this->sv = sv;
        // }
        // string getName(){
        //     return this->name;
        // }
        // string getId(){
        //     return this->id;
        // }
        int getSoLuongSinhVien(){
            return this->soLuongSinhVien;
        }
        // list<Sinhvien> getSv(){
        //     return this->sv;
        // }
        //-------------------------------------
        Phong(){
            this->name = "";
            this->id = "";
            this->soLuongSinhVien = 0;
            this->sv = list<Sinhvien>();
        }
        string find(string name){
            for(auto i:sv){
                if(i.getName() == name) return i.getName();
            }
            return "Khong tim thay";
        }
        friend istream& operator>>(istream &is, Phong &p){
            //is.ignore('\n' - 1e9);
            getline(is,p.name);
            is>>p.id;
            is>>p.soLuongSinhVien;
            return is;
        }
        void pushSinhVien(Sinhvien sv){
            this->sv.push_back(sv);
        }
        friend ostream& operator<<(ostream &os, Phong &p){
            os<<"Name: "<<p.name<<endl;
            os<<"Id: "<<p.id<<endl;
            os<<"So luong sinh vien: "<<p.soLuongSinhVien<<endl;
            os<<left<<setw(25)<<"Name";
            os<<left<<setw(23)<<"Msv";
            os<<left<<setw(25)<<"Age";
            os<<left<<setw(25)<<"Lop"<<endl;
            for(auto i:p.sv){
                os<<i.getName()<<setw(30 - i.getName().size())<<right<<i.getMsv()<<setw(30 - i.getMsv().size())<<i.getAge()<<setw(30)<<i.getLop()<<endl;
            }
            return os;
        }
        void sortSinhvien() {
            sv.sort(cmp);
        }
    
};
#endif