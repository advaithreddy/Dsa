#include<bits/stdc++.h>
using namespace std;

class animal{
    int age;
    int weight;
    float height;
    string name;
public:
    double ball;
public:
    void setage(void){
        cout<<"Enter the age: "<<endl;
        cin>>age;
    }
    void setweight(int w){
        this-> weight = w;
    }
    void setheight(float h){
        this-> height = h;
    }
    void getagehw(void){
        cout<<"Age of "<<name<<" is "<<age<<" with a weight of "<<this->weight<<"Kgs and height "<<this->height<<" ft"<<endl;
    }
    void getname();
};

class wildanimal{
public:
    void bark(void){
        cout<<"Bow bow bow "<<endl;
    }
};

void animal::getname(){
    cout<<"Enter the name of the person: "<<endl;
    cin>>name;
}


// Single inheritance
class dog: public animal{
    string name;

public:
    void getname(void){
        cout<<"Enter the name of the person: "<<endl;
        cin>>name;
    }
};

// multi level ingheritance
class germanshepard:public dog{

};


// Multiple inheritance
class lion:public animal, public wildanimal{
public:
    float age;
};


// Hirarchical inheritance;
class cat:public animal{

};
class rabbit:public animal{

};
class male:rabbit{

};
class female:private cat{

};

// Inhertiance Ambiguity
class A{
public:
    void call(void){
        cout<<"I am A"<<endl;
    }
};

class B{
public:
    void call(void){
        cout<<" I am B"<<endl;
    }
};

class C:public A,public B{

};

//Polymorphism
// compile time polymor -> static polymorphism
// 1 Function overloading
class S{
public:
    void print(){
        cout<<"This is Sukrutha"<<endl;
    }

    void print(string name){
        cout<<"This is "<<name<<endl;
    }
    int print(int age){
        cout<<"Iam "<<age<<" Years old"<<endl;
        return 1;
    }
};

// 2 Operator overloading

class oops{
public:
    int a;
    int b;

    void operator+ (oops &obj){
        int val1 = this -> a;
        int val2 = obj.a;
        cout<<"Sub "<<val2-val1<<endl;
    }
};



// Run time polymorphism -> dynamic polymorphism
// Method overriding
class over{
public:
    void bark(void){
        cout<<"Ok this is over"<<endl;
    }
    void func2(){
        cout<<"cannot change"<<endl;
    }
};

class riding:public over{
public:
    void bark(void){                              // Here it overrided the bark fucn from class over
        cout<<"Changed the subject"<<endl;
    }
};



int main(){

    riding babu;
    babu.bark();
    babu.func2();



//
//    oops obj1,obj2;
//    obj1.a= 20;
//    obj2.a=25;
//
//    obj1+obj2;
//

//
//    string n;
//    cout<<"Enter your name:"<<endl;
//    cin>>n;
//    S sukrutha;
//    sukrutha.print();
//    sukrutha.print(n);
//    sukrutha.print(19);
//

//    lion male;
//    male.bark();
//    male.setage();
//    male.setweight(120);
//    male.setheight(4.1);
//    male.getname();
//    male.getagehw();
//
//    C obj;
//    obj.A::call();
    return 0;
}