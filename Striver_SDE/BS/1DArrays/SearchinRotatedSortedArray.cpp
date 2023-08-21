#include<iostream>
using namespace std;

// Approach 1 is simple linear search so direct to BS

int solve(int *arr, int n, int k){
    int left = 0, right = n-1;
    while(left <= right){
        int mid = left + (right - left)/2;

        if(arr[mid] == k) return mid;

        // Check if your left array is sorted or right array is sorted
        if(arr[left] <= arr[mid]){ // This means our left array is sorted
            // Now check if k exists b/w these boundries
            if(arr[left] <= k && k <= arr[mid]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }else{
            if(arr[mid] <= k && k <= arr[right]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
    }
    return -1;
}

// Rotated II
bool rotated2(int *arr,int n, int k){
    int left = 0, right = n-1;
    while(left <= right){
        int mid = left + (right - left)/2;

        if(arr[mid] == k) return 1;

        // Check if your left array is sorted or right array is sorted
        if(arr[left] <= arr[mid]){ // This means our left array is sorted
            // Now check if k exists b/w these boundries
            if(arr[left] <= k && k <= arr[mid]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }else{
            if(arr[mid] <= k && k <= arr[right]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
    }
    return 0;
}

signed main(){

    int arr[] = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 10;
    int ans = solve(arr, n, k);
    if(ans==-1){
        cout<<"The number "<<k<<" is not present in the array🙇🏻‍♂️\n";
    }else{
        cout<<"The number "<<k<<" is at index "<<ans<<"\n";
    }
    cout<<endl;
    if(rotated2(arr,n,k)){
        cout<<"The number "<<k<<" is present in the array\n";
    }else{
        cout<<"The number "<<k<<" is not present in the array"<<"\n";
    }



    return 0;
}
