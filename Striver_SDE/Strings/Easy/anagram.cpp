#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

// Approach 1 using sort 
/*
Just sort them both and check char by char if anywhere they cant be same return false*/
bool approach1(string &s, string &t){
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    for(int i=0;i<s.length();i++){
        if(s[i] != t[i]) return false;
    }
    return true;
}

bool approach2(string &s, string &t){
    // Approach 2 using default map or user made array map
    // I will use defult map
    map<char, char> mp;
    for(char c:s){
        mp[c]++;
    }

    for(char c:t){
        mp[c]--;
    }

    // Now if both the string are same then they would have elimanated each other
    for(auto &i:mp){
        if(i.second != 0) return 0;
    }
    return 1;
}


signed main(){

    string s = "hello";
    string t = "eldoh";

    cout<<approach1(s,t);

    return 0;
}