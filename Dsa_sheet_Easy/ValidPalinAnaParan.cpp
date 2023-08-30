#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;


char toLower(char ch){
    if((ch >= 'a' && ch <='z') || (ch >= '0' && ch<= '9'))
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool  palindrome(string s){
    string str;

    for(int i=0;i<s.size();++i){
        if((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
            str.push_back(s[i]);
        }
    }

    int l = 0;
    int r = str.size()-1;

    while(l<=r){
        if(toLower(str[l])== toLower(str[r])){
            l++;
            r--;
        }else{
            return false;
        }

    }
    return true;
}

bool isAnagram(string s, string t){
    string a = s;
    string b = t;

    int len1 = s.length()-1;
    int len2 = t.length()-1;


    if(len1!=len2)
        return false;

    //sort the strings

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int i=0;i<len1;++i){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}

bool parantheses(string str){
    stack<char> stc;
    char x;

    for(int i=0;i<str.length();++i){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            stc.push(str[i]);
            continue;
        }

        if(stc.empty())
            return false;

        switch (str[i]) {
            case ')':
                x = stc.top();
                stc.pop();
                if(x=='{'||x=='['){
                    return false;
                }
                break;
            case '}':
                x = stc.top();
                stc.pop();
                if(x=='('||x=='['){
                    return false;
                }
                break;
            case ']':
                x = stc.top();
                stc.pop();
                if(x=='('||x=='{'){
                    return false;
                }
                break;
        }
    }
    return stc.empty();
}

int main(){
    string test,para,test1,test2;
//    cout<<"Enter your string : ";
//    cin>>test;
//
//    if(palindrome(test)){
//        cout<<"Yes the given string is palindrome"<<endl;
//    }else{
//        cout<<"No the string is not palindrome"<<endl;
//    }
//
//    cout<<endl;
//    cout<<"Anagram"<<endl;
//    cout<<"Enter the two strings consecutively : ";
//    cin>>test1>>test2;
//
//    if(isAnagram(test1,test2)){
//        cout<<"Yes";
//    }else
//        cout<<"No";

//    cout<<endl;
    cout<<"Parentheses"<<endl;
    cout<<"Enter your expression:";
    cin>>para;

    if(parantheses(para))
        cout<<"Balanced"<<endl;
    else
        cout<<"Not balanced"<<endl;

}