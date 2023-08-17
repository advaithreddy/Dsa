#include<iostream>
using namespace std;

// By one place
void solve1(int *arr, int n){
    int v = arr[0];
    for(int i=0;i<n;i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = v;
}


// By K places
void reversearray(int *arr, int s, int e){
    while(s<=e){
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++, e--;
    }
}

// right rotation
void rotateright(int *arr, int n, int k){
    // First reverse n-k elements
    reversearray(arr, 0, n-k-1);

    // reverse the last k elements
    reversearray(arr,n-k,n-1);

    // Now reverse the whole array
    reversearray(arr, 0, n-1);
}

//left rotation
void rotateleft(int *arr, int n, int k){
    // First rotate the first k elements
    reversearray(arr, 0, k-1);

    // reverse the remaining elements
    reversearray(arr, k, n-1);

    // reverse the arrat
    reversearray(arr, 0, n-1);
}

signed main(){

    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]); int k = 2;
    cout<<"Before Left rotating:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    rotateleft(arr,n,k);
    cout<<"After rotation:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    return 0;
}