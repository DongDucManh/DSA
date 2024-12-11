#ifndef SINHVIEN_CPP
#define SINHVIEN_CPP
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void set_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#define elif else if
#define fix_(x) setprecision(x)<<fixed
class Sinhvien{
    private:
        string name;
        string birthday;
        string msv;
        int sex;//1 la nam, 0 la nu
        string lop;
        int shp;
        vector<pair<string,double>> hocphan;
    public:
        Sinhvien(){
            this->name = "";
            this->birthday = "";
            this->msv = "";
            this->lop = "";
            this->sex = -1;
            this->shp = 0;
        }
        Sinhvien(string name,string msv, string birthday, int sex,int shp ,vector<pair<string,double>> hp, string lop ){
            this->name = name;
            this->birthday = birthday;
            this->msv = msv;
            this->lop = lop;
            this->sex = sex;
            this->shp = shp;
            for (int i=0;i<shp;i++){
                hocphan[i] = hp[i];
            }
        }
        //getter va setter
        void setName(string name){
            this->name = name;
        }
        void setBirthday(string birthday){
            this->birthday = birthday;
        }
        void setMsv(string msv){
            this->msv = msv;
        }
        void setLop(string lop){
            this->lop = lop;
        }
        void setSex(int sex){
            this->sex = sex;
        }
        void setShp(int x){
            this->shp =x;
        }
        void setHocphan(const vector<pair<string,double>> hocphan){
            this->hocphan = hocphan;
        }
        string getName(){
            return this->name;
        }
        string getOnlyName(){
            string tmp="";
            int k = name.size()-1;
            while (k>=0 && name[k] == ' ') k--;
            for (int i = k; i >= 0; i--){
                if (name[i] == ' ') break;
                tmp = name[i] + tmp;
            }
            return tmp;
        }
        string getBirthday(){
            return this->birthday;
        }
        string getMsv(){
            return this->msv;
        }
        string getLop(){
            return this->lop;
        }
        int getSex(){
            return sex;
        }
        int getShp(){
            return shp;
        }
        vector<pair<string, double>> getHocphan(){
            return hocphan;
        }
        //-------------------------------------
        friend istream& operator>>(istream &is, Sinhvien &sv){
            cout<<"Nhap ten: ";
            is.ignore();
            getline(is,sv.name);
            cout<<"Nhap msv: ";
            is>>sv.msv;
            cout<<"Nhap ngay sinh: ";
            is.ignore();
            getline(is,sv.birthday);
            cout<<"Nhap gioi tinh(1 la nam, 0 la nu): ";
            is>>sv.sex;
            cout<<"Nhap so luong mon hoc: ";
            is>>sv.shp;
            for (int i=0;i<sv.shp;i++){
                string thp;
                int d;
                is.ignore();
                cout<<"Nhap ten mon hoc: ";
                getline(is,thp);
                cout<<"Nhap diem mon hoc: ";
                is>>d;
                sv.hocphan.push_back({thp, d});

            }
            cout<<"Nhap lop: ";
            is.ignore();
            getline(is,sv.lop);
            return is;
        }
        friend ostream& operator<<(ostream &os, Sinhvien &sv){
            set_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            os<<"Ho ten: "<<sv.name<<endl;
            os<<"Msv: "<<sv.msv<<endl;
            os<<"Ngay sinh: "<<sv.birthday<<endl;
            os<<"Gioi tinh: "<<sv.sex<<endl;
            os<<"Lop: "<<sv.lop<<endl;
            set_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            return os;
        }
        bool operator<(Sinhvien &sv){
            return this->getOnlyName() < sv.getOnlyName();
        }
        void show(){
            cout<< left <<setw(10)<<"Ho ten: "<<this->name<<endl;
            cout<< left <<setw(10)<<"Ma sinh vien: "<<this->msv<<endl;
            cout<< left <<setw(10)<<"Ngay sinh: "<<this->birthday<<endl;
            cout<< left <<setw(10)<<"Gioi tinh: "<<this->sex<<endl;
            cout<< left <<setw(10)<<"Lop: "<<this->lop<<endl;
        }
        void showHocphan(){
            cout<<"Tong so hoc phan: "<<shp<<endl;
            cout<<"Cac mon hoc va diem cua sinh vien la: \n";
            for (int i=0;i<shp;i++){
                cout<<hocphan[i].first<<": "<<hocphan[i].second<<endl;
            }

        }
};
#endif