#include<iostream>
using namespace std;

void isort(int *arr, int n){
    cout<<"Before Sorting:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    cout<<"After sorting:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

signed main(){

    int arr[] = {7,9,1,4,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    isort(arr,n);
    cout<<"\n";

    return 0;
}