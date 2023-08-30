#include<bits/stdc++.h>
using namespace std;


typedef class methods{
    int id;
    int salary;
    static int count;

public:
    void getID(void){
        cout<<"Id of the employee "<< count <<" is "<<id;
        cout<<" and Salary is : "<<salary<<endl;
        count++;
    }
    void setID(void){
        cout<<"Enter the id of the employee "<<count<<" : ";
        cin>>id;
        cout<<"Required salary : "<<endl;
        cin>>salary;
    }

    // scope resolution operator
    static void getCount(void){
        // we can only use static variables im static function
        cout<<"The value of count is "<< count<<endl;
    }
} x;

int main(){

    x ms,bs, gs;
    ms.setID();
    ms.getID();
    x::getCount();

    bs.setID();
    bs.getID();
    methods::getCount();

    gs.setID();
    gs.getID();
    methods::getCount();
}