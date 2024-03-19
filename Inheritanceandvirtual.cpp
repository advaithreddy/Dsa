#include<iostream>
using namespace std;

/*
Inheritance : When Child class wants to use properties of parent class it will inherit the parent class and this 
mechnasim is know as inheritance

Types:
1) Single level inheritance
2) Multi level inheritance
3) Multiple inheritance
4) Hybrid inheritance
*/

class Animal{ // Parent class
public: // Access specifier always mention it to public in a class.
    void function(){
        cout<<"Hello I am an Animal";
    }

    // Now this is virtual function which I can override in child classes
    virtual void sound(){
        cout<<"I have various sounds";
    }
};

class Dog : public Animal{
public:
    void function(){
        cout<<"Hello I am Dog";
    }


    // we will over ride the virtual function
    void sound(){
        cout<<"Bark..";
    }
};



signed main(){

    // class_name obj_name
    Animal animal;
    animal.function();
    cout<<endl;
    animal.sound();
    cout<<endl;

    Dog shepard;
    shepard.function();
    cout<<endl;
    shepard.sound();
    cout<<endl;

    // But when I do it with pointers
    Animal* new_animal;
    new_animal = &shepard;
    // even though here new_animal is an instance of Animal class it will point to the obj named shepard which is and instance of Dog class
    new_animal->sound();

    return 0;
}