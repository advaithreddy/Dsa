#include<iostream>
#include<vector>
using namespace std;

// Approach 1 - Use map and Approach 2 use Set
// Approach 3 - Two pointer approach
vector<int> solve(int *arr1, int *arr2, int n, int m){
    int i=0,j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(arr1[i] <= arr2[j]){
            if(ans.size() == 0 || ans.back() != arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
        }else{
            if(ans.size() == 0 || ans.back() != arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i<n){
        if(ans.back() != arr1[i]){
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while(j<m){
        if(ans.back() != arr2[j]){
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}

signed main(){

    int arr1[] = {1,2,3,4,4,5,6,7};
    int arr2[] = {3,4,5,6,8,9};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    vector<int> ans = solve(arr1, arr2, n, m);
    cout<<"After Union:\n";
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
    
    return 0;
}