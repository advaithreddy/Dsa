#include<iostream>
using namespace std;


// BS Iteratively
bool bsite(int *arr, int n, int k){
    int left = 0, right = n-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] == k){
            return 1;
        }else if(arr[mid] > k){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return 0;
}

// BS Recursively
bool bs(int *arr, int low, int high, int k){
    // base case
    if(low > high) return 0;

    int mid = low + (high-low)/2;
    if(arr[mid] == k) return 1;
    else if(arr[mid] > k) return bs(arr,low,mid-1,k);
    else return bs(arr,mid+1,high,k);
}

bool bsrec(int *arr, int n, int k){
    return bs(arr, 0, n-1, k);
}

signed main(){

    int arr[] = {1,4,5,21,124,5,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 15;
    if(bsrec(arr,n,k)){
        cout<<"Yes we Found the element!\n";
    }else{
        cout<<"No we didnt find\n";
    }

    return 0;
}