#include<iostream>
#include<vector>
using namespace std;

// Same probelm but atleast apprear twice 

int solve(vector<int> &a, int n){
    if(n<=2) return n;
    int k = 0;
    for(int i=2;i<n;i++){
        if(a[i] != a[k]){
            a[k+2] = a[i];
            k++;
        }
    }
    return k+2;
}

signed main(){

    vector<int> a = {1,1,1,2,2,3};
    int n = a.size();

    int ans = solve(a,n);
    for(int i=0;i<ans;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}