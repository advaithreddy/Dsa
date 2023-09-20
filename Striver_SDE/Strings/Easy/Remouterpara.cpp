#include<iostream>
#include<stack>
using namespace std;

string solve(string &s){
    stack<char> st;
    string ans = "";
    for(char c: s){
        if(c == '('){
            if(!st.empty()){
                ans += c;
            }
            st.push(c);
        }else if(c == ')'){
            st.pop();
            if(!st.empty()){
                ans += c;
            }
        }
    }
    return ans;
}

signed main(){

    string s = "(()())(())(()(()))";
    cout<<"\nAfter the operations the string is "<<solve(s)<<"\n";

    return 0;
}