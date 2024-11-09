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
        string lower(string s){
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s;
        }
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
            name = lower(name);
            for(auto i:sinhviens){
                if(lower(i.getName()) == name){
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

        void modify(){
            int n;
            cout<<"Chon sinh vien can sua: ";
            cin>>n;
            if(n<0 || n>soLuongSinhVien){
                cout<<"Khong tim thay sinh vien"<<endl;
                return;
            }
            list<Sinhvien>::iterator x = sinhviens.begin();
            for (int i = 0; i < getSoLuongSinhVien(); i++, x++)
            {
                if(i == n-1){
                    cout<<"Nhap thong tin moi( nhap -1 voi thong tin khong thay doi): "<<endl;
                    string name,birth,msv,lop;
                    int sex;
                    cout<<"Nhap ho ten: ";
                    cin.ignore();
                    getline(cin,name);
                    cout<<"Nhap msv: ";
                    getline(cin,msv);
                    cout<<"Nhap ngay sinh: ";
                    getline(cin,birth);
                    cout<<"Nhap gioi tinh(1: Nam, 0: Nu): ";
                    cin>>sex;
                    cout<<"Nhap lop: ";
                    cin.ignore();
                    getline(cin,lop);

                    if(name != "-1") (*x).setName(name);
                    if(msv != "-1") (*x).setMsv(msv);
                    if(birth != "-1") (*x).setBirthday(birth);
                    if (sex != -1) (*x).setSex(sex);
                    if(lop != "-1") (*x).setLop(lop);
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
            fileout << *this;
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
                << setw(30) << i.getBirthday()
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