#include <bits/stdc++.h>
using namespace std;

/* Binary Search Working Principle
 * Take a pointer at Starting point and Ending Point
 * as s=0 and e=n
 * Now take a mid-value as s+e/2
 * If key == mid return mid;
 * else if mid<key s=mid +1
 * else e mid-1;
 * no key than return -1
 * Sub values in Main function*/

int Binary_search(const int arr[], int n,int key){
    int low = 0;
    int high = n;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(arr[mid] == key){
            return mid;
        }else if(arr[mid]<key){
            low= mid +1;
        }else{
            high = mid -1;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;

    int result = Binary_search(arr, n, key);
    (result == -1)
    ? cout<<"Element is not Present in the array"<<"\n"
    : cout<<"Present at : "<<result<<"\n";


    int k=0,x=5;
    for(int i = n/2;i>=1;i/=2){
        while(k+i < n && arr[k+i] <= x) k+=i;
    }
    if(arr[k]==x){cout<<"Found"<<endl;}else{cout<<"Not found";}

}

