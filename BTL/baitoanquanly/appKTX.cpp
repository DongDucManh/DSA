#ifndef APPKTX_CPP
#define APPKTX_CPP
#include "QUANLY.cpp"
#include <bits/stdc++.h>
using namespace std;
#define elif else if
class quanlyAPP{
    private:
        quanly p;
    public:
        int menu();
        void run();
        void addSinhVien();
        void addSinhVienFromFile();
        void findSinhVien();
        void removeSinhVien();
        void showPhong();
        void replaceSinhVien();
};
int quanlyAPP::menu(){
    cout<<"1. Them sinh vien tu ban phim"<<endl;
    cout<<"2. Them sinh vien tu file"<<endl;
    cout<<"3. Xoa sinh vien"<<endl;
    cout<<"4. Hien thi thong tin phong"<<endl;
    cout<<"5. Thay the sinh vien"<<endl;
    cout<<"6. Tim sinh vien"<<endl;
    cout<<"7. Thoat"<<endl;
    cout<<"Chon: ";
    int c;
    cin>>c;
    return c;
}
void quanlyAPP::run(){
    system("cls");
    while(1){
        p.sortSinhvien();
        int c = menu();
        if(c == 1) addSinhVien();
        elif(c == 2) {addSinhVienFromFile();system("pause");}
        elif(c == 3) removeSinhVien();
        elif(c == 4) {showPhong();system("pause");}
        elif(c == 5) replaceSinhVien();
        elif(c == 6) findSinhVien();
        elif(c == 7) break;
        system("cls");
    }
}
void quanlyAPP::addSinhVien(){
    Sinhvien sv;
    cin>>sv;
    p.pushSinhVien(sv);
}
void quanlyAPP::addSinhVienFromFile(){
    string path;
    cout<<"Nhap duong dan file: ";
    cin.ignore();
    getline(cin,path);
    ifstream filein(path);
    if(filein.fail()){
        cout<<"Khong the mo file"<<endl;
        return;
    }
    filein.ignore('\n'-1e9);
    while(!filein.eof()){
        Sinhvien sv;
        filein>>sv;
        p.pushSinhVien(sv);
    }
    filein.close();
    system("cls");
    cout<<"Them sinh vien thanh cong"<<endl;
}
void quanlyAPP:: showPhong(){
    cout<<p;
}
void quanlyAPP::findSinhVien(){
    string name;
    cout<<"Nhap ten sinh vien can tim: ";
    cin.ignore();
    getline(cin,name);
    cout<<p.find(name);
}
void quanlyAPP::removeSinhVien(){
    string msv;
    cout<<"Nhap msv cua sinh vien can xoa: ";
    cin>>msv;
}
void quanlyAPP::replaceSinhVien(){
    string msv;
    cout<<"Nhap msv cua sinh vien can thay the: ";
    cin>>msv;
}
#endif