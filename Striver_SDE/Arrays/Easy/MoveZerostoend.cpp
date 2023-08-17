#include<iostream>
using namespace std;

void solve(int *arr, int n){
    int i=0,j=n-1;
    while(i<=j){
        if(arr[i] == 0 && arr[j]!=0){
            swap(arr[i],arr[j]);
            i++,j--;
        }else if(arr[i] == 0 && arr[j] == 0){
            j--;
        }else if(arr[i]!=0){
            i++;
        }
    }

    // optimized way
    /*
        int j = -1;
    //place the pointer j:
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    //no non-zero elements:
    if (j == -1) return a;

    //Move the pointers i and j
    //and swap accordingly:
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    */
}

bool linearsearch(int *arr, int n,int k){
    for(int i=0;i<n;i++){
        if(arr[i] == k){
            return 1;
        }
    }
    return 0;
}

signed main(){

    int arr[] = {1,0,2,3,2,0,0,4,5,1};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"The array before moving zeros is:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    solve(arr,n);
    cout<<"The array after moving zeros is:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}