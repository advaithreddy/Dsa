#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> leader(vector<int> arr, int n){
    vector<int> ans;
    ans.push_back(arr[n-1]);
    int highest_onright = arr[n-1];
    int i = n-1;
    while(i>=0){
        if(arr[i] > highest_onright){
            highest_onright = arr[i];
            ans.push_back(highest_onright);
        }
        i--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

signed main(){

    vector<int> a = {10,22,12,3,0,6};
    int n = a.size();
    // Leader is the element where the right side elements are smaller 
    vector<int> ans = leader(a,n);
    cout<<"The learders in the array are :";
    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}