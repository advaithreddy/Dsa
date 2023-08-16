#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int n, int low, int mid, int high){
    int *ans = new int[n];
    int left = low;
    int right = mid+1;
    int k=0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            ans[k] = arr[left];
            left++;
            k++;
        }else{
            ans[k] = arr[right];
            right++;
            k++;
        }
    }

    while(left<=mid){
        ans[k++] = arr[left++];
    }

    while(right <= high){
        ans[k++] = arr[right++];
    }

    for(int i=low;i<=high;i++){
        arr[i] = ans[i-low];
    }

    delete[] ans;
}

void msort(int arr[], int n,int low, int high){
    if(low>=high) return;
    int mid = low + (high - low)/2;
    msort(arr, n, low, mid);
    msort(arr,n,mid+1,high);
    merge(arr, n, low,mid,high);
}

signed main(){

    int arr[] = {7,9,1,4,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Before Sorting:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    msort(arr,n,0,n-1);
    cout<<"\n";
    cout<<"After Sorting:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}