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
            cout<<"3. Sap xep sinh vien theo ten"<<endl;
            cout<<"4. Sap xep sinh vien theo diem"<<endl;
            cout<<"5. Xoa sinh vien"<<endl;
            cout<<"6. Hien thi thong tin lop"<<endl;
            cout<<"7. Thay the sinh vien"<<endl;
            cout<<"8. Tim sinh vien"<<endl;
            cout<<"9. Lam sach man hinh"<<endl;
            cout<<"10. Hien thi menu"<<endl;
            cout<<"11. Thoat"<<endl;
        }   
};

string quanlyAPP::menu(){
    string c;
    while (1)
    {
        cin>>c;
        if(c>="1" && c<="9") return c;
        system("cls");
        cout<<"Lua chon khong hop le, vui long nhap lai!!!!"<<endl;
    }
    
}
void quanlyAPP::run(){
    system("cls");
    p.sortSinhvienAZ();
    hienthi();
    while(1){
        cout<<"Nhap lua chon: ";
        string c = menu();
        if (c == "1") addSinhVien();
        elif (c == "2") addSinhVienFromFile();
        elif (c == "3") p.sortSinhvienAZ();
        elif (c == "4") p.sortSinhvienDiem();
        elif (c == "5") removeSinhVien();
        elif (c == "6") ListSinhvien();
        elif (c == "7") replaceSinhVien();
        elif (c == "8") findSinhVien();
        elif (c == "9") {
            system("cls");
            hienthi();
            continue;
        }
        elif (c == "10") {
            hienthi();
            continue;
        }
        elif (c == "11") {
            cout<<"Cam on ban da su dung chuong trinh"<<endl;
            break;
        }
        
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
    while(!filein.eof()){
        string name,birth,msv,lop;
        double diem;
        getline(filein,name);
        getline(filein,birth);
        getline(filein,msv);
        getline(filein,lop);
        filein>>diem;
        Sinhvien sv(name,birth,msv,lop,diem);
        p.pushSinhVien(sv);
        filein.ignore();
    }
    filein.close();
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