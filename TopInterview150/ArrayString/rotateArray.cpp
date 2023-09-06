#include<iostream>
#include<algorithm>
using namespace std;

void rev(int *arr, int s, int e){
    while(s<=e){
        swap(arr[s],arr[e]);
    }
}

void solve(int *arr, int n, int k){
    int mid = n-k;
    rev(arr,mid,n-1);
    rev(arr,0,mid-1);
    rev(arr,0,n-1);
}

signed main(){

    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    solve(arr,n,k);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    return 0;
}