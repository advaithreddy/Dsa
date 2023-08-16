#include<iostream>
using namespace std;

int slargest(int *arr, int n){
    int fl = 0;
    int sl = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > fl){
            sl = fl;
            fl = arr[i];
        }else if(arr[i] > sl && arr[i] != fl){
            sl = arr[i];
        }
    }
    return sl;
}

int ssmallest(int *arr, int n){
    int fs = INT_MAX, ss = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i] < fs){
            ss = fs;
            fs = arr[i];
        }else if(arr[i] < ss && arr[i] != fs){
            ss = arr[i];
        }
    }
    return ss;
}

signed main(){

    int arr[] = {1,3,4,45,4123,43};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Second largest element: "<<slargest(arr, n)<<"\n";
    cout<<"Second smallest element: "<<ssmallest(arr, n)<<"\n";

    return 0;
}