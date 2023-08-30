#include<bits/stdc++.h>
using namespace std;

// Delete Middle Element from a stack
void solve(stack<int> s, int count, int n){
    // base case
    if( count == n/2){
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();
    // Recursive Call
    solve(s,count+1,n);
    // Backtracking
    s.push(num);
}

void deleteMiddle(stack<int>& st, int n){
    // Using Recursion
    int count = 0;
    solve(st,count,n);
}

int main(){
//    // Reverse a string using a stack
//    string str = "advaith";
//    stack<char> s;
//    for(int i=0;i<str.length();i++){
//        char ch = str[i];
//        s.push(ch);
//    }
//    string ans="";
//    while(!s.empty()){
//        char ch = s.top();
//        ans.push_back(ch);
//        s.pop();
//    }
//    cout<<ans<<endl;

    // 2nd
    stack<int> st;
    st.push(7);
    st.push(8);
    st.push(12);
    st.push(23);
    st.push(9);
    int n = 4;
    deleteMiddle(st,n);
    cout<<" Stack elements"<<endl;
    for(int i=0;i<n;i++){
        cout<<st.top()<<"\n";
        st.pop();
    }

    return 0;
}