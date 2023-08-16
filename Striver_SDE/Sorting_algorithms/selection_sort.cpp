#include<iostream>
using namespace std;

void ssort(int arr[],int n){
    cout<<"Before Sorting:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n-1;i++){
        int mini = i;
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[mini])
                mini = j;
        }
        swap(arr[mini],arr[i]);
    }

    cout<<"After sorting:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){

    int arr[] = {31,25,85,29,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    ssort(arr,n);

    return 0;
}