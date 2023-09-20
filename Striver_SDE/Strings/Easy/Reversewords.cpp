#include<iostream>
#include<stack>
using namespace std;

// Approach 1 Using Stack o(n) O(n);
string approach1(string s){
    // Intution is simple store every word in the stack and then put it in the answer
    stack<string> st;
    s += " ";
    int n = s.length();
    string str = "";
    for(int i=0;i<n;i++){
        if(s[i] == ' '){ // Corrected the condition here
            st.push(str);
            str = "";
        } else str += s[i];
    }
    // Now we have our stack ready with our words
    string ans = "";
    while(!st.empty()){
        ans += st.top() + " ";
        st.pop();
    } 
    return ans;
}

// Approach 2 Optimizing the space by using extra string
string approach2(string s){
    int n = s.length();
    int left =0, right = n-1;
    
    string temp = "";
    string ans = "";
    
    while(left <= right){
        if(s[left] == ' '){
            if(ans!=""){
                ans = temp + " " + ans;
            }else{
                ans = temp;
            }
            temp = "";
        }else{
            temp += s[left];
        }
        left++;
    }

    if(temp != ""){
        if(ans != ""){
            ans = temp + " " + ans;
        }else{
            ans = temp;
        }
    }
    return ans;
}

signed main(){

    string s = "Advaith is pro in everything";
    string ans = approach2(s);
    cout<<"\nAfter Reverse\n"<<ans<<"\n";

    return 0;
}
