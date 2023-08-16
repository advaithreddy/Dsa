#include<bits/stdc++.h>
using namespace std;

class advaith{
    string s;

public:
    void read(void);
    void chk_bin(void);
    void display();
    void ones_comp();

};

void advaith::read(void) {
    cout<< " Enter the binary number " <<endl;
    cin>>s;
}

void advaith::chk_bin(void) {
    for (int i = 0; i < s.length(); ++i) {
        if(s.at(i)!='0'&&s.at(i)!='1'){
            cout<<"Not a binay number ";
            exit(0);
        }
    }
}

void advaith::ones_comp(){
    read();
    chk_bin();
    for(int i = 0; i < s.length(); ++i) {
        if(s.at(i)=='0'){
            s.at(i)='1';
        }else{
            s.at(i) = '0';
        }
    }
    cout<<endl;
}


void advaith::display() {
    cout<<"Displaying binary format"<<endl;
    for (int i = 0; i < s.length(); ++i) {
        cout<<s.at(i);
    }
}

typedef class Shop{
    int itemId[100];
    int itemPrice[100];
    int counter;

public:
    void initcounter(void) { counter = 0; }
    void setItemPrice(void);
    void displayItemPrice(void);
} a;

void a ::setItemPrice() {
    cout<<"Enter the ID of your item number "<<counter+1<<" : "<<endl;
    cin>>itemId[counter];
    cout<<"Enter the item price : "<<endl;
    cin>>itemPrice[counter];
    counter++;
}

void a::displayItemPrice() {
    for(int i=0;i<counter;++i){
        cout<<"The price of the item with "<<itemId[i]<<" is " <<itemPrice[i]<<endl;
    }
}

int main(){

//    advaith s;
//    s.read();
//    s.chk_bin();
//    s.display();
//    s.ones_comp();
//    s.display();

    a s;
    s.initcounter();
    for(int i=0;i<5;i++){
        s.setItemPrice();
    }
    s.displayItemPrice();
}