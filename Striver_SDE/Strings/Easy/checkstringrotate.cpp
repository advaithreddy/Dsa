#include<iostream>
#include<string>
using namespace std;

string helper(string &s){
    char c = s[0];
    for(size_t i = 0;i<s.length()-1;++i){
        s[i] = s[i+1];
    }
    s[s.length() - 1] = c;
    return s;
}

bool solve(string &s, string &t){
    int count = s.length();
    while(count > 0){
        if(helper(s) == t) return 1;
        count--;
    }
    return 0;
}

// This can be asked in two ways one is left rotation and the other one is right rotation
signed main(){

    string s = "abac";
    string t = "acab";
    cout<<solve(s,t);

    return 0;
}