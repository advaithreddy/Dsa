#include<iostream>
#include<vector>
using namespace std;

vector<int> solve(vector<int> &a){
    int n = a.size();
    vector<int> ans(n);
    ans[0] = 1; // set cause it is used for multiplication
    for(int i=1;i<n;i++){
        ans[i] = ans[i-1] * a[i-1]; // this will form the ans = {1,1,2,6};
    }
    int right = 1;
    // right is initialized to 1 this will keep track of the multiplications
    for(int i=n-1;i>=0;i--){
        ans[i] = ans[i] * right;  // 1. ans[3] = ans[3]-6 * 1 = 6
        // 2. ans[2] = ans[2]-2 * right-4 = 2*4 = 8;
        // ....
        right = right * a[i];  // 1. right  = right-1 * nums[3]-4 = 1*4 = 4 
        // 2. right = right-4 * nums[2]-3 = 4*3 = 12
        // ....
    }
    return ans;
}

signed main(){

    vector<int> a = {1,2,3,4};
    vector<int> ans = solve(a);
    cout<<"\n[ ";
    for(int i:ans){
        cout<<i<<" ";
    } cout<<"]\n";// 24, 12, 8, 6 <- Excpected

    return 0;
}