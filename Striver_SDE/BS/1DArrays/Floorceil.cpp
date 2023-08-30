#include<iostream>
#include<cmath>
#include<utility>
using namespace std;


int findfloor(int *arr, int n,int k){
    int low = 0, high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] <= k){ 
            ans = arr[mid];
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}

int findceil(int *arr, int n,int k){
    int low = 0, high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= k){
            ans = arr[mid];
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

pair<int,int> findfloorceil(int *arr, int n, int k){
    int f = findfloor(arr, n, k);
    int c = findceil(arr, n, k);
    return {f,c};
}


signed main(){

    int arr[] = {1,4,4,7,8,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    pair<int,int> ans = findfloorceil(arr, n, x);
    cout<<"The floor of the given value is "<<ans.first<<" and the ceil is "<<ans.second<<"\n";

    return 0;
}