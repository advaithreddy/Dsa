#include<iostream>
using namespace std;

int solve(int *arr, int n){
    int start = 0, end = n-1;
    int i= -1;
    while(start<= end){
        int mid = start + (end-start)/2;

        if(arr[start] <= arr[end]){
            i = start;
            break;
        }

        if(arr[start] <= arr[mid]){
            i = start;
            start = mid+1;
        }else{
            i = mid;
            end = mid-1;
        }
    }
    return i;
}

signed main(){

    int arr[] = {3,4,5,1,2};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout<<"No of times the array has been rotated is "<<solve(arr,n)<<" times \n";

    return 0;
}