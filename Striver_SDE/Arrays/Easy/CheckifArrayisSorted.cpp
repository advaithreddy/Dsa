#include<iostream>
using namespace std;

bool csorted(int *arr, int n){
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){return 0;}
    }
    return 1;
}

signed main(){

    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(csorted(arr, n)){
        cout<<"Yes the Array is Sorted\n";
    }else{
        cout<<"No the array is not sorted\n";
    }
    
    return 0;
}