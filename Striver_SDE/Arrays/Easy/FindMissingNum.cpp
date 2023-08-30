#include<iostream>
using namespace std;

int solve(int * arr, int n){
    // method one use sum of all number formula  - unsorted / sorted
    // Method two run a loop and find whether it is present or not - sorted
    // int val = 0;
    // for(int i=1;i<=n+1;i++){
    //     if(i!=arr[i-1]){
    //         val = i;
    //         break;
    //     }
    // }
    // return val;

    // or

    // long long int sum = n*(n+1)/2;
    // long long int sum2 = 0;
    // for(int i=0;i<n-1;i++){
    //     sum2 += arr[i];
    // }
    // return sum-sum2;

    // or 

    int xor1 = 0, xor2 = 0;

    for(int i=0;i<n-1;i++){
        xor1 ^= arr[i];  // array elements
        xor2 ^= (i+1);  // xor of 1..n elements
    }
    xor2 = xor2^n;

    return (xor2^xor1);
}

signed main(){

    int arr[] = {1,2,3,5,6,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"The missing number in the array is: "<<solve(arr, n);

    return 0;
}