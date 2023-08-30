#include<iostream>
using namespace std;

int largestelementarr(int *arr, int n){
    int maxi = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] > maxi)
            maxi = arr[i];
    }
    return maxi;
}

signed main(){

    int arr[] = {4,21,421,14,14,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Largest Element in the array is: "<<largestelementarr(arr,n);

    return 0;
}