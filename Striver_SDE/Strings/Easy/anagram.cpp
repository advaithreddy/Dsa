#include<iostream>
#include<map>
#include<string>
using namespace std;

bool solve(string &s, string &t){
    // Approach 1 using sort 
    /*
    Just sort them both and check char by char if anywhere they cant be same return false*/
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

    cout<<solve(s,t);

    return 0;
}