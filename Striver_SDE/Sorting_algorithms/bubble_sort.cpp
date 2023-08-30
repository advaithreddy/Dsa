#include<iostream>
using namespace std;

void bbsort(int *arr, int n){
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped = false;
        for(int j=0;j<n-i-1;++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }

    cout<<"After sort:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

signed main(){

    int arr[] = {78 , 12, 34, 3, 8, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    bbsort(arr,n);

    return 0;
}