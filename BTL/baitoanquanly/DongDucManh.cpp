// quan ly sinh vien o ktx
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed
class Sinhvien{
    private:
        string name;
        int age;
        string msv;
        string lop;
    public:
        Sinhvien(string name, int age, string msv, string lop){
            this->name = name;
            this->age = age;
            this->msv = msv;
            this->lop = lop;
        }
        //getter va setter
        void setName(string name){
            this->name = name;
        }
        void setAge(int age){
            this->age = age;
        }
        void setMsv(string msv){
            this->msv = msv;
        }
        void setLop(string lop){
            this->lop = lop;
        }
        string getName(){
            return this->name;
        }
        string getOnlyName(){
            string tmp="";
            for (int i = name.size()-1; i >= 0; i--){
                if (name[i] == ' ') break;
                tmp = name[i] + tmp;
            }
            return tmp;
        }
        int getAge(){
            return this->age;
        }
        string getMsv(){
            return this->msv;
        }
        string getLop(){
            return this->lop;
        }
        //-------------------------------------
        Sinhvien(){
            this->name = "";
            this->age = 0;
            this->msv = "";
            this->lop = "";
        }
        friend istream& operator>>(istream &is, Sinhvien &sv){
            is.ignore('\n' - 1e9);
            getline(is,sv.name);
            is>>sv.age;
            is>>sv.msv;
            is.ignore();
            getline(is,sv.lop);
            return is;
        }
        friend ostream& operator<<(ostream &os, Sinhvien &sv){
            os<<"Name: "<<sv.name<<endl;
            os<<"Age: "<<sv.age<<endl;
            os<<"Msv: "<<sv.msv<<endl;
            os<<"Lop: "<<sv.lop<<endl;
            return os;
        }
        bool operator==(Sinhvien &sv){
            return this->name == sv.name && this->age == sv.age && this->msv == sv.msv && this->lop == sv.lop;
        }
        bool operator<(Sinhvien &sv){
            return this->name < sv.name;
        }
        void show(){
            cout<< left <<setw(10)<<"Name: "<<this->name<<endl;
            cout<< left <<setw(10)<<"Age: "<<this->age<<endl;
            cout<< left <<setw(10)<<"Msv: "<<this->msv<<endl;
            cout<< left <<setw(10)<<"Lop: "<<this->lop<<endl;
        }
};

int cmp(Sinhvien a, Sinhvien b){
    return a.getOnlyName() < b.getOnlyName();
}
class Phong{
    private:
        string name;
        string id;
        int soLuongSinhVien;
        list<Sinhvien> sv;
    public:
        Phong(string name, string id, int soLuongSinhVien, list<Sinhvien> sv){
            this->name = name;
            this->id = id;
            this->soLuongSinhVien = soLuongSinhVien;
            this->sv = sv;
        }
        //getter va setter
        void setName(string name){
            this->name = name;
        }
        void setId(string id){
            this->id = id;
        }
        void setSoLuongSinhVien(int soLuongSinhVien){
            this->soLuongSinhVien = soLuongSinhVien;
        }
        void setSv(list<Sinhvien> sv){
            this->sv = sv;
        }
        string getName(){
            return this->name;
        }
        string getId(){
            return this->id;
        }
        int getSoLuongSinhVien(){
            return this->soLuongSinhVien;
        }
        list<Sinhvien> getSv(){
            return this->sv;
        }
        //-------------------------------------
        Phong(){
            this->name = "";
            this->id = "";
            this->soLuongSinhVien = 0;
            this->sv = list<Sinhvien>();
        }
        friend istream& operator>>(istream &is, Phong &p){
            is.ignore('\n' - 1e9);
            getline(is,p.name);
            is>>p.id;
            is>>p.soLuongSinhVien;
            is.ignore();
            for(int i=0;i<p.soLuongSinhVien;i++){
                Sinhvien sv;
                is>>sv;
                p.sv.push_back(sv);
            }
            return is;
        }
        friend ostream& operator<<(ostream &os, Phong &p){
            os<<"Name: "<<p.name<<endl;
            os<<"Id: "<<p.id<<endl;
            os<<"So luong sinh vien: "<<p.soLuongSinhVien<<endl;
            os<<left<<setw(25)<<"Name";
            os<<left<<setw(23)<<"Msv";
            os<<left<<setw(25)<<"Age";
            os<<left<<setw(25)<<"Lop"<<endl;
            for(auto i:p.sv){
                os<<i.getName()<<setw(30 - i.getName().size())<<right<<i.getMsv()<<setw(30 - i.getMsv().size())<<i.getAge()<<setw(30)<<i.getLop()<<endl;
            }
            return os;
        }
         void sortSinhvien() {
            sv.sort(cmp);
        }
    
};
main(){
    freopen("input.int","r",stdin);
    Phong p;
    cin>>p;
    p.sortSinhvien();
    cout<<p;
    return 0;
}