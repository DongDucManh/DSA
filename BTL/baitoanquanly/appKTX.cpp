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
        string menu();
        void run();
        void addSinhVien();
        void addSinhVienFromFile();
        void findSinhVien();
        void removeSinhVien();
        void ListSinhvien();
        void replaceSinhVien();
        void hienthi(){
            cout<<"1. Them sinh vien tu ban phim"<<endl;
            cout<<"2. Them sinh vien tu file"<<endl;
            cout<<"3. Xoa sinh vien"<<endl;
            cout<<"4. Hien thi thong tin phong"<<endl;
            cout<<"5. Thay the sinh vien"<<endl;
            cout<<"6. Tim sinh vien"<<endl;
            cout<<"7. Thoat"<<endl;
            cout<<"Chon: ";
        }   
};

string quanlyAPP::menu(){
    string c;
    while (1)
    {
        hienthi();
        cin>>c;
        if(c>="1" && c<="7") return c;
        system("cls");
        cout<<"Lua chon khong hop le, vui long nhap lai!!!!"<<endl;
    }
    
}
void quanlyAPP::run(){
    system("cls");
    while(1){
        p.sortSinhvien();
        string c = menu();
        if(c == "1") addSinhVien();
        elif(c == "2") {addSinhVienFromFile();system("pause");}
        elif(c == "3") {removeSinhVien();system("pause");}
        elif(c == "4") {ListSinhvien();system("pause");}
        elif(c == "5") {replaceSinhVien();system("pause");}
        elif(c == "6") {findSinhVien();system("pause");}
        elif(c == "7") break;
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
void quanlyAPP:: ListSinhvien(){
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
    string name;
    cout<<"Nhap ten sinh vien can xoa: ";
    cin.ignore();
    getline(cin,name);
    p.remove(name);
}
void quanlyAPP::replaceSinhVien(){
    string name;
    cout<<"Nhap ten sinh vien can thay the: ";
    cin.ignore();
    getline(cin,name);
    p.remove(name);
    cout<<"Nhap thong tin sinh vien moi:\n"<<endl;
    Sinhvien sv;
    cin>>sv;
    p.pushSinhVien(sv);
    cout<<"Thay the sinh vien thanh cong"<<endl;
}
#endif