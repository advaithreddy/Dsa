#include<iostream>
using namespace std;



void permutation(string s, string prefix){
    if(s.length() == 0){
        cout<<prefix<<" ";
    }else{
        for(int i=0;i<s.length();i++){
            string rem = s.substr(0,i) + s.substr(i+1);
            permutation(rem, prefix + s[i]);
        }
    }
}

void permutations(string &s){
    permutation(s,"");
}

signed main(){

    string s = "abc";
    permutations(s);

    return 0;
}