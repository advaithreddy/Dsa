#include<iostream>
using namespace std;

int solve(int *arr, int n){
    // Approach 1 - Use two for loops and count the presence of each ele and return if cnt == 1;
    // Approach 2 - Using Hasing take the maxi element create a hash map vector<int> hash(maxi+1,0)
    // Approach 3 - Similar to ap2 use Map that is predefined hash 
    // Approach 4 - Using XOR
    // When you come across the problems like this use Think about XOR
    int ele = 0;
    for(int i=0;i<n;i++){
        ele ^= arr[i];
    }
    return ele;
}

signed main(){

    int arr[] = {1,2,2,1,3,4,3,4,5};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout<< ((solve(arr,n)) ? "The number that apprears once is: " + to_string(solve(arr,n)) : "No number apprears once\n");

    return 0;
}