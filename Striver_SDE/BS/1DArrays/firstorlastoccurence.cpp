#include<iostream>
#include<utility>
using namespace std;


// Approach 1 - using linear search
pair<int,int> approach1(int *arr, int n, int k){
    int fo = -1,lo = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == k){
            fo = i;
            break;
        }
    }

    for(int i=n-1;i>=0;i--){
        if(arr[i] == k){
            lo = i;
            break;
        }
    }
    return {fo,lo};
}

// Approach 2 - using Binary search
pair<int,int> approach2(int *arr, int n, int k){
    int fo = -1,lo= -1;
    int start = 0,end = n-1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k) {
            fo = mid;
            end = mid - 1;
        } else if (arr[mid] > k) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    start = 0,end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k) {
            lo = mid;
            start = mid + 1;

        } else if (k < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return {fo,lo};
}

signed main(){

    int arr[] = {3,4,13,13,13,20,40};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 13;
    pair<int,int> ans = approach2(arr,n,k);
    cout<<"The first occurence of "<<k<<" is at index "<<ans.first<<" and the last occurence is at "<<ans.second<<"\n";
    
    return 0;
}