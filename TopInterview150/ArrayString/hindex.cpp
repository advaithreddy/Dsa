#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Given an array of integers citations where citations[i] is the number of citations a 
researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as 
the maximum value of h such that the given researcher has published at least 
h papers that have each been cited at least h times.
*/

int solve(vector<int> &a, int n){
    // first sort
    sort(a.begin(),a.end());
    // Simple to count sort algorithm
    for(int i=0;i<n;i++){
        if(a[i] >= n){
            return n;
        }else{
            if(n==1 && a[i] != 0){
                return 1;
            }
            n--;
        }
    }
    return n;
}

// H index is similar but here default the array is given in sorted manner
int hindex2(vector<int> &a,int n){
    // This method uses binary search
    int low = 0, high =n-1;
    int ans = 0;
    while(low <= high){
        int mid = low + ((high - low) >> 1);
        int max_cit = n-mid;
        if(a[mid] >= max_cit){
            ans = max_cit;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

signed main(){

    vector<int> a = {1,1,3};
    int n = a.size();
    cout<<"The H- Index is "<<hindex2(a,n);

    return 0;
}