#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string solve(string s){
        int n = s.length();
        string ans = "";

        while(!s.empty()){
            int digit = s.back() - '0';
            if(digit % 2==0){
                s.pop_back();
            }else{
                ans += s;
                break;
            }
        }
        return ans;
    }
};

signed main(){
    Solution ans;
    string s = "52";
    string output = ans.solve(s);
    cout<<output<<"\n";

    return 0;
}