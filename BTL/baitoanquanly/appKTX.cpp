#ifndef APPKTX_CPP
#define APPKTX_CPP
#include "QUANLY.cpp"
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define elif else if
#define endl "\n"
class quanlyAPP{
    private:
        quanly p;
    public:
        int choose();
        void run();
        void addSinhVien();
        void addSinhVienFromFile();
        void findSinhVienName();
        void writeToFile();
        void removeSinhVien();
        void ListSinhvien();
        // sua doi thong tin sinh vien
        void modifySinhVien();
        void menu(){
            cout<<"1. Them sinh vien tu ban phim"<<endl;
            cout<<"2. Them sinh vien tu file"<<endl;
            cout<<"3. Ghi ra file"<<endl;
            cout<<"4. Sap xep sinh vien theo ten"<<endl;
            cout<<"5. Hien thi danh sach sinh vien"<<endl;
            cout<<"6. Xoa sinh vien voi ma sinh vien"<<endl;
            cout<<"7. Sua doi thong tin sinh vien"<<endl;
            cout<<"8. Tim sinh vien theo ten"<<endl;
            cout<<"9. Lam sach man hinh"<<endl;
            cout<<"10. Hien thi menu"<<endl;
            cout<<"11. Thoat"<<endl;
        }   
};

int quanlyAPP::choose(){
    int c;
    while (1)
    {
        cout<<"Nhap lua chon: ";
        cin>>c;
        if(c>=1 && c<=11) return c;
        cout<<"Lua chon khong hop le, vui long nhap lai!!!!"<<endl;
    }
    
}
void quanlyAPP::run(){
    system("cls");
    p.sortSinhvienAZ();
    menu();
    while(1){
        int c = choose();
        if (c == 1) addSinhVien();
        elif (c == 2) addSinhVienFromFile();
        elif (c == 3) writeToFile();
        elif (c == 4) p.sortSinhvienAZ();
        elif (c == 5) ListSinhvien();
        elif (c == 6) removeSinhVien();
        elif (c == 7) modifySinhVien();
        elif (c == 8) findSinhVienName();
        elif (c == 9) {
            system("cls");
            menu();
            continue;
        }
        elif (c == 10) {
            menu();
            continue;
        }
        elif (c == 11) {
            set_color(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout<<"Cam on ban da su dung chuong trinh"<<endl;
            set_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            system("pause");
            break;
        }
        
    }
}
void quanlyAPP::addSinhVien(){
    p.pushSinhVien();
}
void quanlyAPP::addSinhVienFromFile(){
    p.addFromFile();
}
void quanlyAPP:: ListSinhvien(){
    cout<<p;
}
void quanlyAPP::findSinhVienName(){
    string name;
    cout<<"Nhap ho va ten sinh vien can tim: ";
    cin.ignore();
    getline(cin,name);
    cout<<p.find(name);
}
void quanlyAPP:: writeToFile(){
    p.writeFile();
}
void quanlyAPP::removeSinhVien(){
    string msv;
    ListSinhvien();
    cout<<"Nhap ma sinh vien can xoa: ";
    cin.ignore();
    getline(cin,msv);
    p.remove(msv);
}
void quanlyAPP::modifySinhVien(){
    ListSinhvien();
    p.modify();
}
#endif