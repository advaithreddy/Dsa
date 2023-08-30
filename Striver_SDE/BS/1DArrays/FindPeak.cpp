#include<iostream>
using namespace std;


// Brute Force
int approach1(int *arr, int n){
    for(int i=0;i<n;i++){
        if((i==0 || arr[i-1] < arr[i]) &&  (i==n-1 ||  arr[i+1] < arr[i])){
            return i;
        }
    }
    return -1;
}

// Optimal approach Using Binary Search
int approach2(int *arr, int n){
    // egde cases
    if(n==1) return arr[0];
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1, high = n-2;
    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
            return mid;
        }

        // Now removing part
        if(arr[mid] > arr[mid-1]) low = mid+1;
        else high = mid;
    }
    return -1;
}

signed main(){

    int arr[] = {1,2,3,4,5,6,7,8,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"The peak is at the index "<<approach2(arr, n)<<"\n";
    
    return 0;
}