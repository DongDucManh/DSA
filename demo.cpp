#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main
#define elif else if
#define fix_(x) setprecision(x)<<fixed


class Human{
    private:
        string name;
        int age;
    public:
        Human(string name, int age){
            this->name = name;
            this->age = age;
        }
        //getter va setter
        void setName(string name){
            this->name = name;
        }
        void setAge(int age){
            this->age = age;
        }
        string getName(){
            return this->name;
        }
        int getAge(){
            return this->age;
        }
        //-------------------------------------
        Human(){
            this->name = "";
            this->age = 0;
        }
        friend istream& operator>>(istream &is, Human &h){
            is.ignore();
            getline(is,h.name);
            is>>h.age;
            return is;
        }
        friend ostream& operator<<(ostream &os, Human &h){
            os<< left <<setw(10)<<"Name: "<<h.name<<endl;
            os<< left <<setw(10)<<"Age: "<<h.age<<endl;
            return os;
        }

};
class Cauthu: public Human{
    private:
        int sptd;
        int sbt;
    public:
        Cauthu(string name, int age, int sptd, int sbt):Human(name, age){
            this->sptd = sptd;
            this->sbt = sbt;
        }
        //getter va setter
        void setSptd(int sptd){
            this->sptd = sptd;
        }
        void setSbt(int sbt){
            this->sbt = sbt;
        }
        int getSptd(){
            return this->sptd;
        }
        int getSbt(){
            return this->sbt;
        }
        //-------------------------------------
        Cauthu(){
            this->sptd = 0;
            this->sbt = 0;
        }
        friend istream& operator>>(istream &is, Cauthu &ct){
            Human h;
            is>>h;
            ct.setName(h.getName());
            ct.setAge(h.getAge());
            is>>ct.sptd;
            is>>ct.sbt;
            return is;
        }
        friend ostream& operator<<(ostream &os, Cauthu &ct){
            Human h;
            h.setName(ct.getName());
            h.setAge(ct.getAge());
            os<<h;
            os<< left <<setw(10)<<"So phut thi dau "<<ct.sptd<<endl;
            os<< left <<setw(10)<<"So ban thang: "<<ct.sbt<<endl;
            return os;
        }
};
main(){
    freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector<Cauthu> ct;
    for(int i=0;i<n;i++){
        Cauthu c;
        cin>>c;
        ct.push_back(c);
    }
    for(int i=0;i<n;i++){
        cout<<"Cau thu thu: "<<i+1<<endl;
        cout<<ct[i]<<endl;
    }

    cout<<"Cau thu lon tuoi nhat la: "<<endl;
    int maxAge = 0;
    for(int i=0;i<n;i++){
        if(ct[i].getAge() > maxAge){
            maxAge = ct[i].getAge();
        }
    }
    for(int i=0;i<n;i++){
        if(ct[i].getAge() == maxAge){
            cout<<ct[i]<<endl;
        }
    }
    return 0;
}