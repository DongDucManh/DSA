#ifndef QUANLY_CPP
#define QUANLY_CPP
#include <bits/stdc++.h>
#include "Sinhvien.cpp"
using namespace std;
#define elif else if
int cmpName(Sinhvien a, Sinhvien b){
    return a.getOnlyName() < b.getOnlyName();
}
class quanly{
    private:
        int soLuongSinhVien;
        list<Sinhvien> sinhviens;
    public:
        quanly( int soLuongSinhVien=0, list<Sinhvien> sv = list<Sinhvien>()){
            this->soLuongSinhVien = soLuongSinhVien;
            this->sinhviens = sv;
        }
        int getSoLuongSinhVien(){
            return this->soLuongSinhVien;
        }
        string find(string name){
            bool ok = false;
            for(auto i:sinhviens){
                if(i.getName() == name){
                    cout<<i;
                    ok = true;
                }
            }
            if(ok) return "";
            return "Khong tim thay\n";
        }
        string findM(string MSV){
            bool ok = false;
            for(auto i:sinhviens){
                if(i.getMsv() == MSV){
                    cout<<i;
                    ok = true;
                }
            }
            if(ok) return "";
            return "Khong tim thay\n";
        }
        Sinhvien* findM2(string MSV){
            for(auto i=sinhviens.begin();i!=sinhviens.end();i++){
                if(i->getMsv() == MSV){
                    return &(*i);
                }
            }
            return NULL;
        }
        void pushSinhVien(Sinhvien sv){
            this->sinhviens.push_back(sv);
            soLuongSinhVien++;
        }

        void remove(string ma){
            for(auto i=sinhviens.begin();i!=sinhviens.end();i++){
                if(i->getMsv() == ma){
                    sinhviens.erase(i);
                    soLuongSinhVien--;
                    return;
                }
            }
        }


        void addFromFile(){
            string path;
            cout<<"Nhap duong dan file: ";
            cin.ignore();
            getline(cin, path);
            ifstream filein(path);
            if(filein.fail()){
                cout<<"Khong the mo file"<<endl;
                return;
            }
            while(!filein.eof()){
                string name, birth, msv, lop;
                int sex;
                getline(filein, name);
                getline(filein, birth);
                getline(filein, msv);
                filein >> sex;
                filein.ignore();
                getline(filein, lop);
                Sinhvien sv(name, msv, birth, sex, lop);
                pushSinhVien(sv);
            }
            filein.close();
            cout<<"Them sinh vien thanh cong"<<endl;
        }
        void writeFile(){
            string path;
            cout<<"Nhap duong dan file: ";
            cin.ignore();
            getline(cin, path);
            ofstream fileout(path);
            if(fileout.fail()){
                cout<<"Khong the mo file"<<endl;
                return;
            }
            fileout << "So luong sinh vien: " << soLuongSinhVien << endl;
            fileout <<setfill('-')<<setw(140)<<"-"<<endl;
            fileout<<setfill(' ');
            fileout << left << setw(10) << "STT" 
                << setw(30) << "Name"
                << setw(30) << "Msv"
                << setw(30) << "Birth"
                << setw(30) << "Gioi tinh" 
                << setw(30) << "Lop" << endl;
            fileout << setfill('-') << setw(140) << "-" << endl;
            fileout << setfill(' ');
            int stt = 1;
            for (auto i : sinhviens) {
                fileout << left << setw(10) << stt++
                << setw(30) << i.getName()
                << setw(30) << i.getMsv()
                << setw(30) << i.getBirth()
                << setw(30) << (i.getSex()==1?"Nam":"Nu")
                << setw(30) << i.getLop()<< endl;
            }
            fileout << setfill('-') << setw(140) << "-" << endl;
            fileout.close();
            cout<<"Ghi file thanh cong"<<endl;
        }

        Sinhvien& operator[](int i){
            int j = 0;
            for(auto it = sinhviens.begin();it!=sinhviens.end();it++){
                if(j == i){
                    return *it;
                }
                j++;
            }
        }
        friend istream& operator>>(istream &is, quanly &p){
            //is.ignore('\n' - 1e9);
            is>>p.soLuongSinhVien;
            return is;
        }
        friend ostream& operator<<(ostream &os, quanly &p) {
            os << "So luong sinh vien: " << p.soLuongSinhVien << endl;
            os <<setfill('-')<<setw(140)<<"-"<<endl;
            os<<setfill(' ');
            os << left << setw(10) << "STT" 
                << setw(30) << "Name"
                << setw(30) << "Msv"
                << setw(30) << "Birth"
                << setw(30) << "Gioi tinh" 
                << setw(30) << "Lop" << endl;
            os << setfill('-') << setw(140) << "-" << endl;
            os << setfill(' ');
            int stt = 1;
            for (auto i : p.sinhviens) {
                os << left << setw(10) << stt++
                << setw(30) << i.getName()
                << setw(30) << i.getMsv()
                << setw(30) << i.getBirth()
                << setw(30) << (i.getSex()==1?"Nam":"Nu")
                << setw(30) << i.getLop()<< endl;
            }
            os << setfill('-') << setw(140) << "-" << endl;
            return os;
        }


        void sortSinhvienAZ() {
            sinhviens.sort(cmpName);
        }
};
#endif