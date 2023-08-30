#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Small note:
BS on answers have two patterns and the first type we have solved in earlier problems and now we are 
moving to second pattern by this problem.
*/

// Min distance between two cows is maximum

// Helper Function
bool helper(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}

// Approach 1 using LS
int approach1(vector<int> &a, int c){
    int n = a.size();

    // sort them first
    sort(a.begin(),a.end());

    int range = a[n-1] - a[0];    // After sorting the range will be the last ele - first ele

    for(int i=1;i<=range;i++){
        if(helper(a,i,c) == false){
            return (i-1);
        }
    }
    return range;  // This is the only possible if we cant find the min distance
}

// Approach 2 using BS
int approach2(vector<int> &a, int c){
    int n = a.size();
    
    sort(a.begin(),a.end());

    int left = 1, right = a[n-1] - a[0];
    while(left <= right){
        int dis = (left + right)/2;
        if(helper(a,dis,c) == true){
            left = dis + 1;
        }else{
            right = dis - 1;
        }
    }
    return right;
}


signed main(){

    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = approach2(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    
    return 0;
}