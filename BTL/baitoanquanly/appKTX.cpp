#include "PhongKTX.cpp"
#include <bits/stdc++.h>
using namespace std;
#define elif else if
class phongAPP{
    private:
        Phong p;
    public:
        int menu();
        void run();
        void addSinhVien();
        void findSinhVien();
        void removeSinhVien();
        void showPhong();
        void replaceSinhVien();
};
int phongAPP::menu(){
    cout<<"1. Them sinh vien"<<endl;
    cout<<"2. Xoa sinh vien"<<endl;
    cout<<"3. Hien thi thong tin phong"<<endl;
    cout<<"4. Thay the sinh vien"<<endl;
    cout<<"5. Tim sinh vien"<<endl;
    cout<<"6. Thoat"<<endl;
    cout<<"Chon: ";
    int c;
    cin>>c;
    return c;
}
void phongAPP::run(){
    system("cls");
    while(1){
        p.sortSinhvien();
        int c = menu();
        if(c == 1) addSinhVien();
        elif(c == 2) removeSinhVien();
        elif(c == 3) {showPhong(); system("pause");}
        elif(c == 4) replaceSinhVien();
        elif(c == 5) findSinhVien();
        elif(c == 6) break;
        system("cls");
    }
}
void phongAPP::addSinhVien(){
    Sinhvien sv;
    cin>>sv;
    p.pushSinhVien(sv);
}

void phongAPP:: showPhong(){
    cout<<p;
}
void phongAPP::findSinhVien(){
    string name;
    cout<<"Nhap ten sinh vien can tim: ";
    cin.ignore();
    getline(cin,name);
    cout<<p.find(name);
}
void phongAPP::removeSinhVien(){
    string msv;
    cout<<"Nhap msv cua sinh vien can xoa: ";
    cin>>msv;
}
void phongAPP::replaceSinhVien(){
    string msv;
    cout<<"Nhap msv cua sinh vien can thay the: ";
    cin>>msv;
}
main(){
    phongAPP app;
    app.run();
}
