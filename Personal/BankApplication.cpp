#include<vector>
#include<iostream>

class NewUser{
private:
    std::string name;
    int age;
    std::string profession;
    bool spouse;
    std::string pan_number;
    NewUser* next;
public:
    NewUser(std::string name,int age,std::string prof,bool spouse,std::string pan){
        this->name = name;
        this->age = age;
        this->profession = prof;
        this->spouse = spouse;
        this->pan_number = pan;
        this->next = nullptr;
    }
};

signed main(){

    // What do we have in Banking Application
    /*
    1. Account
        a. New User
        b. username, password
            1) User details to take 
                Name::Age::Profession::Spouse::Pan Number
            2) User Details (to show) 
        d. Withdrawl
        e. Credit
        f. Loan Possible or not
    */


    std::cout<<"\nWelcome to Best Bank\n";
    std::cout<<"Choose Any one Option\n";
    std::cout<<"1. New User\n2. Sign In\n";
    int user_choice;
    std::cout<<"Enter your choice: ";
    std::cin>>user_choice;

    while(user_choice != 1 && user_choice != 2){
        std::cout<<"Sorry You have choosed the wrong option Check again\n";
        std::cout<<"Enter your choice: ";
        std::cin>>user_choice;
    }

    if(user_choice == 1){
        // New User
        std::string name_str;
        int age;
        std::string profession;
        bool spouse;
        std::string pan_number;
        std::cout<<"\nHello Welcome to Best Bank\n";
        std::cout<<"New User Portal\n";
        std::cout<<"Please Enter the below asked details:\n";
        std::cout<<"Name: "; std::cin>>name_str; 
        std::cout<<"Age : "; std::cin>>age; 
        std::cout<<"Profession : "; std::cin>>profession; 
        std::cout<<"Are You Married? : "; std::cin>>spouse; 
        std::cout<<"Pan Card Number : "; std::cin>>pan_number; 
        NewUser* head = nullptr;
        if(head != nullptr){
            head = new NewUser(name_str, age, profession, spouse, pan_number);   
        }
    }
    
    if(user_choice == 2){
        // Sign in
    }

    return 0;
}