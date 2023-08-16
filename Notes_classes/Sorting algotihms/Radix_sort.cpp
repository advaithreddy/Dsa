#include<bits/stdc++.h>
using namespace std;

void printarray(int* a, int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int getmax(int* arr, int n){
    int mx = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>mx) mx= arr[i];
    }
    return mx;
}

void countsort(int * a, int n, int pos){
    int B[n], i, count[10] = {0};
    for(int i=0;i<n;i++){
        ++count[(a[i]/pos)%10];
    }

    for(int i=1;i<10;i++){
        count[i] += count[i-1];
    }

    // Build the output array
    for(int i=n-1;i>=0;i--){
        B[--count[(a[i]/pos)%10]] = a[i];
    }

    for(int i=0;i<n;i++){
        a[i] = B[i];
    }
}

void radixsort(int *a,int n){
    int m = getmax(a,n);
    int pos;
    for(pos = 1;m/pos;pos*=10){
        countsort(a,n,pos);
    }
}

int main(){
    int n,a[100000];
    cout<<"Enter the size of the array : "<<"\n";
    cin>>n;
    cout<<"Enter the elements of the array: "<<"\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"\n";
    cout<<"Before sorting:\n";
    printarray(a,n);
    radixsort(a,n);
    cout<<"\n";
    cout<<"After sorting\n";
    printarray(a,n);
    return 0;
}