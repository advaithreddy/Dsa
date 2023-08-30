#include<iostream>
using namespace std;

// Approach 1 - using linear search
int approach1(int *arr, int n, int k){
    for(int i=0;i<n;i++){
        if(arr[i] >= k){
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
        if(arr[mid] >= k){
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return ans;
}

signed main(){

    /*
        The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that 
        index is greater than or equal to a given key i.e. x.

        The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, 
        the lower bound algorithm returns n i.e. size of the given array.
    */

    int arr[] = {1,4,9,15,67,69};
    int k = 10;
    // Here lower bound of 9 is 15 that is index = 3;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"The lower bound of the given key is at index -> "<<approach2(arr,n,k)<<"\n";


    
    return 0;
}