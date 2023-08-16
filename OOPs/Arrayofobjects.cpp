#include<bits/stdc++.h>
using namespace std;

typedef class employee{
  int id;
  int salary;
  string name;

public:
//    void setname(string s){
//        this-> name = s;
//    }

    void setid(void){
        cout<<"Enter the name of the employee :"<<endl;
        cin>>name;
        cout<<"Enter the id of the "<<name<<" : "<<endl;
        cin>>id;
    }
    void getid(void){
        cout<<"Id: "<<id<<" Name: "<<name<<" Salary: "<<salary<<endl;
    }

//    static void setcompany(void){
//        cout<<"Enter your company name "<<endl;
//        cin>>company;
//    }
} e;


int main(){

    e a,b,c;
    a.setid();
    a.getid();

    b.setid();
    b.getid();

    c.setid();
    c.getid();

}