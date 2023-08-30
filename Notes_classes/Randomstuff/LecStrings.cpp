#include<bits/stdc++.h>
using namespace std;


int toLowerCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch;
    } else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}


//int toUpperCase(char ch){
//    if(ch >= 'A' && ch <= 'Z'){
//        return ch;
//    }else{
//        char temp = ch - 'a' + 'A';
//        return temp;
//    }
//}

bool palindrome(char name[], int n){
    int s = 0;
    int e = n-1;

    while(s<=e){
        if(toLowerCase(name[s]) != tolower(name[e]))
            return 0;
        else
            s++;
        e--;
    }
    return 1;
}


void reverse(char name[],int n){
    int s = 0;
    int e = n-1;

    while(s<e){
        swap(name[s++],name[e--]);
    }
}

int getLength(char name[]){
    int count = 0;
    for(int i=0;name[i]!='\0';i++){
        count++;
    }
    return count;
}


int main(){
    char Name[20];
    cout<<"Enter your name : "<<endl;
    cin>>Name;
    cout<<"Your name is : "<<Name<<endl;

    int len = getLength(Name);

    cout<<"Length of your name is : "<<len<<endl;

    reverse(Name, len);
    cout<<"Reverse of your name is : "<<Name<<endl;

    cout<<"Your name is Palindrome or Not "<<palindrome(Name, len)<<endl;

}
