#ifndef QUANLY_CPP
#define QUANLY_CPP
#include <bits/stdc++.h>
#include "Sinhvien.cpp"
using namespace std;
#define elif else if
int cmpName(Sinhvien a, Sinhvien b){
    return a.getOnlyName() < b.getOnlyName();
}
int cmpDiem(Sinhvien a, Sinhvien b){
    return a.getDiem() > b.getDiem();
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
        string findM(string MSV){
            bool ok = false;
            for(auto i:sv){
                if(i.getMsv() == MSV){
                    cout<<i;
                    ok = true;
                }
            }
            if(ok) return "";
            return "Khong tim thay\n";
        }
        Sinhvien* findM2(string MSV){
            for(auto i=sv.begin();i!=sv.end();i++){
                if(i->getMsv() == MSV){
                    return &(*i);
                }
            }
            return NULL;
        }


        void pushSinhVien(Sinhvien sv){
            this->sv.push_back(sv);
            soLuongSinhVien++;
        }
        void remove(string ma){
            for(auto i=sv.begin();i!=sv.end();i++){
                if(i->getMsv() == ma){
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
        friend ostream& operator<<(ostream &os, quanly &p) {
            os << "Name: " << p.name << endl;
            os << "So luong sinh vien: " << p.soLuongSinhVien << endl;
            os <<setfill('-')<<setw(130)<<"-"<<endl;
            os<<setfill(' ');
            os << left << setw(30) << "Name"
            << setw(30) << "Birth"
            << setw(30) << "Msv"
            << setw(30) << "Lop" 
            << setw(30) << "Diem" << endl;
            os << setfill('-') << setw(130) << "-" << endl;
            os << setfill(' ');
            for (auto i : p.sv) {
                os << left << setw(30) << i.getName()
                << setw(30) << i.getBirth()
                << setw(30) << i.getMsv()
                << setw(30) << i.getLop()
                << setw(30) << i.getDiem() << endl;
            }
            os << setfill('-') << setw(130) << "-" << endl;
            return os;
        }
        void sortSinhvienAZ() {
            sv.sort(cmpName);
        }
        void sortSinhvienDiem() {
            sv.sort(cmpDiem);
        }
    
};
#endif