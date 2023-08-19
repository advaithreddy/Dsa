#include<iostream>
#include<algorithm>
using namespace std;

int problem1(int *arr, int n){
    int maxprofit = 0;
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        mini = min(mini, arr[i]);
        maxprofit = max(maxprofit,arr[i] - mini);
    }
    return maxprofit;
}

signed main(){

    int arr[] = {7,1,5,3,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The maximum profit is :"<<problem1(arr,n);
    cout<<"\n";
    
    return 0;
}