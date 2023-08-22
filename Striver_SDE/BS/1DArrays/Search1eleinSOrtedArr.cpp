#include<iostream>
using namespace std;


// Approach 1 - Brute Force
// The single element will not have same elements before or after
// arr[i] != arr[i-1] && arr[i] != arr[i+1] if this is true then its single
int approach1(int *arr, int n){
    for(int i=0;i<n;i++){
        if((i==0 && arr[i] != arr[i+1]) || (arr[i] != arr[i-1] && arr[i] != arr[i+1]) || (i==n-1 && arr[i]!= arr[i-1])){
            return arr[i];
        }
    }
    return -1;
}


// Approach 2 - Brute Force 2
// Using XOR -> this can be used in unsorted array too
int approach2(int *arr, int n){
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

// Approach 3 - Optimal Binary Search
int approach3(int *arr, int n){
    // Binary Search
    // edge cases
    if(n==1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    // Now into problem
    int low = 1, high = n-2;
    while(low<=high){
        int mid = low + (high-low)/2;

        // If we get it its ok
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }

        // Else we need to eliminate the left part or right part
        // As the question only repeats only twice numbers
        if((mid%2==1 && arr[mid] == arr[mid-1]) || (mid%2==0 && arr[mid] == arr[mid+1])){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1; // No element or simply dummy answer cause there will be atleast one element present in the array unique
}

signed main(){

    int arr[] = {1,1,2,2,3,3,4,5,5,5,6,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The element that is present only once is "<<approach3(arr,n);

    return 0;
}