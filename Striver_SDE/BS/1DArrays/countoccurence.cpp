#include<iostream>
using namespace std;


// Approach - 1 Using Linear Search  -- We can use this in both sorted and unsorted
int approach1(int *arr, int n, int k){
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == k)
            cnt++;
    }
    return cnt;
}

// Approach - 2 Using Binary Search - Only sorted
pair<int,int> approach2(int *arr, int n, int k){

    // Simple get the last occurence and first occurence index and do j-i+1 we will get our length
    int fo = -1,lo= -1;
    int start = 0,end = n-1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k) {
            fo = mid;
            end = mid - 1;
        } else if (arr[mid] > k) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    start = 0,end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k) {
            lo = mid;
            start = mid + 1;

        } else if (k < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return {fo,lo};
}



signed main(){

    int arr[] = {1,2,2,3,3,3,3,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    cout<<"Approach 1 Answer\n";
    cout<<"No Of occurence of "<<x<<" in the array is "<<approach1(arr, n, x)<<"\n";
    cout<<"Approach 2 Answer\n";
    pair<int,int> ans = approach2(arr, n, x);
    cout<<"No if occurence of "<<x<<" in the array is "<<(ans.second - ans.first + 1)<<"\n";
    
    
    return 0;
}
