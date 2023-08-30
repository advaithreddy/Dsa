#include<iostream>
using namespace std;

// Approach 1 using LS
int approach1(int *arr, int n, int k){
    for(int i=0;i<n;i++){
        if(arr[i] <= k){
            k++;
        }else{
            break;
        }
    }
    return k;
}

// Approach 2 using BS
int approach2(int *arr, int n, int k){
    int left = 0, right = n-1;
    while(left <= right){
        int mid = (left + right)/2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return k + right + 1;
}

signed main(){

    int arr[] = {4,7,8,9};
    cout<<"The kth missing number is "<<approach2(arr,4,4);
    
    return 0;
}