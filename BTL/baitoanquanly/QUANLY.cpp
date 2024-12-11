#ifndef QUANLY_CPP
#define QUANLY_CPP
#include <bits/stdc++.h>
#include "Sinhvien.cpp"
using namespace std;
#define elif else if
int cmpName(Sinhvien a, Sinhvien b){
    return a < b;
}
string lower(string s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}
class Quanly{
    private:
        list<Sinhvien> sinhviens;
    public:
        int getSoLuongSinhVien();
        string find(string name);
        string findhp(string name);
        void pushSinhVien();
        void remove(string ma);
        void modify();
//        Sinhvien findhp(string name);
        void addFromFile();
        void writeFile();
        void sortSinhvienAZ();
        friend ostream& operator<<(ostream &os, Quanly &p){
            os<<endl;
            set_color(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            os << "So luong sinh vien: " << p.getSoLuongSinhVien() << endl;
            os << "Danh sach sinh vien " << endl;
            os <<setfill('-')<<setw(140)<<"-"<<endl;
            os<<setfill(' ');
            os << left << setw(10) << "STT" 
                << setw(30) << "Ho va ten"
                << setw(30) << "Msv"
                << setw(30) << "Ngay sinh"
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
            set_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            return os;
        }
};
int Quanly::getSoLuongSinhVien(){
    return sinhviens.size();
}
string Quanly::findhp(string name){
    name = lower(name);
    for (auto i : sinhviens){
        if (lower(i.getName()) == name){
            i.showHocphan();
            return "";
        }
    }
    return "Khong tim thay\n";
}
string Quanly::find(string name){
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
void Quanly::pushSinhVien(){
    int n;
    back:
    set_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout<<"Nhap so sinh vien muon them: ";
    cin>>n;
    if(cin.fail()){
        set_color(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout<<"Nhap khong hop le"<<endl;
        set_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto back;
    }
    for (int i=0;i<n;i++){
        Sinhvien sv;
        cin>>sv;
        sinhviens.push_back(sv);
    }
    set_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void Quanly::remove(string ma){
    for(auto i=sinhviens.begin();i!=sinhviens.end();i++){
        if(i->getMsv() == ma){
            sinhviens.erase(i);
            return;
        }
    }
}
void Quanly::modify(){
    int n;
    back:
    cout<<"Chon sinh vien can sua: ";
    cin>>n;
    if(cin.fail()){
        set_color(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout<<"Nhap khong hop le"<<endl;
        set_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto back;
    }
    if(n<0 || n>sinhviens.size()){
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
void Quanly::addFromFile(){
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
        int sex,shp;
        vector<pair<string,double>> hocphan;
        getline(filein, name);
        getline(filein, birth);
        getline(filein, msv);
        filein >> sex;
        filein >> shp;
        filein.ignore();
        for (int i=0;i<shp;i++){
                string thp;
                int d;
                getline(filein,thp);
                filein>>d;
                hocphan.push_back({thp, d});
        }
        getline(filein, lop);
        Sinhvien sv(name, msv, birth, sex,shp , hocphan, lop);
        sinhviens.push_back(sv);
    }
    filein.close();
    cout<<"Them sinh vien thanh cong"<<endl;
}
void Quanly::writeFile(){
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
void Quanly::sortSinhvienAZ(){
    sinhviens.sort(cmpName);
}
#endif