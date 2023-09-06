#include<iostream>
#include<vector>
using namespace std;

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.


Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

int solve(vector<int> &a, int n){
    // This is very unthinkable intution 
    // Simple remember this as an algorithm
    // Major Vikram Algorithm
    // We will use the val so by this val we will have always the major element stored in it
    // There might be some tricy edge case but 97% it will work
    int val = 0;
    int c = 0;
    for(int i=0;i<n;i++){
        if(c == 0){
            val = a[i];
        }

        c += (val == a[i] ? 1 : -1);
    }
    return val;
}

signed main(){

    vector<int> a = {2,2,1,1,1,2,2,1,1};
    int n = a.size();
    cout<<"The major element "<<solve(a,n)<<"\n";


    return 0;
}