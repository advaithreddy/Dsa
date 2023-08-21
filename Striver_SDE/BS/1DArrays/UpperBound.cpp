#include<iostream>
using namespace std;


// Approach 1 - using linear search
int approach1(int *arr, int n, int k){
    for(int i=0;i<n;i++){
        if(arr[i] > k){
            return i;
        }
    }
    return n;
}

// Approach 2 - using Binary Search
int approach2(int *arr, int n, int k){
    int left = 0, right = n-1;
    int ans= n;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] > k){
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return ans;
}

signed main(){


    // Similar to lower bound the only change is arr[i] > k not arr[i] >= k

    int arr[] = {1,4,9,15,67,69};
    int k = 9;
    // Here upper bound of 10 is 9 that is index = 2;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"The lower bound of the given key is at index -> "<<approach1(arr,n,k)<<"\n";
    
    return 0;
}