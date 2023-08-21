#include<iostream>
using namespace std;

// Approach 1 - usign linear search
int approach1(int *arr, int n){
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i] < ans)
            ans = arr[i];
    }
    return ans;
}

// Approach 2 using BS with SOrted array concepts
int approach2(int* arr, int n){
    int left = 0, right = n-1;
    int ans = INT_MAX;

    while(left <= right){
        int mid = (left + right)/2;

        // In searching problem we moved towards the sorted half but here we need to move to the opposite direction
        // Cause we will find the element in the unsorted cause it is the turning point
        if(arr[left] <= arr[right]){
            ans = min(ans, arr[left]);
            break;
        }

        if(arr[left] <= arr[mid]){
            //  This means this is sorted 
            ans = min(ans,arr[left]);
            left = mid+1;
        }else{
            ans = min(ans, arr[mid]);
            right = mid-1;
        }   
    }
    return ans;
}

signed main(){

    int arr[] = {7,8,10,-11,2,5,6};
    int n= sizeof(arr)/ sizeof(arr[0]);
    cout<<"The minimum element in the array is: "<<approach2(arr, n)<<"\n";

    return 0;
}