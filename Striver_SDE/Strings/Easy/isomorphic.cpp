#include<iostream>
#include<unordered_map>
using namespace std;

bool solve(string s, string t){
    if(s.length() != t.length()) return 0;

    unordered_map<char, char> mp1, mp2;
    for(int i=0;i<s.length();i++){
        if(mp1[s[i]] == 0) mp1[s[i]] = t[i];
        else if(mp1[s[i]] != t[i]) return 0;

        if(mp2[t[i]] == 0) mp2[t[i]] = s[i];
        else if(mp2[t[i]] != s[i]) return 0;
    }
    return 1;
}

signed main(){

    string s = "egg";
    string t = "add";
    cout<<solve(s,t);

    return 0;
}