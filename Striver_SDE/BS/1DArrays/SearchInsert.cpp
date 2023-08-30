#include<iostream>
using namespace std;

int solve(int* arr, int n, int k){
    int left = 0, right = n-1;
    int ans = n;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(arr[mid] >= k){
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return ans;
}

signed main(){

    int arr[] = {1,4,7,10};
    int n = 4;
    int k = 9;
    cout<<"The index Number can be placed or placed at "<<solve(arr, n, k)<<"\n";

    return 0;
}