#include<iostream>
#include<vector>
using namespace std;

/*
canJump 1

You are given an integer array nums. You are initially positioned at the array's 
first index, and each element in the array represents your maximum jump length at 
that position.

Return true if you can reach the last index, or false otherwise.

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

canJump 2

Same problem but insted of true, false we need to return the min number of jumps 

*/

class Solution {
public:
    bool canJump1(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;

        int maxReach = 0;
        for(int i=0;i<n;i++){
            if(i > maxReach){
                return 0;
            }
            maxReach = max(maxReach, i+ nums[i]);
            if(maxReach >= n-1) return 1;
        }
        return 0;
    }

    int canJump2(vector<int> &a){
        int n = a.size();
        // base case if the size if 1 no need to jump
        if(n==1) return 0;
        // Modify the array
        for(int i=1;i<n;i++){
            a[i] = max(a[i] + i, a[i-1]);
        }

        int ind = 0;
        int count = 0;

        while(ind < n-1){
            count++;
            ind = a[ind];
        }
        return count;
    }
};


signed main(){

    Solution output;
    vector<int> a = {1,2,1,1,1};
    cout<<"\n";
    cout<<output.canJump2(a);
    cout<<"\n";

    return 0;
}