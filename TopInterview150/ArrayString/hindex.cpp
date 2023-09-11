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

signed main(){

    vector<int> a = {3,0,6,1,5};
    int n = a.size();
    cout<<"The H- Index is "<<solve(a,n);

    return 0;
}