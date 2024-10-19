#ifndef QUANLY_CPP
#define QUANLY_CPP
#include <bits/stdc++.h>
#include "Sinhvien.cpp"
using namespace std;
#define elif else if
int cmp(Sinhvien a, Sinhvien b){
    return a.getOnlyName() < b.getOnlyName();
}
class quanly{
    private:
        string name;
        int soLuongSinhVien;
        list<Sinhvien> sv;
    public:
        quanly(string name = "KHMT", int soLuongSinhVien=0, list<Sinhvien> sv = list<Sinhvien>()){
            this->name = name;
            this->soLuongSinhVien = soLuongSinhVien;
            this->sv = sv;
        }
        int getSoLuongSinhVien(){
            return this->soLuongSinhVien;
        }
        // quanly(){
        //     this->name = "";
        //     this->soLuongSinhVien = 0;
        //     this->sv = list<Sinhvien>();
        // }
        string find(string name){
            bool ok = false;
            for(auto i:sv){
                if(i.getOnlyName() == name){
                    cout<<i;
                    ok = true;
                }
            }
            if(ok) return "";
            return "Khong tim thay\n";
        }
        void pushSinhVien(Sinhvien sv){
            this->sv.push_back(sv);
            soLuongSinhVien++;
        }
        void remove(string namee){
            for(auto i=sv.begin();i!=sv.end();i++){
                if(i->getName() == namee){
                    sv.erase(i);
                    soLuongSinhVien--;
                    return;
                }
            }
        }


        friend istream& operator>>(istream &is, quanly &p){
            //is.ignore('\n' - 1e9);
            getline(is,p.name);
            is>>p.soLuongSinhVien;
            return is;
        }
        friend ostream& operator<<(ostream &os, quanly &p){
            os<<"Name: "<<p.name<<endl;
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