#include<iostream>
#include<set>
using namespace std;


// Brute Force use Hashset
int solve(int arr[], int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    int k = s.size();
    int j=0;
    for(int x:s){
        arr[j++] = x;
    }
    return k;
}

// Optimized Approach - update and move forward - We can only use this if the array is sorted
int solve1(int arr[] , int n){
    int i=0,j=1;
    while(j<n){
        if(arr[i] != arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }

    /* 
        {1,2,2,3,4,5,6};
        i  j
    */
    return i+1;
}

signed main(){

    int arr[] = {1,2,2,3,4,4,4,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The array before removing duplicates is:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    int k = solve1(arr,n);
    cout<<"The array after removing duplicates is:\n";
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}