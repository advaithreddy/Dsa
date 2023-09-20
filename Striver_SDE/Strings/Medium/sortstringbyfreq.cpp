#include <bits/stdc++.h>
using namespace std;

string solve(string s){
    unordered_map<char,int> mp;
    for(char c:s){
        mp[c]++;
    }

    auto helper = [&](char a,char b){
        if(mp[a] == mp[b]){
            return a<b;
        }
        return mp[a] > mp[b];
    };

    sort(s.begin(),s.end(),helper);
    return s;
}

int main(){
    string s = "tree";
    cout << "\nAfter sorting\n" << solve(s) << endl;
    return 0;
}
