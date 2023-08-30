#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

// helper function
int leastcap(vector<int> &a, int cap){
    int days = 1; // first day
    int load = 0;
    for(int i=0;i<a.size();i++){
        if(load + a[i] > cap){
            days++; // move to the next day
            load = a[i];  // Update the load 
        }else{
            load += a[i]; // if no means simply add that weight
        }
    }
    return days;
}

// Appraoach 1 using LS
int approach1(vector<int> &a, int d){
    int range = accumulate(a.begin(),a.end(),0);
    int maxi = *max_element(a.begin(),a.end());

    for(int i=maxi;i<=range;i++){
        if(leastcap(a,i) <= d){
            return i;
        }
    }
    return -1;
}

// Approach 2 using BS
int approach2(vector<int> &a, int d){
    int left = accumulate(a.begin(),a.end(),0);
    int right = *max_element(a.begin(),a.end());

    while(left <= right){
        int cap = (left + right)/2;
        if(leastcap(a,cap) <= d){
            right = cap-1;
        }else{
            left = cap+1;
        }
    }
    return right;
}


signed main(){

    vector<int> a = {5,4,5,2,3,4,5,6};
    int d = 5;

    cout<<"The least capacity is "<<approach1(a,d);
    
    return 0;
}